%%
%
% Navigate with Occupancy Flow
% - Sungjoon Choi in SNU
%   (sungjoon.choi@cpslab.snu.ac.kr)
%
addpath('bayesopt');
addpath('robotsim');
addpath('occflow');
ccc

%% Simulation !! 
ccc

% Simulation flag
manual_control     = 1;
use_occflow        = 1;
colorcoded_occflow = 1;
save_vid           = 0;

% Initialize simulation 
if save_vid
    x = inputdlg('Record? [Y: Yes / Otherwise: No]', 'Video Record', [1 50]); 
	if isempty(x)
        fprintf(2, 'Simulation canceled. \n');
        return;
    elseif isequal(x{1}, 'Y') || isequal(x{1}, 'y')
        fprintf(2, 'Record current experiments. \n');
    else
        fprintf('No record.\n'); save_vid = 0;
    end
    plist.n    = 0;
    plist.data = cell(1E4, 1);
end
rng('shuffle');
sim   = init_sim(1E4, 0.2); prev_sec = 0;
robot = init_robot([2000 5000 0], [0 0], 200);
halfw = 5000;
ginfo = set_grid(-halfw, halfw, 100, -halfw, halfw, 100);
obs   = init_obs();
wall  = 1E3*[0 0 ; 20 0 ; 20 10 ; 0 10 ; 0 0];
obs   = add_obs(obs, [0 0 0], [0 0], wall);
goal  = 1E3*[16 5];
goal_radius = 1500;
nr_ped = 20;
for i = 1:nr_ped
    xrand = 2E3 + 16E3*rand;
    yrand = 1E3 + 8E3*rand;
    drand = 360*rand;
    vrand = (rand < 0.9)*(400+600*rand);
    wrand = -5 + 10*rand;
    if norm(robot.pos(1:2) - [xrand yrand]) < 2E3
        i = i - 1; continue; 
    end
    obs   = add_obs(obs, [xrand yrand drand], [vrand 0]);
end
global SIM_MODE PAUSE_MODE key_pressed
SIM_MODE = 1; PAUSE_MODE = 0; run_mode = SIM_MODE; key_pressed = '';
fig = figure(1);set(fig,'Position', [50 300 1800 1000], 'Name', 'Navigation Experiment' ...
    , 'NumberTitle', 'off', 'MenuBar', 'none', 'KeyPressFcn', @keyDownListener, 'Color', 0.2*[1 1 1]);
img = imread('fig_colorcode.png');
ems_occflow = 0; ems_plot = 0; ems_total = 0;
fprintf('Mobile robot simulation ready. \n'); 
% Initialize OccFlow
load('bayesOpt_occflowParams.mat');
[max_score, max_idx] = max(-bo.output);
vec = bo.input(max_idx, :);
[occflow.g1, occflow.l1, occflow.resize_rate, occflow.g2, occflow.l2] ...
    = parse_occflowparams(vec);
occflow.l2.resize_rate = occflow.resize_rate;
if 1 % Refine network
    occflow.l2.neixres  = 3;
    occflow.l2.neiyres  = 3;
    occflow.l2.nei      = set_nei(occflow.g2, occflow.l2.neixres, occflow.l2.neiyres, occflow.l2.neisig, 1);
    occflow.l2.context  = occflow.l2.reinitval*ones(occflow.g2.n, occflow.l2.nei.filter.n);
    % occflow.l2.intensifyrate      = 8;
    % occflow.l2.nocc_attenuaterate = 0.4;
    % occflow.l2.reinitval          = 2;
    % occflow.l2.bin_threshold      = 0.4;
end
gridmap_mapvec_list = zeros(1E3, ginfo.n);
fprintf('OccFlow ready. \n');
while sim.flag
    iclk = clock;
    % KeyBD
    switch key_pressed
        case 'q',           sim.flag = 0; fprintf(2, 'Quit. \n');
        case 'p',           run_mode = ~run_mode;
        case 'uparrow',     robot.vel(1) = robot.vel(1) + 300;
        case 'downarrow',   robot.vel(1) = robot.vel(1) - 300;
        case 'leftarrow',   robot.vel(2) = robot.vel(2) + 20;
        case 'rightarrow',  robot.vel(2) = robot.vel(2) - 20;
        case 'space',       robot.vel = [0 0];
        otherwise
    end
    key_pressed = '';
    % Update
    switch run_mode
        case SIM_MODE
            % Update
            iclk_update = clock;
            sim     = update_sim(sim);
            obs     = update_obs(obs, sim);
            robot   = update_robot(robot, sim);
            robot   = update_rfs(robot, obs);
            gridmap = get_gridmap(robot.rfs_result_xy, robot.rfs_valid_idx, 0, ginfo);
            gridmap_mapvec = gridmap.map(:);
            gridmap_mapvec_list(sim.tick, :) = gridmap_mapvec;
            ems_update = etime(clock, iclk_update)*1000;
            
            % Let all pedestrians be inside the region
            for i = 2:obs.n
                obs_pos = obs.obs{i}.pos;
                obs_vel = obs.obs{i}.vel;
                obs_sec = obs.obs{i}.sec;
                if inpolygon(obs_pos(1), obs_pos(2), obs.obs{1}.shape(:, 1), obs.obs{1}.shape(:, 2)) == 0 ...
                        && sim.sec - obs_sec > 1
                    % If the pedestrian leaves the region, 
                    obs.obs{i}.sec = sim.sec;
                    obs.obs{i}.pos(3) = obs_pos(3) + 180;
                     vrand = (rand < 0.9)*(400+600*rand);
                     wrand = -10 + 20*rand;
                    obs.obs{i}.vel = [vrand wrand];
                end
            end
            
            % OccFlow
            iclk_occflow = clock;
            occflow.l1.curr_input = gridmap_mapvec(:);
            occflow.l1 = occflow_wrapper(occflow.g1, occflow.l1, occflow.l2.resize_rate);
            occflow.l2.curr_input = occflow.l1.binsmallmtx(:);
            occflow.l2 = occflow_wrapper(occflow.g2, occflow.l2, occflow.l2.resize_rate);
            ems_occflow = etime(clock, iclk_occflow)*1000;
            
            % Variance thresholding
            context_stds = std(occflow.l2.context');
            temp_idx = find(context_stds < 0.1);
            occflow.l2.context(temp_idx, :) = 0.2*occflow.l2.context(temp_idx, :);
            
            % OccFlow -> RGB Image
            rgb_gain2 = 0.3; rgb_th = occflow.l2.bin_threshold;
            [occflow.l2.rgbflowimg, valid_idx, u, v] ...
                = get_rgbflow(occflow.l2.context, occflow.l2.predvec, occflow.l2.nei.filter.shift_xyi ...
                , occflow.g2.nx, occflow.g2.ny, rgb_gain2, rgb_th);
            occflow.l2.rgbflowimg_resize = imresize(occflow.l2.rgbflowimg, 1/occflow.l2.resize_rate);
            
            % OccFlow -> Quiver Arrows
            quiver_rate   = 5E+1;
            min_quiver    = 3;
            max_quiver    = 6;
            resize_quiver = 0.8;
            [xmesh, ymesh, ru, rv] ...
                = get_dirflow(u, v, valid_idx, robot, ginfo, quiver_rate, min_quiver, max_quiver, resize_quiver);
            
            % Sample paths & select the best one 
            iclk_control = clock;
            npath = 400;
            horizon_sec = 4;
            [pset.xpaths, pset.ypaths, pset.dpaths, pset.vlist, pset.wlist] ...
                = get_randompaths(npath, sim.T, horizon_sec);
            predmtx_small  = reshape(occflow.l2.predvec, size(occflow.l2.binpredmtx, 1), size(occflow.l2.binpredmtx, 2));
            predmtx_resize = imresize(predmtx_small, 1/occflow.l2.resize_rate, 'bilinear');
            gridmtx        = gridmap.map;
            if use_occflow
                % Option 1: Use occflow
                occupy_penalty_gain = 10;
                grid4obscost   = max(predmtx_resize, occupy_penalty_gain*gridmtx);
            else
                % Option 2: Use occ grid only
                grid4obscost   = gridmtx;
            end
            % Compute costs of paths
            [obscost, goaldist] ...
                = get_pathcosts_mex(pset.xpaths, pset.ypaths, ginfo.xmesh, ginfo.ymesh, grid4obscost, robot.pos, goal);
            pathscosts  = 0.1*goaldist + obscost; % lower the better
            [~, bestpathidx] = min(pathscosts);
            % Uniformly increasing costs (order unchainged)
            pathscosts_refined = zeros(npath, 1);
            [~, pathcostidx] = sort(pathscosts);
            pathscosts_refined(pathcostidx) = 1:npath;
            bestcontrol = [pset.vlist(bestpathidx) pset.wlist(bestpathidx)];
            
            % Control
            if manual_control == 0
                robot.vel = bestcontrol;
            end
            % Goal reach
            if norm(robot.pos(1:2) - goal) < goal_radius - robot.r
                fprintf(2, 'Goal reached. \n');
                sim.flag = 0;
            end
            ems_control = etime(clock, iclk_control)*1000;
        case PAUSE_MODE
            pause(1E-6);
    end
    
    % Plot
    if ishandle(fig) == 0, break; end;
    iclk_plot = clock;
    title_str = sprintf('[%d] %.1f sec (update: %.1fms + control: %.1fms + occflow: %.1fms + plot: %.1fms = total: %.1fms) / (%.1fmm/s %.1fdeg/s)' ...
        , sim.tick, sim.sec, ems_update, ems_control, ems_occflow, ems_plot, ems_total, robot.vel(1), robot.vel(2));
    p = struct('robot', robot, 'gridmap', gridmap, 'l2', occflow.l2, 'obs', obs, 'img', img, 'title_str', title_str ...
        , 'sim', sim, 'run_mode', run_mode, 'fig', fig ...
        , 'xmesh', xmesh, 'ymesh', ymesh, 'ru', ru, 'rv', rv ...
        , 'pset', pset, 'goal', goal, 'goal_radius', goal_radius ...
        , 'pathcosts', pathscosts_refined, 'bestpathidx', bestpathidx ...
        , 'use_occflow', use_occflow, 'colorcoded_occflow', colorcoded_occflow);
    plot_occflow_navi(p);
    ems_plot  = etime(clock, iclk_plot)*1000;
    ems_total = etime(clock, iclk)*1000;
    if save_vid
        imgname = sprintf('pics4vid/fig_occflowkbd_%03d.png', sim.tick);
        set(fig,'PaperPositionMode','auto');
        print (fig , '-dpng', imgname) ;
    end
end

if save_vid
    if use_occflow
        vidName = sprintf('vids/navi_occflow.avi');
    else
        vidName = sprintf('vids/navi_occgrid.avi');
    end
    fprintf('Saving pngs to Video: %s \n', vidName);
    frmRate  = round(1/sim.T);
    video    = VideoWriter( vidName );
    video.FrameRate = frmRate;
    open( video );
    for i = 1:sim.tick - 1
        imgname = sprintf('pics4vid/fig_occflowkbd_%03d.png', i);
        img   = imread(imgname);
        imgr  = imresize(img, [size(img, 1) size(img, 2)]/1);
        imgd  = im2double(imgr);
        writeVideo(video, imgd);
    end
    close( video );
    fprintf(2, 'Video saved to %s. \n', vidName);
end


%%














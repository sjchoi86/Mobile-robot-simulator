function plot_occflow_navi(p)
global SIM_MODE
persistent plot_buffer

% Parse inputs

iclk_parse  = clock;

sim         = p.sim;
robot       = p.robot;
robot_pos   = robot.pos;
gridmap     = p.gridmap;
xmin        = gridmap.xmin;
xmax        = gridmap.xmax;
ymin        = gridmap.ymin;
ymax        = gridmap.ymax;
nx          = gridmap.xres;
ny          = gridmap.yres;
[xtemp, ytemp] = meshgrid(linspace(xmin, xmax, nx), linspace(ymin, ymax, ny));
xvec        = xtemp(:);
yvec        = ytemp(:);
xyvec       = [xvec yvec];
deg         = robot_pos(3);
c           = cos(deg*pi/180);
s           = sin(deg*pi/180);
rotmat      = [c s ; -s c];
xyvec       = xyvec * rotmat + repmat(robot_pos(1:2), nx*ny, 1);
xvec        = xyvec(:, 1); yvec = xyvec(:, 2);
xmesh_grid  = reshape(xvec, ny, nx);
ymesh_grid  = reshape(yvec, ny, nx);
gridmtx     = gridmap.map;
l2          = p.l2;
use_occflow = p.use_occflow;
colorcoded_occflow = p.colorcoded_occflow;
obs         = p.obs;
if use_occflow
    if colorcoded_occflow
        griddata = l2.rgbflowimg_resize;
    else
        predmtx     = reshape(l2.predvec, size(l2.binpredmtx, 1), size(l2.binpredmtx, 2));
        predmtx_res = imresize(predmtx, 1/l2.resize_rate, 'bilinear');
        occpredmtx  = max(predmtx_res, gridmtx);
        griddata    = occpredmtx;
    end
else
    griddata = gridmtx;
end
pset        = p.pset;
xpaths      = pset.xpaths;
ypaths      = pset.ypaths;
npaths      = size(xpaths, 1);
rel_xypaths = [xpaths(:) ypaths(:)];
ref_xypaths = get_ref_cart_pos(p.robot.pos, rel_xypaths);
ref_xpaths  = reshape(ref_xypaths(:, 1), npaths, []);
ref_ypaths  = reshape(ref_xypaths(:, 2), npaths, []);
pathcolors  = val2color(p.pathcosts, 0); % <= lower the better
bestpathidx = p.bestpathidx;
obs_colors  = lines(obs.n);
robot.color = [0.1 0.9 0.05];
rx          = robot.pos(1);
ry          = robot.pos(2);
rdeg        = robot.pos(3);
radius      = robot.r;
% RFS
rfs_edge_color = [0.7 0.2 0.3];
rfs_end_points = zeros(robot.nr_rfs, 2);
for i = 1:robot.nr_rfs
    rfs_deg = robot.pos(3) + robot.rfs_degs(i);
    rfs_rad = rfs_deg * pi / 180;
    rfs_to = robot.pos(1:2) ...
        + (robot.r+robot.rfs_result(i))*[cos(rfs_rad) sin(rfs_rad)];
    if 0 % Debug purpose
        text( rfs_to(1), rfs_to(2), sprintf(' [%d]', i) );
    end
    rfs_end_points(i, 1) = rfs_to(1);
    rfs_end_points(i, 2) = rfs_to(2);
end
obsplot.iswall          = zeros(obs.n, 1);
obsplot.obs_boundary    = cell(obs.n, 1);
obsplot.center_boundary = cell(obs.n, 1);
obsplot.obs_pos         = cell(obs.n, 1);
for i = 1:obs.n
    obs_pos     = obs.obs{i}.pos;
    obs_shape   = obs.obs{i}.shape;
    r           = obs_pos(3)*pi/180;
    rot_mat     = [cos(r) sin(r) ; -sin(r) cos(r) ];
    obs_shape   = obs_shape*rot_mat;
    xymin       = min(obs_shape);
    xymax       = max(obs_shape);
    xwidth      = xymax(1) - xymin(1);
    obs_boundary = repmat(obs_pos(1:2), size(obs_shape, 1), 1) + obs_shape;
    if xwidth < 2000 % For small obstacles
        center_boundary = repmat(obs_pos(1:2), size(obs_shape, 1), 1) + get_circle(0, 0, 210, 10);
        obsplot.iswall(i)          = 0;
        obsplot.obs_boundary{i}    = obs_boundary;
        obsplot.obs_pos{i}         = obs_pos;
        obsplot.center_boundary{i} = center_boundary;
    else
        obsplot.iswall(i)       = 1;
        obsplot.obs_boundary{i} = obs_boundary;
    end
end
rfs_end_points = [robot.pos(1:2) ; rfs_end_points ; robot.pos(1:2)];
robotBoundary  = get_circle(rx, ry, radius, 20);
robotplot.horizon             = 5;
robotplot.futurerobotBoundary = cell(robotplot.horizon, 1);
robotplot.futurerobotpos      = cell(robotplot.horizon, 1);
v = robot.vel(1);
w = robot.vel(2);
T = 0.6;
curr_pos = robot.pos;
for i = 1:robotplot.horizon
    x = curr_pos(1);
    y = curr_pos(2);
    d = curr_pos(3);
    c = cos(d*pi/180);
    s = sin(d*pi/180);
    x = x + v*c*T;
    y = y + v*s*T;
    d = d + w*T;
    futurerobotBoundary = get_circle(x, y, radius, 20);
    curr_pos = [x y d];
    futurerobotpos = [x y d];
    robotplot.futurerobotBoundary{i} = futurerobotBoundary;
    robotplot.futurerobotpos{i} = futurerobotpos;
end
goal         = p.goal;
goal_radius  = p.goal_radius;
goal_bd      = get_circle(goal(1), goal(2), goal_radius, 40);
goal_str     = sprintf('Goal\nRegion');
img          = p.img;
ccode_center = [19000 9000];
ccode_radius = 1000;
ccode_title_bias = 250;
ccode_center_temp = ccode_center - [0 2*ccode_title_bias];
ccode_rad    = ccode_radius;
img_res      = imresize(img, [100 100]);
img_flip     = flipud(img_res);
[h, w]       = size(img_flip);
[xtemp, ytemp] = meshgrid(linspace(-ccode_rad, ccode_rad, w), linspace(-ccode_rad, ccode_rad, h));
xvec         = xtemp(:);
yvec         = ytemp(:);
xyvec        = [xvec yvec];
deg          = robot.pos(3); c = cos(deg*pi/180); s = sin(deg*pi/180);
rotmat       = [c s ; -s c];
xyvec        = xyvec * rotmat + repmat(ccode_center_temp, w*h, 1);
xvec         = xyvec(:, 1);
yvec         = xyvec(:, 2);
ccode_xmesh  = reshape(xvec, h, w);
ccode_ymesh  = reshape(yvec, h, w);
ems_parse    = etime(clock, iclk_parse)*1000;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Plot starts here %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

iclk_plot    = clock;
if sim.tick == 1 % First time plot 
    clf;
    axes('Parent', p.fig, 'Position', [0.05 0.02 0.92 0.96]); hold on;
    
    % 1. Egocentric Grid Map + Color-coded occupancy flow information
    plot_buffer.grid = surface('xdata', xmesh_grid, 'ydata', ymesh_grid, 'zdata', zeros(ny, nx) ...
        , 'cdata', griddata,'facecolor', 'texturemap', 'edgecolor', 0.5*[1 1 1]);
    alpha(.9);
    
    % 2. Path set
    plot_buffer.pathset.paths = cell(npaths, 1);
    for i = 1:npaths
        plot_buffer.pathset.paths{i}.h = plot(ref_xpaths(i, :), ref_ypaths(i, :), '-', 'Color', pathcolors(i, :));
    end
    plot_buffer.pathset.bestpath = plot(ref_xpaths(bestpathidx, :), ref_ypaths(bestpathidx, :), '-', 'Color', 'g', 'LineWidth', 3);
    
    % Flow direction with arrows (quiver)
    if use_occflow
        plot_buffer.flow.quiver = quiver(p.xmesh, p.ymesh, p.ru, p.rv, 'Color', 'k', 'LineWidth', 1, 'AutoScale', 'off');
    end
    
    % 3. Obstacles and wall
    plot_buffer.obs = cell(obs.n, 1);
    for i = 1:obs.n
        if obsplot.iswall(i) == 0
            obs_boundary    = obsplot.obs_boundary{i};
            obs_pos         = obsplot.obs_pos{i};
            center_boundary = obsplot.center_boundary{i};
            % Body
            hbody = fill(obs_boundary(:, 1), obs_boundary(:, 2), obs_colors(i, :) );
            set(hbody, 'facealpha', 0.5);
            % Head
            hhead = fill(center_boundary(:, 1), center_boundary(:, 2), 0.8*[1 1 1 ]);
            % Direction
            harrow = draw_arrow(obs_pos(1:2), 200, obs_pos(3), 'k', 2);
            
            plot_buffer.obs{i}.harrow = harrow;
            plot_buffer.obs{i}.iswall = 0;
            plot_buffer.obs{i}.hbody  = hbody;
            plot_buffer.obs{i}.hhead  = hhead;
            
        else
            obs_boundary = obsplot.obs_boundary{i};
            hbd = plot(obs_boundary(:, 1), obs_boundary(:, 2), 'Color', obs_colors(i, :), 'LineWidth', 2);
            plot_buffer.obs{i}.iswall = 1;
            plot_buffer.obs{i}.hbd    = hbd;     
        end
    end
    % Robot with range finder sensor
    hfill_rfs = fill(rfs_end_points(:, 1), rfs_end_points(:, 2), 0.7*[1 1 1]);
    set(hfill_rfs, 'facealpha', 0.2);
    hplot_rfs = plot(rfs_end_points(:, 1), rfs_end_points(:, 2), '-' ...
        , 'Color', rfs_edge_color, 'MarkerSize', 11, 'LineWidth', 2);
    plot_buffer.hfill_rfs = hfill_rfs;
    plot_buffer.hplot_rfs = hplot_rfs;
    
    % Future roobt positions
    plot_buffer.futurepos = cell(robotplot.horizon, 1);
    for i = 1:robotplot.horizon
        futurerobotBoundary = robotplot.futurerobotBoundary{i};
        futurerobotpos      = robotplot.futurerobotpos{i};
        plot_buffer.futurepos{i}.bd = plot( futurerobotBoundary(:,1), futurerobotBoundary(:,2), 'Color', [.2 1 .2], 'LineWidth', 1 );
        plot_buffer.futurepos{i}.arrow = draw_arrow(futurerobotpos(1:2), radius, futurerobotpos(3), [.2 1 .2]);
    end
    
    % Robot boundary
    plot_buffer.robotbd.fill = fill(robotBoundary(:,1), robotBoundary(:,2), robot.color, 'LineWidth', 1 );
    plot_buffer.robotbd.plot = plot(robotBoundary(:,1), robotBoundary(:,2), 'Color', 'k', 'LineWidth', 1 );
    % Heading
    plot_buffer.robothead = draw_arrow(robot.pos, radius, rdeg);
    
    % Color code
    if colorcoded_occflow
        plot_buffer.ccode.surf = surface('xdata', ccode_xmesh, 'ydata', ccode_ymesh, 'zdata', zeros(h, w) ...
            , 'cdata', img_flip, 'facecolor', 'texturemap', 'edgecolor', 'none');
        text(ccode_center_temp(1), ccode_center_temp(2)+ccode_rad+ccode_title_bias ...
            , sprintf('Egocentric\nColor-code'), 'FontSize', 13, 'HorizontalAlignment', 'Center');
    end
    % Goal 
    fill(goal_bd(:, 1), goal_bd(:, 2), [1 0.2 0.2], 'LineWidth', 2, 'facealpha', .5);
    text(goal(1), goal(2), goal_str, 'HorizontalAlignment', 'Center', 'FontSize', 25);
    
    % X, Y label
    xlabel('X [mm]', 'FontSize', 18, 'Color', 'w');
    ylabel('Y [mm]', 'FontSize', 18, 'Color', 'w');
    ax = gca; ax.XTick = linspace(0, 2E4, 20+1); ax.YTick = linspace(0, 1E4, 10+1);
    set(ax, 'XColor', 'w', 'YColor', 'w');
    
    % Axis and ETC
    margin = 500;
    grid on; box on; axis equal; axis([0 20 0 10]*1E3 + [-margin margin -margin margin]);
    colormap gray;
    caxis([0 1]);
    
else
    % Parse data for SPEEDUP!
    
    % Occupancy flow grid data
    plot_buffer.grid.XData = xmesh_grid;
    plot_buffer.grid.YData = ymesh_grid;
    plot_buffer.grid.CData = griddata;
    
    
    % Random paths
    for i = 1:npaths
        plot_buffer.pathset.paths{i}.h.XData = ref_xpaths(i, :);
        plot_buffer.pathset.paths{i}.h.YData = ref_ypaths(i, :);
        plot_buffer.pathset.paths{i}.h.Color = pathcolors(i, :);
    end    
    % Best path
    plot_buffer.pathset.bestpath.XData = ref_xpaths(bestpathidx, :);
    plot_buffer.pathset.bestpath.YData = ref_ypaths(bestpathidx, :);
    
    
    % Obstacles 
    for i = 1:obs.n
        obs_boundary = obsplot.obs_boundary{i};
        if plot_buffer.obs{i}.iswall == 0
            obs_pos         = obsplot.obs_pos{i};
            center_boundary = obsplot.center_boundary{i};
            % Body
            plot_buffer.obs{i}.hbody.Vertices  = obs_boundary;
            plot_buffer.obs{i}.hbody.FaceColor = obs_colors(i, :);
            plot_buffer.obs{i}.hbody.FaceAlpha = 0.5;
            % Head
            plot_buffer.obs{i}.hhead.Vertices  = center_boundary;
            plot_buffer.obs{i}.hhead.FaceColor = 0.8*[1 1 1];
            % Direction
            harrow = get_arrow(obs_pos(1:2), 200, obs_pos(3), 'k', 2);
            for j = 1:3
                plot_buffer.obs{i}.harrow{j}.XData = harrow{j}.XData;
                plot_buffer.obs{i}.harrow{j}.YData = harrow{j}.YData;
            end
        else
            plot_buffer.obs{i}.hbd.XData = obs_boundary(:, 1);
            plot_buffer.obs{i}.hbd.YData = obs_boundary(:, 2);
            plot_buffer.obs{i}.hbd.Color = obs_colors(i, :);
        end
    end
    
    % Range-finder sensor
    plot_buffer.hfill_rfs.Vertices  = rfs_end_points;
    plot_buffer.hfill_rfs.FaceColor = 0.7*[1 1 1];
    plot_buffer.hplot_rfs.XData = rfs_end_points(:, 1);
    plot_buffer.hplot_rfs.YData = rfs_end_points(:, 2);
    plot_buffer.hplot_rfs.Color = rfs_edge_color;
    
    % Robot future position
    for i = 1:robotplot.horizon
        futurerobotBoundary = robotplot.futurerobotBoundary{i};
        futurerobotpos      = robotplot.futurerobotpos{i};
        plot_buffer.futurepos{i}.bd.XData = futurerobotBoundary(:, 1);
        plot_buffer.futurepos{i}.bd.YData = futurerobotBoundary(:, 2);
        hfrobotarrow = get_arrow(futurerobotpos(1:2), radius, futurerobotpos(3), [.2 1 .2]);
        for j = 1:3
            plot_buffer.futurepos{i}.arrow{j}.XData = hfrobotarrow{j}.XData;
            plot_buffer.futurepos{i}.arrow{j}.YData = hfrobotarrow{j}.YData;
        end
    end
    
    % Robot body
    plot_buffer.robotbd.fill.Vertices = robotBoundary;
    plot_buffer.robotbd.fill.FaceColor = robot.color;
    plot_buffer.robotbd.plot.XData = robotBoundary(:, 1);
    plot_buffer.robotbd.plot.YData = robotBoundary(:, 2);
    hrobotheadarrow = get_arrow(robot.pos, radius, rdeg);
    for j = 1:3
        plot_buffer.robothead{j}.XData = hrobotheadarrow{j}.XData;
        plot_buffer.robothead{j}.YData = hrobotheadarrow{j}.YData;
    end
    
    % Color coding image
    if colorcoded_occflow
        plot_buffer.ccode.surf.XData = ccode_xmesh;
        plot_buffer.ccode.surf.YData = ccode_ymesh;
        plot_buffer.ccode.surf.CData = img_flip;
    end
    
    % Arrow 
    if use_occflow
        plot_buffer.flow.quiver.XData = p.xmesh;
        plot_buffer.flow.quiver.YData = p.ymesh;
        plot_buffer.flow.quiver.UData = p.ru;
        plot_buffer.flow.quiver.VData = p.rv;
    end

end
ems_plot = etime(clock, iclk_plot)*1000;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Plot ends here %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
iclk_etc = clock;

% Title
title_fontSize = 20;
if p.sim.flag == 0
    title(sprintf('TERMINATED %s', p.title_str), 'fontSize', title_fontSize, 'color', 'r');
elseif p.run_mode == SIM_MODE
    title(sprintf('%s', p.title_str), 'fontSize', title_fontSize, 'color', 'g');
else
    title(sprintf('PAUSED %s', p.title_str), 'fontSize', title_fontSize, 'color', 'r');
end;


ems_etc = etime(clock, iclk_etc)*1000;

% Show time
drawnow;

ems_total = ems_parse + ems_plot + ems_etc;
% fprintf('ems_parse: %.1fms + ems_plot: %.1fms + ems_etc: %.1fms = ems_total: %.1fms\n' ...
%     , ems_parse, ems_plot, ems_etc, ems_total);


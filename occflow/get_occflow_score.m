function score_avg = get_occflow_score(g1, l1, g2, l2, resize_rate, plot_flag)

score_sum = 0;
maxtrial  = 10; % <= 몇 번 서로 다른 장애물 시나리오에 대해서 실험을 할지
for trial = 1:maxtrial
    rng(trial);
    % Initialize Obstacle(s)
    nr_obs        = randi([2 7]);
    obs4grid      = init_obs4grid(g1, nr_obs, [200 800], [1000 6000]);
    val.pred_mtx  = cell(100, 1);
    val.input_mtx = cell(100, 1);
    score_sumtemp = 0;
    for i = 1:100 % <= 한 실험의 최대 길이 (iteration)
        % update
        iclk          = clock;
        obs4grid      = update_obs4grid(obs4grid);
        obs_grid      = get_obsgrid2(g1, obs4grid);
        curr_input    = obs_grid(:); % <= input to the first layer
        toc_update_ms = etime(clock, iclk)*1000;
        
        % addnoise to input
        noise_level = 0.01;
        flip_idx    = randsample(g1.n, round(g1.n*noise_level));
        curr_input(flip_idx) = ~curr_input(flip_idx);
        
        % occupnacy flow
        iclk           = clock;
        % occupnacy flow on first layer
        l1.curr_input  = curr_input;
        l1             = occflow_wrapper(g1, l1, resize_rate);
        % occupancy flow on second layer
        l2.curr_input  = l1.binsmallmtx(:);
        l2             = occflow_wrapper(g2, l2, resize_rate);
        % feedback from l2 to l1 (not implemented yet)
        l2predmtx = reshape(l2.predvec, g2.ny, g2.nx);
        l2predmtx_resize = imresize(l2predmtx, 1/resize_rate);
        toc_occflow_ms = etime(clock, iclk)*1000;
        
        
        % color-coding
        iclk           = clock;
        gain = 0.5; th = l1.bin_threshold;
        l1.rgbflowimg  = get_rgbflow(l1.context, l1.predvec, l1.nei.filter.shift_xyi, g1.nx, g1.ny, gain, th);
        gain = 0.5; th = l2.bin_threshold;
        l2.rgbflowimg  = get_rgbflow(l2.context, l2.predvec, l2.nei.filter.shift_xyi, g2.nx, g2.ny, gain, th);
        l2.rgbflowimg_resize = imresize(l2.rgbflowimg, 1/resize_rate);
        toc_colorcode_ms = etime(clock, iclk)*1000;
        
        
        % plot
        iclk = clock;
        if plot_flag
            do_plot_occflow_doublelayer_grid;
        end
        toc_plot_ms = etime(clock, iclk)*1000;
        
        
        % terminate if obs is outside the stage
        x1 = g1.xmin; x2 = g1.xmax; y1 = g1.ymin; y2 = g1.ymax; bd = [x1 y1 ; x2 y1 ; x2 y2 ; x1 y2 ; x1 y1];
        obsoutcnt = 0;
        for j = 1:obs4grid.n
            if ~inpolygon(obs4grid.obs{j}.pos(1), obs4grid.obs{j}.pos(2), bd(:, 1), bd(:, 2)) % || ishandle(fig) == 0
                obsoutcnt = obsoutcnt + 1;
            end
        end
        if obsoutcnt == obs4grid.n
            break;
        end
        
        % validation
        val.pred_mtx{i} = imresize(reshape(l2.predvec, g2.ny, g2.nx), 1/resize_rate);
        val.input_mtx{i} = obs_grid; % <= 이건 noise free이다. 
        
        if i >= 3
            pred_mtx    = val.pred_mtx{i-2};
            zeroidx = find(pred_mtx < l2.bin_threshold);
            oneidx  = find(pred_mtx >= l2.bin_threshold);
            pred_mtx(zeroidx) = 0;
            pred_mtx(oneidx)  = 1;
            
            input1 = val.input_mtx{i-0};
            input2 = val.input_mtx{i-1};
            input3 = val.input_mtx{i-2};
            input_all = max(input1, input2);
            input_all = max(input_all, input3);
            
            occ_idx  = find(input_all == 1);
            nocc_idx = find(input_all == 0);
            
            % Score를 계산한다.
            score = sum(sum(pred_mtx(occ_idx))) - 0.2*sum(sum(pred_mtx(nocc_idx)));
%             score = sum(sum(pred_mtx(occ_idx)))/(1+length(occ_idx)) ...
%                 - sum(sum(pred_mtx(nocc_idx)))/(1+length(nocc_idx));
        else
            score = 0;
        end
        
        % show
        score_sumtemp = score_sumtemp + score;
        % fprintf('score: %.3f \n', score);
        % fprintf('[tocs] update: %.1fms occflow: %.1fms colorcoding: %.1fms plot: %.1fms \n' ...
        %     , toc_update_ms, toc_occflow_ms, toc_colorcode_ms, toc_plot_ms);
    end % for i = 1:100
    score_avgtemp = score_sumtemp / (i+1);
    score_sum = score_sum + score_avgtemp;
end % for trial = 1:maxtrial
score_avg = score_sum / maxtrial; % <= 이게 스코어이다!

if abs(score_avg) < 0.001
    score_avg = -10;
elseif score_avg < -100
    score_avg = -100;
end



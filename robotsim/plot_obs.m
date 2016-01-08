function plot_handle = plot_obs(obs, obs_colors)
% Plot obs

if nargin == 1
    obs_colors = lines(obs.n);
end

for i = 1:obs.n
    obs_pos      = obs.obs{i}.pos;
    obs_shape    = obs.obs{i}.shape;
    % obs_vel      = obs.u{i};
    
    r = obs_pos(3)*pi/180;
    rot_mat = [cos(r) sin(r) ; -sin(r) cos(r) ];
    obs_shape = obs_shape*rot_mat;
    
    xymin = min(obs_shape);
    xymax = max(obs_shape);
    xwidth = xymax(1) - xymin(1);
    obs_boundary = repmat(obs_pos(1:2), size(obs_shape, 1), 1) + obs_shape;

    if xwidth < 2000
        % For small obstacles 
        hf = fill(obs_boundary(:, 1), obs_boundary(:, 2) ...
            , obs_colors(i, :) );
        set(hf, 'facealpha', 0.5);
        % Head 
        center_boundary = repmat(obs_pos(1:2), size(obs_shape, 1), 1) + get_circle(0, 0, 210, 10);
        fill(center_boundary(:, 1), center_boundary(:, 2), 0.8*[1 1 1 ]);
        draw_arrow(obs_pos(1:2), 200, obs_pos(3), 'k', 2);
        
        show_text = 0;
        if show_text
            h = text(obs_pos(1), obs_pos(2), sprintf('%d', i) ...
                , 'HorizontalAlignment', 'center' ...
                , 'FontSize', 12 );
            set(h, 'rotation', obs_pos(3))
        end
    end 
    
    plot_handle = plot(obs_boundary(:, 1), obs_boundary(:, 2) ...
        , 'Color', obs_colors(i, :)  ...
        , 'LineWidth', 2);
    
end


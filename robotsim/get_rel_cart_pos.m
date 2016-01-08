function rel_pos = get_rel_cart_pos(robot_pos, obs_traj)
%
% Get relative Cartesian position
%
disp_debug = 0;

nr_obs  = size(obs_traj, 1);
rel_pos = zeros(nr_obs, 2);

for i = 1:nr_obs
    cur_obs_pos = obs_traj(i, :);
    
    rel_x = cur_obs_pos(1) - robot_pos(1);
    rel_y = cur_obs_pos(2) - robot_pos(2);
    rel_dist = norm([rel_x rel_y]);
    
    rel_rad = atan2(rel_y, rel_x);
    robot_rad = robot_pos(3)*pi/180;
    diff_rad = robot_rad - rel_rad;
    diff_rad = -diff_rad;
    % diff_rad = pi/2 - diff_rad;
    
    % x 
    rel_pos(i, 1) = rel_dist*cos(diff_rad);
    % y 
    rel_pos(i, 2) = rel_dist*sin(diff_rad);
    
    if disp_debug
        fprintf('robot_pos: (%.1f, %.1f) deg: %.1f / obs_pos: (%.1f, %.1f) / rel_dist: %.1f rel_deg: %.1f diff_deg: %.1f / rel_pos: (%.2f, %.2f) \n' ...
            , robot_pos(1), robot_pos(2), robot_pos(3)  ...
            , cur_obs_pos(1), cur_obs_pos(2) ...
            , rel_dist, rel_rad*180/pi, diff_rad*180/pi ...
            , rel_pos(1), rel_pos(2) );
    end
end

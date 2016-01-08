function [obscost, goaldist] = get_pathcosts(xpaths, ypaths, xmesh, ymesh, grid4obscost, robot_pos, goal)

npath          = size(xpaths, 1);
obscost        = zeros(npath, 1);
goaldist       = zeros(npath, 1);
for path_idx = 1:npath
    curr_path = [xpaths(path_idx, :)' ypaths(path_idx, :)'];
    predvals  = interp2(xmesh, ymesh, grid4obscost, curr_path(:, 1), curr_path(:, 2));
    maxval    = max(predvals);
    end_pos   = curr_path(end, :);
    
    obscost(path_idx)  = maxval;  % lower the better
    goaldist(path_idx) = norm(goal - get_ref_cart_pos(robot_pos, end_pos)); % lower the better
end
obscost     = obscost / (max(obscost) + 1E-6);
goaldist    = goaldist / max(goaldist);


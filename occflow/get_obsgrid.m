function obs_grid = get_obsgrid(g, obs_pos, obs_r)

obs_grid = zeros(g.ny, g.nx);
obs_diff = g.xy - repmat(obs_pos(1:2), g.n, 1);
obs_dist = sqrt(obs_diff(:, 1).*obs_diff(:, 1) + obs_diff(:, 2).*obs_diff(:, 2));
obs_valid = obs_dist <= obs_r;
obs_grid(obs_valid) = 1;





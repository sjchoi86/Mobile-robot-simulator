function obs = add_obs(obs, pos, u, shape, rgb_color)

if nargin == 3
    obs_d = 400;
    shape = get_ellipse(0, 0, 0, obs_d, 0.75, 10);
    % shape(:, 2) = 1.3*shape(:, 2);
    
    shape = make_boundary(shape);
    rgb_color = rand(1, 3);
end
if nargin == 4
    rgb_color = rand(1, 3);
end

obs.n = obs.n + 1;
n     = obs.n;
obs.obs{n}.pos   = pos;  
obs.obs{n}.shape = shape; 
obs.obs{n}.vel   = u;     
obs.obs{n}.color = rgb_color;
obs.obs{n}.sec   = 0;


function boundary = make_boundary(corners)
boundary = [corners ; corners(1, :)];
function obs4grid = init_obs4grid(g, n, rrange, vrange)

obs4grid.n = n;
obs4grid.obs = cell(n, 1);
for i = 1:n
    obs4grid.obs{i}.r   = rrange(1) + (rrange(2)-rrange(1))*rand; % [mm]
    obs4grid.obs{i}.pos = [g.xmin g.ymin 0] + [g.xlen g.ylen 360]*rand;
    obs4grid.obs{i}.vel = [vrange(1)+(vrange(2)-vrange(1))*rand 50*rand];
end


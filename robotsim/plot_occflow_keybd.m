function plot_occflow_keybd(p)
global SIM_MODE

clf;
axes('Parent', p.fig, 'Position', [0.08 0.08 0.87 0.87]); hold on;
plot_gridmap(p.robot, p.gridmap, p.l2);
plot_obs(p.obs);
plot_robot(p.robot);
center = [19000 9000]; radius = 1000; title_bias = 200;
plot_colorcode(p.img, p.robot, center, radius, title_bias);

quiver(p.xmesh, p.ymesh, p.ru, p.rv, 'Color', 'k', 'LineWidth', 1, 'AutoScale', 'off');

if p.sim.flag == 0
    title(sprintf('TERMINATED %s', p.title_str), 'fontSize', 16, 'color', 'r');
elseif p.run_mode == SIM_MODE
    title(sprintf('%s', p.title_str), 'fontSize', 16, 'color', 'b');
else
    title(sprintf('PAUSED %s', p.title_str), 'fontSize', 16, 'color', 'r'); 
end;
grid on; box on; axis equal; axis([0 2E4 0 1E4]); xlabel('X [mm]'); ylabel('Y [mm]');
ax = gca; ax.XTick = linspace(0, 2E4, 20+1); ax.YTick = linspace(0, 1E4, 10+1);
drawnow;

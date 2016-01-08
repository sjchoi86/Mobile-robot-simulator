function plot_obs4grid(obs4grid)

colors = lines(obs4grid.n);
for j = 1:obs4grid.n
    pos = obs4grid.obs{j}.pos;
    r   = obs4grid.obs{j}.r;
    vel = obs4grid.obs{j}.vel;
    
    circlebd = get_circle(pos(1), pos(2), r, 20);
    
    if 0
        plot(circlebd(:, 1), circlebd(:, 2), '-' ...
            , 'LineWidth', 3, 'Color', colors(j, :) );
    end
    h = fill(circlebd(:, 1), circlebd(:, 2), colors(j, :));
    set(h,'facealpha', 0.1);
    
    plot_arrow(pos(1:2), r, pos(3), colors(j, :), 2);
    
    if 0
        text(pos(1) + 2*r, pos(2) + r ...
            , sprintf('%.1fm/s', vel(1)/1000) ...
            , 'BackgroundColor', 'w', 'EdgeColor', 'b');
    end
end


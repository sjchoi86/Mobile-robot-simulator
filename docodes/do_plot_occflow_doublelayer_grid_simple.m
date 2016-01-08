
if exist('fig') == 0
    fig = figure(4); set(fig, 'position', [200 100 1000 1000]); colormap gray;
end
xm = 0.01; ym = 0.04;
set(fig, 'visible','off', 'Name', 'Hierchical Occupancy Flow', 'NumberTitle', 'Off'); clf;

title_fontSize = 15;

% Figure 1 - Original
subaxes(fig, 2, 2, 1, xm, ym); hold on;
imagesc(g1.xs, g1.ys, obs_grid); plot_obs4grid(obs4grid);
caxis([0 1]); axis equal off; axis(g1.axis); 
title(sprintf('Reference Grids %d', i), 'FontSize', title_fontSize);

% Figure 2 - Noisy
subaxes(fig, 2, 2, 2, xm, ym); hold on;
imagesc(g1.xs, g1.ys, reshape(l1.curr_input, g1.ny, g1.nx));
caxis([0 1]); axis equal off; axis(g1.axis); 
title(sprintf('Noisy Grids (Actual Input) %d', i), 'FontSize', title_fontSize);

% Figure 3 - L1 Color-coded 
subaxes(fig, 2, 2, 3, xm, ym); hold on;
image(g1.xs, g1.ys, l1.rgbflowimg);
plot_obs4grid(obs4grid);
caxis([0 1]); axis equal off; axis(g1.axis); 
title(sprintf('Color-coded Prediction in the 1st Layer %d', i), 'FontSize', title_fontSize);


% Figure 4 - Color-coded flow from 2nd Layer
subaxes(fig, 2, 2, 4, xm, ym); hold on;
image(g1.xs, g1.ys, l2.rgbflowimg_resize);
plot_obs4grid(obs4grid);
axis equal off; axis(g1.axis); caxis([0 1]); 
title(sprintf('Color-coded Prediction in the 2nd Layer %d', i), 'FontSize', title_fontSize);

% Color codes
axes('Parent', fig, 'Position', [0.88, 0.345, 0.1, 0.1] );
imshow(img_colorcode); title('Color-code', 'FontSize', 8);

% Draw now
set(fig, 'visible','on'); drawnow;



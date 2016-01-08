
fig = figure(4); set(fig, 'position', [200 300 1500 800]); colormap gray;

xm = 0.00; ym = 0.06;
set(fig, 'visible','off'); clf;

% Figure 1 - Current Input
subaxes(fig, 2, 3, 1, xm, ym); hold on;
imagesc(g1.xs, g1.ys, reshape(l1.curr_input, g1.ny, g1.nx));
% plot_obs4grid(obs4grid);
caxis([0 1]); axis equal off; axis(g1.axis); title(sprintf('Noisy Input %d', i));

% Figure 2 - Prediction in 1st Layer
subaxes(fig, 2, 3, 2, xm, ym); hold on;
imagesc(g1.xs, g1.ys, reshape(l1.predvec, g1.ny, g1.nx));
plot_obs4grid(obs4grid);
caxis([0 1]); axis equal off; axis(g1.axis); title(sprintf('Prediction in the 1st Layer %d', i));

% Figure 3 - L1 Color-coded 
subaxes(fig, 2, 3, 3, xm, ym); hold on;
image(g1.xs, g1.ys, l1.rgbflowimg);
plot_obs4grid(obs4grid);
caxis([0 1]); axis equal off; axis(g1.axis); title(sprintf('Color-coded Prediction in the 1st Layer %d', i));
axes('Parent', fig, 'Position', [0.87, 0.83, 0.1, 0.1] );
imshow(img_colorcode); title('Color-code', 'FontSize', 8);

% Figure 4 - Input to 2nd Layer
subaxes(fig, 2, 3, 4, xm, ym); hold on;
imagesc(g1.xs, g1.ys, l1.binsmallmtx); axis equal off; axis(g1.axis); caxis([0 1]); 
plot_obs4grid(obs4grid);
title(sprintf('Input to the 2nd Layer %d', i));

% Figure 5 - Prediction in 2nd Layer
subaxes(fig, 2, 3, 5, xm, ym); hold on;
imagesc(g2.xs, g2.ys, reshape(l2.predvec, g2.ny, g2.nx));
plot_obs4grid(obs4grid); axis equal off; axis(g1.axis); caxis([0 1]); 
title(sprintf('Prediction in the 2nd Layer %d', i));

% Figure 6 - Color-coded flow from 2nd Layer
subaxes(fig, 2, 3, 6, xm, ym); hold on;
image(g1.xs, g1.ys, l2.rgbflowimg_resize);
plot_obs4grid(obs4grid);
axis equal off; axis(g1.axis); caxis([0 1]); 
title(sprintf('Color-coded Prediction in the 2nd Layer %d', i));

% Draw now
set(fig, 'visible','on'); drawnow;
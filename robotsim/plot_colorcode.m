function [ccode_xmesh, ccode_ymesh, img_flip] = plot_colorcode(img, robot, ccode_center, ccode_radius, ccode_title_bias)

ccode_center_temp = ccode_center - [0 2*ccode_title_bias];
ccode_rad   = ccode_radius;
img_res     = imresize(img, [100 100]);
img_flip    = flipud(img_res);
[h, w]      = size(img_flip);
[xtemp, ytemp] = meshgrid(linspace(-ccode_rad, ccode_rad, w), linspace(-ccode_rad, ccode_rad, h));
xvec        = xtemp(:); 
yvec        = ytemp(:); 
xyvec       = [xvec yvec];
deg         = robot.pos(3); c = cos(deg*pi/180); s = sin(deg*pi/180);
rotmat      = [c s ; -s c]; 
xyvec       = xyvec * rotmat + repmat(ccode_center_temp, w*h, 1);
xvec        = xyvec(:, 1); 
yvec        = xyvec(:, 2);
ccode_xmesh  = reshape(xvec, h, w); 
ccode_ymesh  = reshape(yvec, h, w);
surface('xdata', ccode_xmesh, 'ydata', ccode_ymesh, 'zdata', zeros(h, w) ...
    , 'cdata', img_flip, 'facecolor', 'texturemap', 'edgecolor', 'none');
text(ccode_center_temp(1), ccode_center_temp(2)+ccode_rad+ccode_title_bias ...
    , sprintf('Egocentric\nColor-code'), 'FontSize', 13, 'HorizontalAlignment', 'Center');


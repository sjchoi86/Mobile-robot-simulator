function plot_gridmap(robot, gridmap, l2, use_occflow, colorcoded_occflow)

if nargin == 3
    use_occflow = 1;
    colorcoded_occflow = 1; 
end

nx = gridmap.xres; ny = gridmap.yres;
[xtemp, ytemp] = meshgrid(linspace(gridmap.xmin, gridmap.xmax, nx) ...
    , linspace(gridmap.ymin, gridmap.ymax, ny));
xvec = xtemp(:); yvec = ytemp(:); xyvec = [xvec yvec];
deg = robot.pos(3); c = cos(deg*pi/180); s = sin(deg*pi/180);
rotmat = [c s ; -s c];
xyvec = xyvec * rotmat + repmat(robot.pos(1:2), nx*ny, 1);
xvec = xyvec(:, 1); yvec = xyvec(:, 2);
xtemp = reshape(xvec, ny, nx); ytemp = reshape(yvec, ny, nx);
gridmtx     = gridmap.map;

if use_occflow
    if colorcoded_occflow
        surface('xdata', xtemp, 'ydata', ytemp, 'zdata', zeros(ny, nx) ...
            , 'cdata', l2.rgbflowimg_resize ...
            ,'facecolor', 'texturemap', 'edgecolor', 0.5*[1 1 1]);
    else
        predmtx     = reshape(l2.predvec, size(l2.binpredmtx, 1), size(l2.binpredmtx, 2));
        predmtx_res = imresize(predmtx, 1/l2.resize_rate, 'bilinear');
        
        occpredmtx  = max(predmtx_res, gridmtx);
        surface('xdata', xtemp, 'ydata', ytemp, 'zdata', zeros(ny, nx) ...
            , 'cdata', occpredmtx, 'facecolor', 'texturemap', 'edgecolor', 'k');
    end
else
    surface('xdata', xtemp, 'ydata', ytemp, 'zdata', zeros(ny, nx) ...
        , 'cdata', gridmtx ...
        ,'facecolor', 'texturemap', 'edgecolor', 0.5*[1 1 1]);
end
colormap gray; caxis([0 1]);
alpha(.9);


    
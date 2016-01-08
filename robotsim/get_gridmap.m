function gridmap = get_gridmap(res_xy, valid_idx, margin_level, ginfo)
%
%
OCCUPIED = 1;
UNKOWN   = 0.1;
FREE     = 0;


nr_data  = size(res_xy, 1);
grid_len = ginfo.nx;
xmin     = ginfo.xmin;
xmax     = ginfo.xmax;
ymin     = ginfo.ymin;
ymax     = ginfo.ymax;

% nr_x     = round((xmax-xmin)/ginfo.nx);
% nr_y     = round((ymax-ymin)/ginfo.ny);
nr_x     = ginfo.nx;
nr_y     = ginfo.ny;
gridmap  = init_grid_stage([xmin xmax ymin ymax], [nr_x nr_y]);
gridmap.data = res_xy;

% Occupancy grid map
gridmap.map = UNKOWN*ones(nr_y, nr_x);

for i = 1:nr_data
    curr_xy = res_xy(i, :);
    len     = norm(curr_xy);
    nr_grid = ceil(len/grid_len);
    for j = 1:nr_grid
        curr_pos = curr_xy*j/nr_grid;
        x_idx = round(nr_x*(curr_pos(1) - xmin)/(xmax-xmin));
        y_idx = round(nr_y*(curr_pos(2) - ymin)/(ymax-ymin));
        if x_idx < 1, continue; end 
        if x_idx > nr_x, continue; end
        if y_idx < 1, continue; end
        if y_idx > nr_y, continue; end
        gridmap.map(y_idx, x_idx) = FREE;
    end
end 

% Occupancy 
for i = 1:nr_data
    if valid_idx(i) == 0
        continue;
    end
    curr_xy = res_xy(i, :);
    
    x_idx = round(nr_x*(curr_xy(1) - xmin)/(xmax-xmin));
	y_idx = round(nr_y*(curr_xy(2) - ymin)/(ymax-ymin));
    if x_idx < 1, continue; end 
    if x_idx > nr_x, continue; end 
    if y_idx < 1, continue; end
    if y_idx > nr_y, continue; end
    gridmap.map(y_idx, x_idx) = OCCUPIED;
    
end

if 1
    h     = fspecial('gaussian', [3 3], 3);
    temp  = imfilter(gridmap.map, h);
    noccidx        = find(temp < 0.2);
    occidx         = find(temp > 0.2);
    temp(noccidx)  = 0;
    temp(occidx)   = 1;
    gridmap.map    = temp;
end

gridmap.OCCUPIED = OCCUPIED;
gridmap.UNKOWN   = UNKOWN;
gridmap.FREE     = FREE;


function gridmap = init_grid_stage(axis_info, res_info)
%
gridmap.xmin = axis_info(1);
gridmap.xmax = axis_info(2);
gridmap.ymin = axis_info(3);
gridmap.ymax = axis_info(4);
 
gridmap.xres = res_info(1);
gridmap.yres = res_info(2);
gridmap.xgrid = linspace(gridmap.xmin, gridmap.xmax, gridmap.xres);
gridmap.ygrid = linspace(gridmap.ymin, gridmap.ymax, gridmap.yres);
[mesh_X, mesh_Y] = meshgrid(gridmap.xgrid, gridmap.ygrid); 
 
% (x, y) points in column direction 
gridmap.points = [mesh_X(:) mesh_Y(:)]; 
gridmap.nr_points = length(gridmap.points);


function plot_handle = plot_robot(robot, show_text)

if ~isfield(robot, 'color')
    % ?????? ???? ??????.
    robot.color = [0.1 0.9 0.05];
end

if nargin == 1
    show_text = 0;
end

rx = robot.pos(1);
ry = robot.pos(2);
rdeg = robot.pos(3);
radius = robot.r;


% RFS
rfs_edge_color = [0.7 0.2 0.3];
rfs_end_points = zeros(robot.nr_rfs, 2);
for i = 1:robot.nr_rfs
    rfs_deg = robot.pos(3) + robot.rfs_degs(i);
    rfs_rad = rfs_deg * pi / 180;
    rfs_fr = robot.pos(1:2) ...
        + robot.r*[cos(rfs_rad) sin(rfs_rad)];
    rfs_to = robot.pos(1:2) ...
        + (robot.r+robot.rfs_result(i))*[cos(rfs_rad) sin(rfs_rad)];
    if show_text
        text( rfs_to(1), rfs_to(2), sprintf(' [%d]', i) );
    end
    rfs_end_points(i, 1) = rfs_to(1);
    rfs_end_points(i, 2) = rfs_to(2);
end
rfs_end_points = [robot.pos(1:2) ; rfs_end_points ; robot.pos(1:2)];
hfill = fill(rfs_end_points(:, 1), rfs_end_points(:, 2), 0.7*[1 1 1]);
set(hfill, 'facealpha', 0.2);
plot(rfs_end_points(:, 1), rfs_end_points(:, 2), '-' ...
    , 'Color', rfs_edge_color, 'MarkerSize', 11 ...
    , 'LineWidth', 2);

% Future roobt positions
v = robot.vel(1);
w = robot.vel(2);
T = 0.6;
curr_pos = robot.pos;
for i = 1:5
    x = curr_pos(1);
    y = curr_pos(2);
    d = curr_pos(3);
    c = cos(d*pi/180);
    s = sin(d*pi/180);
    
    x = x + v*c*T;
    y = y + v*s*T;
    d = d + w*T;
    robotBoundary = get_circle(x, y, radius, 20);
    plot( robotBoundary(:,1), robotBoundary(:,2) ...
        , 'Color', [.2 1 .2], 'LineWidth', 1 );
    draw_arrow([x y], radius, d, [.2 1 .2]);

    curr_pos = [x y d];
end

% Robot boundary 
robotBoundary = get_circle(rx, ry, radius, 20);
plot_handle = fill( robotBoundary(:,1), robotBoundary(:,2) ...
    , robot.color, 'LineWidth', 1 );
plot( robotBoundary(:,1), robotBoundary(:,2) ...
    , 'Color', 'k', 'LineWidth', 1 );

% Heading 
draw_arrow(robot.pos, radius, rdeg);



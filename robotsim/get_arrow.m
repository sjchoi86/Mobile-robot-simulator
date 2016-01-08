function h = get_arrow(fr, dist, deg, color, thick)

if nargin == 3
    color = 'k';
    thick = 2;
end
if nargin == 4
    thick = 2;
end

arrow_rate = 1/3;

rad  = deg * pi / 180;
fr_x = fr(1);
fr_y = fr(2);
to_x = fr_x + dist*cos(rad);
to_y = fr_y + dist*sin(rad);

c_x = fr_x + (1-arrow_rate)*dist*cos(rad);
c_y = fr_y + (1-arrow_rate)*dist*sin(rad);

l_x = c_x + arrow_rate*dist*cos(rad+pi/2);
l_y = c_y + arrow_rate*dist*sin(rad+pi/2);
r_x = c_x + arrow_rate*dist*cos(rad-pi/2);
r_y = c_y + arrow_rate*dist*sin(rad-pi/2);


h = cell(3, 1);
h{1}.XData = [fr_x to_x];
h{1}.YData = [fr_y to_y];
h{2}.XData = [l_x to_x];
h{2}.YData = [l_y to_y];
h{3}.XData = [r_x to_x];
h{3}.YData = [r_y to_y];

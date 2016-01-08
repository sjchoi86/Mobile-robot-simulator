function subaxes(figHandler, h, w, index, mx, my)
% subplot과 같지만, margin을 내가 조절할 수 있다는 장점이 있다. 
% 
% figHandler : Figure handler
% h          : 전체 subfigure의 height
% w          : 전체 subfigure의 width
% index      : subfigure의 inded
% (margin)   : margin
% 
if nargin == 4
    mx = 0.1;
    my = 0.1;
end

w_idx = rem(index, w);
if w_idx == 0, w_idx = w; end;
w_idx = w_idx - 1;
h_idx = ceil(index/w) - 1;
h_idx = h - h_idx - 1;

w_unit = 1/w;
h_unit = 1/h;

x_start = w_unit*(w_idx) + mx/2;
y_start = h_unit*(h_idx) + my/2 - 0.02;
x_len = w_unit-mx;
y_len = h_unit-my;

axes('Parent', figHandler ...
    , 'Position' ...
    , [x_start, y_start, x_len, y_len] );    


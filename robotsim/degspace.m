function degs = degspace(d1, d2, nr)
% 
% degspace(10, 60, 5)
% ans =
%    10.0000
%    22.5000
%    35.0000
%    47.5000
%    60.0000
% 
degs = zeros(nr, 1);
res  = (d2-d1)/(nr-1);
for i = 1:nr
    curdeg = d1 + res*(i-1);
    if curdeg < 0
        curdeg = curdeg + 360;
    end
    if curdeg > 360
        curdeg = curdeg - 360;
    end
    degs(i) = curdeg;
end

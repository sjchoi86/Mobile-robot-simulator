function colors = val2color(costs, flipcolors)
%
% if flipcolors == 1 (default)
% 0 -> red
% 1 -> blue
%
if nargin == 1
    flipcolors = 1; 
end


n = size(costs, 1);
if length(unique(costs)) == 1
    colors = repmat(0.5*[1 1 1], n, 1);
    return;
end


% normalize
minc  = min(costs);
maxc  = max(costs);
costs = (costs - minc)/(maxc - minc);

if flipcolors
    jetcolors = flipud(jet(120));
else
    jetcolors = (jet(120));
end
colors    = zeros(n, 3);

for i = 1:n 
    cost = costs(i);
    color_idx = 10+ceil(cost*100);
    if color_idx == 0, color_idx = 1; end;
    colors(i, :) = jetcolors(color_idx, :);
end
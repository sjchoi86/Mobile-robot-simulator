function d=sqdist(a_temp, b_temp)
% SQDIST - computes squared Euclidean distance matrix
%          computes a rectangular matrix of pairwise distances
% between points in A (given in rows) and points in B

% NB: very fast implementation taken from Roland Bunschoten
a = a_temp';
b = b_temp';

aa = sum(a.*a,1); bb = sum(b.*b,1); ab = a'*b; 
d = abs(repmat(aa',[1 size(bb,2)]) + repmat(bb,[size(aa,2) 1]) - 2*ab);

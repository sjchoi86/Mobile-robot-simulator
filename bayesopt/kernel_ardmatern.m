function K = kernel_ardmatern(X1, X2, bo, factor)

if nargin == 3
    factor = 0.5;
end

nr_X1 = size(X1, 1);
nr_X2 = size(X2, 1);
% First, normalize inputs 
norm_factors = zeros(1, bo.d);
for i = 1:bo.d
    if length(bo.data{i}.range) == 1
        norm_factors(i) = bo.data{i}.range(1)*factor;
    else
        norm_factors(i) = (bo.data{i}.range(end) - bo.data{i}.range(1))*factor;
    end
end
norm_X1 = X1 ./ repmat(norm_factors, nr_X1, 1);
norm_X2 = X2 ./ repmat(norm_factors, nr_X2, 1);
% Compute Squared distances
rsq = sqdist(norm_X1, norm_X2);
% Compute Kernels
K = (1 + sqrt(5*rsq) + 5/3*rsq).*exp(-sqrt(5*rsq));


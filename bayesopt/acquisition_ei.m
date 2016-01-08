function val = acquisition_ei(x, bo, factor)
%
% Acquisition function for Bayesian Optimization
%  Expected Improvement Criteria
%
if nargin == 2
    factor = 1;
end

n = bo.n;
X = bo.input(1:bo.n, :);
Y = bo.output(1:bo.n, :);
xstar   = x;
KX      = kernel_ardmatern(X, X, bo, factor);
Kxstar  = kernel_ardmatern(xstar, xstar, bo, factor);
KXxstar = kernel_ardmatern(X, xstar, bo, factor);
gpvar   = Kxstar - KXxstar'/(KX + 1E-6*eye(n, n))*KXxstar;
gpvar   = abs(gpvar);
gpmean  = KXxstar'/(KX + 1E-6*eye(n, n))*Y;
fmin    = min(Y);
gamma   = (fmin - gpmean)/sqrt(gpvar);
Phi     = cdf('Normal', gamma, 0, 1);
val     = sqrt(gpvar) * gamma * Phi + pdf('Normal', gamma, 0, 1);
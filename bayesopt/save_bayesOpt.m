function bo = save_bayesOpt(bo, vec, fval)

bo.n = bo.n + 1;
bo.input(bo.n, :)  = vec;
bo.output(bo.n, :) = fval;

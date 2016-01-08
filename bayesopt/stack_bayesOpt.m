function vec = stack_bayesOpt(bo)

vec = zeros(1, bo.d);
for i = 1:bo.d
    vec(i) = bo.data{i}.val;
end


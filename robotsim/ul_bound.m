function ret = ul_bound(vel, ub, lb)
% upper-lower bound 
if vel > ub
    ret = ub;
elseif vel < lb
    ret = lb;
else
    ret = vel;
end

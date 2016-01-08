function ref_cart_pos_list = get_ref_cart_pos(ref_pos, rel_cart_pos )
%
% Get Reference Cartesian Position from Relative Cartiesian Position  
%
ref_x    = ref_pos(1);
ref_y    = ref_pos(2);
ref_deg  = ref_pos(3);

nr_polar_pos = size(rel_cart_pos, 1);
ref_cart_pos_list = zeros(nr_polar_pos, 2);
for i = 1:nr_polar_pos
    curr_rel_x = rel_cart_pos(i, 1);
    curr_rel_y = rel_cart_pos(i, 2);
    curr_rel_r = norm([curr_rel_x curr_rel_y]);
    curr_rel_deg = atan2(curr_rel_y, curr_rel_x)*180/pi;
    
    % cartesian pos
    curr_cart_x = ref_x ...
        + curr_rel_r*cos(pi/180*(ref_deg+curr_rel_deg));
    curr_cart_y = ref_y ...
        + curr_rel_r*sin(pi/180*(ref_deg+curr_rel_deg));
    
    % ref cart pos
    curr_cart_pos = [curr_cart_x curr_cart_y];
    ref_cart_pos_list(i, :) = curr_cart_pos;
end 


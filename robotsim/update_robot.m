function robot = update_robot(robot, sim)
% Update robot position

vel   = robot.vel(1);
w_deg = robot.vel(2);
rad   = robot.pos(3)*pi/180;

v_max = robot.max_vel(1);
w_max = robot.max_vel(2);
vel   = ul_bound(vel, v_max, -v_max);
w_deg = ul_bound(w_deg, w_max, -w_max);

robot.vel(1) = vel;
robot.vel(2) = w_deg;

d_x   = vel*cos(rad)*sim.T;
d_y   = vel*sin(rad)*sim.T;
d_deg = w_deg*sim.T;

robot.pos = robot.pos + [d_x d_y d_deg];
robot.str = sprintf('v: %.1f [mm/s] w: %.1f [deg/s]', vel, w_deg);
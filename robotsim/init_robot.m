function robot = init_robot(pos, vel, nr_rfs)

if nargin == 0
    pos = [0 0 0];
    vel = [0 0];
    nr_rfs = 300;
elseif nargin == 2
    nr_rfs = 300;
end

robot.r   = 250;
robot.pos = pos;
robot.vel = vel;
robot.max_vel = [900 80];

% Range Finder Sensor
robot.rfs_dist = 6000; 
robot.rfs_deg  = 270;
robot.nr_rfs   = nr_rfs;
robot.rfs_degs = degspace(-robot.rfs_deg/2, robot.rfs_deg/2, robot.nr_rfs );
robot.rfs_result = robot.rfs_dist*ones(robot.nr_rfs, 1); 


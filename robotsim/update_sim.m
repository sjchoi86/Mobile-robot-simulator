function sim = update_sim(sim)

% tick
sim.tick = sim.tick + 1;

% sec 
sim.sec = sim.tick * sim.T;

if sim.sec > sim.max_sec
    sim.flag = 0;
end

sim.str = sprintf('%.1f sec', sim.sec);

function [xpaths, ypaths, dpaths, vlist, wlist] = get_randompaths(npath, T, horizon_sec)
%
% Generate random paths
%
% Example code
% % sample
% npath = 100;
% horizon_sec = 5;
% [xpaths, ypaths, dpaths, vlist, wlist] = get_randompaths(npath, sim.T, horizon_sec);
% % plot
% figure(1); hold on;
% plot(xpaths', ypaths', '-', 'LineWidth', 2);
% axis equal; grid on;
%
len    = horizon_sec / T;
xpaths = zeros(npath, len);
ypaths = zeros(npath, len);
dpaths = zeros(npath, len);
vlist  = zeros(npath, len);
wlist  = zeros(npath, len);

for i = 1:npath
    % for each path
    if i == 1
        vrand1 = 1000;
        vrand2 = 1000;
        wrand1 = 0;
        wrand2 = 0;
    elseif i == 2
        vrand1 = 500;
        vrand2 = 500;
        wrand1 = 0;
        wrand2 = 0;
    elseif i == 3
        vrand1 = 200;
        vrand2 = 200;
        wrand1 = 0;
        wrand2 = 0;
    else
        vrand1 = -1000 + 2000*rand;
        wrand1 = -50 + 100*rand;
        vrand2 = -1000 + 2000*rand;
        wrand2 = -50 + 100*rand;
    end
    
    pos    = [0 0 0];
    vrand = vrand1;
    wrand = wrand1;
    for j = 1:len
        if j == round(len/2)
            vrand = vrand2;
            wrand = wrand2;
        end
        
        % Heuristics for not going back too much
        curr_sec = j*T;
        if curr_sec >= 2 && vrand1 < 0
            vrand = 0;
        end
        
        xpaths(i, j) = pos(1);
        ypaths(i, j) = pos(2);
        dpaths(i, j) = pos(3);
        vlist(i, j)  = vrand;
        wlist(i, j)  = wrand;
        pos          = update_pos(pos, vrand, wrand, T);
    end
end

% Update position
function pos = update_pos(pos, v, w, T)
c = cos(pos(3)*pi/180);
s = sin(pos(3)*pi/180);
pos(1) = pos(1) + v*T*c;
pos(2) = pos(2) + v*T*s;
pos(3) = pos(3) + w*T;

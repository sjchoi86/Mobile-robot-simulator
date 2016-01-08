%%
%
% Bayesian optimization을 구현해보자.
%
ccc

%% Bayesian Optimization on simple 2D example
ccc
rng(2);

do_bayeopt = 1; % <== Bayesian Optimization을 할지 여부! 

g = set_grid(-5, 5, 100, -5, 5, 100);
% 이함수는 scalabale kernel method via DSG 논문에서 사용한 synthetic function이다.
f = @(x)(sqrt(0.0001)*randn(size(x, 1), 1) + cos(0.5*pi*sqrt(x(:, 1).*x(:, 1)+x(:, 2).*x(:, 2))).*exp(-0.1*pi*sqrt(x(:, 1).*x(:, 1)+x(:, 2).*x(:, 2))));
Z = f(g.xy);

% plot original field
if 1
    figure(1); clf;
    plot3(g.xy(:, 1), g.xy(:, 2), Z, '.');
    grid on;
    xlabel('X'); ylabel('Y'); zlabel('Z');
    view(71, 21);
end

% 초기화 한다. (범위는 0에서 10 사이이다.)
bo = init_bayesOpt4toy2D();

% 처음에 10개의 랜덤 샘플링을 해서 몇 개의 값을 구한다.
for i = 1:20
    % Random Sampling
    bo = sample_bayesOpt(bo);
    % 벡터꼴로 바꾼다.
    vec = stack_bayesOpt(bo);
    % Evaluation을 한다.
    fval = f(vec);
    % 벡터들을 bo.save_data에 모은다.
    bo = save_bayesOpt(bo, vec, -fval);
end

% 이제 데이터가 좀 모였으니 Bayesian Optimization을 해보자.
fig = figure(2); set(fig, 'Position', [300 300 1300 600]);
maxiter = 100; 
for iter = 1:maxiter
    % max_sample 만큼 뽑아보고, acquisition이 제일 큰 걸 골라서 그걸 추가한다.
    max_sample = 50;
    acq_vals = zeros(max_sample, 1);
    vecs = zeros(max_sample, bo.d);
    for i = 1:max_sample
        % random sampling
        bo = sample_bayesOpt(bo);
        vec = stack_bayesOpt(bo);
        acquisition_val = acquisition_ei(vec, bo);
        vecs(i, :)  = vec;
        acq_vals(i) = acquisition_val;
    end
    
    if do_bayeopt
        [~, maxidx] = max(acq_vals);
    else
        % Bayesian optimization을 하지 않을 땐, 처음 sample된 것을 쓴다. 
        maxidx = 1;
    end
    selected_vec = vecs(maxidx, :);
    
    % selected_vec에서 evaluation을 하고 추가한다.
    fval = f(selected_vec); % <== Evaluation!! 
    bo   = save_bayesOpt(bo, selected_vec, -fval);
    
    % 그려본다
    if 1
        figure(2); clf; 
        subaxes(fig, 1, 2, 1);
        hold on;
        plot3(g.xy(:, 1), g.xy(:, 2), Z, '.', 'Color', [0.4 0.4 0.4]);
        plot3(bo.input(1:bo.n, 1), bo.input(1:bo.n, 2), -bo.output(1:bo.n), 'bo', 'MarkerSize', 10, 'LineWidth', 2);
        plot3(selected_vec(1), selected_vec(2), fval, 'ro', 'MarkerSize', 12, 'LineWidth', 2);
        grid on; 
        xlabel('X'); ylabel('Y'); zlabel('Z'); 
        if do_bayeopt
            title(sprintf('%d/%d Bayesian Optimization with Expected Improvement', iter, maxiter));
        else
            title(sprintf('%d/%d Random Sampling', iter, maxiter));
        end
        view(75, 11); 
        subaxes(fig, 1, 2, 2);
        hold on;
        plot3(g.xy(:, 1), g.xy(:, 2), Z, '.', 'Color', [0.4 0.4 0.4]);
        plot3(bo.input(1:bo.n, 1), bo.input(1:bo.n, 2), -bo.output(1:bo.n), 'bo', 'MarkerSize', 10, 'LineWidth', 2);
        plot3(selected_vec(1), selected_vec(2), fval, 'ro', 'MarkerSize', 12, 'LineWidth', 2);
        grid on; axis equal;
        xlabel('X'); ylabel('Y'); zlabel('Z'); % title(sprintf('%d/%d', iter, maxiter));
        view(90, 90); 
        drawnow;
    end
end

%%



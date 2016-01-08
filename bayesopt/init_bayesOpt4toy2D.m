function bo = init_bayesOpt4toy2D()

bo.n = 0;
bo.d = 2;
bo.input  = zeros(10000, bo.d); 
bo.output = zeros(10000, 1); 

bo.data{1}.type  = 'continuous';
bo.data{1}.range = [-5 5];

bo.data{2}.type  = 'discrete';
bo.data{2}.range = linspace(-5, 5, 100);

bo.n = 0;
function bo = init_bayesOpt4occflow()

bo.n = 0;
bo.d = 27;
bo.input  = zeros(10000, bo.d); 
bo.output = zeros(10000, 1); 

%                                   Layer 1
% neixy -> neixres, neiyres
bo.data{1}.type  = 'discrete';
bo.data{1}.range = [3 5];

% neisig
bo.data{2}.type  = 'continuous';
bo.data{2}.range = [1 5];

% nei4uxy -> nei4uxres, nei4uyres
bo.data{3}.type  = 'discrete';
bo.data{3}.range = [3];

% nei4usig
bo.data{4}.type  = 'continuous';
bo.data{4}.range = [1 5];

% minthreshold
bo.data{5}.type  = 'continuous';
bo.data{5}.range = [0 1];

% maxthreshold
bo.data{6}.type  = 'continuous';
bo.data{6}.range = [5 30];

% reinitval
bo.data{7}.type  = 'continuous';
bo.data{7}.range = [0 4];

% intensifyrate
bo.data{8}.type  = 'continuous';
bo.data{8}.range = [1 10];

% nocc_attenuaterate
bo.data{9}.type  = 'continuous';
bo.data{9}.range = [0 1];

% unknown_attenuaterate
bo.data{10}.type  = 'continuous';
bo.data{10}.range = [0 1];

% sigm_coef
bo.data{11}.type  = 'continuous';
bo.data{11}.range = [0 2];

% pred_threshold
bo.data{12}.type  = 'continuous';
bo.data{12}.range = [0 1];

% bin_threshold
bo.data{13}.type  = 'continuous';
bo.data{13}.range = [0 1];

%                                   Layer 2
% neixy -> neixres, neiyres
bo.data{14}.type  = 'discrete';
bo.data{14}.range = [3 5 7];

% neisig
bo.data{15}.type  = 'continuous';
bo.data{15}.range = [1 5];

% nei4uxy -> nei4uxres, nei4uyres
bo.data{16}.type  = 'discrete';
bo.data{16}.range = [3];

% nei4usig
bo.data{17}.type  = 'continuous';
bo.data{17}.range = [1 5];

% minthreshold
bo.data{18}.type  = 'continuous';
bo.data{18}.range = [0 1];

% maxthreshold
bo.data{19}.type  = 'continuous';
bo.data{19}.range = [5 30];

% reinitval
bo.data{20}.type  = 'continuous';
bo.data{20}.range = [0 2];

% intensifyrate
bo.data{21}.type  = 'continuous';
bo.data{21}.range = [1 15];

% nocc_attenuaterate
bo.data{22}.type  = 'continuous';
bo.data{22}.range = [0 1];

% unknown_attenuaterate
bo.data{23}.type  = 'continuous';
bo.data{23}.range = [0 1];

% sigm_coef
bo.data{24}.type  = 'continuous';
bo.data{24}.range = [0 2];

% pred_threshold
bo.data{25}.type  = 'continuous';
bo.data{25}.range = [0 1];

% bin_threshold
bo.data{26}.type  = 'continuous';
bo.data{26}.range = [0 1];

% resize_rate (layer1 -> layer2)
bo.data{27}.type  = 'discrete';
bo.data{27}.range = (5:9)/10;


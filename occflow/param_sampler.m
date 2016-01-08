function params = param_sampler(mode)

if nargin == 0
    neixy               = 1+2*randi([1 3]); % 3, 5, 7 중 하나
    params.neixres      = neixy;
    params.neiyres      = neixy;
    params.neisig       = 1 + 4*rand; % 1~5
    
    params.nei4uxy      = 2*randi([1 3])-1; % 1, 3, 5 중 하나
    params.nei4uxres    = 3;
    params.nei4uyres    = 3;
    params.nei4usig     = 2;
    
    params.minthreshold = 0.1 + 0.9*rand;
    params.maxthreshold = 5 + 25*rand;
    
    params.reinitval             = 0.1 + 4*rand;
    params.intensifyrate         = 1 + 10*rand;
    params.nocc_attenuaterate    = rand;
    params.unknown_attenuaterate = rand;
    
    params.sigm_coef             = 2*rand;
    params.pred_threshold        = rand;
    params.bin_threshold         = rand;
    
    params.occval  = 1;
    params.noccval = 0;
else
    switch mode
        case 1
            neixy               = 5;
            params.neixres      = neixy;
            params.neiyres      = neixy;
            params.neisig       = 2;
            
            params.nei4uxy      = 3;
            params.nei4uxres    = 3;
            params.nei4uyres    = 3;
            params.nei4usig     = 2;
            
            params.minthreshold = 0.5;
            params.maxthreshold = 20;
            
            params.reinitval             = 2;
            params.intensifyrate         = 7;
            params.nocc_attenuaterate    = 0.14;
            params.unknown_attenuaterate = 0.3;
            
            params.sigm_coef             = 0.5;
            params.pred_threshold        = 0.3;
            params.bin_threshold         = 0.5;
            
            params.occval  = 1;
            params.noccval = 0;
        case 2
            neixy               = 5;
            params.neixres      = neixy;
            params.neiyres      = neixy;
            params.neisig       = 2;
            
            params.nei4uxy      = 3;
            params.nei4uxres    = 3;
            params.nei4uyres    = 3;
            params.nei4usig     = 2;
            
            params.minthreshold = 0.5;
            params.maxthreshold = 20;
            
            params.reinitval             = 2;
            params.intensifyrate         = 7;
            params.nocc_attenuaterate    = 0.14;
            params.unknown_attenuaterate = 0.3;
            
            params.sigm_coef             = 0.2;
            params.pred_threshold        = 0.3;
            params.bin_threshold         = 0.5;
            
            params.occval  = 1;
            params.noccval = 0;            
    end
end


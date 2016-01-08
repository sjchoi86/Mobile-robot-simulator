function bo = sample_bayesOpt(bo)

for i = 1:bo.d
    data_type  = bo.data{i}.type;
    data_range = bo.data{i}.range;
    switch data_type
        case 'discrete'
            nr_range = length(data_range);
            randidx = randi([1 nr_range]);
            bo.data{i}.val = data_range(randidx);
        case 'continuous'
            bo.data{i}.val = data_range(1) + (data_range(2)-data_range(1))*rand;
        otherwise
            fprintf(2, '[sample_bayesOpt] %s is invalid. \n', data_type);
    end
end

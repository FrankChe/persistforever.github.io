% load('rate.mat')
% load('e_dist')
% load('user_id')
% load('brand_id')
% load('buy_number')
% load('user_buy')
% % load('real_rate')
% scale_factor = 0.5;
% sim_count = 20;
% rmse = zeros(11,1);
% for i =1:11
%     sim_count = i*10
%     real_rate = update_rate(rate,e_dist,scale_factor,sim_count);
%     [f1 guess_result hb pb bb right] = week4(real_rate, user_id, brand_id, buy_number, user_buy) ; % Ԥ��Ľ��
%     f1
%     rmse(i)=f1;
% end

% load('rate.mat')
% load('e_dist')
% load('user_id')
% load('brand_id')
% load('buy_number')
% load('user_buy')
% load('u2usim')
% % load('real_rate')
% scale_factor = 0.5;
% sim_count = 20;
% % rmse = zeros(11,1);
% %  for i =1:11
% %      sim_count = i*10
%     real_rate = update_rate(rate,u2usim,scale_factor,sim_count);
%     [f1 guess_result hb pb bb right] = week4(real_rate, user_id, brand_id, buy_number, user_buy) ; % Ԥ��Ľ��
% %     f1
% %     rmse(i)=f1;
% %  end



% e_dist = euclidean_distance(rate);

% rate = zeros(884,9531) ;
% % a = importdata('train_and_remine.mat');
% % training_data = a.training_data;
% % b = importdata('brand_user_id.mat');
% % brand_id = b.brand_id;
% % user_id = b.user_id;
% rate = rateMatrix(data, brand_id, user_id) ; % ������־���
% % save rate.mat rate;
% % [rate_bili res2] = DiscretRate(rate) ;
% % % avguserscore2 = avgUserScore(rate) ;% ����û�����ֵƽ������
% % avguserscore = avgUserScore(rate) ; % ����û���ɢֵƽ������
% % save avguserscore.mat avguserscore
% u2usim = u2uSim_pearson(rate, avguserscore) ; % �û����û�֮������ƶȾ���(pearson����)   
% % % u2usim = u2uSim_easy(rate) ; % �û����û�֮������ƶȾ���(�򵥷���)
% buy_number = buyNumber(data,user_id,4) ; % Ԥ���û��������Ʒ����
% scale_factor = 0.5;
% sim_count = 50;
% e_dis = euclidean_distance(rate) ;
% real_rate = update_rate(rate,e_dis,scale_factor,sim_count);
% final_rate = CFR(rate, u2usim, avguserscore) ; % �û����յ�����
% [f1 guess_result hb pb bb right] = week4(final_rate, user_id, brand_id, buy_number, user_buy) ; % Ԥ��Ľ��
print_result(real_rate, user_id, brand_id, buy_number) ; % ��ӡ���
% 

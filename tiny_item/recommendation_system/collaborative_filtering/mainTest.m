rate = zeros(884,9531) ;
rate = rateMatrix(training_data, brand_id, user_id) ; % ������־���
% [rate_bili res2] = DiscretRate(rate) ;
% % avguserscore2 = avgUserScore(rate) ;% ����û�����ֵƽ������
avguserscore = avgUserScore(rate) ; % ����û���ɢֵƽ������
u2usim = u2uSim_pearson(rate, avguserscore) ; % �û����û�֮������ƶȾ���(pearson����)
% % u2usim = u2uSim_easy(rate) ; % �û����û�֮������ƶȾ���(�򵥷���)
buy_number = buyNumber(training_data,user_id,3) ; % Ԥ���û��������Ʒ����
final_rate = CFR(rate, u2usim, avguserscore) ; % �û����յ�����
[f1 guess_result hb pb bb right] = week4(final_rate, user_id, brand_id, buy_number, user_buy) ; % Ԥ��Ľ��
% print_result(final_rate, user_id, brand_id, buy_number) ; % ��ӡ���


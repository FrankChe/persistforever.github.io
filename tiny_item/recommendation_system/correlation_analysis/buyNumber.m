function buy_number = buyNumber(training_data,user_id,month)
%����ƽ��ÿ��Ҫ�����Ʒ�� data��ԭʼ����month��ʾ����
[m n] = size(training_data);
scoreVector=[0 1 0 0] ; % ÿ���Ȩ��
buy_number = zeros(size(user_id));
for i = 1:m
    temp = find(user_id == training_data(i,1));
    buy_number(temp) = buy_number(temp) + scoreVector(training_data(i,3)+1);
end
buy_number = buy_number./month;
buy_number = ceil(buy_number);
end


function res = u2uSim(rate, b2bsim)
[m,n] = size(rate) ;
u2usim = zeros(m,m) ;
for user1=1:m
    for user2=i+1:m
        NBSu = zeros(3,1) ;
        for i=1:n
            if rate(user1,i)~=0 || rate(user2,i)~=0
                temp = [i ; rate(user1,i) ; rate(user2,i)] ;
                NBSu = [NBSu temp] ;
            end
        end
        NBSu = NBSu(:,2:end) ; % ���������û�1���û�2���۵Ĳ���
        [r,c] = size(NBSu) ;
        for j=1:c
            if 0 == NBSu(2,j)
                NBSu(2,j) = u2bScore(rate,b2bsim,user1,NBSu(1,j)) ; % �����û�1������
            end
            if 0 == NBSu(3,j)
                NBSu(3,j) = u2bScore(rate,b2bsim,user2,NBSu(1,j)) ; % �����û�2������
            end
        end
        NBSu = NBSu(2:3,2:end) ;
        u2usim(user1,user2) = pearsonSim(NBSu(1,:),NBSu(2,:)) ;
    end
end
res = u2usim ;
end
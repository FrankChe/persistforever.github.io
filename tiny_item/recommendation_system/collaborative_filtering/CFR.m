function res = CFR(rate, u2usim, avguserscore)
[m,n] = size(rate) ;
k = 20 ; % ѡȡ20��������û�
NBSu = zeros(m,3) ;
for i=1:m
    i
    NBSu = [(1:m)' u2usim(i,:)'] ;
    NBSu = sortrows(NBSu,2) ;
    for j=1:n
        NBSub = [NBSu rate(NBSu(:,1),j)];
%         NBSub(NBSub(:,3) < avguserscore(i,1),:) = [] ; % ��ȥ�Դ���Ʒ����Ϊ0���û�
%         NBSub(NBSub(:,1) == i,:) = [] ; % ��ȥ�Դ���Ʒ����Ϊ0���û�
%         [a,b] = size(NBSub) ;
%         if a < 1
%             continue ;
%         end
%         if a > k
        NBSub = NBSub(m-k+1:m,:) ; % �û�i����Ʒj�µ�������û�
%         end
        score = 0 ;
        sim = 0 ;
        NBSub(:,3) = rate(NBSub(:,1),j) - avguserscore(NBSub(:,1)) ;
        score = score + NBSub(:,3)' * NBSub(:,2) ;
        sim = sim + sum(NBSub(:,2)) ;
        if rate(i,j) == 0
        rate(i,j) = avguserscore(i) + score/sim ;
        else
        rate(i,j) = rate(i,j) + score/sim ;
        end
    end
end
res = rate ;
end
function res = u2bScore(rate, b2bsim, user, brand)
[m,n] = size(rate) ;
k = 25 ; % ����Ʒp�����Ƶ�k����Ŀ
Mp = zeros(n,3) ;
for i=1:n
    Mp(i,1) = i ;
    Mp(i,2) = b2bsim(i,brand) ;
end
Mp = sortrows(Mp,2) ;
score = 0 ; % �û�����Ʒ�Ĵ��
sim = 0 ; % ���ƶ�֮��
for i=n-k-1:n-1
    Mp(i,3) = rate(user,Mp(i,1)) ;
end
score = Mp(n-k-1:n-1,3)'*Mp(n-k-1:n-1,2) ;
sim = sum(abs(Mp(n-k-1:n-1,2))) ;
res = score/sim ;
end
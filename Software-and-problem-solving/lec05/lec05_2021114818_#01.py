N=int(input())
i=2
while i<N:
    if N%i==0:
       break
    i=i+1
if i==N :
    print('소수이다')
else:
    print('소수가 아니다')


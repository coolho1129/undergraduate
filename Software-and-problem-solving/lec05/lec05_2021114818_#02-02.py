a=input().upper()
b=input().upper()
alen=len(a)
blen=len(b)
isanaram=True
alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ'

if alen!=blen:
    print('문자열 길이가 다름')
else:
    for i in range(26):
        if a.count(alpha[i])!=b.count(alpha[i]):
            print('anagaram이 아니다')
            isanaram=False
            break
    if isanaram:
        print('anagaram이다')
        
        
        

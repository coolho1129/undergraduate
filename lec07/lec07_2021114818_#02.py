cnt=0
for i in range(1,100001):
    tmp=i
    while tmp!=0:
        if tmp%10==7:
            cnt+=1

        tmp//=10

print(cnt)



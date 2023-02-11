def m2n_sum(m,n):
    sum=0
    if n<m:
        (n,m)=(m,n)

    for i in range(m,n+1):
        sum=sum+i

    return(sum)



n=int(input('정수1:'))
m=int(input('정수2:'))
print(f'{n} -- {m} = {m2n_sum(n, m)}')

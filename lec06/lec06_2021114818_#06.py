def one2n_sum1(n):
    if n>1:
       s=(n*(n+1))/2
       return(s)


    else:
        print('입력된 수가 1보다 작습니다')

n=int(input('자연수 :'))
print('1---',n,'=',one2n_sum1(n))

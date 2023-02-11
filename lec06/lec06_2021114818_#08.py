def cal(num1,num2,act='+'):
    if act=='+':
        return num1+num2
    elif act=='-':
        return num1-num2
    elif act=='*':
        return num1*num2
    elif act=='/':
        return num1/num2
    else:
        return '잘못된 연산자 입니다'

n1=int(input('정수1:'))
n2=int(input('정수2:'))
print(cal(n1,n2))
print(cal(n1,n2,'*'))
print(cal(n1,n2,'^'))
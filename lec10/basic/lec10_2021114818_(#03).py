score=int(input('\n점수:'))
if 90<=score<=100:
    print(score,'A')
elif 80<=score<=89:
    print(score,'B')
elif 70<=score<=79:
    print(score,'C')
elif 60<=score<=69:
    print(score,'D')
elif 0<=score<=59:
    print(score,'F')
else:
    print('입력 가능한 점수 범위는 0~100입니다')
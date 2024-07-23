jnymd=input('주민등록번호 년월일: ' )
if 00<int(jnymd[2:4])<13:
    if 00<int(jnymd[4:6])<32:
        a=input('성별표시 : ')
        print(jnymd,'-',a)
    else:
        print('주민번호 일 형식이 잘못되었습니다.')
else:
    print('주민번호 월 형식이 잘못되었습니다.')

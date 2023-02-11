jnymd=input('주민등록번호 년월일:' )
if 00<int(jnymd[2:4])<13:
    if 00<int(jnymd[4:6])<32:
        mf=input('성별표시 :')

    else:
        print('주민번호 일 형식이 잘못되었습니다.')
else:
    print('주민번호 월 형식이 잘못되었습니다.')
mfd ={9:1800,0:1800,1:1900,2:1900,3:2000,4:2000,5:1900,7:2000,8:2000}

year=mfd[int(mf)]
if int(mf)%2==1:
    if int(mf)==5:
        print(year,'년대에 태어난 외국인 남성입니다.')
    elif int(mf)==7:
        print(year, '년대에 태어난 외국인 남성입니다.')
    else:
        print(year, '년대에 태어난 남성입니다.')

elif int(mf)%2==0:
    if int(mf) == 6:
        print(year, '년대에 태어난 외국인 여성입니다.')
    elif int(mf) == 8:
        print(year, '년대에 태어난 외국인 여성입니다.')
    else:
        print(year, '년대에 태어난 여성입니다.')

    print(year,'년대에 태어난 여성입니다.')
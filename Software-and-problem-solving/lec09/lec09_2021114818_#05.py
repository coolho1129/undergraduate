from random import *
R = randint(0, 2)

if R == 0:
    print("가위")
elif R == 1:
    print("주먹")
elif R == 2:
    print("보")


r = randint(1, 10)
if r <= 5:
    print("가위")
elif r > 5 and r <= 8:
    print("바위")
elif r > 8 and r <= 10:
    print("보")



X= 100
for i in range(X + 1):
    for j in range(X - i + 1):
        P_100 = 3 * i + 5 * j + 2 * (X- i - j)
        if P_100 == 4 * X:
            a = round(i / 100, 2)
            b = round(j / 100, 2)
            c = round((X / 100) - a - b, 2)
            P = (0.3 * a + 0.5 * b + 0.2 * c) * 100
            print("가위 = %.2f 바위 = %.2f 보 = %.2f 이길 확률 = %.2f" %(a, b, c, P))

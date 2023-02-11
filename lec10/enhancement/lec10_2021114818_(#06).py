import math
cnt = 0
kd = 0
moneys = {1: 50000, 2: 10000, 3: 5000, 4: 1000, 5: 500, 6: 100, 7: 50, 8: 10, 9: 5, 10: 1}
p = int(input("금액 : "))
for i, value in moneys.items():
    qtt = math.trunc(p / moneys[i])
    p = p - math.trunc(p / moneys[i]) * moneys[i]
    cnt += qtt
    if qtt == 0:
        kd += 1
    print(value, ":", qtt)
print("총", 10 - kd, "종류", cnt, "개 필요")
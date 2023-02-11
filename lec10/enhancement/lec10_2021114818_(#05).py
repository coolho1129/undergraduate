cnt = 0
kd = 0
moneys = {1: 50000, 2: 10000, 3: 5000, 4: 1000, 5: 500, 6: 100, 7: 50, 8: 10, 9: 5, 10: 1}
price = int(input("금액 : "))
for key, value in moneys.items():
    qtt = price // value
    price = price % value
    cnt = cnt + qtt
    if qtt == 0:
        kd += 1
    print(value, ":", qtt)
print("총", 10 - kd, "종류", cnt, "개 필요")
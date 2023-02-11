items={"라면":650, "우유":1100, "콜라":1200, "캔커피":500, "과자":700}
s = 0
while True:
    it = input("제품명 : ")
    if it in items:
        s += items[it]
        print("[%s:%d] > %d"%(it, items[it], s))
    elif it == "":
        break
    else:
        print(it, "는 미등록 제품입니다.")

print("총 금액 :", s)
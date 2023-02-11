items = {'공책': 325, '연필': 427, '지우개': 125, '복사지': 510}
stock = int(input("파악 재고수 기준 : "))
for k, v in items.items():
    if stock > v:
        print(k, ":", v)

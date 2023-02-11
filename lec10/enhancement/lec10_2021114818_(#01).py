sales = {1: 8, 2: 6, 3: 10, 4: 13}
for i in range(4):
    print(i + 1, "분기:", '#' * sales[i + 1], "(", sales[i + 1], ")")
#학부: 컴퓨터학부
#학번: 2021114818
#이름: 김찬호
# Linear Algebra Programming Project
# Q2.2.

import numpy as np

np.set_printoptions(precision=6,suppress=True)
def Print(i,List,name):
    print(f"{name}[{i}]")
    print(List[i])
    print()

def solve(a):
    m = []
    x = []
    y = []
    v = []
    A = np.array(
        [
            [10, -8, -4],
            [-8, 13, 4],
            [-4, 5, 4]

        ]
    )

    x0 = np.array(
        [
            [1],
            [1],
            [1]
        ]

    )
    x.append(x0)
    I = np.identity(n=3, dtype=np.int32)

    #print(I)
    print(f"a={a}")
    print()

    for i in range(0, 5):
        y.append(np.linalg.solve((A - a * I), x[i]))
        tmp=[]
        for j in range(0, 3):
            tmp.append(abs(y[i][j][0]))
        m.append(np.round(max(tmp),6))
        v.append(np.round(a + (1 / m[i]),6))
        x.append((1 / m[i]) * y[i])

    #cnt = 0
    for i in range(5):
        print(f"k: {i}")
        Print(i, x,"x")
        Print(i, y,"y")
        Print(i, m,"m")
        Print(i, v,"v")

    print(m)
    print(v)








#solve(21)
solve(3.3)
solve(1.9)
#학부: 컴퓨터학부
#학번: 2021114818
#이름: 김찬호
# Linear Algebra Programming Project
# Q1.2.
import numpy as np
np.set_printoptions(precision=6,suppress=True)
def Print(i,List,name):
    print(f"{name}[{i}]")
    print(List[i])
    print()


A = np.array(
    [
        [6,5],
        [1,2]

    ]
)

x0 = np.array(
    [
        [0],
        [1],
    ]

)

Ax=[]
m=[]
x=[]
x.append(x0)

for i in range(0,6):
     Ax.append(A @ x[i])
     #print(Ax[i][0][0])
     #print(Ax[i][1][0])
     m.append(np.round(max(abs(Ax[i][0][0]),abs(Ax[i][1][0])),6))
     x.append(Ax[i]/m[i])


for i in range(0,6):
    Print(i, x, "x")
    Print(i, Ax, "Ax")
    Print(i, m, "m")





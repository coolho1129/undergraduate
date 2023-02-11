import math, sys
def points_to_line(point):
    p1 = point[0:2]
    p2 = point[2:]
    if p1[0]==p2[0]:
        a=1
        b=0
        c=-p1[0]
    else:
        b=1
        a=-(p1[1]-p2[1])/(p1[0]-p2[0])
        c=-(a*p1[0])-b*(p1[1])
    return [a,b,c]

def parallelQ(m1, m2):
    return ( math.fabs((m1[0]/m1[1]) - (m2[0]/m2[1])) <= sys.float_info.epsilon)

def same_lineQ(m1, m2):
    return (parallelQ(m1, m2) and math.fabs((m1[2] / m1[1]) - (m2[2] / m2[1])) <= sys.float_info.epsilon)

def intersection_point(m1, m2):
    p = [0.0, 0.0]
    p[0] = (m2[1] * m1[2] - m1[1] * m2[2]) / (m2[0] * m1[1] - m1[0] * m2[1])
    if math.fabs(m1[1]) > sys.float_info.epsilon:
        p[1] = - (m1[0] * p[0] + m1[2] ) / m1[1]
        return p
    elif math.fabs(m2[1]) > sys.float_info.epsilon:
        p[1] = - (m2[0] * p[0] + m2[2]) / m2[1]
        return p
    if same_lineQ(m1, m2):
        print("INFINITY\n")
        p = [0.0, 0.0]
    if parallelQ(m1, m2):
        print("Error: Distinct parallel lines do not intersect.\n")
    if math.fabs(m1[1]) <= sys.float_info.epsilon:
        p[1] = - (m2[0] * p[0] + m2[2] ) / m2[1]
        return p




N=int(input())
X=[]

for i in range(N):
    X.append(list(map(float, input().split())))

M=[]
for i in range(N):
    M.append(points_to_line(X[i]))

for i in range(N):
    for j in range(i+1,N):
        print(f"({i+1}, {j+1}) : ", end="")
        print(f"({intersection_point(M[i],M[j])[0]}, {intersection_point(M[i], M[j])[1]})")









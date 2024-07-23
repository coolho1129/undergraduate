X=list(map(int,input().split()))

P1=X[:2]
P2=X[2:4]
P3=X[4:]


def points_to_line(p1,p2):
    if(p1[0]==p2[0]):
        a=1
        b=0
        c=-p1[0]
    else:
        b=1
        a=-(p1[1]-p2[1])/(p1[0]-p2[0])
        c=-(a*p1[0])-b*(p1[1])

    return [a,b,c]


m1=points_to_line(P1,P2)
m2=points_to_line(P2,P3)


if m1==m2:
    print('yes')
else:
    print('no')




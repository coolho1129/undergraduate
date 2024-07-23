import math
import sys


def intersection_point(m1, m2):
    p = [0.0, 0.0]

    if parallelQ(m1, m2):
        print("만나지 않아요")
        return
    if same_lineQ(m1, m2) and count <= 1:
        print("무한 입니다.")
        return
    p[0] = ((m2[1] * m1[2]) - (m1[1] * m2[2])) / ((m2[0] * m1[1]) - (m1[0] * m2[1]))
    if math.fabs(m1[1]) > sys.float_info.epsilon:
        p[1] = - ((m1[0] * p[0] + m1[2]) / m1[1])
    else:
        p[1] = - ((m2[0] * p[0] + m2[2]) / m2[1])

    return p


def point_and_slope_to_line(p, s):  # ax + by + c = 0 꼴의 방정식을 배열에다 저장한다.
    linear = []
    if s == sys.float_info.epsilon / 10 ** 100:
        a = 1
        b = 0
        c = -p[0]
        linear.append(a)
        linear.append(b)
        linear.append(c)
        return linear
    else:
        a = -s
        b = 1
        c = -((a * p[0]) + (b * p[1]))
        linear.append(a)
        linear.append(b)
        linear.append(c)
        return linear


def print_clearly(i, j, l_1, l_2, list_l):
    i_1 = i + 1
    j_1 = j + 1
    a = intersection_point(l_1, l_2)
    a_0_0 = a[0] + 0.0
    a_1_0 = a[1] + 0.0

    if (a == None):
        return
    else:

        min_1 = min(list_l[0], list_l[2])
        max_1 = max(list_l[0], list_l[2])
        min_2 = min(list_l[1], list_l[3])
        max_2 = max(list_l[1], list_l[3])

        if (a_0_0 <= max_1 and a_0_0 >= min_1):
            if (a_0_0 <= max_2 and a_0_0 >= min_2):
                print(f"({i_1}, {j_1})")
                return


def parallelQ(m1, m2):
    standard_constant = sys.float_info.epsilon
    if m1[1] <= standard_constant and m2[1] > standard_constant:
        return False
    elif m1[1] > standard_constant and m2[1] <= standard_constant:
        return False
    elif m1[1] <= standard_constant and m2[1] <= standard_constant:
        return True
    else:
        return (math.fabs((m1[0] / m1[1]) - (m2[0] / m2[1])) <= sys.float_info.epsilon)


def same_lineQ(m1, m2):
    return (m1[0] == m2[0] and m1[1] == m2[1] and m1[2] == m2[2])


number = int(input("직선의 개수를 입력해주세요 : "))

a = [[0] * 2 for i in range(number)]
b = [[0] * 2 for i in range(number)]

for i in range(number):
    a[i][0], a[i][1], b[i][0], b[i][1] = map(float, input().split())

count = 0
for i in range(0, number - 1, 1):
    count += 1
    for j in range(count, number, 1):
        linear_1 = []
        linear_2 = []
        list_2 = []
        list_2.append(b[i][0])
        list_2.append(b[j][0])
        list_2.append(a[i][0])
        list_2.append(a[j][0])

        p1 = [b[i][0], b[i][1]]
        p2 = [b[j][0], b[j][1]]

        if (b[i][0] - a[i][0]) == 0.0:
            m1 = sys.float_info.epsilon / 10 ** 100
            if (b[j][0] - a[j][0]) == 0.0:
                m2 = sys.float_info.epsilon / 10 ** 100
                linear_1 = point_and_slope_to_line(p1, m1)
                linear_2 = point_and_slope_to_line(p2, m2)
                print_clearly(i, j, linear_1, linear_2, list_l=list_2)

            else:
                m2 = (b[j][1] - a[j][1]) / (b[j][0] - a[j][0])
                linear_1 = point_and_slope_to_line(p1, m1)
                linear_2 = point_and_slope_to_line(p2, m2)
                print_clearly(i, j, linear_1, linear_2, list_l=list_2)

        else:
            m1 = (b[i][1] - a[i][1]) / (b[i][0] - a[i][0])
            m2 = (b[j][1] - a[j][1]) / (b[j][0] - a[j][0])
            linear_1 = point_and_slope_to_line(p1, m1)
            linear_2 = point_and_slope_to_line(p2, m2)

            print_clearly(i, j, linear_1, linear_2, list_l=list_2)
import math
import timeit
import random


def collinearPoints(points):
    def getslope(p1, p2):
        if p1[0] == p2[0]: 
            return float('inf')
        else:
          slope = (p1[1] - p2[1]) / (p1[0] - p2[0])
          slope = math.floor(slope * 1000000) / 1000000
          return slope
    
    def select_res(p1, p2, p3):
        candidate = [p1, p2, p3]
        candidate.sort(key=lambda p: (p[0], p[1]))
        res = (candidate[0][0], candidate[0][1], candidate[-1][0], candidate[-1][1])
        return res
    
    points.sort(key=lambda p: (p[0], p[1]))
    n = len(points)
    result = []

    for i in range(n):
        slopes = []
        for j in range(n):
            if i!=j:
                slopes.append((points[j][0], points[j][1], getslope(points[i],points[j])))

        slopes.sort(key=lambda p: (p[2],p[0],p[1]))
        cnt = 1 # 시작점 개수
        checkpoint=slopes[0]
        checkslope = checkpoint[2]
        
        for k in range(0, len(slopes)):
            if checkslope == slopes[k][2]:
                cnt += 1
                if k == len(slopes) - 1 and cnt > 3 : 
                    res = select_res(points[i], slopes[k],checkpoint) 
                    if res not in result:
                        result.append(res)
            else:
                if cnt > 3:
                    res = select_res(points[i], slopes[k - 1], checkpoint)
                    if res not in result:
                        result.append(res)
                cnt = 2 # 시작점+checkpoint 개수
                checkpoint = slopes[k]
                checkslope = checkpoint[2]
                
    return result

           
def correctnessTest(input, expected_output, correct):
    output = collinearPoints(input)
    print(f"collinearPoints({input})\n{output}")
    if output == expected_output: print("Pass")
    else:        
        print(f"Fail - expected output: {expected_output}")
        correct = False
    print()    

    return correct


def simulateNSquareLogN(points):
    points = sorted(points, key=lambda p:(p[1], -p[0]))
    for i in range(0, len(points)):
        slopes = []
        for j in range(i+1, len(points)):
            if points[i][0] == points[j][0]: slopes.append((points[j][0], points[j][1], float('inf')))
            else: slopes.append((points[j][0], points[j][1], (points[j][1]-points[i][1])/(points[j][0]-points[i][0])))
        slopes.sort(key=lambda p:(p[1],p[2],p[0]))
        
        for j in range(1, len(slopes)):
            if slopes[j][2] == slopes[j-1][2]:
                for k in range(5): pass


'''
Unit Test
'''
if __name__ == "__main__":

    print("Correctness test for collinearPoints()")
    print("For each test case, if your answer does not appear within 5 seconds, then consider that you failed the case")
    print()
    correct = True

    # No collinear sets found, thus return the empty list []
    input = [(0,0),(1,1)]
    expected_output = []
    correct = correctnessTest(input, expected_output, correct)


    input = [(0,0), (1,1), (3,3), (4,4), (6,6), (7,7), (9,9)]
    expected_output = [(0,0,9,9)]    
    correct = correctnessTest(input, expected_output, correct)

    input = [(1,0), (2,0), (3,0), (4,0), (5,0), (6,0), (8,0)]
    expected_output = [(1,0,8,0)]
    correct = correctnessTest(input, expected_output, correct)

    input = [(7,0), (14,0), (22,0), (27,0), (31,0), (42,0)]
    expected_output = [(7,0,42,0)]
    correct = correctnessTest(input, expected_output, correct)

    input = [(0,0), (0,1), (0,2), (0,3), (0,4), (0,5), (0,-2), (0,-53)]
    expected_output = [(0, -53, 0, 5)]
    correct = correctnessTest(input, expected_output, correct)

    input = [(19000,10000), (18000,10000), (32000,10000), (21000,10000), (1234,5678), (14000,10000)]
    expected_output = [(14000,10000,32000,10000)]
    correct = correctnessTest(input, expected_output, correct)

    input = [(12446,18993), (12798,19345), (12834,19381), (12870,19417), (12906,19453), (12942,19489)]
    expected_output = [(12446,18993,12942,19489)]
    correct = correctnessTest(input, expected_output, correct)


    input = [(0,0), (0,1), (0,2), (0,3), (1,0), (1,1), (1,2), (1,3)]
    expected_output = [(0,0,0,3), (1,0,1,3)]
    correct = correctnessTest(input, expected_output, correct)

    input = [(10000,0), (0,10000), (3000,7000), (7000,3000), (20000,21000), (3000,4000), (14000,15000), (6000,7000)]
    expected_output = [(0, 10000, 10000, 0), (3000, 4000, 20000, 21000)]    
    correct = correctnessTest(input, expected_output, correct)    


    # Case where the same point appears multiple times
    input = [(1,1), (2,2), (3,3), (4,4), (2,0), (3,-1), (4,-2), (0,1), (-1,1), (-2,1), (-3,1), (2,1), (3,1), (4,1), (5,1)]
    expected_output = [(-3, 1, 5, 1), (1, 1, 4, -2), (1, 1, 4, 4)]
    correct = correctnessTest(input, expected_output, correct)    


    print()
    print("Speed test for collinearPoints()")
    if not correct: print("Fail (since the algorithm is not correct)")
    else:
        repeat = 10
        inputLength = 100
        minC, maxC = -1000000, 1000000
        points = [(random.randint(minC, maxC), random.randint(minC, maxC)) for _ in range(inputLength)]
        tCodeToCompare = timeit.timeit(lambda: simulateNSquareLogN(points), number=repeat) / repeat
        tSubmittedCode = timeit.timeit(lambda: collinearPoints(points), number=repeat) / repeat        
        print(f"Average running time of collinearPoints() and simulateNSquareLogN() with {inputLength} points: {tSubmittedCode:.10f} and {tCodeToCompare:.10f}")
        #print(f"{tSubmittedCode / tCodeToCompare}")
        if tSubmittedCode < tCodeToCompare * 3: print("Pass")
        else:
            print("Fail")
        print()
        
    
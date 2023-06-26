import sys
def hanoi(N, A, B, C):
    if N == 1:
        print("%d번 기둥에서 %d번 기둥으로 %d번 원반 이동"%(A,C,N))
        return 
        
    hanoi(N - 1, A, C, B)
    print("%d번 기둥에서 %d번 기둥으로 %d번 원반 이동"%(A,C,N))
    hanoi(N - 1, B, A, C)

    
def main():
    hanoi(int(sys.argv[1]),1,2,3)
      

main()


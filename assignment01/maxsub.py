import sys
import FinanceDataReader as fdr
import matplotlib.pyplot as plt

sys.setrecursionlimit(10**6)

def Find_MaxCrossing(A,low,mid,high):
    left_sum=-(sys.maxsize + 1)
    sum=0
    max_left=0
    
    
    for i in range(mid,low-1,-1):
        sum=sum+A[i]
        if(sum>left_sum):
            left_sum=sum
            max_left=i
    
    right_sum=-(sys.maxsize + 1)
    sum=0
    max_right=0

    for i in range(mid+1,high+1):
        sum=sum+A[i]
        if(sum>right_sum):
            right_sum=sum
            max_right=i
    
    return (max_left,max_right,left_sum+right_sum)
    
    

def Find_MaxSuB(A,low,high):
    if(high==low):
        return (low,high,A[low])
    else: 
        mid=(low+high)//2
        left_low,left_high,left_sum=Find_MaxSuB(A,low,mid)
        right_low,right_high,right_sum=Find_MaxSuB(A,mid+1,high)
        cross_low,cross_high,cross_sum=Find_MaxCrossing(A,low,mid,high)
        
        if(left_sum>=right_sum and left_sum>=cross_sum):
            return (left_low,left_high,left_sum)
        elif(right_sum>=left_sum and right_sum>=cross_sum):
            return (right_low,right_high,right_sum)
        else:
            return(cross_low,cross_high,cross_sum)
        
        
        
def main():
    df=fdr.DataReader(sys.argv[1],sys.argv[2],sys.argv[3])
    price=list(df['Close'])
    change=[0]
    
    for i in range(1,len(price)):
        change.append(price[i]-price[i-1])
    
    start,end,maxprice=Find_MaxSuB(change,1,len(change)-1)
    print("종목: %s, 매입날짜: %10.10s, 매도 날짜: %10.10s, 총 수익: %d"%(sys.argv[1],df.index[start],df.index[end],maxprice))
    
    df['Close'].plot()
    plt.ylabel('Price')
    plt.vlines(df.index[start],min(price)//3*2,price[start] , color='red', linestyle='solid', linewidth=3)
    plt.vlines(df.index[end],min(price)//3*2,price[end] , color='red', linestyle='solid', linewidth=3)
    plt.grid(True)
    plt.show()
   

main()     
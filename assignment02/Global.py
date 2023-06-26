import sys

def main():
    x=sys.argv[1]
    y=sys.argv[2]
    match=1
    miss=-1
    gap=-1
    
    score_matrix=[[0 for _ in range(len(y)+2)] for _ in range(len(x)+2)]
    backtrack_matrix=[[" " for _ in range(len(y)+2)] for _ in range(len(x)+2)]
    
    for col in range(0,len(y)+2):
        if(col<2):
            score_matrix[0][col]=" "
        else:
            score_matrix[0][col]=y[col-2]
            
    for row in range(1,len(x)+2):
        if(row<2):
            score_matrix[row][0]=" "
        else:
            score_matrix[row][0]=x[row-2]
    
    for col in range(2,len(y)+2):
        score_matrix[1][col]=(col-1)*gap
        
    for row in range(2,len(x)+2):
        score_matrix[row][1]=(row-1)*gap
        
    for row in range(2,len(x)+2):
        for col in range(2,len(y)+2):
            s=miss
            if(score_matrix[0][col]==score_matrix[row][0]):
                s=match
            
            score_matrix[row][col]=max(score_matrix[row-1][col-1]+s,score_matrix[row][col-1]+gap,score_matrix[row-1][col]+gap)
            
            if(score_matrix[row][col]==score_matrix[row-1][col-1]+s):
                 backtrack_matrix[row][col]+='↖ '
              
            
            if(score_matrix[row][col]==score_matrix[row][col-1]+gap):
                backtrack_matrix[row][col]+='← '
            
          
            if(score_matrix[row][col]==score_matrix[row-1][col]+gap):
                backtrack_matrix[row][col]+='↑ '
                
    print("SCORE MATRIX") 
    for i in range(0,len(x)+2):
        for j in range(0,len(y)+2):
            if(i==0):
                print("%5c"%(score_matrix[i][j]),end=" ")
            else:
                if(j==0):
                    print("%5c"%(score_matrix[i][j]),end=" ")
                else:
                    print("%5d"%(score_matrix[i][j]),end=" ")
        print()
        
    print()
    print("BACKTRACK MATRIX")  
    for i in range(0,len(x)+2):
        for j in range(0,len(y)+2):
            if(i==0):
                print("%5c"%(score_matrix[i][j]),end=" ")
            else:
                if(j==0):
                    print("%5c"%(score_matrix[i][j]),end=" ")
                else:
                    print("%5s"%(backtrack_matrix[i][j]),end=" ")
        print()
    print()
    
    print("SCORE and BACKTRACK MATRIX")
    for i in range(0,len(x)+2):
        for j in range(0,len(y)+2):
            if(i==0):
                print("%10c"%(score_matrix[i][j]),end=" ")
            else:
                if(j==0):
                    print("%10c"%(score_matrix[i][j]),end=" ")
                else:
                    print("%10s"%(backtrack_matrix[i][j]+str(score_matrix[i][j])),end=" ")
        print()
        
main()
    
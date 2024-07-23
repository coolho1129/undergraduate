import turtle

def rectangle_draw(col,row):
     tmpstr = ""
     turtle.forward(col)
     turtle.right(90)
     turtle.forward(row)
     turtle.right(90)
     turtle.forward(col)
     turtle.right(90)
     turtle.forward(row)
     tmpstr='가로'+str(col)+'세로'+str(row)+'인 사각형의 넓이 ='+str(col*row)
     turtle.write(tmpstr)
a=int(input('가로:'))
b=int(input('세로:'))

rectangle_draw(a,b)
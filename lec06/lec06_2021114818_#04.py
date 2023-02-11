import turtle
def rectangle_area(col,row):
    print('가로',col,'세로',row,'인 사각형의 넓이 =',col*row)


def rectangle_draw(col,row):
    turtle.forward(col)
    turtle.right(90)
    turtle.forward(row)
    turtle.right(90)
    turtle.forward(col)
    turtle.right(90)
    turtle.forward(row)



a=int(input('가로:'))
b=int(input('세로:'))

rectangle_area(a,b)
rectangle_draw(a,b)


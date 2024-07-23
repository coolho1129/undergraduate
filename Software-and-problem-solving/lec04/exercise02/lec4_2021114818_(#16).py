import turtle

radius=int(input('반지름: '))
turtle.circle(radius)
turtle.up()
turtle.goto(0,radius*2)
turtle.down()
turtle.circle(radius/2)
turtle.forward(30)

turtle.mainloop()
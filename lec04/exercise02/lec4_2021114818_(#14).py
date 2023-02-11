import turtle

length=int(input('길이를 입력하세요 : '))
distance=int(input('간격을 입력하세요 : '))
import turtle
turtle.shape('turtle')
turtle.forward(length)
turtle.up()
turtle.goto(0,-distance)
turtle.down()
turtle.forward(length)
turtle.up()
turtle.goto(0,-distance*2)
turtle.down()
turtle.forward(length)

turtle.mainloop()

import turtle as t
t.shape('turtle')

def key_Up():
    t.setheading(90)
    t.forward(10)

def key_Down():
    t.setheading(270)
    t.forward(10)

def key_right():
    t.setheading(0)
    t.forward(10)

def key_left():
    t.setheading(180)
    t.forward(10)

def key_r():
    t.goto(0,0)
    t.clear()

t.setup(400, 400)
s=t.Screen()
t.speed(0)

s.onkey(key_Up,'Up')
s.onkey(key_Down,'Down')
s.onkey(key_left,'Left')
s.onkey(key_right,'Right')
s.onkey(key_r,'r')
s.listen()
t.mainloop()
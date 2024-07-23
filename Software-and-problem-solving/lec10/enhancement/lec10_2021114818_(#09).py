import turtle as t

def write_xy(x, y):
    if x >= -100 and x <= 100 and y <= 100 and y >= -100:
        t.penup()
        t.setpos(x,y)
        t.pendown()
        t.circle(20)
        t.penup()
    else:
        t.setpos(x, y)
        t.write("x:%d, y:%d"%(x, y))


t.setup(600, 600)
t.penup()
s = t.Screen()
s.onscreenclick(write_xy, 1)
s.listen()

t.mainloop()

import turtle as t
import math

tm = 0.3
ux = 0
uy = 0
dx = 0
dy = 0
g = 9.8
velo = 0
ang = 0

def draw_pos(x, y):
    tm = 0.3
    velo = t.numinput("입력", "속도 : ", 50, 10, 100)
    ang = math.radians(t.numinput("입력", "각도 : ", 45, 0, 360))

    t.clearstamps()
    t.hideturtle()
    t.setpos(x,y)
    t.showturtle()
    t.stamp()

    hl = -(t.window_height() / 2)
    ux = velo * math.cos(ang)
    uy = velo * math.sin(ang)
    while True:
        uy = uy - g * tm
        dy = y + velo * math.cos(ang) * tm - g * tm * tm / 2
        dx = x + ux * tm
        if dy > hl:
            t.setpos(dx, dy)
            t.stamp()
            tm += 0.5
        else:
            break

t.setup(600, 600)
t.shape("circle")
t.shapesize(0.3, 0.3, 0)
t.penup()
s = t.Screen()
s.onscreenclick(draw_pos)
s.listen()
t.mainloop()

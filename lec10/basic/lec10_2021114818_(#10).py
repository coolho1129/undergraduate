import turtle as t



def write_xy(x, y):
    t.penup()
    t.setpos(x, y)
    t.pendown()
    t.circle(20)
    t.penup()

def screen_clear():
    t.clear()



t.setup(600, 600)
t.penup()
s = t.Screen()
s.onscreenclick(write_xy, 1)
s.onscreenclick(screen_clear, 3)
s.listen()

t.mainloop()
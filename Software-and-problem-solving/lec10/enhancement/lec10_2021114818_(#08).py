import math, turtle as t

r = 100
for a in range(0, 361):
    rad = math.radians(a)
    x = r * math.cos(rad)
    y = r * math.sin(rad)
    if a == 0:
        t.penup()
        t.setpos(x, y)
        t.pendown()
    else:
        t.goto(x, y)
        
t.mainloop()
import math, turtle as t
r = 100
for a in range(0, 361):
    rad = math.radians(a)
    x = r * math.cos(rad)
    y = r * math.sin(rad)
    t.penup()
    t.setpos(x, y)
    t.pendown()
    t.dot(2)
    
t.mainloop()
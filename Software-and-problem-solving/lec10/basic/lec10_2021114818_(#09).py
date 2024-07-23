import turtle as t

def write_xyleft(x, y):
    t.setpos(x,y)
    t.write(f"x:{x}, y:{y} - 마우스 왼쪽 버튼 클릭")
def write_xyright(x, y):
    t.setpos(x, y)
    t.write(f"x:{x}, y:{y} - 마우스 오른쪽 버튼 클릭")




t.setup(600, 600)
t.penup()
s = t.Screen()
s.onscreenclick(write_xyleft, 1)
s.onscreenclick(write_xyright, 3)
s.listen()

t.mainloop()
#PythonDraw.py
import turtle
turtle.setup(650,350,200,200)
turtle.penup()
turtle.forward(-250)
turtle.pendown()
turtle.pensize(25)
turtle.pencolor(0,1,0)
turtle.seth(-40)
for i in range(4):
    turtle.circle(40,80)
    turtle.circle(-40,80)
turtle.circle(40,80/2)
turtle.fd(40)
turtle.circle(20,180)
turtle.fd(40*2/3)
turtle.done()

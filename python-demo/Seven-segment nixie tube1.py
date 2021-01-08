import turtle
import random
import time

def fot0():
    turtle.penup()
    turtle.fd(5)
def one(logic):
    fot0()
    turtle.pendown() if logic else turtle.penup()
    turtle.fd(30)
    fot0()
    turtle.right(90)
def two(digit):
    if digit == 1:
        turtle.penup()
        turtle.fd(-20)
    man={0:"0111111",1:"0100001",2:"1011011",3:"1110011",4:"1100101",\
         5:"1110110",6:"1111110",7:"0100011",8:"1111111",9:"1110111"}
    t=1
    for i in man[digit]:
        one(True) if i in '1' else one(False)
        if t==4:
            turtle.left(90)
        t=t+1
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)
def fot1():
    turtle.penup()
    turtle.fd(-10)
def fot2():
    turtle.penup()
    turtle.fd(40)
def ser(date):
    for i in date:
        turtle.pencolor(random.random(),random.random(),random.random())
        if i=='-':
            fot1()
            turtle.write('年',font=("楷体",20,"normal"))
            fot2()
        elif i=='+':
            fot1()
            turtle.write('月',font=("楷体",20,"normal"))
            fot2()
        elif i=='=':
            fot1()
            turtle.write('日',font=("楷体",20,"normal"))
        else :
            two(eval(i))
def main():
    turtle.setup(800,350,200,200)
    turtle.penup()
    turtle.fd(-250)
    turtle.pensize(5)
    ser(time.strftime('%Y-%m+%d=',time.gmtime()))
    turtle.hideturtle()
    turtle.done()
main()


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
    one(True) if digit in [2,3,4,5,6,8,9] else one(False)
    one(True) if digit in [0,1,3,4,5,6,7,8,9] else one(False)
    one(True) if digit in [0,2,3,5,6,8,9] else one(False)
    one(True) if digit in [0,2,6,8] else one(False)
    turtle.left(90)
    one(True) if digit in [0,4,5,6,8,9] else one(False)
    one(True) if digit in [0,2,3,5,6,7,8,9] else one(False)
    one(True) if digit in [0,1,2,3,4,7,8,9] else one(False)
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

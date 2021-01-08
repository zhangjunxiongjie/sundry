#心形轨迹绘制
import turtle as t # 库导入

t.title("心形轨迹绘制") # 窗口标题
t.setup(800,600,0,0)   # 窗口大小
t.pencolor("red")      # 颜色
t.pensize(5) # 画笔粗细

datals=[] # 定义一个数组变量 

f=open("自动轨迹绘制.txt")  # 打开文件
for line in f:
    line = line.replace("\n"," ")# 按行读取
    datals.append(list(map(eval,line.split(","))))# 分割
f.close() # 关闭文件

t.penup() 
t.right(135)
t.fd(100)
t.right(-135)
t.pendown()

for i in range(len(datals)):  #取长度生成遍历列表
    t.pencolor(datals[i][3],datals[i][4],datals[i][5])
    t.fd(datals[i][0]) # 移动
    if datals[i][1]:
        t.right(datals[i][2]) # 转向
    else:
        t.left(datals[i][2])
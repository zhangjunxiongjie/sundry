# 网上看到的一个牛逼的程序
# 绘制 sin 函数图像。

import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(-np.pi,np.pi,256,endpoint=True)
c,s=np.cos(x),np.sin(x)

plt.figure(1)
# plt.plot(x,c)
plt.plot(x,c,color="blue",linewidth=3.0,linestyle="-",label="COS",alpha=0.9)    # 颜色 线宽 类型 标签 透明度
plt.plot(x,s,"r*",label="SIN")                                                  # r*:red *  颜色为红色，线型为*
plt.title("COS and SIN")     # 标题

#坐标轴的操作
# 坐标轴的位置
ax=plt.gca()         # 引入坐标轴
ax.spines["right"].set_color("none")
ax.spines["top"].set_color("none")
ax.spines["left"].set_position(("data",0))
ax.spines["bottom"].set_position(("data",0))

# 坐标轴的刻度显示位置
ax.xaxis.set_ticks_position("bottom")
ax.yaxis.set_ticks_position("left")

# 设置坐标的显示范围
plt.yticks(np.linspace(-1,1,5,endpoint=True))     # 设置坐标的显示范围
# 设置刻度数字大小和边框
for lable in ax.get_xticklabels()+ax.get_yticklabels():
    lable.set_fontsize(16)            # 刻度大小
    lable.set_bbox(dict(facecolor="white",edgecolor="None",alpha=0.2))   # 刻度下面的小边框
 
# 图例
plt.legend(loc="upper left")

# 网格线
plt.grid()

# 显示范围
#plt.axis([-1,1,-0.5,1])   # 前面两个是x轴的范围，后面是y轴的两个范围。

# 以上为基本功能，下面为有意思的功能
# 填充 
# plt.fill_between(x,np.abs(x)<0.5,c,c>0.5,color="green",alpha=0.5)   #搞不通这个范围？？？

# 划线
t=1
plt.plot([t,t],[0,np.cos(t)],"y",linewidth=3.0,linestyle="--")      # [t,t],[0,np.cos(t)]  应该是相当于[x1,x2],[y1,y2] 所以点应该是(x1,y1)和(x2,y2)

# 注释增加
plt.annotate("cos(1)",xy=(t,np.cos(1)),xycoords="data",xytext=(+10,+30),textcoords="offset points",arrowprops=dict(arrowstyle="->",connectionstyle="arc3,rad=0.2"))
#           注释的文本，位置           ，不清楚         ，偏移量         ，相对偏移                  ，箭头            类型           ，类型                ，弧度
plt.show()


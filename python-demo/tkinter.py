from tkinter import *           # 导入 Tkinter 库
root = Tk()                     # 创建窗口对象的背景色
                                # 创建两个列表
li     = ['C','python','php','html','SQL','java']
movie  = ['CSS','jQuery','Bootstrap']
listb  = Listbox(root)          #  创建两个列表组件
listb2 = Listbox(root)
for item in li:                 # 第一个小部件插入数据
    listb.insert(0,item)
 
for item in movie:              # 第二个小部件插入数据
    listb2.insert(0,item)
 
listb.pack()                    # 将小部件放置到主窗口中
listb2.pack()
root.mainloop()                 # 进入消息循环


'''
import tkinter #一个Pyhon图形库，用于创建GUI程序
 

#创建窗口

if __name__ == '__main__': #当本文件为程序入口文件时执行以下语句

    win = tkinter.Tk()

    #设置标题
    win.title("sunck")

    #设置窗口大小
    win.geometry("500x500+200+200")





    win.mainloop()


'''

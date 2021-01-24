#贪吃蛇小游戏
import pygame, sys
import random

def draw_init( node, v ):            #初始绘制蛇身，传入蛇身节点信息，及速度信息以便绘制节点圆弧，node【0】存放节点个数信息,
    pygame.draw.line(screen, (255, 255, 255), node[1], node[2], v)


def draw_initr(node, v):           #绘制蛇身,传入更新的蛇身属性信息和速度信息，以便绘制蛇身
#    for i in range(2, node[0]+1):
#       pygame.draw.line(screen, (255, 255, 255), node[i-1], node[i], v)
#    for i in range(6):
    pygame.draw.aalines(screen, (255, 255, 255), False, node[1:], 1)    #此处用到了列表截取的方法截取了列表第一个元素后面的所有元素，
    # 因为第一个元素存储着节点个数信息并不是节点坐标信息


#只是头尾头尾节点移动其他节点不动
def up_snake( node, k, kr, v ):     #更新蛇身属性信息,传入蛇身前面属性信息，和现方向，前方向，以及速度
    if k == kr:                 #当方向未改变时节点坐标的移动

        move_node(k, node[1], v)     # 移动头部
        move_node(judge_dire(node[node[0]], node[node[0]-1]), node[node[0]], v)   #移动尾部节点

        if judge_coin(node[node[0]], node[node[0]-1]):
            del node[node[0]]     #减去最后一个节点
            node[0] -= 1     #记录节点个数的头节点减去1

    else:
        noder1 = node[1][0]
        noder2 = node[1][1]
        noder = [noder1, noder2]      #列表与列表之间是传递指针而非值，故需要中间变量重新组成一个列表传给第二节点

        node.insert(2, noder)

        node[0] += 1  # 增加节点

        move_node(k, node[1], v)   # 移动头部

        move_node(judge_dire(node[node[0]], node[node[0]-1]), node[node[0]], v)   #移动尾部节点

        if judge_coin(node[node[0]], node[node[0]-1]):
            del node[node[0]]     #减去最后一个节点
            node[0] -= 1     #记录节点个数的头节点减去1


#因为列表有插入元素并将插入位置后面元素后移的方法故此函数并无实际用途
def move_coor(coor):    #传入节点列表并将头结点后面的节点向后移动一位，以便在头结点后面增加一个节点
    coor.append(coor[coor[0]])
    for i in range(2, coor[0]-1, -1):
        coor[i+1] = coor[i]


def judge_coin(coor, node):   #判断尾节点是否与前一节点重合 ，前者为尾节点
    if coor[0] == node[0] and coor[1] == node[1]:
        return True
    else:
        return False

def judge_dire(coor, node):    #判断当前节点应该移动的方向,前者为移动节点，后者为前一节点,传入的都是节点坐标
    if coor[0] == node[0]:
        if coor[1] > node[1]:
            k = 'up'
        elif coor[1] < node[1]:
            k = 'down'
    if coor[1] == node[1]:
        if coor[0] > node[0]:
            k = 'left'
        elif coor[0] < node[0]:
            k = 'right'
    return k   #返回一个移动方向


def move_node(k, coor, v):     #根据方向移动节点坐标,传入节点坐标，方向，及速度
    if k == 'up':
        coor[1] -= v
    elif k == 'down':
        coor[1] += v
    elif k == 'left':
        coor[0] -= v
    elif k == 'right':
        coor[0] += v


def negation_dire(k):    #用于增产蛇尾时，方向取反以增长蛇尾，传入移动方向，返回增长方向
    if k == 'up':
        kr = 'down'
    elif k == 'down':
        kr = 'up'
    elif k == 'left':
        kr = 'right'
    elif k == 'right':
        kr = 'left'
    return kr


#要考虑到产生的食物不能与已有食物重合
def produce_food(foodr, size, count, gatism):    #产生随机食物的函数,传入储存食物的列表，窗口大小和产生随机食物的个数,及食物的最大大小
    for i in range(count):
        foodi = {}
        foodi['x'] = random.randint(5, size[0]-gatism)    #食物坐标随机
        foodi['y'] = random.randint(5, size[1]-gatism)     #更改食物形状后作为更改形状的圆心

        foodi['R'] = random.randint(5, gatism)     #食物大小随机，产生的随机数作为食物的大小并不是食物的坐标
#        foodi['dy'] = random.randint(10, gatism[1])      #更改形状后只需一个参数即半径

        foodi['r'] = random.randint(1, 255)      #食物颜色随机，分别产生食物的rgb值
        foodi['g'] = random.randint(1, 255)
        foodi['b'] = random.randint(1, 255)

        foodr.append(foodi)    #在末尾增加一个食物字典，字典中存储食物的矩形坐标（形状暂时都统一为矩形）


#更改形状后绘制圆心
def move_food(foodr):                #绘制食物，矩形，传入食物字典
    for food in foodr:
#        pygame.draw.rect(screen, (food['r'], food['g'], food['b']), ((food['x'], food['y']), (food['dx'], food['dy'])), 0)   #参数中第一个元组表示矩形左上角地坐标，第二个元祖表示矩形的宽和高
        pygame.draw.circle(screen, (food['r'], food['g'], food['b']), (food['x'], food['y']), food['R'], 0)   #绘制圆形食物
#        print("{}".format(food['R']))

#最后一个参数是蛇每次移动的距离即蛇宽
def judge_food(foodr, head, v):     #传入储存食物的列表，蛇头结点的坐标，这个函数直接不对蛇节点做更改，仅判断是否有食物被吃有则删除被吃食物，并且返回True，否则返回false
    for i in range(len(foodr)):      #为了便于删除这里用数字索引而不直接对列表内容遍历
        if foodr[i]['x'] - foodr[i]['R'] - v/4 < head[0] < foodr[i]['R'] + foodr[i]['x'] + v/2 and foodr[i]['y'] - foodr[i]['R'] - v/2 < head[1] < foodr[i]['R'] + foodr[i]['y'] + v/4:
            dr = foodr[i]['R']*foodr[i]['R']     #如果有食物被吃则返回食物的面积,改为圆形食物后半径平方作为食物面积
            del foodr[i]
            return dr
    return 0

#在产生随机食物时不仅要求当前有食物被吃还要求食物不能大于某一值，因为如果每次食物被吃，均产生随机个食物那么食物个数将随程序运行（食物持续被吃）而增加


pygame.init()          #加载一些硬件设备
pygame.mixer.init()     #加载音频设备

icon = pygame.image.load("time.jpg")    #打开图片
pygame.display.set_icon(icon)           #设置右上角图标

size = width, height = 900, 500

screen = pygame.display.set_mode(size, pygame.RESIZABLE)   #设置窗口大小及窗口模式为可调
pygame.display.set_caption("贪吃蛇小游戏")     #设置右上角小标题

kaishi1 = pygame.image.load("开始按钮.png")     #加载按钮图片
kaishi2 = pygame.image.load("开始按钮2.png")
kaishi = [kaishi1, kaishi2]

tuichu1 = pygame.image.load("退出游戏.png")
tuichu2 = pygame.image.load("退出游戏2.png")
tuichu = [tuichu1, tuichu2]


pygame.mixer.music.load('dianji.mp3')   #加载音乐

i0 = 0    #控制字体动态变化
i1 = 0

Sign = -1

fps = 150    #用于设置延时时长
#fcloock = pygame.time.Clock()
#fcloock.tick(fps)     # 设置帧速率

head = 900/2-150
wide1 = 500/2-500/3
wide2 = 500/2+500/9

screen.fill((255, 255, 255))  # 设置背景颜色
pygame.display.flip()

while Sign == -1:   #用到了python的取反运算符~，界面循环

    for event in pygame.event.get():
        if event.type == pygame.QUIT:     #处理队列中的事件，同时判断事件类型，根据事件类型的不同分别做不通操作
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:    #处理鼠标按键事件
            pressed_array = pygame.mouse.get_pressed()
            if pressed_array[0]:
                pygame.mixer.music.play()        #播放音乐
                pos = pygame.mouse.get_pos()    #获取按键
                if head < pos[0] < head+300 and wide1 < pos[1] < wide1+79:
                    if i0 == 1:
                        i0 = 0
                    else:
                        i0 = 1
                    Sign = 1
                elif head < pos[0] < head+300 and wide2 < pos[1] < wide2+79:
                    if i1 == 1:
                        i1 = 0
                    else:
                        i1 = 1
                    Sign = 0
                pygame.mixer.music.play()      #暂停音乐

        elif event.type == pygame.VIDEORESIZE:   #处理屏幕拉伸事件

            size = width, height = event.size[0], event.size[1]

            head = size[0] / 2 - 150
            wide1 = size[1] / 2 - size[1] / 5
            wide2 = size[1] / 2 + size[1] / 10

            screen = pygame.display.set_mode(size, pygame.RESIZABLE)  # 设置窗口大小及窗口模式为可调
            screen.fill((255, 255, 255))  # 设置背景颜色
            pygame.display.flip()

    screen.blit(kaishi[i0], (head, wide1))
    screen.blit(tuichu[i1], (head, wide2))
    pygame.display.update()  # 刷新屏幕

    if Sign != -1:
        pygame.time.wait(fps)    #延时函数，使程序通知一段时间


#初始化一些环境变量
screen.fill((0, 0, 0))     #设置背景颜色
pygame.display.flip()       #刷新整个屏幕

Vide = 10      #设置速度，一次移动三个像素
Keyr = 'right'     #上次蛇移动的方向
Key = 'right'    #up,down,left,right,上下左右，，分别对应键盘的K_UP，K_DOWN,K_LEFT,K_RIGHT
snake = [2, [size[0]/2+Vide, size[1]/2], [size[0]/2-Vide, size[1]/2]]      #设置蛇的初始属性

draw_init(snake, Vide)       #绘制初始蛇身


#食物相关
food = []      #食物参数
gatism = 10   #设置食物的最大大小
foodsum = 0    #所吃食物总个数，用于计分显示

#蛇身增长长度变量,蛇身增长的长度暂时不能随所吃食物大小改变而改变

#先把此标志位置‘真’是因为游戏开始时并无食物
foodbool = True    #用于判断是否有食物被吃如果有在当前食物总数小于随机食物最大个数时在产生随机个食物
foodcount = random.randint(2, 10)   #食物最大个数随机产生

#加减速操作
speedbool = False   #如果按键不能使当前方向改变则为真
speupbool = False   #如果同向真为加速，反向假为减速

fpsr = 100   #延时长度
interval = 30  #加速减速的时间间隔，即延时的时间改变长度

#载入音乐
pygame.mixer.music.load('贪吃蛇大作战.mp3')
pygame.mixer.music.play(-1, 0.0)  #循环播放音乐，第一个参数表示播放次数，第二个参数表示播放初始位置即指定开始播放的时间点
musicbool = False    #用于在窗口最小化时暂停音乐的判断,false表示音乐播放，true表示音乐停止


#把蛇身绘制成曲线，再加一个半圆的蛇头，把食物绘制成圆形
#加个游戏音效，和同向加速效果.\\\，再加个吃到食物时的音效和没吃到多少个食物就来一个大音效
#不如写一个仅撞墙才死而吃到自己身体不死的贪吃蛇，哈哈.
#蛇身绘制的圆滑一些再在蛇头加一个圆形作为蛇头.
#产生食物的个数在一定范围内随机但食物的最大个数一定.
#产生的食物不仅不能在其它食物之上也不能与其他食物重合，更不能在蛇身上.
#最小化的时候游戏暂停\\\
#增加计分（）和计时（time）显示，或者所吃食物总个数（foodsum），还有蛇当前速度（fpsr），屏幕当前的食物个数（len（food））
#增加个好看的背景，和绘制更美观的蛇身
#绘制多个形状的食物


while Sign:    #开始游戏的循环

    cls = [[0, 0], size]  # 清屏矩形坐标
    pygame.draw.rect(screen, (0, 0, 0), cls)

    if len(food) < foodcount and foodbool:      #如果没有食物信息则产生随机食物
        produce_food(food, size, random.randint(1, foodcount-len(food)), gatism)     #为了避免食物被全部吃完而又未产生新食物的情况将所有食物的随机最小值设为2
        foodcount = random.randint(2, 10)
        foodbool = False


    move_food(food)    #绘制食物

    for event in pygame.event.get():
        if event.type == pygame.QUIT:     #处理队列中的时间，同时判断事件类型，根据事件类型的不同分别做不通操作
            sys.exit()
        elif event.type == pygame.KEYDOWN:    #键盘按下事件
            if event.key == pygame.K_UP:
                if Key != 'down' and Key != 'up':
                    Keyr = Key
                    Key = 'up'
                else:                       # 前者决定是否加减速，后者用于判断是加速还是减速,kre传入按键方向，ker传入移动方向
                    speedbool = True
                    if Key == 'up':
                        speupbool = True
                    else:
                        speupbool = False
            elif event.key == pygame.K_DOWN:
                if Key != 'up' and Key != 'down':
                    Keyr = Key
                    Key = 'down'
                else:
                    # 前者决定是否加减速，后者用于判断是加速还是减速,kre传入按键方向，ker传入移动方向
                    speedbool = True
                    if Key == 'down':
                        speupbool = True
                    else:
                        speupbool = False
            elif event.key == pygame.K_RIGHT:
                if Key != 'left' and Key != 'right':
                    Keyr = Key
                    Key = 'right'
                else:
                    # 前者决定是否加减速，后者用于判断是加速还是减速,kre传入按键方向，ker传入移动方向
                    speedbool = True
                    if Key == 'right':
                        speupbool = True
                    else:
                        speupbool = False
            elif event.key == pygame.K_LEFT:
                if Key != 'right' and Key != 'left':
                    Keyr = Key
                    Key = 'left'
                else:
                    # 前者决定是否加减速，后者用于判断是加速还是减速,kre传入按键方向，ker传入移动方向
                    speedbool = True
                    if Key == 'left':
                        speupbool = True
                    else:
                        speupbool = False

        elif event.type == pygame.VIDEORESIZE:   #处理屏幕拉伸事件

            size = width, height = event.size[0], event.size[1]

            screen = pygame.display.set_mode(size, pygame.RESIZABLE)  # 设置窗口大小及窗口模式为可调
            screen.fill((0, 0, 0))  # 设置背景颜色
            pygame.display.flip()


# 更新延时，即调整蛇的移动速度
    if speedbool:
        if speupbool and fpsr - interval > 10:  # 加速
            fpsr -= interval
        elif not speupbool and fpsr + interval < 300:    #减速
            fpsr += interval
        speedbool = False
        print("当前速度：{}，".format(fpsr))

    if pygame.display.get_active():      #判断窗口是否被最小化是则停止蛇身移动否则继续移动蛇身
        up_snake(snake, Key, Keyr, Vide)   #更新蛇身属性。先要改变蛇身属性，再进行绘制，改变蛇身位置就得改变节点

    if not pygame.display.get_active() and not musicbool:    #用于在窗口最小化时暂停音乐
        pygame.mixer.music.pause()
        musicbool = True
    elif pygame.display.get_active() and musicbool:
        pygame.mixer.music.unpause()
        musicbool = False


    dr = judge_food(food, snake[1], Vide)   #传入食物坐标信息和蛇头结点信息判断蛇是否吃到食物，
    if dr:   #如果有吃到食物则利用返回的食物面积增加蛇的长度。

        foodbool = True     #每次被吃掉一个食物就重新产生随机个食物，并且食物总数也再随机一次
        foodsum += 1        #记录所吃食物总个数用于计分板显示
        kre = negation_dire(judge_dire(snake[-1], snake[-2]))      #先判断蛇尾的移动方向,再取反得到增长蛇尾的方向
        move_node(kre, snake[-1], Vide)        #再在蛇尾增加节点,即再次更新蛇尾坐标
        #此处蛇身的增长不能随食物大小而改变，可以尝试食物的面积越大而蛇身增加的越多

    print("所吃食物：{}，".format(foodsum))
    print("屏幕食物：{}，".format(len(food)))


    draw_initr(snake, Vide)                     #重新绘制蛇身，先清屏，在这个函数里面改变蛇身的节点，方向用于改变节点，速度用于绘制拐角

#    pygame.display.flip()      #刷新整个屏幕
    pygame.display.update()      #刷新像素改变部分的屏幕

    pygame.time.wait(fpsr)  # 延时函数，使程序停止一段时间





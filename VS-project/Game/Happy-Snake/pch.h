#ifndef PCH_H
#define PCH_H

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>  //光标设置API ，即贪吃蛇的移动
#include<time.h>     //随机食物
#include <conio.h>   //按键监控

constexpr auto CKKD = 76;		//窗口宽度
constexpr auto CKGD = 24;		//窗口高度;
constexpr auto SMAX = 10;		//蛇的最大节数;

struct {				//储存蛇的属性信息；
	int  x[SMAX];
	int  y[SMAX];
	int len;			 //蛇长度；
	int v;  //蛇的速度；
}snake;

struct {
	int x;   //随机食物的坐标
	int y;
}food;

int key = 'a';    //移动方向
int last = 'a';		//记录上一次的移动方向以便判断这一次移动是否加减速
int press = 0;    //记录是否按下，0表示没按下，1表示按下了

int changeFlag=0;       //食物标记，当产生新食物时即蛇吃掉一个食物时就置为1，否则就为0；
//当判断出蛇吃掉食物时，就少擦除一截即本次不擦出，如果判断出当次蛇没有吃掉食物则常态式的擦除，每次擦除一节。

void drawMap();     //画地图

void createFood();    //产生随机食物

void KeyDown();      //按键操作

int snakeStatus();				//蛇的状态

void gotoxy(int x, int y);					//光标移动

void Over();    //游戏结束的输出。

int Reverse();//判断是否反向；

void Tongue(int keys);     //根据keys移动蛇头

#endif //PCH_H

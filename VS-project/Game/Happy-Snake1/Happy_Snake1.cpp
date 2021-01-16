// Happy Snake1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 经过自己改经的贪吃蛇游戏。
// 此项目使用C++面向对象的方法实现贪吃蛇游戏
// 蛇身：○；地图：■；食物：★。
// 食物剩余时间较少时闪烁，蛇的剩余存活时间设置进度条

/*
可改进的地方：按键检测及蛇显示不及时，对于按键的响应不及时。
可增加的地方：游戏时间显示并实时刷新，设计回合制游戏
*/

#include <iostream>
#include <time.h>
#include "share.h"
#include "game.h"
#include "assistant.h"

int main()
{
	srand((unsigned)time(NULL));//设置随机数种子，如果没有这个种子，食物的出现位置将会固定

	Share share(50, 32, 41); // 设置食物有效时间， 窗口大小；

	Assistant assis(share);

	Game game(share, assis); // 传入工具类

	while (game.Start()); // 重新开始

	return 0;
}
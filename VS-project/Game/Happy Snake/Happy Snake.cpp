// 此项目实现简易版贪吃蛇游戏 
  
#include "pch.h"
//#include <iostream>

int main()
{
	drawMap();
	while (1)
	{
		createFood();
		KeyDown();
		//Sleep(snake.v);    //延时，延时时长由蛇的速度决定；
		if (!snakeStatus())
		{
			break;
		}
	}
	Over();
	system("pause");
	while (1);
	return 0;
}





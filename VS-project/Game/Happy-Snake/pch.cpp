#include "pch.h"

//■○蛇身和食物

void drawMap()
{
	srand((unsigned int)time(NULL));   //随机函数种子
	for (int i = 0; i <= CKGD; i++)
	{ 
		gotoxy(0, i);
		printf("■");
		gotoxy(CKKD, i);
		printf("■");
	}
	for (int i = 0; i <= CKKD; i+=2)
	{
		gotoxy(i, 0);
		printf("■");  //■占用两个字符。
		gotoxy(i, CKGD);
		printf("■");
	}


	snake.len = 3;			//初始化蛇身的节数
	snake.v = 300;			//初始化蛇身速度
	snake.x[0] = CKKD / 2;  //初始化蛇头坐标
	snake.y[0] = CKGD / 2;
	
	gotoxy(snake.x[0], snake.y[0]);
	printf("■"); 
	for (int k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1]+2;
		snake.y[k] = snake.y[k - 1];
		gotoxy(snake.x[k], snake.y[k]);
		printf("■");
	}
	do
	{
		food.x = rand() % ((CKKD)-4) + 2;
		food.y = rand() % ((CKGD)-2) + 1;
	}while (food.x % 2);   //初始食物
	gotoxy(food.x, food.y);
	printf("○");
}
//画地图,画食物，画蛇身

void createFood()
{
	if (snake.x[0] == food.x&&snake.y[0] == food.y)
	{
		srand((unsigned int)time(NULL));
		while (1)
		{
			int flag = 1;
			food.x = rand() % (CKKD - 4) + 2;
			food.y = rand() % (CKGD - 2) + 1;
			for (int k = 0; k < snake.len; k++)
			{
				if (snake.x[k] == food.x&&snake.y[k] == food.y)
				{
					flag = 0;
					break;
				}
			}
			if (flag&&food.x%2==0)
				break;
		}
		snake.len++;
	/*	snake.x[snake.len] = snake.x[snake.len-1];
		snake.y[snake.len] = snake.y[snake.len - 1];*/	
		changeFlag = 1;
		gotoxy(food.x, food.y);
		printf("○");
	}
}
//产生随机食物

void KeyDown()
{
	//printf("%d ", snake.len);
	if (_kbhit())  //检查键盘是否有输入值
	{
		fflush(stdin);    //清空键盘输入缓存区
		key = _getch();  //获取键盘输入
		press = 1;
	}
	if (!changeFlag)
	{
	gotoxy(snake.x[snake.len-1], snake.y[snake.len-1]);
	printf("  ");
	}
	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}
	if (key == last && press)			//如果键盘按下并且按下的键与上次相同则增加速度
	{
		snake.v -= 50;    
		Tongue(key);
		last = key;
	}
	else if (press && Reverse())  //如果键盘按下但不与上次按下相同则判断与上次按下是否相反
	{
		snake.v += 50;
		Tongue(last);
		key = last;   
	}
	else   //如果没按下键盘或者按下的与上次既不相同也不想反时执行此项
	{
		Tongue(key);
		last = key;
	}
	press = 0;
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
	changeFlag = 0;
	gotoxy(CKGD+2,0);
	Sleep(snake.v);
}
//按键操作

int snakeStatus()
{
	if ((snake.x[0] == 0 || snake.x[0] == CKKD)||( snake.y[0] == 0 || snake.y[0] == CKGD))   //当蛇头与墙壁重合时结束游戏
		return 0;
	for (int k = 1; k < snake.len; k++)
		if (snake.x[0] == snake.x[k] && snake.y[0] == snake.y[k])   //当蛇头与蛇身任何一部分重合时结束游戏
			return 0;
	if (snake.len >= SMAX)     //如果蛇的长度等于最大长度时退出游戏
		return 0;
	return 1;
}
//蛇的状态

void gotoxy(int x, int y)
{
	HANDLE  handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
//光标移动

void Over()   //游戏结束输出
{
	if (snake.len == SMAX)
	{
		gotoxy(CKKD / 2-8, CKGD / 2);
		printf("牛逼啊，老兄！");
	}
	else
	{
		gotoxy(CKKD / 2-8, CKGD / 2);
		printf("Game over!");
	}
}

int Reverse()		//判断是否反向；
{
	int i = 0;
	switch (key)
	{
	case 'W':
	case 'w':
		(last == 's' || last == 'S') ? i = 1 : i = 0;
		break;
	case 'S':
	case 's':
		(last == 'w' || last == 'W') ? i = 1 : i = 0;
		break;
	case 'A':
	case 'a':
		(last == 'd' || last == 'D') ? i = 1 : i = 0;
		break;
	case 'D':
	case 'd':
		(last == 'a' || last == 'A') ? i = 1 : i = 0;
		break;
	}
	return i;
}


void Tongue(int keys)     //根据keys移动蛇头
{
	switch (keys)
	{
	case 'w':
	case 'W':
		snake.y[0]--;
		break;
	case 's':
	case 'S':
		snake.y[0]++;
		break;
	case 'A':
	case 'a':
		snake.x[0] -= 2;
		break;
	case 'd':
	case 'D':
		snake.x[0] += 2;
		break;
	}
}
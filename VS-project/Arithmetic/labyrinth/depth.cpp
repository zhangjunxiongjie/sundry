//pragma once
//使用深度优化算法走迷宫
//1:墙■，0:可以经过的地方◇，8,2,4,6：已经经过的地方↑↓← →不同方向使用不同符号，-1：终点☆,5：成功：○ 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define X 10
#define Y 10

void Output(int mazer[][Y]);    //输出地图信息


bool Depth_optimizer(int mazer[][Y], int x, int y);   //传入盘面和入口地址，深度优化探索迷宫

int a[4][3] = { {0,1,2}, {1,0,6}, {-1,0,4}, {0,-1,8} };   //2,6,4,8，转向。

void main()
{
	int i = 0, j = 0;
	int maze[X][Y]{
		{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 0, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
		{ 1, 1, 1, 0, 1, 1, 0, 0, 1, -1}
	};

	Output(maze);

	if (Depth_optimizer(maze, i, j))
		Output(maze);


	system("Pause");   //调用DOS命令暂停程序

}

bool Depth_optimizer(int mazer[][Y], int x, int y)   //传入盘面和上一次地址
{
	int i;
	if (mazer[x][y] == -1)
	{
		mazer[x][y] = 5;
		return true;
	}

	if (x == 0 && y == 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (((x + a[i][1]) >= 0 && (x + a[i][1]) < X) && ((y + a[i][0]) >= 0 && (y + a[i][0]) < Y) && ((mazer[(x + a[i][1])][(y + a[i][0])] == 0) || (mazer[(x + a[i][1])][(y + a[i][0])] == -1)))
			{
				mazer[x][y] = a[i][2];
				Output(mazer);
				if (Depth_optimizer(mazer, x + a[i][1], y + a[i][0]))
					return true;
				mazer[x][y] = 0;
			}
		}
	}
	
	//这里的x，y并不是真的x轴y轴，搞反了。。。真他妈操蛋
	//还有一个地方有点问题！！！
	//原来最后一个问题是在判断下一个点是否能走时没有加入终点及不仅0：◇可以走，-1：☆也可以走。 

	else
	{
		for (i = 0; i < 4; i++)
		{
			if (((x + a[i][1]) >= 0 && (x + a[i][1]) < X) && ((y + a[i][0]) >= 0 && (y + a[i][0]) < Y) && ((mazer[(x + a[i][1])][(y + a[i][0])] == 0) || (mazer[(x + a[i][1])][(y + a[i][0])] == -1)))
			{
				mazer[x][y] = a[i][2];
				Output(mazer);
				if (Depth_optimizer(mazer, x + a[i][1], y + a[i][0]))
					return true;
				mazer[x][y] = 0;    //还原初始状态
			}
		}
	}
	return false;
}


void Output(int mazer[][Y])   //函数定义
{
	int i, j;
	system("cls");        //用于清屏覆盖输出
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (mazer[i][j] == 1)
				printf("■");
			else if (mazer[i][j] == 2)
				printf("↓");
			else if (mazer[i][j] == 4)
				printf("←");
			else if (mazer[i][j] == 6)
				printf("→");
			else if (mazer[i][j] == 8)
				printf("↑");
			else if (mazer[i][j] == 0)
				printf("◇");
			else if (mazer[i][j] == -1)
				printf("☆");
			else if (mazer[i][j] == 5)
				printf("○");
		}
		printf("\n");
	}
	printf("\n");
}

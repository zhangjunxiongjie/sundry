//使用广度优先搜索地图中的所有岛屿。
//岛屿使用数组模拟。
//-1:已探索岛屿①②③④⑤⑥⑦⑧⑨⑩，0:海洋◇，1：未探索岛屿：○ 

//可以再新建两个项目用广度优先探索迷宫，而使用深度优化搜索岛屿。


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define X 10
#define Y 10

int COUNT = -1;     //对当前岛屿数做标记

int a[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };   //2,6,4,8，转向。

typedef struct coordinates {
	int x;
	int y;
}coor;    //坐标结构体，重命名

struct queue {     //这里队列空间是一个坐标结构体
	coor container[20];    //队列空间，取决于队列的最大大小，即岛屿最大大小，这里每个岛屿后都需要将队列清零及将头尾指针指向队列开始
	int tail = 0;   //队列尾指针，当头指针与尾指针相同时队列为空
	int head = 0;
}QUE;    //定义队列变量。


void Dreadth_first(int mazer[][Y]);    //进行搜索的函数
void Output(int mazer[][Y]);    //输出函数

void main()
{
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
		{ 1, 1, 1, 1, 1, 1, 0, 0, 1, 0 }
	};
	Output(maze);

	Dreadth_first(maze);    //广度优先算法搜索岛屿。

	Output(maze);
	system("Pause");   //调用DOS命令暂停程序
}

void Dreadth_first(int mazer[][Y])   //双重队列？？？一个队列存储每一个岛屿的一个引子，另一个队列对每个引子进行探索但是相同的问题却做的更复杂了
{
	int i, j, z;
	int xr, yr;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (mazer[i][j] == 1)
			{

				QUE.container[QUE.tail].x = i;
				QUE.container[QUE.tail].y = j;
				QUE.tail++;
				mazer[i][j] = COUNT;
				while (QUE.tail != QUE.head)
				{
					for (z = 0; z < 4; z++)
					{
						xr = QUE.container[QUE.head].x + a[z][0];
						yr = QUE.container[QUE.head].y + a[z][1];
						//printf("%d-%d=%d\n",xr,yr,mazer[xr][yr]);
						if (xr < 10 && xr >= 0 && yr < 10 && yr >= 0 && mazer[xr][yr] == 1)
						{
							mazer[xr][yr] = COUNT;
							QUE.container[QUE.tail].x = xr;
							QUE.container[QUE.tail].y = yr;
							QUE.tail++;
						}
					}
					QUE.head++;
					//printf("%d,%d\n",QUE.tail, QUE.head);
				}
				QUE.tail = 0;
				QUE.head = 0;
				COUNT--;
			}
		}
	}
}








void Output(int mazer[][Y])
{
	int i, j;
	system("cls");        //用于清屏覆盖输出
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			switch(mazer[i][j])
			{
			case 0:printf("◇"); break;
			case 1:printf("○"); break;
			case -1:printf("①"); break;
			case -2:printf("②"); break;
			case -3:printf("③"); break;
			case -4:printf("④"); break;
			case -5:printf("⑤"); break;
			case -6:printf("⑥"); break;
			default:printf("⑩");
			}
		}
		printf("\n");
	}
}
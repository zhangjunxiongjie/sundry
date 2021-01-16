//pragma once
//ʹ������Ż��㷨���Թ�
//1:ǽ����0:���Ծ����ĵط���8,2,4,6���Ѿ������ĵط������� ����ͬ����ʹ�ò�ͬ���ţ�-1���յ��,5���ɹ����� 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define X 10
#define Y 10

void Output(int mazer[][Y]);    //�����ͼ��Ϣ


bool Depth_optimizer(int mazer[][Y], int x, int y);   //�����������ڵ�ַ������Ż�̽���Թ�

int a[4][3] = { {0,1,2}, {1,0,6}, {-1,0,4}, {0,-1,8} };   //2,6,4,8��ת��

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


	system("Pause");   //����DOS������ͣ����

}

bool Depth_optimizer(int mazer[][Y], int x, int y)   //�����������һ�ε�ַ
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
	
	//�����x��y���������x��y�ᣬ�㷴�ˡ�����������ٵ�
	//����һ���ط��е����⣡����
	//ԭ�����һ�����������ж���һ�����Ƿ�����ʱû�м����յ㼰����0��������ߣ�-1����Ҳ�����ߡ� 

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
				mazer[x][y] = 0;    //��ԭ��ʼ״̬
			}
		}
	}
	return false;
}


void Output(int mazer[][Y])   //��������
{
	int i, j;
	system("cls");        //���������������
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (mazer[i][j] == 1)
				printf("��");
			else if (mazer[i][j] == 2)
				printf("��");
			else if (mazer[i][j] == 4)
				printf("��");
			else if (mazer[i][j] == 6)
				printf("��");
			else if (mazer[i][j] == 8)
				printf("��");
			else if (mazer[i][j] == 0)
				printf("��");
			else if (mazer[i][j] == -1)
				printf("��");
			else if (mazer[i][j] == 5)
				printf("��");
		}
		printf("\n");
	}
	printf("\n");
}

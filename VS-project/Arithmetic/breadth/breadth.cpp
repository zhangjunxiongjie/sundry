//ʹ�ù������������ͼ�е����е��졣
//����ʹ������ģ�⡣
//-1:��̽������٢ڢۢܢݢޢߢ��⣬0:�����1��δ̽�����죺�� 

//�������½�������Ŀ�ù������̽���Թ�����ʹ������Ż��������졣


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define X 10
#define Y 10

int COUNT = -1;     //�Ե�ǰ�����������

int a[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };   //2,6,4,8��ת��

typedef struct coordinates {
	int x;
	int y;
}coor;    //����ṹ�壬������

struct queue {     //������пռ���һ������ṹ��
	coor container[20];    //���пռ䣬ȡ���ڶ��е�����С������������С������ÿ���������Ҫ���������㼰��ͷβָ��ָ����п�ʼ
	int tail = 0;   //����βָ�룬��ͷָ����βָ����ͬʱ����Ϊ��
	int head = 0;
}QUE;    //������б�����


void Dreadth_first(int mazer[][Y]);    //���������ĺ���
void Output(int mazer[][Y]);    //�������

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

	Dreadth_first(maze);    //��������㷨�������졣

	Output(maze);
	system("Pause");   //����DOS������ͣ����
}

void Dreadth_first(int mazer[][Y])   //˫�ض��У�����һ�����д洢ÿһ�������һ�����ӣ���һ�����ж�ÿ�����ӽ���̽��������ͬ������ȴ���ĸ�������
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
	system("cls");        //���������������
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			switch(mazer[i][j])
			{
			case 0:printf("��"); break;
			case 1:printf("��"); break;
			case -1:printf("��"); break;
			case -2:printf("��"); break;
			case -3:printf("��"); break;
			case -4:printf("��"); break;
			case -5:printf("��"); break;
			case -6:printf("��"); break;
			default:printf("��");
			}
		}
		printf("\n");
	}
}
/*使用下面这种方式显示二叉树：
	  _____4_____
	 |           |
   __5__       __8__
  |	    |     |     |
 _1_   _3_   _2_   _9_
|   | |   | |   | |   |
1   2 3   4 5   6 7   8

*/
/*
有待优化。
程序基本成形，但问题还多，打印空格可以单独拿出来做成一个模块。
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 30
int tree[N] = { 8,1,3,2,6,8,8,1,3,2,6,8,1,3,2,5,0,2,1,6,8,1,3,2,6,8,8,1,3,2 };
int Coun = 0;   //链表级数
int Conu;   //最后一层的元素最大个数


struct MyStruct
{
	int tail = 0;
	int list[N*2][2];   //一个用来存储每个数字的下标，一个用来存储数字周围辅助字符的个数
	int hear = 0;
}Box;  //存储每个数字字符的位置信息，对应层的符号字符位置信息可以由本层的数字字符位置得到。


void Calcul()   //使用N计算链表的级数
{
	int Nr = 1;  //存储Coun级数对应的总的数字个数
	while (Nr < N + 1)
	{
		Nr *= 2;
		Coun++;
	}
	Conu = Nr / 2;
}

void printfr(int tr, int ty)   //用于打印数字每行的'_'，传入起始位置及符号个数。
{
	int i;
	printf("\r");//因为是从后往前输出所以每次输出时都要从每行的起始位置开始输出。
	for (i = 0; i < tr; i++)
		printf(" ");
	for (i = 0; i < ty; i++)
		printf("_");
}

void printfd()//用于打印‘|’辅助符。
{
	int Tr = Box.hear,Ty=Box.tail;
	int i;
	for (; Tr < Ty; Tr++)
	{
		printf("\r");
		for (i = 0; i < Box.list[Tr][0]; i++)
			printf(" ");
		printf("|");
	}
}



int main()
{
	int Ntt = 0;   //当前级数
	int Ji = 1;  //每级数字个数
	int Hi;     //Ntt层对应的最大数字个数
	int i = 0, j;
	Calcul();
	Box.list[Box.tail][0] = (Conu / 2 * 5 + Conu / 2 - 2) / 2;   //第一层的字符位置。
	Box.list[Box.tail][1] = (Box.list[Box.tail][0] - 1) / 2;
	Box.tail++;
	while(Ntt < Coun)  //级数
	{
		Hi = int(pow(2.0, Ntt));
		for (i = Ji - 1; i >= Ji - Hi; i--)   //每级的数字个数
		{
			if (N > (i + 1) * 2)   //如果当前输出数字的左边有数字则输出辅助符
			{
				printfr(Box.list[Box.hear][0] + 1, Box.list[Box.hear][1]);
				Box.list[Box.tail][0] = Box.list[Box.hear][0] + Box.list[Box.hear][1] + 1;
				if (0 == (Box.list[Box.hear][1] - 1) / 2)
					Box.list[Box.tail][1] = 1;
				else
					Box.list[Box.tail][1] = (Box.list[Box.hear][1] - 1) / 2;
			
				Box.tail++;
			}
	
			//Sleep(300);
			if (N > i)   //如果当前输出的数字不为空即存在
			{
				printf("\r");
				for (j = 0; j < Box.list[Box.hear][0]; j++)    //可以试着把输出空格的部分提出来作为一个模块
					printf(" ");
				Box.hear++;
				printf("%d", tree[i]);
			}
			//Sleep(300);
			//printf("N=%d,(i + 1) * 2 - 1=%d", N, (i + 1) * 2 - 1);
			//Sleep(300);
			if (N > (i + 1) * 2 - 1)  //如果当前输出数字的右边有数字则输出辅助字符
			{
				printfr(Box.list[Box.hear - 1][0] - Box.list[Box.hear - 1][1], Box.list[Box.hear - 1][1]);
				Box.list[Box.tail][0] = Box.list[Box.hear - 1][0] - Box.list[Box.hear - 1][1]-1;
				if (0 == (Box.list[Box.hear - 1][1] - 1) / 2)
					Box.list[Box.tail][1] = 1;
				else
					Box.list[Box.tail][1] = (Box.list[Box.hear - 1][1] - 1) / 2;
				Box.tail++;
			}
			//Sleep(300);
		}
		printf("\n");
		printfd();
		printf("\n");
		Ji = 2 * Ji + 1;  //每输出一级下一级的数字增加一倍
		Ntt++;
	}

	system("Pause");   //调用DOS命令暂停程序
	return 0;
}

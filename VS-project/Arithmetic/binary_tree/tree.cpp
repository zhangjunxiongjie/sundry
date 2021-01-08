//尝试绘出使用数组模拟的二叉树
//二叉树的级数越多上层的‘/’越多越到下层越少倒数第一层时只有一个,每层下方的‘/\’符号等于总级数减当前级数
//“/\”符号的位置有上一层的数坐标决定，第几层相应的坐标为上一层数减符号层数
//"/\"符号始终是其上层数字的两倍且多层不变
//每一层的不管数字还是符号当层的坐标都由上一层决定
//需要先根据级数计算最后一层占位进而计算第一级的占位，
//可以使用队列没结束一个字符的输出就添加下一层对应的坐标信息。

/*现在还有两个主要问题：
一个是每一层数字下的“/\”符号的层数还没有调整好，每增加一层二叉树第一层下方或者其他层的字符层数并不是增加一层，增加一层并不足够需要综合考量。
另一个问题就是列表大小的定义，应该随级数增加而增加但是与级数是一个什么关系还需要综合考量
*/

/*
经过改进第一个问题即每层数字下面的字符层数问题已经得到解决：起初我想着字符层数应该由当前级数和总的级数决定；
后来在网上看到二叉树的另一种表示（即下面那种）后想到每一级的字符层数应该是紧邻的上一层的第一个数字前空格的一半（观察得到）
这里每一级的字符层数即为下一级数字和本级数字之间的（横向）间隔而下一级数字与本级数字的（横向）间隔应该为本级前面空格的一半。
或者说下一级数字应该位于本级数字至起始位置的中间。（因为每一级均左右对称这里主要叙述最左端数字的位置）
*/

/*
			     4
				/ \
			   /   \
			  /		\	 
			 5       8
			/ \     / \
		   1   3   2   9
	 	  /	    \ /     \
	                 

     / \   / \   / \   / \
	1   2 3   4 5   6 7   8
*/
/*网上看到了另一种直观显示二叉树的方法：
	  _____4_____  
     |           |
   __5__       __8__
  |	    |     |     |
 _1_   _3_   _2_   _9_
|   | |   | |   | |   |
1   2 3   4 5   6 7   8

另外建一个项目实现一下。
*/

/*
经过改进程序基本成形但任有优化的地方：
①，适当改进使程序能适应多位数字的二叉树值，输出做到依然美观。
②，
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


#define N 60

struct Que {
	int qu[N * 10];    //这里之所以要乘以十是因为这个结构体要存储每一层字符的位置信息，并不只是数字字符。
	int hear=0;  //头
	int tail=0;   //尾
}Rue;
int Coun = 0;   //链表级数
int Conu;   //最后一层的元素最大个数

int tree[N] = { 8,1,3,2,6,8,8,1,3,2,6,8,1,3,2,5,0,2,1,6,8,1,3,2,6,8,8,1,3,2,8,1,3,2,6,8,8,1,3,2,6,8,1,3,2,5,0,2,1,6,8,1,3,2,6,8,8,1,3,2 };   //先简单尝试绘制一个三级二叉树

void Calcul()   //使用N计算链表的级数
{
	int Nr=1;  //存储Coun级数对应的总的数字个数
	while (Nr < N+1)
	{
		Nr *= 2;
		Coun++;
	}
	Conu = Nr / 2;
}

void printd(int Nr)
{
	int j;
	printf("\r");
	for (j = 0; j < Rue.qu[Rue.hear]; j++)   //输出空格
	{
		printf(" ");
	}
	printf("%d", Nr);
	Rue.qu[Rue.tail] = Rue.qu[Rue.hear] + 1;
	Rue.tail++;
	Rue.qu[Rue.tail] = Rue.qu[Rue.hear] - 1;
	Rue.tail++;
	Rue.hear++;
}

void printc(int Nr)
{
	int j;
	printf("\r");
	for (j = 0; j < Rue.qu[Rue.hear]; j++)   //输出空格
	{
		printf(" ");
	}
	Rue.hear++;
	printf("%c", Nr);
	
}


int main()
{
	int i, j;
	int Ji,Hi;
	int Ntt=0;   //链表数组下标；
	int Zi;    //每一级的辅助字符层数为上一层的一半
	Calcul();
	Rue.qu[Rue.tail] = (Conu / 2 * 5 + Conu / 2 - 1)/2;   //第一层字符位置
	Rue.tail++;
	Ji = 1;    //当前级数
	while (Ntt < N)   //一次将一行数字即其下所有字符辅助输出
	{
		Hi = int(pow(2.0, Ji - 1));
		for (i = Hi - 1; i >= 0; i--)  //确定输出的数字个数
		{
			if (Ntt + i < N)
				printd(tree[Ntt + i]);
			else
				Rue.hear++;
			//Sleep(1000);
		}
		Ntt+=Hi;   //链表下标。
		printf("\n");
		if (Ntt < N)
		{

			//控制每一层的字符层数
			if (Ntt == 1)
				Zi = Rue.qu[Rue.hear] / 2-1;
			else
				Zi = Zi / 2;
			for (j=0; j < Zi; j++)//确定输出字符辅助的行数
			{
				for (i = Hi; i > 0; i--)   //输出一行的辅助符号
				{
					//Sleep(1000);
					if (N - Ntt >= i * 2)
						printc('\\');
					else
						Rue.hear++;
					Rue.qu[Rue.tail] = Rue.qu[Rue.hear - 1] + 1;
					Rue.tail++;
					if (N - Ntt >= i * 2 - 1)
						printc('/');
					else
						Rue.hear++;
					Rue.qu[Rue.tail] = Rue.qu[Rue.hear - 1] - 1;
					Rue.tail++;
					//Sleep(1000);
				}
				printf("\n");
			}
		}
		Ji++;
	}
	system("Pause");   //调用DOS命令暂停程序
	return 0;
}
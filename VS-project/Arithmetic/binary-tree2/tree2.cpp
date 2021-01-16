//这一版本用于对binary_tree进行完全重构，使原先的程序能够适应多位的整数。
//至此，能够适应节点数值不同位数的二叉树可视化程序基本完成。

/*
这里存在一个很致命的问题那就是上层根节点的数值位数实际上是受到下层子树根节点限制了的，这是这种设计方法不可避免的缺陷，唯一都能够彻底解决问题的办法是完全的重构
需要改变所有根节点和叶节点的计算方法，使其既能够自上而下的由上方节点改变下方节点的输出参数，也要能够自下而上的由下方节点改变上方节点的输出参数。
这里不再继续深究，只待将来能够实现更健壮更完善的二叉树可视化。
*/

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
1-n层;
1.自上而下求最上层的头部位置。首先要先将所有数字放入队列，遍历队列，一次求得每一个数的位数，然后根据头节点的下面以及其自身的数字位数判断头结点位置。
递归的过程，求上层头结点位置要依据下层头结点以及叶子节点和自身节点。一个递归要根据这些要素求得所有的数值位置。要注意的是叶结点不满的情况。
2.根据头结点位置求得‘_’‘|’两个符号的位置，要注意的是要从后往前开始输出而不能从前往后因为后者会掩盖前面的输出内容。
3.递归得到的头结点以及叶节点位置应该是开始输出的位置。
*/

/*
不对思路不对，应该先计算出所有的节点数值位数，然后自上向下依据节点下面的子树以及叶节点求得节点输出起始位置，然后再根据节点起始位置判断_|两种符号的起始位置。
要注意的是左子节点（或子树）在出现双数位时应该向后靠，而右子节点（子树）在出现双数位时应该向前靠，这是为了避免前面的子树的叶节点与其后面的子树的叶节点靠在一起。
因为两颗最小子树的叶结点之间只相隔一个空格，而同一最小子树的两个叶节点之间相隔三个节点。
树的显示辅助符号|_的输出位置应该由其下面节点以及紧邻节点的位置确定，而不应该跟树的级数挂钩？
*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 30
int tree[N] = { 128,2,45693,-68,789,2,123,31223,245,-62,-18,10,1,31,821,1,3,2,5,150,2,31,6,36,-4,4747,45,5,-345645456,345 };
//int tree[N] = { 81,123,3,12,4,561 };

int series_num;  //存储二叉树总的级数。

struct XY_place {
	int XY;			//节点的开始输出位置
	int Place;      //对应节点的数值位数
//	int Left_wide;   //左右的宽，用于计算后面根节点的开始输出位置。
//	int Right_wide;
}Node[N * 2];//为了避免最后一层缺项但是又要使用下一层的XY成员故这里取了两倍。

int Node_Place(int Node_number)  //传入节点的数值，返回节点的数值位数，包括负号。
{
	int count = 0;
	int sign = 0;
	if (Node_number < 0)
	{
		sign = 1;
		Node_number = -Node_number;
	}
	else if (Node_number == 0)
		return 1;
	while (Node_number > 0)
	{
		Node_number /= 10;
		count++;
	}
	if (sign)   //如果数值为负数符号也算在位数里面。
		return count + 1;
	else
		return count;
	
}

int Node_Number(int series)  //返回传入级数的理论（最大）节点个数
{
	int count = 1;
	if (series == 1)
		return 1;
	while (series > 1)
	{
		count *= 2;
		series--;
	}
	return count;
}

int Series_initial(int series)//传入级数返回当前级数对应的第一个元素的位置。
{

	int count = 0;
	for (int i = 1; i < series; i++)
	{
		count += Node_Number(i);
	}

	return count;
}

int Series_Number(int Nr)   //给入数组大小求得数组组成二叉树的级数
{
	int count = 1;  //从第一级开始,至少一级
	for (int number = 1; number < Nr; )//要注意的是N是数组总的元素个数，而非其它。
	{
		count++;
		number += Node_Number(count);
	}

	return count;
}

//传入当前计算的节点输出位置的层数
//在计算倒数第二层时将倒数第一层一起计算了，要满足如下条件：
//1.根节点的开始输出位置与左叶节点的末尾相隔一个空格；
//2.根节点结束输出位置与右叶节点的开始输出位置相隔一个空格；
//3.两个子树之间的叶节点开始位置和结束位置相隔一个空格；
//4.上层根节点的位置置于两个子树根节点的中间位置；
//5.|_两个符号前者始终位于某一节点中间位置的上方，而后者位于前者符号和之后第一个节点的开始位置之间。
//6.当数组元素组成的二叉树不是满二叉树时缺项按一位数值计算。
void Node_XY(int series)//只计算倒数第二层开始向上的子树根节点的开始输出位置。最后一层特殊处理（最后处理），容错性检查保证只有一层或者两层时仍正确输出。
{
	int ser_init = Series_initial(series);   //得到当前层的第一个元素下标
	if (series == series_num - 1)//如果当前计算的是倒数第二层的节点开始输出的位置。那么就得特殊计算
	{
		for (int i = ser_init; i < ser_init + Node_Number(series); i++)//给每一个元素计算开始输出位置
		{
			if (i == ser_init)//计算第一个位置
			{
				
				if(i * 2 + 1 < N && i * 2 + 2 >= N)  //如果只缺后一项
				{
					Node[i * 2 + 2].Place = 1;  //对于缺项在发现时就将缺项的初值赋上，因为计算后面节点时可能会用到
				}
				else  if(i * 2 + 1 >= N && i * 2 + 2 >= N)//两项都缺的情况
				{

					Node[i * 2 + 1].Place = 1;
					Node[i * 2 + 2].Place = 1;
				}

				Node[i * 2 + 1].XY = 0;  //最后一层第一个节点起始位置为零,左子节点的起始位置
				
			}
			else//计算倒数第二层后面节点的输出起始位置。
			{

				if (i * 2 + 1 < N && i * 2 + 2 >= N)
				{
					Node[i * 2 + 2].Place = 1;
				}
				else if(i * 2 + 1 >= N && i * 2 + 2 >= N) //两项都缺的情况
				{

					Node[i * 2 + 1].Place = 1;
					Node[i * 2 + 2].Place = 1;
				}
				Node[i * 2 + 1].XY = Node[i * 2 + 1 - 1].XY + Node[i * 2 + 1 - 1].Place + 1;//下一棵树的子节点与前一棵树的子节点之间相隔一个空格

			}
			Node[i].XY = Node[i * 2 + 1].XY + Node[i * 2 + 1].Place + 1;//根节点的起始位置。
			Node[i * 2 + 2].XY = Node[i].XY + Node[i].Place + 1;//右子节点的起始位置。
		}
	}
	else
	{
		for (int i = ser_init; i < ser_init + Node_Number(series); i++)//如果不是倒数第二层那么就不用将第一个位置拿出来特殊对待
		{
			int middle = ((Node[2 * i + 2].XY + Node[2 * i + 2].Place / 2) - (Node[2 * i + 1].XY + Node[2 * i + 1].Place / 2)) / 2; //先计算出中间位置。

			Node[i].XY = Node[2 * i + 1].XY + Node[2 * i + 1].Place / 2 + middle - Node[i].Place / 2;  
//这里存在一个很致命的问题那就是上层根节点的数值位数实际上是受到下层子树根节点限制了的，这是这种设计方法不可避免的缺陷，唯一都能够彻底解决问题的办法是完全的重构
//需要改变所有根节点和叶节点的计算方法，使其既能够自上而下的由上方节点改变下方节点的输出参数，也要能够自下而上的由下方节点改变上方节点的输出参数。
//这里不再继续深究，只待将来能够实现更健壮更完善的二叉树可视化。
		}
	}
}

void Printf_null(int number)//打印number个空格
{
	for (; number > 0; number--)
	{
		printf(" ");
	}
}

void Printf_across(int number,int sign)//绘制横竖
{
	
	for (; number > 0; number--)
	{
		if (sign < N)
			printf("_");
		else	
			printf(" ");
	}
	
}
/*
void Printf_vertical(int number)//绘制竖
{
	for (; number > 0; number--)
	{
		printf("|");
	}
}
*/
void Printf_sign(int sign)//传入当前节点的元素下标绘制节点以及_|符号，当绘制到最后一层时特殊处理。
{
	
	printf("\r"); //从每行的起始位置开始打印
		
	int init = Node[2 * sign + 1].XY + Node[2 * sign + 1].Place / 2 + 1;
	Printf_null(init);//打印空格
	Printf_across(Node[sign].XY - init, 2 * sign + 1);//绘制横
	printf("%d",tree[sign]);
	Printf_across(Node[2 * sign + 2].XY + Node[2 * sign + 2].Place/2 - Node[sign].XY - Node[sign].Place, 2 * sign +2);//绘制横
	
	
}

void Printf_sign1(int sign)//传入当前节点的元素下标绘制节点以及_|符号，当绘制到最后一层时特殊处理。
{

	printf("\r"); //从每行的起始位置开始打印
	Printf_null(Node[sign].XY);//打印空格
	printf("%d", tree[sign]);

}
void Printf_sign2(int sign)
{
	printf("\r");
	Printf_null(Node[sign].XY + Node[sign].Place/2);
	printf("|");
}

void Tree_Draw()//使用前面得到的起始输出位置，对二叉树进行绘制。
{
	for (int i = 1; i <= series_num;i++)//级数
	{

		if (i < series_num)
		{
			for (int j = Series_initial(i) + Node_Number(i) - 1; j >= Series_initial(i); j--)//绘制每一个节点，从后往前开始绘制。
			{
				Printf_sign(j);

			}

			printf("\n");

			for (int j = Series_initial(i + 1) + Node_Number(i + 1) - 1; j >= Series_initial(i + 1); j--)
			{
				if(j < N)
					Printf_sign2(j);
			}
			
		}
		else
		{
			for (int j = Series_initial(i) + Node_Number(i) - 1; j >= Series_initial(i); j--)//绘制每一个节点，从后往前开始绘制。
			{
				if (j < N)
					Printf_sign1(j);
			}
		}
		printf("\n");
	}
}


void Node_main()    //这个函数用于得到每一个节点的开始输出的位置和没一个节点的数值位数，先计算每一个节点的数值位数然后自下而上的计算每一个节点的输出位置
{
	
	for (int i = 0; i < N; i++)  //先计算出每一节点的数值位数
	{
		Node[i].Place = Node_Place(tree[i]);
	}
	series_num = Series_Number(N);  //由数组元素个数得到组成的二叉树的级数。
	
	//printf("%d", Series_Number(N));
	
	/*
	for (int i = 1; i <= series_num; i++)
		printf("%d:", Series_initial(i));
	*/
	
	for (int i = series_num - 1; i >= 1 ; i--)
	{
		Node_XY(i);
	}
	
	/*
	for (int i = 0; i < N; i++)
	{
		printf("%d:%d\n", Node[i].XY,Node[i].Place);
	}
	*/

	Tree_Draw();  //进行二叉树的绘制。

}


int main()
{
	/*数值位数函数调试
	for (int i = 0; i < 10; i++)
		printf("%d:",Node_Place(tree[i]));
	*/
	/*根据级数求最大节点个数调试
	for (int i = 1; i < 10; i++)
	{
		printf("%d:", Node_Number(i));
	}
	*/
	Node_main();


	/*
	for (int i = 0; i < N; i++)
		printf("%d:", Node[i].Place);
	*/

	system("Pause");   //调用DOS命令暂停程序
	return 0;
}


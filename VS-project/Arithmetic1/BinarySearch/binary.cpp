//这个项目用于建立一个应用二分查找的项目。
//程序建立有序序列，因为是有序的那么无可避免的使用二分查找就是一个不二的选择
//程序持续建立有序数组，在加入新数值时使用二分查找（这里实现多种查找算法）查找插入位置。
//输入任意个数的任意数字然后以多余空格或者换行结束输入。

//实现了多种数值查找算法（顺序查找，级数查找，二分查找）。


//始终都存在输入几个数之后就不能再输入的问题？？？为什么怎么回事？？？
//问题出在二分查找返回插入索引那！！！
//问题已解决是二分查找那可能的情况比较多有几种情况没有想到！

//实现上有三个调用函数，一个用于查找插入位置，另一个用于将后续数值整个后移，一个用于输出整个序列。
//加了一个输入函数



#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct //定义一个输入函数返回的结构体
{
	bool execute = false;
	int temporary_get;
}Returned;


Returned scanf_r()
{
	Returned result;
	char temporary_char;
	int sign = 0, temporary_result = 0;

	//bool flag = false;
	//如果考虑容错那就要复杂得多了，这里不考虑容错，数字间值有一个空格或者换行
	for (int i = 0; ((temporary_char = getchar()) >= '0' && temporary_char <= '9') || temporary_char == '-'; i++) //容错性较差，数字与数字之间只能有一个空格或者一个换行符
	{
		result.execute = true;//如果没有进入这个循环就结束了这个输入函数则直接判定为输入失败。
		//temporary_str[i] = temporary_char;
		if (temporary_char == '-')
			sign = 1;
		else
		{
			temporary_result = temporary_result * 10 + temporary_char - 48;
		}
	} 

	if (sign)
		result.temporary_get = 0 - temporary_result;
	else
		result.temporary_get = temporary_result;

	return result;
}


//直到左值比target小，右值比target大且左右值差一。或者找到相同值时。
int dichotomy_find(const int* it, const int target)//这个函数用于返回插入位置
{
	int result;
	int left = 1, right = it[0] - 2; //最后一个数是待插入的数
	bool flag = true;

	if (it[right] <= target) //当新加入数比先序列最大数大或者比最小数小或者只有一个数是当做特殊情况处理。
	{
		result = right + 1;
		flag = false;
	}
	else if(it[left] >= target)
	{
		result = left;
		flag = false;
	}
	else if (it[0] == 3)
	{
		result = right + 1;
		flag = false;
	}

	while (flag)  //这里使用的二分查找情况很多！！！
	{
		int middle = (left + right) / 2;
	
		if (it[middle] >= target)  
		{
			right = middle;
		}
		else if(it[middle] < target)
		{
			left = middle;
		}

		if (it[left] == target || it[right] == target)
		{
			if (it[left] == target)
				result = left;
			else
				result = right;
			break;
		}
		else if (right - left == 1 && it[left] < target && it[right] > target)
		{
			result = right;
			break;
		}
		
	}

	return result;
}


//次方查找，先从第一个位置开始比较然后查找位置以次方的数量级增加，请看详细实现。
int power_find(const int* it, const int target)//传入建立的数组和插入的数值，返回插入的位置。
{//需要注意的是数组第一个元素是数组大小（即当前的序列个数）最后一个元素是要插入的数值，实际上这里的传入参数可以省略插入数值
	int result;
	int series = 1;//head变化的级数，以指数级增长。
	int head = 1, tail = 1;  //这里其实可以有更加优化的算法即根据插入数值与头尾数值大小的比较决定是从头开始查找还是从尾开始查找。这里不再具体实现
	//另为了使后移函数更加高效可以在碰到相同的数值时将新插入的数值添加在后面
	
	if (target < it[1])
	{
		return 1;
	}

	while (true)
	{
		if (target >= it[tail])
		{
			if (target == it[tail] && (tail + 1 > it[0] - 2 || target < it[tail + 1]))
			{
				result = tail + 1;
				break;
			}
			else if (target == it[tail])
			{
				continue;    //退出当前循环使series为1使得tail后移一个
			}
			else if(target < it[tail + 1])
			{
				result = tail + 1;
				break;
			}

			head = tail;
		}

		if (head == tail && head + series * 2 <= it[0] - 2)
		{
			series *= 2;
			//printf("$%d$", series);
		}
		else if(head + 1 <= it[0] - 2)
			series = 1;
		else
		{
			result = head + 1;
			break;
		}
		
		tail = series + head;
	}

	return result;
}

int order_find(const int* it, const int target)  //顺序查找
{
	int result;
	if (target < it[1])
		return 1;
	for (int i = 1; i <= it[0] - 2; i++)
	{
		if (i + 1 > it[0] - 2 || target < it[i + 1])
		{
			result = i + 1;
			break;
		}
	}
	return result;
}

//从插入位置开始后移
int retrude(int* it, const int location)  //将location位置后面的所有数值整体后移，返回值表示执行状态：溢出：-1，成功：1，其他原因？？
{
	if (it[0] == 100) //溢出
		return -1;
	for (int i = it[0]; i > 0 && i > location; i--)
	{
		it[i] = it[i - 1];
	}

	return 1;
}

void print(const int* it)//输出整个有序序列。
{
	for (int i = 1; i < it[0]; i++)
	{
		printf_s("%d:", it[i]);
		if (i % 10 == 0)
			printf("\n");
	}
	printf("\n");
}

int main()
{
	int Object[100];   //序列最多有一百数值。
	int input, count;
	for (count = 1; count < 100; count++)
	{
		/*
		scanf_s("%d", &temporary_get);
		if (temporary_get == 123)
			break;
		*///起初为了简便就直接使用scanf_s进行输入，可是使用过程中发现还是有些问题，最大的问题是输入几个数后就不能输入了，这个问题暂未得到解决，
		//所以为了规避这个问题下面直接使用字符输出转换成数值，在函数中实现，
		
		Returned temporary = scanf_r();//两次回车或者任何不规范的输入都将导致输入结束。
		if (temporary.execute)
			input = temporary.temporary_get;
		else
			break;

		Object[count] = input;
		
		Object[0] = count + 1;  //这里数组第一个位置用于存储长度。
		
		if (count != 1)
		{
			//int location = dichotomy_find(Object, input);  二分查找
			//int location = power_find(Object, input);   //级数查找
			int location = order_find(Object, input);   //顺序查找

			if (retrude(Object, location) != 1)
			{
				printf_s("异常退出！！！");
				print(Object);
				return 0;
			}
			else
			{
				Object[location] = input;
			}
			/*
			print(Object);
			printf("#%d\n", location);
			*/
		}
		//print(Object);
	}
	print( Object );
	system("Pause");   //调用DOS命令暂停程序

	return 0;
}






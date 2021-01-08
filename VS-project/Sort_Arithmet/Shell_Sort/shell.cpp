//实现希尔排序。
//希尔排序也是一种插入排序，它是简单插入排序经过改进之后的一个更高效的版本，也称为缩小增量排序，

#include <iostream>
#include <time.h>

#define NUM 15
#define MAX 100

void Random_initial(int* object) //对数组进行随机初始化
{
	srand((unsigned)time(NULL)); //初始化随机数种子

	for (int number = 0; number < NUM; number++)
	{
		object[number] = rand() % MAX;
	}
}

void Printf_list(int* result)//格式化输出数组
{
	for (int number = 0; number < NUM; number++)
	{
		printf("%d", result[number]);
		if (number % 10 + 1 == 0)
			printf("\n");
		else
		{
			printf(":");
		}
	}
	printf("\n");
}

void Shell_initial(int* target)//原始的希尔排序
{
	int gap = NUM / 2; // 首次增量
	while (gap > 0)
	{
		for (int group = 0; group < gap; group++) // 需要进行插入排序的分组循环，此处对每个分组内可以选择适宜的排序方法并不一定要使用插入排序。
		{
			for (int member = group + gap; member < NUM; member+=gap) // 组内排序使用插入排序算法；
			{
				int inster_value = target[member];
				int inster_site = member; // 这里循环保证了出来的inster_site值就是插入位置。
				while (inster_site >= gap && target[inster_site - gap] > inster_value) // 寻找插入位置instersite。
				{
					target[inster_site] = target[inster_site - gap];
					inster_site -= gap;
				}
				target[inster_site] = inster_value;
			}
		}
		gap = gap / 2; // 缩小组距，增加每组的成员个数。
	}
}


int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Shell_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



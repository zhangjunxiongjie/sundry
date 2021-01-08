//计数排序。
// 进行优化尝试增加一层映射，以削弱计数排序对原始序列的要求。

#include <iostream>
#include <time.h>
#include <queue> // 使用队列记录基准元素的位置。

#define NUM 20
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


void Count_initial(int* target)//原始的计数排序
{
	// 计数数组。一个优化的方法是添加一层映射使这个算法即使在数值范围较大的情况下也不至于消耗太多的内存。
	int assis[MAX] = {}; 
	for (int i = 0; i < NUM; i++)
	{
		assis[target[i]]++; // 计数。
	}

	/*
	for (int i = 1; i < NUM; i++) // 累加
	{
		assis[i] = assis[i] + assis[i - 1];
	}
	*/

	for (int i = 0, j = 0; i < MAX; ) // 直接利用计数结果将对应的数值填入对应的位置。
	{
		if (assis[i] != 0)
		{
			target[j++] = i;
			assis[i]--;
		}
		else
		{
			i++;
		}
	}
}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Count_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}




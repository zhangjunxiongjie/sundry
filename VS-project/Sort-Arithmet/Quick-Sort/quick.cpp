//非递归实现快速排序（使用队列保存需要分区的区间）
//快速排序（Quicksort）是对冒泡排序的一种改进。

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

// 返回基准元素的位置。
int Assistant_Quick(int* target, int left, int right)
{
	int i = left, j = right - 1; // 从两头分别开始放大于和小于基准元素的项。包左不包右。
	int pivot = target[left]; // 基准项，基准项的选取策略决定着算法的效率
	while (i < j) // 将大于和小于基准元素的项分开放在基准元素的两头。
	{
		while (i < j && target[j] >= pivot) j--; // 找出小于基准元素的项（如果是大于等于的话则继续循环不须操作），放到前面。
		if (i < j)
		{
			int middle = target[i];
			target[i] = target[j];
			target[j] = middle;
		}

		while (i < j && target[i] <= pivot) i++; // 找出大于基准元素的项
		if (i < j)
		{
			int middle = target[i];
			target[i] = target[j];
			target[j] = middle;
		}
	}
	
	return i; // 经过循环后等式i==j应该是成立的且i的位置应该就是pivot的位置。
}
void Quick_initial(int* target)//原始的快速排序
{
	typedef struct border
	{
		int left;
		int right;
	}Border; // 边界结构体。

	std::queue<Border> pivot_list; // 存放分区后基准元素的位置。
	
	pivot_list.push({ 0, NUM }); // 
	while (!pivot_list.empty()) // 
	{
		int left = pivot_list.front().left; // 取出需要进行分区的区间。
		int right = pivot_list.front().right;
		pivot_list.pop();

		int pivot = Assistant_Quick(target, left, right); // 进行分区并返回基准元素的位置。
		
		if (pivot - left >= 2) // 至少要包含两个元素否则就没有再进行分区的必要。
		{
			pivot_list.push({left, pivot}); // 左边界包含，右边界不包含。 
		}
		if (right - (pivot + 1) >= 2) // 至少要包含两个元素否则就没有再进行分区的必要。
		{
			pivot_list.push({pivot + 1, right}); // pivot是基准元素的位置，已经移动到正确位置无需再做操作。
		}
	}
}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Quick_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}




/*
桶排序是对计数排序的改进，计数排序申请的额外空间跨度从最小元素值到最大元素值，若待排序集合中元素不是依次递增的（离散分布），
则必然有空间浪费情况。桶排序则是弱化了这种浪费情况，将最小值到最大值之间的每一个位置申请空间，
更新为最小值到最大值之间每一个固定区域申请空间，尽量减少了元素值大小不连续情况下的空间浪费情况。

由数值通过映射函数得到桶下标。然后放入桶中。

这里桶排序的策略（即映射函数）比较简单将数值个数直接作为桶个数，然后除数保证最大的数值在最后一个桶内。

桶排序的策略可以进一步进行优化，以使数值尽可能的均匀分布在每一个桶内，以减小进一步排序的负担。
*/

#include <iostream>
#include <vector>
#include <time.h>

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


void Bucket_initial(int* target)//原始的桶排序（不考虑负数）
{
	int divisor = MAX / (NUM - 1); // 使用这个值做除数可以使最大值在最后一个数组桶内。

	// 初始化桶。
	std::vector<int> bucket[NUM] = { {} }; // bucket_number = NUM; 数值个数就作为桶的数量。
	for (int i = 0; i < NUM; i++) // 装入桶内。
	{
		// target[count] / divisor 确定所在桶的位置。小数在前面的桶内，大数在后面的桶内。
		bucket[target[i] / divisor].push_back(target[i]);
	}

	// 如果装入桶内后每个桶本身的数值个数不多那可以直接使用比较排序对其进行排序。否则也可以使用递归的方法，继续进行桶排序。
	for (int i = 0; i < NUM; i++) 
	{
		if (bucket[i].size() > 1)
		{
			for (int j = 0; j < bucket[i].size(); j++) // 如果当前桶的数值个数大于1则进行排序。
			{
				int min = j;
				for (int z = j + 1; z < bucket[i].size(); z++) // 找出未排序序列中最小的那一个数值。
				{
					if (bucket[i].at(min) > bucket[i].at(z))
					{
						min = z;
					}
				}
				// 数值交换。
				int middle = bucket[i].at(min);
				bucket[i].at(min) = bucket[i].at(j);
				bucket[i].at(j) = middle;
			
			}
		}
	}

	int number = 0;
	for (int i = 0; i < NUM; i++) // 将桶中的数值填回数组中。
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			target[number++] = bucket[i].at(j);
		}
	}
}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Bucket_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



// 非递归实现归并排序

#include <iostream>
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

void Assistant_Merge(int* target, int left0, int right0, int left1, int right1) // 辅助归并函数。包含左元素不包含右元素。
{
	// 上层保证了前一个数组在左边，后一个数组在右边，且两个数组紧挨着。
	int left = left0; // 保存起点（不需要保存终点，因为两个数组的合并是逻辑上的其存放的位置不改变且挨着。）。
 	
	int assis[NUM]; // 辅助数组。 
	int cursor = 0; // 辅助数组指针。
	while (left0 < right0 && left1 < right1) // 在某一组元素到达边界时即退出。
	{
		if (target[left0] <= target[left1]) // 等于放在这保证了相等元素的相对位置不会改变。
		{
			assis[cursor++] = target[left0++];
		}
		else
		{
			assis[cursor++] = target[left1++];
		}
	}
	if (left0 < right0) // 保证归并能够全部完成。
	{
		while (left0 < right0)
		{
			assis[cursor++] = target[left0++];
		}
	}
	else
	{
		while (left1 < right1)
		{
			assis[cursor++] = target[left1++];
		}
	}

	for (int i = 0; i < cursor; i++) // 放回原数组
	{
		target[left++] = assis[i];
	}
}
void Merge_initial(int* target)//原始的归并排序
{
	int gap = 1; // 归并组所含元素个数。
	while (gap < NUM) // 
	{
		int i = 0;
		while (i + gap + gap <= NUM)
		{
			Assistant_Merge(target, i, i + gap, i + gap, i + gap + gap);

			i = i + gap + gap;
		}
		if (i + gap < NUM) // 此时说明最后一组不够，需要特殊处理，如果是倒数第二组不够则不用管。
		{
			Assistant_Merge(target, i, i + gap, i + gap, NUM);
		}

		gap *= 2; // 每次讲合并组的元素个数增加两倍。
	}

}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Merge_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



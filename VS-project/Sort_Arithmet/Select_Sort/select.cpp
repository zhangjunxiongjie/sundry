//这个项目用于实现优化的选择排序,以及原选择排序

#include <iostream>
#include <time.h>

#define NUM 10
#define MAX 100

void Random_initial(int* object) //对数组进行随机初始化
{
	srand((unsigned)time(NULL)); //初始化随机数种子

	for (int number = 0; number < NUM; number++)
	{
		object[number] = rand() % MAX;
	}
}

void Select_initial(int* result)//最原始的选择排序,升序
{
	for (int number = 0; number < NUM; number++)
	{
		int min = number;
		for (int count = number; count < NUM; count++)
		{
			if (result[min] > result[count])
				min = count;
		}
		if (min != number)
		{
			int middle = result[min];
			result[min] = result[number];
			result[number] = middle;
		}
	}
}

void Select_change(int* result)//改良的选择排序,使用了双端查找能够更加高效的对数组序列进行排序
{
	
	for (int left = 0, right = NUM - 1; left <= right; left++, right--)
	{
		int min = left;
		int max = right;
		for (int count = left; count <= right; count++)
		{
			if (result[min] > result[count])
				min = count;
			if (result[max] < result[count])
				max = count;
		}


		if(min == right && max == left)
		{
			int middle = result[right];
			result[right] = result[left];
			result[left] = middle;
		}
		else if(max == left && min != right)
		{
			int middle = result[max];
			result[max] = result[right];
			result[right] = middle;

			if (min != left)
			{
				int middle = result[min];
				result[min] = result[left];
				result[left] = middle;
			}
		}
		else if(max != left && min == right)
		{
			int middle = result[min];
			result[min] = result[left];
			result[left] = middle;

			if (max != right)
			{
				int middle = result[max];
				result[max] = result[right];
				result[right] = middle;
			}
		}
		else 
		{
			if (min != left)
			{
				int middle = result[min];
				result[min] = result[left];
				result[left] = middle;
			}
			if (max != right)
			{
				int middle = result[max];
				result[max] = result[right];
				result[right] = middle;
			}
		}
		
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

int main()
{
	int target[NUM];  //
	
	Random_initial(target);

	//Printf_list(target);
	Select_change(target);
	Printf_list(target);


	Random_initial(target);

	//Printf_list(target);
	Select_initial(target);
	Printf_list(target);

	system("Pause");
	return 0;
}
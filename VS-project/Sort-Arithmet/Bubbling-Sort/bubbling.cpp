// 本解决方案用于实现函数式十大排序算法。
//实现冒泡排序


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

void Bubbling_initial(int* target)//原始的冒泡排序
{
	int number,count,middle;
	for (count = 0; count < NUM; count++)
	{
		for (number = 0; number < NUM - count - 1; number++)//每完成一次外循环，队尾都有一个数放到了正确的位置
		{
			if (target[number] > target[number + 1])
			{
				middle = target[number];
				target[number] = target[number + 1];
				target[number + 1] = middle;
			}
		}
	}

}


int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Bubbling_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}

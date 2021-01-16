//实现插入排序,较难实现，有几个地方很坑。

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

void Insert_initial(int* target)//原始的插入排序
{
	int number;
	int middle;
	int count;
	
	for (count = 1; count < NUM; count++)
	{

		middle = target[count];

		for (number = count - 1; ; )
		{
			if (number >= 0 && target[number] > middle)
			{
				target[number + 1] = target[number];
				number--;
			}
			else
			{
				target[number + 1] = middle;
				break;
			}
		}

	}
}


int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Insert_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}

/*
计数排序，桶排序，基数排序三种排序方法都使用了相似的算法思想。

基数排序，利用数值的相同位的数值大小进行排序，然后依次对每一位进行相同操作。
*/

#include <iostream>
#include <time.h>
#include <vector>

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


void Radix_initial(int* target)//原始的基数排序
{
	
	int divisor = 1; // 除数
	int remainder = 10;  // 取余,取“最后”一个数。
	
	while (divisor < MAX) // 
	{
		std::vector<int> assistant[10] = { {} }; // 辅助数组。十进制所以这里的数组大小是10。

		// 根据每个数值的每一位判断其所在位置
		for (int i = 0; i < NUM; i++)
		{
			int middle = target[i] / divisor;
			middle = middle % remainder;
			assistant[middle].push_back(target[i]);
		}

		// 将结果放置回数组。
		int number = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < assistant[i].size(); j++)
			{
				target[number++] = assistant[i].at(j);
			}
		}
		
		divisor = divisor * 10;
	}

}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Radix_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}




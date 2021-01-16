// Learn0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 函数递归，实例。

#include <iostream>

const int Len = 66; // 字符数组大小
const int Divs = 6; // 阶数。

void subdivide(char ar[], int low, int high, int level);

int main()
{
	char ruler[Len];
	int i; 
	for (i = 1; i < Len - 2; i++) // 初始化。
	{
		ruler[i] = ' ';
	}
	ruler[Len - 1] = '\0'; 
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';

	std::cout << ruler << std::endl;
	for (i = 1; i < Divs; i++)
	{
		subdivide(ruler, min, max, i); // 

		std::cout << ruler << std::endl; 
		
		for (int j = 1; j < Len - 2; j++) // 重置
		{
			ruler[j] = ' ';
		}

	}
	system("pause");
	return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
	{
		return ;
	}
	int mid = (low + high) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}
// LeeCode_test60.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 力扣驱动程序，[60]第K个排列

#include <iostream>

using namespace std;

char* getPermutation(int n, int k);

int main()
{
	cout << getPermutation(5, 20) << endl;

	system("Pause");

	return 0;
}

// 第二版，优化后
void move(char* target, int left, int right) // 移动
{
	char middle = target[right];

	// cout << target << endl;

	for (int i = right - 1; i >= left; i--)
	{
		target[i + 1] = target[i];
		// cout << target << endl;
	}

	target[left] = middle;
}

char* getPermutation(int n, int k) {
	int employee[9] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	// 需要使用到的辅助数组

	char* result = (char*)(malloc(sizeof(char) * n + 1));
	result[n] = '\0';

	int ret = -1; // 记录当前所处位置；

	// 一方面对字符数组进行初始化另一方面还做了一点额外工作就是找到第一级变换下标。
	for (int i = 0; i < n; i++)
	{
		result[i] = (i + 1) + 48; // 加48变为字符

		if (ret == -1 && employee[i] >= k)
			ret = i;    // 放在这个循环里的额外工作。
	}

	k = k - 1;  // 这里把‘第k个排列’变换为‘做k次变换’；
	while (k > 0)
	{
		int place = n - 1 - ret;

		int spacer = k / employee[ret - 1]; // 临时变量

		int space = spacer + place; // 计算要交换的下标

		if (spacer)   // 每次下标向后移动都要保证后面的整个区块是其所对应的的最小值即第一个值。
		{
			k = k % employee[ret - 1]; // 更新k值

			move(result, place, space); // 传入要移动的一些参数

			// cout << result << endl;
		}

		ret--;
	}

	//

	return result;
}

/* 第一版，
void sort(char* target, int left, int right)
{
	for (int i = left; i < right; i++)
	{
		for (int j = i + 1; j < right; j++)
		{
			if (target[i] > target[j])
			{
				char middle = target[i];
				target[i] = target[j];
				target[j] = middle;
			}
		}
	}
}

char* getPermutation(int n, int k) {
	//int employee[9] = { 362880, 40320, 5040, 720, 120, 24, 6, 2, 1 };
	int employee[9] = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	char* result = (char*)(malloc(sizeof(char) * n + 1));

	int ret = -1; // 记录当前所处位置；

	for (int i = 0; i < n; i++)
	{
		result[i] = (i + 1) + 48; // 加48变为字符

		if (ret == -1 && employee[i] >= k)
		{
			ret = i; // 放在这个循环里的额外工作。
		}
	}

	k = k - 1;
	while (k > 0)
	{
		int place = n - 1 - ret;

		int spacer = k / employee[ret - 1];
		int space = spacer + place;

		if (spacer)
			k = k % employee[ret - 1];

		int middle = result[space];

		result[space] = result[place];

		result[place] = middle;

		if (spacer > 1)
			sort(result, place + 1, n);

		ret--;
	}

	result[n] = '\0';

	return result;
}

*/
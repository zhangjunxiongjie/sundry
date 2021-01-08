// LeetCode_test5147.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 暂时还没找到是第几个题。待定！
// 最后达到的效果是使数组每隔一个数就比前一个数小或者比后一个数大。

#include <iostream>
using namespace std;

int juchi_t(int* nums, int numsSize, int tant)
{
	int count = 0;
	for (int i = tant; i < numsSize; )
	{
		if (i == 0)
		{
			while (nums[i] <= nums[i + 1])
			{
				nums[i + 1]--;
				count++;
			}
		}
		else if (i == numsSize - 1)
		{
			while (i - 1 >= 0 && nums[i] <= nums[i - 1])
			{
				nums[i - 1]--;
				count++;
			}
			break;
		}
		else if (i >= 1 && i < numsSize - 1)
		{
			while (nums[i] <= nums[i + 1] || nums[i] <= nums[i - 1])
			{
				if (nums[i] <= nums[i + 1])
				{
					nums[i + 1]--;
					count++;
				}
				if (nums[i] <= nums[i - 1])
				{
					nums[i - 1]--;
					count++;
				}
			}
		}

		

		i = i + 2;
	}

	return count;
}

int movesToMakeZigzag(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;

	int nums_copy[1000];

	for (int i = 0; i < numsSize; i++)
		nums_copy[i] = nums[i];

	int t = juchi_t(nums, numsSize, 0);
	int f = juchi_t(nums_copy, numsSize, 1);

	for (int i = 0; i < numsSize; i++)
	{
		cout << nums[i] << ":";
	}
	cout << endl;

	for (int i = 0; i < numsSize; i++)
	{
		cout << nums_copy[i] << ":";
	}
	cout << endl;

	if (t > f)
		return f;
	else
		return t;
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "tf:" << movesToMakeZigzag(nums, 9) << endl;

	system("Pause");
}
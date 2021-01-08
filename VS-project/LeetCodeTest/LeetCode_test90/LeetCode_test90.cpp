// LeetCode_test90.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【90】子集2  未实现。超时，超内存，结果不准确。

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 递归实现，超时，超内存，结果还不准确。
// 生成组合。
void recursion(vector<vector<int>>& result, vector<int>& nums, vector<int>& buffer, int nowiter, int& sumiter, int pointer)
{
	if (nowiter == sumiter)
	{
		result.push_back(buffer);
		return;
	}

	for (; pointer < nums.size(); pointer++)
	{
		if (nums.size() - pointer < sumiter - nowiter)
		{
			return;
		}

		buffer.push_back(nums.at(pointer));
		recursion(result, nums, buffer, nowiter + 1, sumiter, pointer + 1);
		buffer.pop_back();
	}

}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>>& result = *new vector<vector<int>>;

	// 先排序以便去重、
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums.at(i) > nums.at(j))
			{
				int middle = nums.at(i);
				nums.at(i) = nums.at(j);
				nums.at(j) = middle;
			}
		}
	}

	// 生成组合。
	vector<int> buffer;
	for (int i = 0; i <= nums.size(); i++)
	{
		recursion(result, nums, buffer, 0, i, 0);
	}

	// 去重。 0 和 nums.size() 无须去重。
	for (auto i = result.begin() + 1; i != result.end() - 1; i++)
	{
		if (i->size() == (i + 1)->size())
		{
			int j = 0;
			for (; j < i->size(); j++)
			{
				if (i->at(j) != (i + 1)->at(j))
				{
					break;
				}
			}
			if (j == i->size())
			{
				result.erase(i + 1);
				i--;
			}
		}
	}

	return result;
}

int main()
{
	vector<int> target = {1, 2, 3};

	subsetsWithDup(target);

	system("pause");
	return 0;
}


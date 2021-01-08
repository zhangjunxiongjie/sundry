// LeetCode_test77.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【77】组合

#include <iostream>
#include <vector>
using namespace std;

// 递归实现。
void recursion(vector<vector<int>>& result, int number, int tier)
{

}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>>& result = *new vector<vector<int>>;

	// 特殊情况。
	if (n == 0)
	{
		vector<int> buffer;
		result.push_back(buffer);
		return result;
	}

	if (k == 0)
	{
		vector<int> buffer;
		for (int i = 0; i < n; i++)
		{
			buffer.push_back(i + 1);
		}

		result.push_back(buffer);
		return result;
	}


	recursion(result, n, k);

	return result;
}

int main()
{

	vector<vector<int>> result = combine(5, 0);

	for (auto i = result.begin(); i != result.end(); i++ )
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			cout << *j << ":";
		}
	}

	system("pause");
	return 0;
}

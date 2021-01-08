// LeetCode115.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【115】不同的子序列。

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 递归实现。使用堆栈循环实现递归。迭代。
void recursion(string& s, string& t, int nowiter, int pointer, int& result)
{
	if (nowiter == t.size())
	{
		result++;
		return;
	}
	for (; pointer < s.size(); pointer++)
	{
		if (t.size() - nowiter > s.size() - pointer)
		{
			return;
		}
		if (s.at(pointer) == t.at(nowiter))
		{
			recursion(s, t, nowiter + 1, pointer + 1, result);
		}
	}
}

int numDistinct(string s, string t) {
	int result = 0;

	recursion(s, t, 0, 0, result);

	return result;
}

int main()
{
	string s = "babgbag", t = "bag";
	numDistinct(s, t);

	system("pause");
	return 0;
}

// LeetCode_test97.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【97】交错字符串 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 时间复杂度较高仍有待改进。
// 直接递归进行比较。
bool recursion(string s1, string s2, string s3, int iter1, int iter2, int iter3) {

	if (iter1 == s1.size() && iter2 == s2.size() && iter3 == s3.size())
	{
		return true;
	}

	int i1 = iter1, i2 = iter2;
	for (int i3 = iter3; i3 < s3.size(); i3++)
	{
		if (i1 == s1.size())
		{
			for (; i2 < s2.size() && i3 < s3.size(); i2++, i3++)
			{
				if (s2.at(i2) != s3.at(i3))
				{
					return false;
				}
			}
			if (i2 == s2.size() && i3 == s3.size())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (i2 == s2.size())
		{
			for (; i1 < s1.size() && i3 < s3.size(); i1++, i3++)
			{
				if (s1.at(i1) != s3.at(i3))
				{
					return false;
				}
			}
			if (i1 == s1.size() && i3 == s3.size())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (s1.at(i1) == s2.at(i2) && s2.at(i2) == s3.at(i3))
		{
			if (recursion(s1, s2, s3, i1 + 1, i2, i3 + 1) || recursion(s1, s2, s3, i1, i2 + 1, i3 + 1))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (s1.at(i1) == s2.at(i2) && s2.at(i2) != s3.at(i3))
		{
			return false;
		}
		else if (s1.at(i1) != s2.at(i2))
		{
			if (s1.at(i1) == s3.at(i3))
			{
				i1++;
			}
			else if (s2.at(i2) == s3.at(i3))
			{
				i2++;
			}
			else
			{
				return false;
			}

		}
	}

	return false;
}

bool isInterleave(string s1, string s2, string s3) {

	return recursion(s1, s2, s3, 0, 0, 0);
}

int main()
{
	string str1 = "aabcc";
	string str2 = "dbbca";
	string str3 = "aadbbcbcac";

	isInterleave(str1, str2, str3);

	system("pause");
	return 0;
}


/*  简单粗暴，但效率太低。
	
	// 产生可能的位置信息。
	void recursion(string s1, string s3, vector<vector<int>>& cache, vector<int>& buffer, int s1tier, int s3tier)
	{
		if (s1tier == s1.size())
		{
			cache.push_back(buffer);
			return ;
		}

		for (int i = s3tier; i < s3.size(); i++)
		{
			// 时间优化。
			if (s3.size() - i < s1.size() - s1tier)
			{
				return ;
			}

			if (s1.at(s1tier) == s3.at(i))
			{
				buffer.push_back(i);
				recursion(s1, s3, cache, buffer, s1tier + 1, i + 1);
				buffer.pop_back();
			}
		}

	}

	// 判断
	bool judge(vector<int> buffer, int target)
	{
		// 其实这里可以使用二分查找进行优化的。
		for (int i = 0; i < buffer.size(); i++)
		{
			if (target == buffer.at(i))
			{
				return false;
			}
			if (target < buffer.at(i))
			{
				return true;
			}

		}
		return true;
	}

	bool isInterleave(string s1, string s2, string s3) {

		if (s1.size() + s2.size() != s3.size())
		{
			return false;
		}

		vector<vector<int>> cache; // s1 在 s3 可能的位置信息
		vector<int> buffer;

		recursion(s1, s3, cache, buffer, 0, 0);

		for (int i = 0; i < cache.size(); i++)
		{
			string str;
			for (int j = 0; j < s3.size(); j++)
			{
				if (judge(cache.at(i), j))
				{
					str.push_back(s3.at(j));
				}
			}
			if (str == s2)
			{
				return true;
			}
		}

		return false;
	}
*/

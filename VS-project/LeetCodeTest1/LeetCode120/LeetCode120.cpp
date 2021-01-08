// LeetCode120.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【120】三角形最小路径和。

#include <iostream>
#include <vector>
using namespace std;

// 只考虑左方影响时。
int minimumTotal(vector<vector<int>>& triangle) {
	vector<int> cache;

	for (int i = 0; i < triangle.size(); i++)
	{
		cache.push_back(0);
		for (int j = i; j >= 0; j--)
		{
			if (j != 0)
			{
				if (j == i)
				{
					cache.at(j) = cache.at(j - 1);
				}
				else if (cache.at(j - 1) < cache.at(j))
				{
					cache.at(j) = cache.at(j - 1);
				}
			}
			cache.at(j) += triangle.at(i).at(j);
		}
		
		for (int i = 0; i < cache.size(); i++)
		{
			cout << cache.at(i) << ":";
		}
		cout << endl;
	}

	int result = cache.at(0);
	for (int i = 1; i < cache.size(); i++)
	{
		if (result > cache.at(i))
		{
			result = cache.at(i);
		}
	}
	return result;
}

/* 考虑到左右均有影响时。
int minimumTotal(vector<vector<int>>& triangle) {
	vector<int> cache;

	for (int i = 0; i < triangle.size(); i++)
	{
		int lastmin;
		for (int j = 0; j < i + 1; j++)
		{
			int cachemin;
			if (j >= i - 1) // i - 1 最后一个， i 新填的一个。
			{
				if (j == 0) // j == 0 特殊情况
				{
					if (j == i) // 新填的一个元素。
					{
						cachemin = 0;
					}
					else // 最后一个元素。
					{
						cachemin = cache.at(j);
					}
				}
				else // 一般情况。
				{
					if (j == i)
					{
						cachemin = cache.at(i - 1);
					}
					else
					{
						cachemin = cache.at(j);
						if (cachemin > cache.at(j - 1))
						{
							cachemin = cache.at(j - 1);
						}
					}
				}
			}
			else //
			{
				if (j == 0) // 处理首元素。
				{
					cachemin = cache.at(0);
				}
				else // 处理位于中间的元素。
				{
					cachemin = cache.at(j);
					if (cachemin > cache.at(j - 1))
					{
						cachemin = cache.at(j - 1);
					}
				}
			}
			if (j - 1 >= 0)
			{
				cache.at(j - 1) = lastmin + triangle.at(i).at(j - 1);
			}
			lastmin = cachemin; // 先保存结果，等下一元素结果计算出来后再覆盖填充。
		}
		cache.push_back(lastmin + triangle.at(i).at(i));
	}

	int result = cache.at(0);
	for (int i = 1; i < cache.size(); i++)
	{
		if (result > cache.at(i))
		{
			result = cache.at(i);
		}
	}
	return result;
}
*/

int main()
{
	vector<vector<int>> target = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

	cout << minimumTotal(target) << endl;

    system("pause");
    return 0;
}

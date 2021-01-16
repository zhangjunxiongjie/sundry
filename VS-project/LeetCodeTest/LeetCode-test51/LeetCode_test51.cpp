// LeetCode_test51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【51】N皇后问题1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void create(int n, vector<int>& cache, vector<vector<string>>& result)
{
	vector<string> buffer1;

	for (int i = 0; i < n; i++)
	{
		string buffer2;

		for (int j = 0; j < cache[i]; j++)
		{
			buffer2 = buffer2 + '.';
		}
		buffer2 = buffer2 + 'Q';
		for (int j = cache[i] + 1; j < n; j++)
		{
			buffer2 = buffer2 + '.';
		}

		buffer1.push_back(buffer2);

		cout << buffer2 << endl;
	}

	result.push_back(buffer1);
}

// 递归尝试所有可能
void findmay(vector<vector<string>>& result, vector<int>& cache, int n, int now)
{
	if (n == now)
	{
		create(n, cache, result);

		for (int i = 0; i < n; i++)
		{
			cout << cache.at(i);
		}
		cout << endl;

		return;
	}

	vector<int> impose;
	for (int i = 0; i < n; i++)
	{
		impose.push_back(0);
	}
	// 这里的问题是每一层都要重新计算限制条件
	for (int i = 0; i < now; i++) // 计算限制条件
	{
		impose[cache[i]] = 1;
		int impose1 = cache[i] - (now - i);
		int impose2 = cache[i] + (now - i);

		if (impose1 >= 0)
		{
			impose[impose1] = 1;
		}
		if (impose2 < n)
		{
			impose[impose2] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (impose.at(i) == 0)
		{
			cache.at(now) = i;
			findmay(result, cache, n, now + 1);

			cache.at(now) = -1; //
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>>& result = *new vector<vector<string>>;

	vector<int> cache;  //记录每一行占据到的位置
	for (int i = 0; i < n; i++)
	{
		cache.push_back(-1);
	}

	// findmay(result, cache, n, 0); // 从第零行开始
	vector<int> impose;
	
	int now = 0;
	while (now != -1)
	{
		if (n == now)
		{
			create(n, cache, result);

			for (int i = 0; i < n; i++)
			{
				cout << cache.at(i);
			}
			cout << endl;

			now--;
		}

		impose.clear();
		for (int i = 0; i < n; i++)
		{
			impose.push_back(0);
		}
		for (int i = 0; i < now; i++) // 计算限制条件
		{
			impose[cache[i]] = 1;
			int impose1 = cache[i] - (now - i);
			int impose2 = cache[i] + (now - i);

			if (impose1 >= 0)
			{
				impose[impose1] = 1;
			}
			if (impose2 < n)
			{
				impose[impose2] = 1;
			}
		}

		int sign = cache.at(now) + 1;
		for (; sign < n; sign++)
		{
			if (impose.at(sign) == 0)
			{
				cache.at(now) = sign;

				now++;
				
				break;
			}
		}
		if (sign == n)
		{
			cache.at(now) = -1;

			now--;
		}

	}

	return result;
}

int main()
{
	solveNQueens(5);

	system("pause");
	return 0;
}
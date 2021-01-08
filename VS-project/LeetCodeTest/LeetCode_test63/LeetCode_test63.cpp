// LeeCode_test63.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//【63】不同路径2

#include <iostream>
#include <vector>
using namespace std;

// 一个崭新的思路，到达位置[i,j]的路技数等于达到[i-1,j]加上达到[i,j-1]的路径总数。（前提是只能向右向下）（动态规划）
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int result = 0;
	// 特殊情况
	if (obstacleGrid.empty())
	{
		return 0;
	}
	else if (obstacleGrid.at(0).empty())
	{
		return 1;
	}
	else if (obstacleGrid.at(0).at(0) == 1)
	{
		return 0;
	}
	else if (obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1) == 1)
	{
		return 0;
	}

	for (int i = 0; i < obstacleGrid.size(); i++)
	{
		for (int j = 0; j < obstacleGrid.at(0).size(); j++)
		{
			if (obstacleGrid.at(i).at(j))
			{
				obstacleGrid.at(i).at(j) = -1; // 把所有阻碍标志改为-1；方便计路径数。
			} 
		}
	}

	obstacleGrid.at(0).at(0) = 1; // 到达起始位置的路径数为1。
	for (int i = 1; i < obstacleGrid.at(0).size(); i++)
	{
		if (obstacleGrid.at(0).at(i) != -1)
		{
			obstacleGrid.at(0).at(i) = obstacleGrid.at(0).at(i - 1);
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < obstacleGrid.size(); i++)
	{
		if (obstacleGrid.at(i).at(0) != -1)
		{
			obstacleGrid.at(i).at(0) = obstacleGrid.at(i - 1).at(0);
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i < obstacleGrid.size(); i++)
	{
		for (int j = 1; j < obstacleGrid.at(0).size(); j++)
		{
			if (obstacleGrid.at(i).at(j) != -1)
			{
				if (obstacleGrid.at(i - 1).at(j) == -1)
				{
					obstacleGrid.at(i).at(j) = obstacleGrid.at(i).at(j - 1);
				}
				else if (obstacleGrid.at(i).at(j - 1) == -1)
				{
					obstacleGrid.at(i).at(j) = obstacleGrid.at(i - 1).at(j);
				}
				else // 返回值为int，但是计算过程中依然可能产生不影响输出结果的大于int最大值的数值，所以这里依然可能出错。
				{
					obstacleGrid.at(i).at(j) = obstacleGrid.at(i).at(j - 1) + obstacleGrid.at(i - 1).at(j);
				}
			}
		}
	}

	for (int i = 0; i < obstacleGrid.size(); i++)
	{
		for (int j = 0; j < obstacleGrid.at(0).size(); j++)
		{
			cout << obstacleGrid.at(i).at(j) << ":";
		}
		cout << endl;
	}

	result = obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1);
	if (result == -1) // 此时终点不可达。
	{
		return 0;
	}

	return result;
}

/*  深度优化时间复杂度太大！
// 深度优化寻路。 超时！！！
void recursion(vector<vector<int>>& obstacleGrid, int& sum, int x, int y)
{
	int xmax = obstacleGrid.size() - 1;
	int ymax = obstacleGrid.at(0).size() - 1;

	if (x == xmax && y == ymax)
	{
		sum++;
		return;
	}

	if (x + 1 <= xmax && y <= ymax && obstacleGrid.at(x + 1).at(y) == 0)
	{
		obstacleGrid.at(x + 1).at(y) = 1;
		recursion(obstacleGrid, sum, x + 1, y);
		obstacleGrid.at(x + 1).at(y) = 0;
	}
	if (y + 1 <= ymax && x <= xmax && obstacleGrid.at(x).at(y + 1) == 0)
	{
		obstacleGrid.at(x).at(y + 1) = 1;
		recursion(obstacleGrid, sum, x, y + 1);
		obstacleGrid.at(x).at(y + 1) = 0;
	}

}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

	int result = 0;
	// 特殊情况
	if (obstacleGrid.empty())
	{
		return 0;
	}
	else if (obstacleGrid.at(0).empty())
	{
		return 1;
	}
	else if (obstacleGrid.at(0).at(0) == 1)
	{
		return 0;
	}
	else if (obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1) == 1)
	{
		return 0;
	}

	int x = obstacleGrid.size() - 1;
	int y = obstacleGrid.at(0).size() - 1;
	// 解决超时问题，优化寻路可能，减少不必要的寻路。
	for (int i = x; i >= 0; i--)
	{
		for (int j = y; j >= 0; j--)
		{
			if (i < x || j < y) // 极致优化了！！！
			{
				if (i == x && j < y && obstacleGrid.at(i).at(j + 1)) // 最后一行只需右边不能通过则无须探寻。
				{
					obstacleGrid.at(i).at(j) = 1;
				}
				else if (j == y && i < x && obstacleGrid.at(i + 1).at(j)) // 最后一列只须下方不能通过即可。
				{
					obstacleGrid.at(i).at(j) = 1;
				}
				else if (i < x && j < y && obstacleGrid.at(i).at(j + 1) && obstacleGrid.at(i + 1).at(j)) // 当某一位置右方和下方不能通过时则此路不必再探寻。
				{
					obstacleGrid.at(i).at(j) = 1;
				}
			}
		}
	}

	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			cout << obstacleGrid.at(i).at(j) << ":";
		}
		cout << endl;
	}

	obstacleGrid.at(0).at(0) = 1;
	recursion(obstacleGrid, result, 0, 0);

	return result;
}
*/

int main()
{
	vector<vector<int>> result = {
	{ 0, 1 },
	{ 1, 0, }
	};

	cout << uniquePathsWithObstacles(result) << endl;

	system("pause");
	return 0;
}

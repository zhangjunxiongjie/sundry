// LeeCode_test2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 力扣驱动程序，[62]不同路径1

#include <iostream>

// 二维数组在函数间传递的方法；

int judge(int m, int n, int(*assistant)[100])
{
	if (m > 1 && n > 1)
	{
		if (assistant[m - 1][n] && assistant[m][n - 1])
		{
			return assistant[m - 1][n] + assistant[m][n - 1];
		}
		else if (assistant[m - 1][n])
		{
			assistant[m][n - 1] = judge(m, n - 1, assistant);

			return assistant[m - 1][n] + assistant[m][n - 1];
		}
		else if (assistant[m][n - 1])
		{
			assistant[m - 1][n] = judge(m - 1, n, assistant);

			return assistant[m - 1][n] + assistant[m][n - 1];
		}
		else
		{
			assistant[m][n - 1] = judge(m, n - 1, assistant);
			assistant[m - 1][n] = judge(m - 1, n, assistant);

			return assistant[m - 1][n] + assistant[m][n - 1];
		}
	}
	else if (m > 1)
	{
		assistant[m - 1][n] = judge(m - 1, n, assistant);

		return assistant[m - 1][n];
	}
	else if (n > 1)
	{
		assistant[m][n - 1] = judge(m, n - 1, assistant);

		return assistant[m][n - 1];
	}
	else
	{
		return 1;
	}
}

int uniquePaths(int m, int n) {
	if (m == 0 && n == 0)
	{
		return 0;
	}
	else
	{
		int assistant[100][100] = {};  // 初始化数组全为零的方法

		return judge(m, n, assistant);
	}
}

int main()
{
	std::cout << "Hello World!\n";
}

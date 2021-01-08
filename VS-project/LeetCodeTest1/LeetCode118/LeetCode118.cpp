// LeetCode118.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【118】杨辉三角

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>>& result = *new vector<vector<int>>;
	for (int i = 1; i <= numRows; i++)
	{
		vector<int> buffer;
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				buffer.push_back(1);
			}
			else
			{	
				cout << i << ":" << j << endl;
				int sum = result.at(i - 2).at(j - 2) + result.at(i - 2).at(j - 1);
				buffer.push_back(sum);
			}
		}
		result.push_back(buffer);
	}
	return result;
}

int main()
{
	generate(5);
	system("pause");
	return 0;
}


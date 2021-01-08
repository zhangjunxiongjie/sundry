// StickCut.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// [30] 棍子切割：将长度为100的棍子切割为100根长度为1的棍子，一次可同时切割多跟棍子。

#include <iostream>
#include <vector>
using namespace std;

void StickCut(vector<int>& target) {
	bool sign = true;
	int count = 0; // 计数器，记录切割次数。
	while (sign)
	{
		sign = false;
		int buffer = target.size();
		for (int i = 0; i < buffer; i++) // 每次切割都把所有棍子对半切。
		{
			if (target.at(i) > 1)
			{
				if (target.at(i) % 2 == 0) // 偶数切割
				{
					target.at(i) = target.at(i) / 2;
					target.push_back(target.at(i));
				}
				else // 奇数切割。
				{
					target.at(i) = (target.at(i) - 1) / 2;
					target.push_back(target.at(i) + 1);
				}
				sign = true;
			}
		}
		if (sign)
		{
			count++;
		}
	}
	cout << count << endl;
}

int main()
{
	vector<int> target{100};

	StickCut(target);

	system("pause");
	return 0;
}

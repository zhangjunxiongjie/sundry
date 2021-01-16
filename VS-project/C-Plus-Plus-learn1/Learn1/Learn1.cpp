// Learn1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// for循环遍历与迭代器的使用。

#include <iostream>

int main()
{
	double prices[5] = { 4.99, 10.99, 6.87, 7.99, 8.49 };
	for (double x : prices)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (double& x : prices)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (int x : {1, 2, 3, 4, 5})
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}


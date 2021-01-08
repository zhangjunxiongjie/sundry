// Learn8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 异常处理 try...catch...

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double triangle(double, double, double) throw(double); // 函数声明

	double a, b, c;

	cin >> a >> b >> c; 

	try
	{
		while (a > 0 && b > 0 && c > 0)
		{
			cout << triangle(a, b, c) << endl;
			cin >> a >> b >> c;
		}
		if (a == 0 || b == 0 || c == 0)
		{
			throw 1;  // 抛出边为零异常
		}
		else
		{
			throw '0';  // 抛出其它异常
		}

	}
	catch (double t) // 处理异常，获取类型值
	{
		cout << "a = " << a << ",b = " << b << ",c = " << c << " endl:" << t << endl;
	}
	catch (int t)  
	{
		cout << "a = " << a << ",b = " << b << ",c = " << c << " endl:" << t << endl;
	}
	catch(...)
	{
		cout << "a = " << a << ",b = " << b << ",c = " << c << " endl:" << "other" << endl;
	}

	system("Pause");
	return 0;
}

// 异常指定，即指定一个函数块可以抛出的异常（或者说标记一个函数快可能抛出的异常）
// 异常指定一方面起到标记的作用，另一方面能够限制函数块可以抛出的异常类型。
double triangle(double a, double b, double c) throw(double) 
{
	double s = (a + b + c) / 2;  

	try
	{
		if (a + b <= c || b + c <= a || a + c <= b) 
			throw - 1.1;  // 抛出不能组成三角形异常
	}
	catch(...)
	{
		throw; // 将已捕获的异常信息再此原样抛出。
	}

	return sqrt(s * (s - a) * (s - b) * (s - c)); // 计算面积
}

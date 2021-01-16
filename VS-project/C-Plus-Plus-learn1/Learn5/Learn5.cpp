// Learn5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 定位new运算符

#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;

char buffer[BUF];    // 申请一块空间

int main()
{
	using namespace std;

	double* pd1, * pd2;
	double* pd3, * pd4;
	int i;

	cout << "Calling new and placement new:\n";

	pd1 = new double[N];
	pd2 = new (buffer) double[N]; // 定位new运算符，从buffer位置开始分配内存。
	
	cout << "Memory addresses;\n" << " heap:" << pd1 << " static:" << (void*)buffer << endl;    // (void*)buffer 指针地址
	cout << "Memory contens:\n";
	for (i = 0; i < N; i++) // 初始化
		pd2[i] = pd1[i] = 1000 + 20.0 * i; 
	for (i = 0; i <N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}


	cout << "\nCalling new and placement new a second time:\n";
	
	pd3 = new double[N];
	pd4 = new (buffer) double[N];

	cout << "Memory contens:\n";
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << ";";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}


	cout << "\nCalling new and placement new a third time:\n";
	
	delete[] pd1;

	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];

	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;

	system("pause");
	return 0;
}

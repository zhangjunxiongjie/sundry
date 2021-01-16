// Learn3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 函数重载。

#include <iostream>

// 取左边ct位
unsigned long left(unsigned long num, unsigned ct); // unsigned无符号类型

// 取左边n个字符。
char* left(const char* str, int n = 1);

int main()
{
	using namespace std;

	const char* trip = "Hawaii!!"; // 字符串常量
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl; // unsigned long left(unsigned long num, unsigned ct);
		
		temp = left(trip, i); // char* left(const char* str, int n = 1);
		cout << temp << endl;
		
		delete [] temp; // 内存回收。
	}

	system("pause");
	return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++; // num位数。
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--) // 取左边ct位。
			num /= 10;
		return num;
	}
	else
		return num;
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i]; // 取字符串左边n（0~n-1）位。
	while (i <= n) // 如果字符串不够长则将后面的字符置‘\0’;
		p[i++] = '\0';
	return p; // 返回一个字符串指针。
}

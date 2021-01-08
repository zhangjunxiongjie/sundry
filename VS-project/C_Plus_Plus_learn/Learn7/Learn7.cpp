// Learn7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 字符串流

#include <iostream>
#include <strstream>
using namespace std;

struct student
{
	int num;
	char name[20];
	float score;
};

int main()
{
	student stu[3] = { 1001, "Li", 78, 1002, "Wang", 89.5, 1004, "Fang", 90 };
	
	student stur[3] = {};

	char c[50];  // 字符串流数组 
	
	ostrstream strout(c, sizeof(c));  // 输出字符串流
	for (int i = 0; i < (sizeof(stu) / sizeof(stu[0])); i++)
	{
		strout << stu[i].num << " " << stu[i].name << " " << stu[i].score << " ";   // 将数据输出到字符串流
	}
	strout << ends;
	cout << "strout:" << c << endl;   // 在终端打印出字符串

	istrstream strin(c, sizeof(c));  // 输入字符串流
	for (int i = 0; i < (sizeof(stur) / sizeof(stur[0])); i++)
	{
		strin >> stur[i].num >> stur[i].name >> stur[i].score;  // 从字符串流提取数据，只能提取基本类型而不能提取自定义类型。
	}
	for (int i = 0; i < (sizeof(stu) / sizeof(stu[0])); i++) // 打印
	{
		cout << stur[i].num << " " << stur[i].name << " " << stur[i].score << endl;
	}

	system("Pause");
	return 0;
}


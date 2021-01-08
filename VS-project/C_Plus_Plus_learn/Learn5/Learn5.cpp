// Learn5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 格式化输出的方法：1.使用控制符控制输出格式；2.用流对象的成员函数控制输出格式。

#include <iostream>
using namespace std;

int main()
{
	int a = 21;

	cout.setf(ios::showbase);         // 显示基数符号
	cout << "dec:" << a << endl;   // 默认十进制输出  

	cout.unsetf(ios::dec);    // 终止十进制输出
	cout.setf(ios::hex);   // 设置以十六进制输出
	cout << "hex:" << a << endl;
	
	cout.unsetf(ios::hex);  // 终止十六进制输出
	cout.setf(ios::oct);    // 开始八进制输出
	cout << "oct:" << a << endl;

	char pt[] = "China";
	
	cout.width(10);   // 设置域宽，只对后面第一个输出项有效。
	cout << pt << endl;

	cout.width(10);
	cout.fill('*');  // 设置填充字符
	cout << pt << endl;

	double pi = 22.0 / 7.0;

	cout.setf(ios::scientific);  // 以科学计数法输出
	cout << "pi=";
	cout.width(14);   // 域宽
	cout << pi << endl;

	cout.unsetf(ios::scientific);   // 终止科学计数法输出
	
	cout.setf(ios::fixed);  // 指定以定点形式输出
	cout.width(12);       // 域宽
	cout.setf(ios::showpos);  // 正数输出“+”
	cout.setf(ios::internal);  // 整数出现在左侧
	cout.precision(6);   // 保留6位小数
	cout << pi << endl;

	return 0;
}





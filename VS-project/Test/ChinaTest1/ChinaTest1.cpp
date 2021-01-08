// ChinaTest1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// C++中文处理测试程序，文件处理

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// 文件读入
	std::ifstream input("Test.txt");
	std::string instr;
	input >> instr;
	std::cout << instr << std::endl;
	input.close();
	
	// 文件写出
	std::ofstream output("Test.txt");
	std::string outstr;
	std::cin >> outstr;
	output << outstr;
	output.close();

	system("pause");
	return 0;
}


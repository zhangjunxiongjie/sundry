// Learn2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 对象，继承，引用。基类引用，派生类引用。

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// 基类引用参数可以引用派生类对象。
void file_it(ostream& os, double fo, const double fe[], int n);

const int LIMIT = 5;

int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt"; 
	fout.open(fn);
	// ofstream fout("ep-data.txt");

	if (!fout.is_open()) // 判断文件打开是否成功。
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}

	double objective;
	cout << "Enter the focal length of your telescope objective in mm: ";
	cin >> objective;
	
	double eps[LIMIT];
	cout << "Enter the focal lenths, in mm, of " << LIMIT << "eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ":";
		cin >> eps[i];
	}

	// 派生类引用，fout是ofstream类对象是ostream类的派生类。
	file_it(fout, objective, eps, LIMIT); 

	// 基类引用，cout是ostream类对象是ofstream类的基类。
	file_it(cout, objective, eps, LIMIT); 

	system("pause");
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);

	os << "Focal length of objective: " << fo << " mm\n";
	
	os.setf(ios::showpoint);
	os.precision(1);
	
	os.width(12);
	os << "f.1. eyepiece";
	
	os.width(15);
	os << "magnification" << endl;
	
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];

		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	
	os.setf(initial);
}

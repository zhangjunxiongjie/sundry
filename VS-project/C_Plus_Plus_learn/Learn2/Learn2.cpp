// Learn2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 运算符重载，类型转换函数，转换构造函数。

#include <iostream>
using namespace std;

class Complex
{
public:
	Complex() { real = 0; imag = 0; }
	
	Complex(double r) { real = r; imag = 0; }  // 转换构造函数，用于将double类型的变量构造转换为Complex对象
	// operator double() { return real; }           // 类型转换函数，用于将Complex类对象实例转换为double类型
	/*
	（转换构造函数+运算符重载函数）和（类型转换函数）从某种意义上来说是互斥的，
	因为在类对象实例和一个基本类型进行运算时，如果定义类型转换函数则会将类实例转换为基本类型然后使用内置运算直接进行运算；
	而当存在转换构造函数时则可以将基本类型转换构造为对象，然后使用重载运算符进行运算。
	所以应当避免前者和后者同时共存以避免歧义。
	*/


	Complex(double r, double i) { real = r; imag = i; }


	friend Complex operator + (Complex c1, Complex c2);  // 运算符重载函数

	void display();

private:
	double real;
	double imag;
};

void Complex::display()
{
	cout << " " << real << " + " << imag << "i " << endl;
}


Complex operator + (Complex c1, Complex c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}


int main()
{
	Complex c1(3, 4), c2(5, 10), c3;
	
	/*
	// 这里既可以使用内置的+运算（即将Complex转换为double）也可以使用重载的+运算（即将double转换构造为Complex对象）
	c3 = c1 + 2.5;   // 这里存在两种语义：将double转换为Complex对象；或者将complex对象转换为double类型变量。
	// 因为上面将两种函数都进行了实现所以这里存在语义歧义。

	c3.display();
	*/
	
	c3 = c1 + c2;
	c3.display();

	system("Pause");
	return 0;
}



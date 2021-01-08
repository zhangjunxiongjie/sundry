/*
// 此解决方案用于保存在学习c++过程中的测试代码
// 构造函数，析构函数
*/

#include <iostream>
#include <string>
using namespace std;

class Time
{
public:

	Time();  // 构造函数(无实参的默认构造函数)

	// 存在默认值的形参要放在形参列表的最后面，如果一个构造函数没有形参或者形参都有默认值则此构造函数为默认构造函数。
	// 重载函数不关注存在默认值的参数，重载函数必须保证所有重载函数的无默认值参数个数或者类型至少一者不同
	// 否则将导致编译器在处理时出现歧义，即不知道应该调用哪一个函数。
	Time(int a, int b, int c, string d = "str") : hour(a), minute(b), sec(c), name(d) { } // 函数重载，使用参数初始化列表对成员属性进行初始化，

	~Time();   // 析构函数

	void Set_Time();
	void Show_Time();

private:
	string name;
	int hour;
	int minute;
	int sec;
};

Time::Time()
{
	name = "str";
	hour = 0;
	minute = 0;
	sec = 0;
}

Time::~Time()
{
}

void Time::Set_Time()
{
	cin >> name;
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::Show_Time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
	cout << name << endl;
}

int main()
{
	Time t1;
	t1.Set_Time();
	t1.Show_Time();

	Time t2(1, 2, 3);
	t2.Show_Time();

	system("Pause");
	return 0;
}
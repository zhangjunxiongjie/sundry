// Learn1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 静态成员变量与对象初始化

#include <iostream>
using namespace std;

class Student {
public:
	Student();
	Student(int n, int a, float s) : num(n), age(a), score(s) {};

	void total();
	void show();

	static float average();

	float averager();  // 非静态函数可以直接访问静态成员变量，但是静态函数不能直接访问非静态成员变量。

private:
	int num;
	int age;
	float score;
	static float sum;
	static int count;
};

Student::Student() {
	num = 0;
	age = 0;
	score = 0;
}

void Student::show() {
	cout << num << " " << age << " " << score << " sign " << endl;
}

void Student::total() {
	sum += score;

	count++;
}

float Student::average() {
	return (sum / count);
}

float Student::averager() {
	return (sum / count);
}

float Student::sum = 0;
int Student::count = 0;
int main() {
	Student stud[3] = {
		Student(1001, 18, 70.1),
		Student(1002, 19, 71.2),
		Student(1003, 20, 72.3)
	};

	int n = 3;

	for (int i = 0; i < n; i++)
	{
		//stud[i].show();
		stud[i].total();
	}

	cout << n << " " << stud[0].averager() << endl;

	system("Pause");
	return 0;
}
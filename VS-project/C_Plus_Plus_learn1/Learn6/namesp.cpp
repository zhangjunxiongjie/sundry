// 对两个名称空间中的函数进行定义。

#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;

	void getPerson(Person& rp) // 设置person的结构体成员值。
	{
		cout << "Enter first name:";
		cin >> rp.fname;

		cout << "Enter last name:";
		cin >> rp.lname;
	}

	void showPerson(const Person& rp) // 展示person的结构体成员值。
	{
		std::cout << rp.lname << "," << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt& rd)  // 设置结构体的值
	{
		getPerson(rd.name);
		std::cout << "Enter debt:";
		std::cin >> rd.amount;
	}

	void showDebt(const Debt& rd) // 展示结体值。
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}

	double sumDebts(const Debt ar[], int n) // 计算结构体成员amount值的总和
	{
		double total = 0;
		for (int i = 0; i < n; i++)  
			total += ar[i].amount;
		return total;
	}

}

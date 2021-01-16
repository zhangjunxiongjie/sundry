// ���������ƿռ��еĺ������ж��塣

#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;

	void getPerson(Person& rp) // ����person�Ľṹ���Աֵ��
	{
		cout << "Enter first name:";
		cin >> rp.fname;

		cout << "Enter last name:";
		cin >> rp.lname;
	}

	void showPerson(const Person& rp) // չʾperson�Ľṹ���Աֵ��
	{
		std::cout << rp.lname << "," << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt& rd)  // ���ýṹ���ֵ
	{
		getPerson(rd.name);
		std::cout << "Enter debt:";
		std::cin >> rd.amount;
	}

	void showDebt(const Debt& rd) // չʾ����ֵ��
	{
		showPerson(rd.name);
		std::cout << ": $" << rd.amount << std::endl;
	}

	double sumDebts(const Debt ar[], int n) // ����ṹ���Աamountֵ���ܺ�
	{
		double total = 0;
		for (int i = 0; i < n; i++)  
			total += ar[i].amount;
		return total;
	}

}

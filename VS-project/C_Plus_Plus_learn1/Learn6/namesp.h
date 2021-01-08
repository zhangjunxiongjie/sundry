// 声明了两个名称空间

#include <string>

namespace pers 
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};

	void getPerson(Person&);
	void showPerson(const Person&);
}

namespace debts
{
	using namespace pers;

	struct Debt
	{
		Person name;
		double amount = 0.0;  // 给结构体成员设置初始化值。
	};

	void getDebt(Debt&);
	void showDebt(const Debt&);
	double sumDebts(const Debt ar[], int n);
}


// Learn6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 名称空间示例。
// 使用自定义的名称空间中的函数及结构体类型。

#include <iostream>
#include "namesp.h"

void other(void);
void another(void);

int main(void)
{
	using debts::Debt; // using声明语句
	using debts::showDebt;

	Debt golf = { {"Benny", "Goatsniff"}, 120.0 }; // 
	showDebt(golf);
	
	other();
	another();

	system("pause");
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts; // using编译指令 

	Person dg = { "Doodles", "Glister" };
	showPerson(dg);
	cout << endl;
	
	Debt zippy[3];
	for (int i = 0; i < 3; i++)
		getDebt(zippy[i]);
	for (int i = 0; i < 3; i++)
		showDebt(zippy[i]);
	cout << "Total debt: $ " << sumDebts(zippy, 3) << endl;

}

void another(void)
{
	using pers::Person;

	Person colletor = { "Milo", "Rightshift" };
	pers::showPerson(colletor);
	std::cout << std::endl;
}

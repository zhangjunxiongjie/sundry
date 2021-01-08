#include "book.h"
#include <fstream>
#include <iostream>

void Book::ResetState(Share::BookState s) // 重置状态
{
	state = s;
}
Share::BookState Book::GetState() // 
{
	return state;
}

int Book::GetId()    // 获得值
{
	return id;
}
std::string Book::GetBookname()
{
	return bookname;
}
std::string Book::GetWritername()
{
	return writername;
}
std::string Book::GetPressname()
{
	return pressname;
}
std::string Book::GetCategory()
{
	return category;
}


void Book::LookBook(int site) // 在指定行按一定格式输出书籍信息。
{
	GoToXY(0, site);
	std::cout << id;
	
	GoToXY(6, site);
	std::cout << bookname;
	
	GoToXY(26, site);
	std::cout << writername;

	GoToXY(45, site);
	std::cout << pressname;
	
	GoToXY(70, site);
	std::cout << category;
	
	GoToXY(86, site);
	switch (state)
	{
	case Share::Want:
		std::cout << "want";
		break;
	case Share::Read:
		std::cout << "read";
		break;
	case Share::Reading:
		std::cout << "reading";
		break;
	case Share::Null:
		std::cout << "null";
		break;
	default:
		std::cout << "error";
	}
	
}


void Book::Save(std::ofstream& output)  //书籍数据保存
{
	output << id << " " << bookname << " " << writername << " " << pressname << " " << category << "\n";
}

void Book::InIt(std::ifstream& input)     // 读取（初始化）书籍数据
{
	input >> id >> bookname >> writername >> pressname >> category;
	state = Share::Null; // 书籍状态为null.
}


void Book::UserSave(std::ofstream& output)
{
	output << id << " " << bookname << " " << writername << " " << pressname << " " << category;

	int middle;
	middle = StateTo(state);
	output << " " << middle << "\n";
}
void Book::UserInIt(std::ifstream& input) // 用户书库数据初始化
{
	input >> id >> bookname >> writername >> pressname >> category;
	
	int middle;
	input >> middle;
	state = ToState(middle);
}

Book::Book():id(0), bookname(""), writername(""), pressname(""), category(""), state(Share::StateError)
{
}

Book::~Book()
{
}


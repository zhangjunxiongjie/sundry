#include "book.h"
#include <fstream>
#include <iostream>

void Book::ResetState(Share::BookState s) // ����״̬
{
	state = s;
}
Share::BookState Book::GetState() // 
{
	return state;
}

int Book::GetId()    // ���ֵ
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


void Book::LookBook(int site) // ��ָ���а�һ����ʽ����鼮��Ϣ��
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


void Book::Save(std::ofstream& output)  //�鼮���ݱ���
{
	output << id << " " << bookname << " " << writername << " " << pressname << " " << category << "\n";
}

void Book::InIt(std::ifstream& input)     // ��ȡ����ʼ�����鼮����
{
	input >> id >> bookname >> writername >> pressname >> category;
	state = Share::Null; // �鼮״̬Ϊnull.
}


void Book::UserSave(std::ofstream& output)
{
	output << id << " " << bookname << " " << writername << " " << pressname << " " << category;

	int middle;
	middle = StateTo(state);
	output << " " << middle << "\n";
}
void Book::UserInIt(std::ifstream& input) // �û�������ݳ�ʼ��
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


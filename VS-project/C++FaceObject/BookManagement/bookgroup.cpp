#include "bookgroup.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <windows.h>

extern bool into1; // ѡ���Ρ�

void BookGroup::DisposeChoice(int choice) //����ѡ�� 
{
	UserUserGui(choice);

	switch (choice)
	{
	case 1:
		library->FindUser(books);
		system("cls");
		UserUserGui(choice);
		break;
	case 2:
		LookBooks();
		break;
	case 3:
		AddBook(); // Ҫʹ�������鼮ID������
		break;
	case 4:
		DeleteBook();
		break;
	case 5:  
		into1 = false; 
		break;
	default:
		break;
	}

}

void BookGroup::UserUserGui(int choice) //�û�ʹ��Gui;
{

	LightSet(false);
	GoToXY(38, 5);
	std::cout << "�û�ʹ�ý���";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.�����鼮";

	LightSet(choice == 2);
	GoToXY(40, 11); 
	std::cout << "2.�鿴�鼮";

	LightSet(choice == 3);
	GoToXY(40, 13); 
	std::cout << "3.����鼮";

	LightSet(choice == 4);
	GoToXY(40, 15); 
	std::cout << "4.ɾ���鼮";

	LightSet(choice == 5);
	GoToXY(40, 17); 
	std::cout << "5.�˳���¼";

	SetFrontColor();
}

void BookGroup::UserUser() // �û�������
{
	system("cls");

	int choice = 1; // ��ѡѡ��,����ѡ��
	UserUserGui(choice);

	into1 = true;
	bool sign = false;  // ��־λ��ÿ����һ��ѡ�����������������ѡ�񣨼������������һ������
	while (into1)
	{
		if (_kbhit())
		{
			char ch = _getch();

			if (sign && (ch == 72 || ch == 80 || ch == 13))
			{
				system("cls");
				sign = false;
			}

			switch (ch)
			{
			case 72:// up
				if (choice > 1)
				{
					choice--;
				}
				else
				{
					choice = 5;
				}
				UserUserGui(choice);
				break;
			case 80:// down
				if (choice < 5)
				{
					choice++;
				}
				else
				{
					choice = 1;
				}
				UserUserGui(choice);
				break;
			case 13: // �س���
				DisposeChoice(choice);
				sign = true;
				break;
			default:
				break;
			}

		}
	}
}


void BookGroup::LookBooks() // �鿴�����鼮
{
	
	GoToXY(0, 20);
	std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";
	
	auto book = books.begin();
	for (int i = 21; book != books.end(); ++book, i++) // �����鼮��
	{
		book->LookBook(i);
	}

	GoToXY(0, 0); // ��������û������������һ������û����浼��ѡ������ϻ���

	LightSet(true);
	GoToXY(40, 11);
	std::cout << "2.�鿴�鼮"; // �ػ�
	LightSet(false); // ���������

}

void BookGroup::StateInput(int& state) // ״̬����,Ĭ��״̬Ϊ�㡣
{
	state = 0; // ��ʼֵ��Ϊ0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // �������
		{
			char ch = _getch();

			if (ch >= 48 && ch <= 57) // 
			{
				std::cout << ch;
				state = state * 10 + ch - 48;
				number++;
			}
			else if (ch >= 96 && ch <= 105) // С���̣�֧��С����������ܻᵼ�²�����ĸҲ�������롣
			{
				std::cout << ch;
				state = state * 10 + ch - 96;
				number++;
			}
			else if (ch == 8 && number > 0) // ɾ����
			{
				state = int(state / 10);

				number--;

				std::cout << "\b"; // ����һ��
				std::cout << " ";
				std::cout << "\b";
			}
			else if (ch == 13)
			{
				return; // �س�ֱ�ӷ��ء�
			}
			else
				continue;
		}
		if (number == 2)// ��֤���2���ַ�����,���������û���Ϊ100����
		{
			return;
		}
	}
}

void BookGroup::AddBook() // ID����鼮,���ID��ͬ��Ϊ�޸��鼮״̬��������ΪҪʹ�õ��鼮���ҹ��������Ȳ�ʵ�֡�
{

	GoToXY(40, 13);
	std::cout << "����������鼮ID��";
	int bookid;
	IdInPut(bookid); // �鼮ID���룬�м������ơ�
	GoToXY(40, 13);
	std::cout << "                          ";

	Book* bookp = library->IdFindUser(bookid); // ���û�����鼮ʹ�õ�ID��ѯ�߼�������

	if (bookp == NULL)
	{
		
		GoToXY(40, 19);
		std::cout << "�����鼮ID�����ڣ�����";

	}
	else
	{
		Book book = *bookp;

		GoToXY(40, 13);
		std::cout << "����������鼮״̬��";
		int state;
		StateInput(state);
		GoToXY(40, 13);
		std::cout << "                            ";

		book.ResetState(ToState(state));  // ����״̬�� 

		for (auto bookr = books.begin(); bookr != books.end(); ++bookr) // ����鼮���ڣ�����Ҫɾ��ԭ�鼮��
		{
			if (bookr != books.end() && bookr->GetId() == bookid)
			{
				books.erase(bookr);
				booknumber--;
				break;
			}

		}

		books.push_back(book);
		booknumber++;
		
	}
	

	LightSet(true);
	GoToXY(40, 13);
	std::cout << "3.����鼮";
	LightSet(false);
}



void BookGroup::IdInPut(int& id) // id�����ɾ��ID��һ�������Լ�����롣���ֻ������4λ����
{
	id = 0; // ��ʼֵ��Ϊ0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // �������
		{
			char ch = _getch();

			if (ch >= 48 && ch <= 57) // 
			{
				std::cout << ch;
				id = id * 10 + ch - 48;
				number++;
			}
			else if (ch >= 96 && ch <= 105) // С���̣�֧��С����������ܻᵼ�²�����ĸҲ�������롣
			{
				std::cout << ch;
				id = id * 10 + ch - 96;
				number++;
			}
			else if (ch == 8 && number > 0) // ɾ����
			{
				id = int(id / 10);

				number--;

				std::cout << "\b"; // ����һ��
				std::cout << " ";
				std::cout << "\b";
			}
			else if (ch == 13)
			{
				if (number == 0) // ��numberΪ0ʱ��ʾ�������ʱӦ�÷���-1������1���鼮��ɾ��
				{
					id = -1; 
				}
				return; // �س�ֱ�ӷ��ء�
			}
			else
				continue;
		}
		if (number == 4)// ��֤���5���ַ�����,���������鼮��Ϊ10000����
		{
			return;
		}
	}

}
void BookGroup::DeleteBook()  // ɾ���鼮��
{
	GoToXY(40, 15);
	std::cout << "������ɾ���鼮ID��";
	int bookid;
	IdInPut(bookid); // �鼮ID���룬�м������ơ�
	GoToXY(40, 15);  //����
	std::cout << "                      ";

	for (auto book = books.begin(); bookid != -1 && book != books.end(); ++book) // ���δ�ҵ��鼮�򲻻����κ�Ч����
	{
		if (book->GetId() == bookid)
		{
			books.erase(book);
			booknumber--;
			break;
		}
	}

	LightSet(true);
	GoToXY(40, 15);
	std::cout << "4.ɾ���鼮";
	SetFrontColor();
}



void BookGroup::InIt() // ��ʼ��������⡣
{

	std::ifstream BooksIn(UserBookFile); // ��ȡ�û���������ļ���

	if (!BooksIn.is_open()) // ��������û�����ļ���ʧ��
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "���ش���δ�ҵ��û�����ļ�������"; // 
		Sleep(3000); // ��ʱ

		system("exit"); // �˳���������  // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	// �ļ�������
	BooksIn.seekg(std::ios::beg); //�����ļ�������ʼλ�á� 
	BooksIn >> booknumber; // ��ȡ�鼮��
	for (int i = 0; i < booknumber; i++)
	{
		Book book;
		book.UserInIt(BooksIn); // �û���������
		books.push_back(book);
	}

	BooksIn.close();

}
void BookGroup::Save() // ���������⡣
{
	std::ofstream BooksOut(UserBookFile);  // д���û��ļ�

	if (!BooksOut.is_open()) // ����û��ļ���ʧ��
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "���ش���δ�ҵ��û�����ļ�,�����޸Ľ���Ч������"; // 
		Sleep(3000); // ��ʱ

		system("exit"); // �˳���������  // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	// �ļ�д��
	BooksOut.seekp(std::ios::beg);   // �����ļ�д�뿪ʼλ�á�
	BooksOut << booknumber << "\n";
	for (auto book = books.begin(); book != books.end(); ++book) // 
	{
		book->UserSave(BooksOut); // д�����
	}

	BooksOut.close();
}



BookGroup::BookGroup(std::string a, Library* b):UserBookFile(a), library(b), booknumber(0)
{
	InIt();
}
BookGroup::~BookGroup()
{
	Save();
}

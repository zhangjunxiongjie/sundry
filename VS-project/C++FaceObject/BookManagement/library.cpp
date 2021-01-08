#include "library.h"
#include "share.h"
#include <fstream> // ��ȡ����ļ�
#include <iostream>
#include <windows.h>
#include <conio.h>

extern bool into1;
extern bool into2;
extern bool into3;

void Library::LibraryGroupGui(int choice) // GUI
{
	LightSet(false);
	GoToXY(38, 5);
	std::cout << "���������";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.�����鼮";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.����鼮";

	LightSet(choice == 3);
	GoToXY(40, 13); 
	std::cout << "3.ɾ���鼮";

	LightSet(choice == 4);
	GoToXY(40, 15); 
	std::cout << "4.��⵼��";

	LightSet(choice == 5);
	GoToXY(40, 17); 
	std::cout << "5.������һ��";

	LightSet(choice == 6);
	GoToXY(40, 19); 
	std::cout << "6.�˳���¼";

	LightSet(false);
}

void Library::DisposeChoice(int choice) // ѡ���֧����
{
	LibraryGroupGui(choice); // ��֤�������������ѡ�����һֱ���ڣ�����������������������ѡ��ٴλ�������

	switch (choice)
	{
	case 1:
		Find();
		system("cls");
		LibraryGroupGui(choice);
		break;
	case 2:
		AddBook();
		break;
	case 3:
		DeleteBook();
		break;
	case 4: 
		ImportData(); // �������ݡ�
		break;
	case 5:   // ������һ����
		into2 = false;
		break;
	case 6:  // �˳���¼��
		into1 = false;
		into2 = false;
		break;
	default:

		break;
	}
}

void Library::LibraryGroup() // ���������߼���
{
	system("cls");
	int choice = 1; // ��ѡѡ��,����ѡ��
	LibraryGroupGui(choice);

	into2 = true;
	bool sign = false;  
	while (into2)
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
					choice = 6;
				}
				LibraryGroupGui(choice);
				break;
			case 80:// down
				if (choice < 6)
				{
					choice++;
				}
				else
				{
					choice = 1;
				}
				LibraryGroupGui(choice);
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


int Library::ProduceId() // ר�����ڲ����鼮id
{
	for (int i = 0; i < booknumber; i++) // ���ﲻ֪����++����ǰ��ͺ�����û��ʲô����
	{
		auto book = books.begin();
		for (; book != books.end(); ++book) // ��֤�˲�����IDδʹ��
		{
			if (book->GetId() == i)
			{
				break;
			}
		}

		if (book == books.end()) // ���forѭ��������break������˵����ʱi���á�
		{
			return i; // �򵥴ֱ�ֱ���ҵ���һ��δʹ�õ��û�ID��
		}
	}

	return booknumber;
}

void Library::AddBook() // ����鼮���鼮ID��ϵͳ���ɣ�
{

	if (booknumber == BOOK_MAX_NUMBER) // �����ǰ�鼮����������鼮������ʾֱ���˳���
	{
		GoToXY(30, 21);
		std::cout << "��ǰ�Ѵﵽ����鼮�����޷���������鼮��";
		return;
	}

	Book book;
	std::string middle;

	book.id = ProduceId(); // ϵͳ�����û�ID

	GoToXY(40, 11);
	std::cout << "������������";
	std::cin >> middle;
	GoToXY(40, 11);
	std::cout << "                                                                         ";
	if (middle.size() <= 20)
	{
		book.bookname = middle;
		middle.clear();

		GoToXY(40, 11);
		std::cout << "��������������";
		std::cin >> middle;
		GoToXY(40, 11);
		std::cout << "                                                                         ";

		if (middle.size() <= 20)
		{
			book.writername = middle;
			middle.clear();
			
			GoToXY(40, 11);
			std::cout << "���������������";
			std::cin >> middle;
			GoToXY(40, 11);
			std::cout << "                                                                         ";

			if (middle.size() <= 20)
			{
				book.pressname = middle;
				middle.clear();

				GoToXY(40, 11);
				std::cout << "�������鼮���";
				std::cin >> middle;

				if (middle.size() <= 20)
				{
					book.category = middle;

					books.push_back(book);
					booknumber++;

					system("cls");
					LibraryGroupGui(2); // ��ȫ�ػ档

					GoToXY(40, 21);
					std::cout << "�鼮��ӳɹ���";

					return;

				}
				else
				{
					system("cls");
					LibraryGroupGui(2);

					GoToXY(40, 21);
					std::cout << "�������룬�鼮���ʧ�ܡ�";

					return;
				}
			}
			else
			{
				system("cls");
				LibraryGroupGui(2);

				GoToXY(40, 21);
				std::cout << "�������룬�鼮���ʧ�ܡ�";

				return;
			}
		}
		else
		{
			system("cls");
			LibraryGroupGui(2);

			GoToXY(40, 21);
			std::cout << "�������룬�鼮���ʧ�ܡ�";

			return;
		}

	}
	else // ��������ֱ���˳�
	{
		system("cls");
		LibraryGroupGui(2);

		GoToXY(40, 21);
		std::cout << "�������룬�鼮���ʧ�ܡ�";

		return;
	}

}

void Library::DeleteBook() // ɾ���鼮(ֻ�ܸ����鼮IDɾ��)
{
	GoToXY(40, 13);
	std::cout << "������ɾ���û�ID��";
	int id;
	IdInput(id);	
	GoToXY(40, 13);
	std::cout << "                          ";  // \b�˸�

	for (auto book = books.begin(); book != books.end(); ++book) // id!=0��֤���޷�ɾ��root�û�
	{
		if (book->GetId() == id)
		{
			books.erase(book); // ���ݴ�������ҳ���֮��ͬ�Ķ���Ԫ��Ȼ��ɾ����Ԫ�أ�
			booknumber--;  // ���ĵ�ǰ�û�������
			break;
		}
	}

	LightSet(true);
	GoToXY(40, 13);
	std::cout << "3.ɾ���鼮";
	LightSet(false); // ���������
}

void Library::ImportData() // �������ݡ�
{

}

void Library::FindUser(std::list<Book>& userbooks) // �û����״̬���¡�
{

	for (auto book1 = userbooks.begin(); book1 != userbooks.end(); ++book1)
	{
		for (auto book2 = books.begin(); book2 != books.end(); ++book2)
		{
			if (book2->GetId() == book1->GetId())
			{
				book2->ResetState(book1->GetState());
				break;
			}
		}
	}
	
	Find();
}

void Library::FindGui(int choice) // GUI
{
	LightSet(false);
	GoToXY(38, 5);
	std::cout << "�鼮���ҽ���";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.ID����";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.��������";

	LightSet(choice == 3);
	GoToXY(40, 13);
	std::cout << "3.���߲���";

	LightSet(choice == 4);
	GoToXY(40, 15);
	std::cout << "4.���������";

	LightSet(choice == 5);
	GoToXY(40, 17);
	std::cout << "5.������";

	LightSet(choice == 6);
	GoToXY(40, 19);
	std::cout << "6.������һ��";

	LightSet(choice == 7);
	GoToXY(40, 21);
	std::cout << "7.�˳���¼";

	LightSet(false);
}

void Library::FindDisposeChoice(int choice) // ѡ���֧����
{
	FindGui(choice); // ��֤�������������ѡ�����һֱ���ڣ�����������������������ѡ��ٴλ�������

	switch (choice)
	{
	case 1:
		IdFind();
		break;
	case 2:
		BookNameFind();
		break;
	case 3:
		WriterNameFind();
		break;
	case 4:
		PressNameFind();
		break;
	case 5:
		CategoryFind();
		break;
	case 6: // ������һ����
		into3 = false;
		break;
	case 7:   // �˳���¼��
		into1 = false;
		into2 = false;
		into3 = false;
		break;
	default:
		break;
	}

}


void Library::Find() // ����Ա��������������û�������ʹ�õĲ����������û�����ʾ״̬�������û��򲻻ᣩ
{
	system("cls");
	int choice = 1; // ��ѡѡ��,����ѡ��
	FindGui(choice);

	into3 = true;
	bool sign = false;  // ��־λ��ÿ����һ��ѡ�����������������ѡ�񣨼������������һ������
	while (into3)
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
					choice = 7;
				}
				FindGui(choice);
				break;
			case 80:// down
				if (choice < 7)
				{
					choice++;
				}
				else
				{
					choice = 1;
				}
				FindGui(choice);
				break;
			case 13: // �س���
				FindDisposeChoice(choice);
				sign = true;
				break;
			default:
				break;
			}

		}
	}
}

void Library::IdInput(int& id) // ID���롣
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
				id = id * 10 + (ch - 48);
				number++;
			}
			else if (ch >= 96 && ch <= 105) // С���̣�֧��С����������ܻᵼ�²�����ĸҲ�������롣
			{
				std::cout << ch;
				id = id * 10 + (ch - 96);
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

Book* Library::IdFindUser(int id) // ���û�����鼮ʹ�õ�ID��ѯ�߼�������
{
	for (auto book = books.begin(); book != books.end(); ++book)
	{
		if (book->GetId() == id)
		{
			return &(*book); // ��������
		}
	}
	return NULL;
}

void Library::IdFind() // ID�������߼�
{
	
	GoToXY(40, 9);
	std::cout << "������ID��";
	int bookid;
	IdInput(bookid);
	GoToXY(40, 9);
	std::cout << "              "; // ��������

	Book* book = IdFindUser(bookid);

	GoToXY(0, 23);
	std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";
	if (book) // ��Ϊ��
	{
		book->LookBook(24);
	}

	GoToXY(0, 0); // ��������û������������һ������û����浼��ѡ������ϻ���

	LightSet(true);
	GoToXY(40, 9);
	std::cout << "1.ID����"; // �ػ�
	LightSet(false); // ���������
}


void Library::BookNameFind() // �������ң�
{
	GoToXY(40, 11);
	std::cout << "������������";
	std::string bookname;
	std::cin >> bookname;  // �������벻����顣
	GoToXY(40, 11);
	std::cout << "                                    "; // ��������

	if (bookname.size() <= 20) // �������С�ڵ���20����Ϊ��������
	{
		GoToXY(0, 23);
		std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";

		auto book = books.begin();
		for (int i = 24; book != books.end(); ++book)
		{
			if (book->GetBookname() == bookname) // ̰�����ң�
			{
				book->LookBook(i);
				i++;
			}
		}

		GoToXY(0, 0); // ������������������һ��������浼��ѡ������ϻ���
		LightSet(true);
		GoToXY(40, 11);
		std::cout << "2.��������"; // �ػ�
		LightSet(false); // ���������
	}
	else // �쳣���롣
	{
		system("cls");
		FindGui(2);
	}
	
}

void Library::WriterNameFind() // ���߲��ң�
{
	GoToXY(40, 13);
	std::cout << "��������������";
	std::string writername;
	std::cin >> writername;  // �������벻����顣
	GoToXY(40, 13);
	std::cout << "                                    "; // ��������

	if (writername.size() <= 20) // �������С�ڵ���20����Ϊ��������
	{
		GoToXY(0, 23);
		std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";

		auto book = books.begin();
		for (int i = 24; book != books.end(); ++book)
		{
			if (book->GetWritername() == writername)
			{
				book->LookBook(i);
				i++;
			}
		}

		GoToXY(0, 0); // ������������������һ��������浼��ѡ������ϻ���
		LightSet(true);
		GoToXY(40, 13);
		std::cout << "3.���߲���"; // �ػ�
		LightSet(false); // ���������
	}
	else // �쳣���롣
	{
		system("cls");
		FindGui(3);
	}
}

void Library::PressNameFind() // ��������ҡ�
{
	GoToXY(40, 15);
	std::cout << "���������������";
	std::string pressname;
	std::cin >> pressname;  // �������벻����顣
	GoToXY(40, 15);
	std::cout << "                                    "; // ��������

	if (pressname.size() <= 20) // �������С�ڵ���20����Ϊ��������
	{

		GoToXY(0, 23);
		std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";

		auto book = books.begin();
		for (int i = 24; book != books.end(); ++book)
		{
			if (book->GetPressname() == pressname)
			{
				book->LookBook(i);
				i++;
			}
		}

		GoToXY(0, 0); // ������������������һ��������浼��ѡ������ϻ���
		LightSet(true);
		GoToXY(40, 15);
		std::cout << "4.���������"; // �ػ�
		LightSet(false); // ���������
	}
	else // �쳣���롣
	{
		system("cls");
		FindGui(4);
	}
}

void Library::CategoryFind() // �����ҡ�
{
	GoToXY(40, 17);
	std::cout << "���������";
	std::string category;
	std::cin >> category;  // �������벻����顣
	GoToXY(40, 17);
	std::cout << "                                    "; // ��������

	if (category.size() <= 20) // �������С�ڵ���20����Ϊ��������
	{

		GoToXY(0, 23);
		std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";

		auto book = books.begin();
		for (int i = 24; book != books.end(); ++book)
		{
			if (book->GetCategory() == category)
			{
				book->LookBook(i);
				i++;
			}
		}

		GoToXY(0, 0); // ������������������һ��������浼��ѡ������ϻ���
		LightSet(true);
		GoToXY(40, 17);
		std::cout << "5.������"; // �ػ�
		LightSet(false); // ���������
	}
	else // �쳣���롣
	{
		system("cls");
		FindGui(5);
	}
}


void Library::Init() // ��ʼ������б�
{
	std::ifstream LibraryIn(LIBRARY_FILE);  // ��ȡ����ļ�

	if (!LibraryIn.is_open()) // �������ļ���ʧ��
	{
		std::cout << "���ش���δ�ҵ�����ļ�������"; // 

		system("exit"); // �˳��������� // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	LibraryIn >> booknumber; // ��ȡ�鼮��

	for (int i = 0; i < booknumber; i++) // 
	{
		Book book;  // ��ʱ����

		book.InIt(LibraryIn); // ��ȡ����

		books.push_back(book); // ���鼮�������
	}

	LibraryIn.close(); // �ر�����ļ�
}

void Library::Save() // ������ݱ���
{
	std::ofstream LibraryOut(LIBRARY_FILE);  // д���û��ļ�

	if (!LibraryOut.is_open()) // ����û��ļ���ʧ��
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "���ش���δ�ҵ�����ļ�,�����޸Ľ���Ч������"; // 
		Sleep(3000); // ��ʱ

		system("exit"); // �˳���������  // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	LibraryOut.seekp(std::ios::beg);   // �����ļ�д�뿪ʼλ�á�

	LibraryOut << booknumber << "\n";

	for (auto book = books.begin(); book != books.end(); ++book) // 
	{
		book->Save(LibraryOut); // д�����
	}

	LibraryOut.close();

}


Library::Library():booknumber(0)
{
	Init();
}

Library::~Library()
{
	Save();
}



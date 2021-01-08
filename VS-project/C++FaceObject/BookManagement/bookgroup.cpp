#include "bookgroup.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <windows.h>

extern bool into1; // 选项层次。

void BookGroup::DisposeChoice(int choice) //处理选项 
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
		AddBook(); // 要使用书库的书籍ID搜索。
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

void BookGroup::UserUserGui(int choice) //用户使用Gui;
{

	LightSet(false);
	GoToXY(38, 5);
	std::cout << "用户使用界面";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.查找书籍";

	LightSet(choice == 2);
	GoToXY(40, 11); 
	std::cout << "2.查看书籍";

	LightSet(choice == 3);
	GoToXY(40, 13); 
	std::cout << "3.添加书籍";

	LightSet(choice == 4);
	GoToXY(40, 15); 
	std::cout << "4.删除书籍";

	LightSet(choice == 5);
	GoToXY(40, 17); 
	std::cout << "5.退出登录";

	SetFrontColor();
}

void BookGroup::UserUser() // 用户书库管理；
{
	system("cls");

	int choice = 1; // 所选选项,高亮选项
	UserUserGui(choice);

	into1 = true;
	bool sign = false;  // 标志位，每进行一个选项输出结果后如果继续选择（即按键）则会清一次屏。
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
			case 13: // 回车键
				DisposeChoice(choice);
				sign = true;
				break;
			default:
				break;
			}

		}
	}
}


void BookGroup::LookBooks() // 查看所有书籍
{
	
	GoToXY(0, 20);
	std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";
	
	auto book = books.begin();
	for (int i = 21; book != books.end(); ++book, i++) // 遍历书籍组
	{
		book->LookBook(i);
	}

	GoToXY(0, 0); // 避免输出用户后光标落在最后一个输出用户后面导致选项界面上滑。

	LightSet(true);
	GoToXY(40, 11);
	std::cout << "2.查看书籍"; // 重绘
	LightSet(false); // 避免白屏。

}

void BookGroup::StateInput(int& state) // 状态输入,默认状态为零。
{
	state = 0; // 初始值设为0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // 按键检测
		{
			char ch = _getch();

			if (ch >= 48 && ch <= 57) // 
			{
				std::cout << ch;
				state = state * 10 + ch - 48;
				number++;
			}
			else if (ch >= 96 && ch <= 105) // 小键盘，支持小键盘输入可能会导致部分字母也可以输入。
			{
				std::cout << ch;
				state = state * 10 + ch - 96;
				number++;
			}
			else if (ch == 8 && number > 0) // 删除键
			{
				state = int(state / 10);

				number--;

				std::cout << "\b"; // 后退一格；
				std::cout << " ";
				std::cout << "\b";
			}
			else if (ch == 13)
			{
				return; // 回车直接返回。
			}
			else
				continue;
		}
		if (number == 2)// 保证最大2个字符输入,及最大可能用户数为100个。
		{
			return;
		}
	}
}

void BookGroup::AddBook() // ID添加书籍,如果ID相同则为修改书籍状态，这里因为要使用到书籍查找功能所以先不实现。
{

	GoToXY(40, 13);
	std::cout << "请输入添加书籍ID：";
	int bookid;
	IdInPut(bookid); // 书籍ID输入，有检查和限制。
	GoToXY(40, 13);
	std::cout << "                          ";

	Book* bookp = library->IdFindUser(bookid); // 给用户添加书籍使用的ID查询逻辑独立快

	if (bookp == NULL)
	{
		
		GoToXY(40, 19);
		std::cout << "输入书籍ID不存在！！！";

	}
	else
	{
		Book book = *bookp;

		GoToXY(40, 13);
		std::cout << "请输入添加书籍状态：";
		int state;
		StateInput(state);
		GoToXY(40, 13);
		std::cout << "                            ";

		book.ResetState(ToState(state));  // 重置状态。 

		for (auto bookr = books.begin(); bookr != books.end(); ++bookr) // 如果书籍存在，则需要删除原书籍。
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
	std::cout << "3.添加书籍";
	LightSet(false);
}



void BookGroup::IdInPut(int& id) // id输入对删除ID做一个限制性检查输入。最多只能输入4位数。
{
	id = 0; // 初始值设为0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // 按键检测
		{
			char ch = _getch();

			if (ch >= 48 && ch <= 57) // 
			{
				std::cout << ch;
				id = id * 10 + ch - 48;
				number++;
			}
			else if (ch >= 96 && ch <= 105) // 小键盘，支持小键盘输入可能会导致部分字母也可以输入。
			{
				std::cout << ch;
				id = id * 10 + ch - 96;
				number++;
			}
			else if (ch == 8 && number > 0) // 删除键
			{
				id = int(id / 10);

				number--;

				std::cout << "\b"; // 后退一格；
				std::cout << " ";
				std::cout << "\b";
			}
			else if (ch == 13)
			{
				if (number == 0) // 当number为0时表示无输入此时应该返回-1，避免1号书籍被删。
				{
					id = -1; 
				}
				return; // 回车直接返回。
			}
			else
				continue;
		}
		if (number == 4)// 保证最大5个字符输入,即最大可能书籍数为10000个。
		{
			return;
		}
	}

}
void BookGroup::DeleteBook()  // 删除书籍。
{
	GoToXY(40, 15);
	std::cout << "请输入删除书籍ID：";
	int bookid;
	IdInPut(bookid); // 书籍ID输入，有检查和限制。
	GoToXY(40, 15);  //清理
	std::cout << "                      ";

	for (auto book = books.begin(); bookid != -1 && book != books.end(); ++book) // 如果未找到书籍则不会有任何效果。
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
	std::cout << "4.删除书籍";
	SetFrontColor();
}



void BookGroup::InIt() // 初始化个人书库。
{

	std::ifstream BooksIn(UserBookFile); // 读取用户个人书库文件。

	if (!BooksIn.is_open()) // 如果个人用户书库文件打开失败
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "严重错误：未找到用户书库文件！！！"; // 
		Sleep(3000); // 延时

		system("exit"); // 退出整个程序  // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	// 文件读出。
	BooksIn.seekg(std::ios::beg); //设置文件读出开始位置。 
	BooksIn >> booknumber; // 读取书籍数
	for (int i = 0; i < booknumber; i++)
	{
		Book book;
		book.UserInIt(BooksIn); // 用户书库读出。
		books.push_back(book);
	}

	BooksIn.close();

}
void BookGroup::Save() // 保存个人书库。
{
	std::ofstream BooksOut(UserBookFile);  // 写入用户文件

	if (!BooksOut.is_open()) // 如果用户文件打开失败
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "严重错误：未找到用户书库文件,所有修改将无效！！！"; // 
		Sleep(3000); // 延时

		system("exit"); // 退出整个程序  // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	// 文件写入
	BooksOut.seekp(std::ios::beg);   // 设置文件写入开始位置。
	BooksOut << booknumber << "\n";
	for (auto book = books.begin(); book != books.end(); ++book) // 
	{
		book->UserSave(BooksOut); // 写入对象
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

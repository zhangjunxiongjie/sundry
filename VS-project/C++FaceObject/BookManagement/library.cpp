#include "library.h"
#include "share.h"
#include <fstream> // 读取书库文件
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
	std::cout << "书库管理界面";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.查找书籍";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.添加书籍";

	LightSet(choice == 3);
	GoToXY(40, 13); 
	std::cout << "3.删除书籍";

	LightSet(choice == 4);
	GoToXY(40, 15); 
	std::cout << "4.书库导入";

	LightSet(choice == 5);
	GoToXY(40, 17); 
	std::cout << "5.返回上一级";

	LightSet(choice == 6);
	GoToXY(40, 19); 
	std::cout << "6.退出登录";

	LightSet(false);
}

void Library::DisposeChoice(int choice) // 选项分支处理。
{
	LibraryGroupGui(choice); // 保证在清屏的情况下选择界面一直存在，（清屏有两个条件：进入选项，再次击键。）

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
		ImportData(); // 导入数据。
		break;
	case 5:   // 返回上一级。
		into2 = false;
		break;
	case 6:  // 退出登录。
		into1 = false;
		into2 = false;
		break;
	default:

		break;
	}
}

void Library::LibraryGroup() // 书库管理主逻辑。
{
	system("cls");
	int choice = 1; // 所选选项,高亮选项
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


int Library::ProduceId() // 专门用于产生书籍id
{
	for (int i = 0; i < booknumber; i++) // 这里不知道把++放在前面和后面有没有什么区别。
	{
		auto book = books.begin();
		for (; book != books.end(); ++book) // 保证了产生的ID未使用
		{
			if (book->GetId() == i)
			{
				break;
			}
		}

		if (book == books.end()) // 如果for循环不是由break出来的说明此时i可用。
		{
			return i; // 简单粗暴直接找到第一个未使用的用户ID。
		}
	}

	return booknumber;
}

void Library::AddBook() // 添加书籍（书籍ID由系统生成）
{

	if (booknumber == BOOK_MAX_NUMBER) // 如果当前书籍数等于最大书籍数则提示直接退出。
	{
		GoToXY(30, 21);
		std::cout << "当前已达到最大书籍数，无法继续添加书籍。";
		return;
	}

	Book book;
	std::string middle;

	book.id = ProduceId(); // 系统产生用户ID

	GoToXY(40, 11);
	std::cout << "请输入书名：";
	std::cin >> middle;
	GoToXY(40, 11);
	std::cout << "                                                                         ";
	if (middle.size() <= 20)
	{
		book.bookname = middle;
		middle.clear();

		GoToXY(40, 11);
		std::cout << "请输入作者名：";
		std::cin >> middle;
		GoToXY(40, 11);
		std::cout << "                                                                         ";

		if (middle.size() <= 20)
		{
			book.writername = middle;
			middle.clear();
			
			GoToXY(40, 11);
			std::cout << "请输入出版社名：";
			std::cin >> middle;
			GoToXY(40, 11);
			std::cout << "                                                                         ";

			if (middle.size() <= 20)
			{
				book.pressname = middle;
				middle.clear();

				GoToXY(40, 11);
				std::cout << "请输入书籍类别：";
				std::cin >> middle;

				if (middle.size() <= 20)
				{
					book.category = middle;

					books.push_back(book);
					booknumber++;

					system("cls");
					LibraryGroupGui(2); // 完全重绘。

					GoToXY(40, 21);
					std::cout << "书籍添加成功。";

					return;

				}
				else
				{
					system("cls");
					LibraryGroupGui(2);

					GoToXY(40, 21);
					std::cout << "错误输入，书籍添加失败。";

					return;
				}
			}
			else
			{
				system("cls");
				LibraryGroupGui(2);

				GoToXY(40, 21);
				std::cout << "错误输入，书籍添加失败。";

				return;
			}
		}
		else
		{
			system("cls");
			LibraryGroupGui(2);

			GoToXY(40, 21);
			std::cout << "错误输入，书籍添加失败。";

			return;
		}

	}
	else // 错误输入直接退出
	{
		system("cls");
		LibraryGroupGui(2);

		GoToXY(40, 21);
		std::cout << "错误输入，书籍添加失败。";

		return;
	}

}

void Library::DeleteBook() // 删除书籍(只能根据书籍ID删除)
{
	GoToXY(40, 13);
	std::cout << "请输入删除用户ID：";
	int id;
	IdInput(id);	
	GoToXY(40, 13);
	std::cout << "                          ";  // \b退格

	for (auto book = books.begin(); book != books.end(); ++book) // id!=0保证了无法删除root用户
	{
		if (book->GetId() == id)
		{
			books.erase(book); // 根据传入对象找出与之相同的对象元素然后删除此元素；
			booknumber--;  // 更改当前用户总数。
			break;
		}
	}

	LightSet(true);
	GoToXY(40, 13);
	std::cout << "3.删除书籍";
	LightSet(false); // 避免白屏。
}

void Library::ImportData() // 导入数据。
{

}

void Library::FindUser(std::list<Book>& userbooks) // 用户书库状态更新。
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
	std::cout << "书籍查找界面";

	LightSet(choice == 1);
	GoToXY(40, 9);
	std::cout << "1.ID查找";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.书名查找";

	LightSet(choice == 3);
	GoToXY(40, 13);
	std::cout << "3.作者查找";

	LightSet(choice == 4);
	GoToXY(40, 15);
	std::cout << "4.出版社查找";

	LightSet(choice == 5);
	GoToXY(40, 17);
	std::cout << "5.类别查找";

	LightSet(choice == 6);
	GoToXY(40, 19);
	std::cout << "6.返回上一级";

	LightSet(choice == 7);
	GoToXY(40, 21);
	std::cout << "7.退出登录";

	LightSet(false);
}

void Library::FindDisposeChoice(int choice) // 选项分支处理。
{
	FindGui(choice); // 保证在清屏的情况下选择界面一直存在，（清屏有两个条件：进入选项，再次击键。）

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
	case 6: // 返回上一级。
		into3 = false;
		break;
	case 7:   // 退出登录。
		into1 = false;
		into2 = false;
		into3 = false;
		break;
	default:
		break;
	}

}


void Library::Find() // 管理员书库搜索（三种用户都可以使用的操作，个人用户会显示状态，其他用户则不会）
{
	system("cls");
	int choice = 1; // 所选选项,高亮选项
	FindGui(choice);

	into3 = true;
	bool sign = false;  // 标志位，每进行一个选项输出结果后如果继续选择（即按键）则会清一次屏。
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
			case 13: // 回车键
				FindDisposeChoice(choice);
				sign = true;
				break;
			default:
				break;
			}

		}
	}
}

void Library::IdInput(int& id) // ID输入。
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
				id = id * 10 + (ch - 48);
				number++;
			}
			else if (ch >= 96 && ch <= 105) // 小键盘，支持小键盘输入可能会导致部分字母也可以输入。
			{
				std::cout << ch;
				id = id * 10 + (ch - 96);
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

Book* Library::IdFindUser(int id) // 给用户添加书籍使用的ID查询逻辑独立快
{
	for (auto book = books.begin(); book != books.end(); ++book)
	{
		if (book->GetId() == id)
		{
			return &(*book); // 迭代器。
		}
	}
	return NULL;
}

void Library::IdFind() // ID查找主逻辑
{
	
	GoToXY(40, 9);
	std::cout << "请输入ID：";
	int bookid;
	IdInput(bookid);
	GoToXY(40, 9);
	std::cout << "              "; // 残余清理。

	Book* book = IdFindUser(bookid);

	GoToXY(0, 23);
	std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";
	if (book) // 不为空
	{
		book->LookBook(24);
	}

	GoToXY(0, 0); // 避免输出用户后光标落在最后一个输出用户后面导致选项界面上滑。

	LightSet(true);
	GoToXY(40, 9);
	std::cout << "1.ID查找"; // 重绘
	LightSet(false); // 避免白屏。
}


void Library::BookNameFind() // 书名查找；
{
	GoToXY(40, 11);
	std::cout << "请输入书名：";
	std::string bookname;
	std::cin >> bookname;  // 中文输入不做检查。
	GoToXY(40, 11);
	std::cout << "                                    "; // 残余清理。

	if (bookname.size() <= 20) // 如果长度小于等于20，则为正常输入
	{
		GoToXY(0, 23);
		std::cout << "ID" << "    " << "bookname" << "            " << "writername" << "         " << "pressname" << "                " << "category" << "        " << "state";

		auto book = books.begin();
		for (int i = 24; book != books.end(); ++book)
		{
			if (book->GetBookname() == bookname) // 贪婪查找，
			{
				book->LookBook(i);
				i++;
			}
		}

		GoToXY(0, 0); // 避免输出后光标落在最后一个输出后面导致选项界面上滑。
		LightSet(true);
		GoToXY(40, 11);
		std::cout << "2.书名查找"; // 重绘
		LightSet(false); // 避免白屏。
	}
	else // 异常输入。
	{
		system("cls");
		FindGui(2);
	}
	
}

void Library::WriterNameFind() // 作者查找；
{
	GoToXY(40, 13);
	std::cout << "请输入作者名：";
	std::string writername;
	std::cin >> writername;  // 中文输入不做检查。
	GoToXY(40, 13);
	std::cout << "                                    "; // 残余清理。

	if (writername.size() <= 20) // 如果长度小于等于20，则为正常输入
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

		GoToXY(0, 0); // 避免输出后光标落在最后一个输出后面导致选项界面上滑。
		LightSet(true);
		GoToXY(40, 13);
		std::cout << "3.作者查找"; // 重绘
		LightSet(false); // 避免白屏。
	}
	else // 异常输入。
	{
		system("cls");
		FindGui(3);
	}
}

void Library::PressNameFind() // 出版社查找。
{
	GoToXY(40, 15);
	std::cout << "请输入出版社名：";
	std::string pressname;
	std::cin >> pressname;  // 中文输入不做检查。
	GoToXY(40, 15);
	std::cout << "                                    "; // 残余清理。

	if (pressname.size() <= 20) // 如果长度小于等于20，则为正常输入
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

		GoToXY(0, 0); // 避免输出后光标落在最后一个输出后面导致选项界面上滑。
		LightSet(true);
		GoToXY(40, 15);
		std::cout << "4.出版社查找"; // 重绘
		LightSet(false); // 避免白屏。
	}
	else // 异常输入。
	{
		system("cls");
		FindGui(4);
	}
}

void Library::CategoryFind() // 类别查找。
{
	GoToXY(40, 17);
	std::cout << "请输入类别：";
	std::string category;
	std::cin >> category;  // 中文输入不做检查。
	GoToXY(40, 17);
	std::cout << "                                    "; // 残余清理。

	if (category.size() <= 20) // 如果长度小于等于20，则为正常输入
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

		GoToXY(0, 0); // 避免输出后光标落在最后一个输出后面导致选项界面上滑。
		LightSet(true);
		GoToXY(40, 17);
		std::cout << "5.类别查找"; // 重绘
		LightSet(false); // 避免白屏。
	}
	else // 异常输入。
	{
		system("cls");
		FindGui(5);
	}
}


void Library::Init() // 初始化书库列表
{
	std::ifstream LibraryIn(LIBRARY_FILE);  // 读取书库文件

	if (!LibraryIn.is_open()) // 如果书库文件打开失败
	{
		std::cout << "严重错误：未找到书库文件！！！"; // 

		system("exit"); // 退出整个程序 // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	LibraryIn >> booknumber; // 读取书籍数

	for (int i = 0; i < booknumber; i++) // 
	{
		Book book;  // 临时变量

		book.InIt(LibraryIn); // 读取对象

		books.push_back(book); // 将书籍加入书库
	}

	LibraryIn.close(); // 关闭书库文件
}

void Library::Save() // 书库数据保存
{
	std::ofstream LibraryOut(LIBRARY_FILE);  // 写入用户文件

	if (!LibraryOut.is_open()) // 如果用户文件打开失败
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "严重错误：未找到书库文件,所有修改将无效！！！"; // 
		Sleep(3000); // 延时

		system("exit"); // 退出整个程序  // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	LibraryOut.seekp(std::ios::beg);   // 设置文件写入开始位置。

	LibraryOut << booknumber << "\n";

	for (auto book = books.begin(); book != books.end(); ++book) // 
	{
		book->Save(LibraryOut); // 写入对象
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



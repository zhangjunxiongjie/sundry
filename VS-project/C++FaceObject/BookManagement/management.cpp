#include "management.h"
#include "share.h"
#include "usergroup.h"
#include "library.h"
#include "bookgroup.h"
#include <iostream>
#include <conio.h>

// 返回与退出菜单。
extern bool into0;
extern bool into1;

void Management::GuiInit() // 管理系统GUI初始化
{
	system("title 图书管理系统");  //设置窗口标题
	
	char cmd[30] = {};
	sprintf_s(cmd, "mode con cols=%d lines=%d", WINDOWS_WIDTH, WINDOWS_TALL);  // 设置窗口大小
	system(cmd); //system(mode con cols=88 lines=88)设置窗口宽度和高度

}

void Management::Run()		// 总的执行逻辑放在这里。
{
	into0 = true;
	while (into0)
	{
		GuiInit();

		library = new Library();
		users = new Usergroup; //

		SetFrontColor();
		user = users->LogOn();  // 在登陆后创建了一个动态内存的用户对象，使用完后需要手动清除。 

		switch (user->GetJuri())
		{
		case Share::Root:
			Root();
			break;
		case Share::Dry:
			Dry();
			break;
		case Share::Leaf:
			bookgroup = new BookGroup(user->GetName() + ".txt", library);  //使用个人书库文件进行初始化。
			Leaf();
			delete bookgroup;
			break;
		default:
			break;
		}

		// 善后。
		delete user;
		delete users;
		delete library;
	}
}


void Management::DisposeChoice(int choice) // 处理选项。
{
	
	switch (choice)
	{
	case 1:
		users->UserGroup();
		break;
	case 2:
		library->LibraryGroup();
		break;
	case 3:
		into1 = false;
		break;
	}

	system("cls");
	RootGui(choice); 
}

void Management::RootGui(int choice) // 根用户gui
{
	LightSet(false);
	GoToXY(38, 5);
	std::cout << "书库管理系统";

	LightSet(choice == 1); // 根据比较的bool值确定是否高亮
	GoToXY(40, 11);
	std::cout << "1.用户管理";

	LightSet(choice == 2);
	GoToXY(40, 15);
	std::cout << "2.书库管理";

	LightSet(choice == 3);
	GoToXY(40, 19);
	std::cout << "3.退出登录";

	SetFrontColor();
}

// 用户登录放在用户组管理中，判断用户权限后，根据权限进入以下不同的用户执行逻辑。
void Management::Root() // 不同权限用户的执行逻辑
{
	int choice = 1; // 所选选项,高亮选项

	system("cls");
	RootGui(choice);

	into1 = true;
	bool sign = false;
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
					choice = 3;
				}
				RootGui(choice);
				break;
			case 80:// down
				if (choice < 3)
				{
					choice++;
				}
				else
				{
					choice = 1;
				}
				RootGui(choice);
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

void Management::Dry()
{
	library->LibraryGroup();
}

void Management::Leaf()
{
	bookgroup->UserUser();
}


Management::Management():user(NULL), library(NULL), users(NULL), bookgroup(NULL)
{
}

Management::~Management()
{
}

#include "usergroup.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

extern bool into1;
extern bool into2;

void Usergroup::DisposeChoice(int choice) // 处理选项
{
	
	UserGroupGui(choice); 

	switch (choice)
	{
	case 1:
		LookUsers();
		break;
	case 2:
		DeleteUser();
		break;
	case 3:
		AddUser();
		break;
	case 4:
		into2 = false;
		break;
	case 5:   
		into1 = false;
		into2 = false;
		break;
	default:
		break;
	}

}


void Usergroup::UserGroupGui(int choice)  // 用户管理界面.传入值表示当前高亮选项。
{

	LightSet(false);
	GoToXY(38, 5);
	std::cout << "用户管理界面";

	LightSet(choice == 1); 
	GoToXY(40, 9);
	std::cout << "1.查看用户";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.删除用户";

	LightSet(choice == 3);
	GoToXY(40, 13);
	std::cout << "3.添加用户";

	LightSet(choice == 4);
	GoToXY(40, 15);
	std::cout << "4.返回上一级";

	LightSet(choice == 5);
	GoToXY(40, 17);
	std::cout << "5.退出登录";

	LightSet(false);  //避免白屏。
}


void Usergroup::UserGroup() // 用户管理逻辑
{
	system("cls");
	int choice = 1; // 所选选项,高亮选项
	UserGroupGui(choice);

	into2 = true;
	bool sign = false;  // 标志位，每进行一个选项输出结果后如果继续选择（即按键）则会清一次屏。
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
					choice = 5;
				}
				UserGroupGui(choice);
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
				UserGroupGui(choice);
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



// 每次进行选项输出打印时都要清屏重绘选项内容
void Usergroup::LookUsers() // 输出所有用户的用户id，用户名，用户类型
{
	GoToXY(40, 20);
	std::cout << "ID" << " " << "name" << "        " << "type";

	auto user = users.begin();
	for (int i = 21; user != users.end(); ++user, i++) // 遍历用户组
	{
		user->LookUser(i); // 格式化输出。
	}

	GoToXY(0, 0); // 避免输出用户后光标落在最后一个输出用户后面导致选项界面上滑。
	
	LightSet(true);
	GoToXY(40, 9);
	std::cout << "1.查看用户"; // 重绘
	LightSet(false);

}



void Usergroup::IdInPut(int& id) // id输入对删除ID做一个限制性检查输入。最多只能输入两位数。
{
	id = 0; // 初始值设为0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // 按键检测
		{
			char ch = _getch();
			
			if(ch >= 48 && ch <= 57) // 
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

void Usergroup::DeleteUser() // 删除用户;  只是删除用户数据并不会删除书籍数据
{

	GoToXY(40, 11);
	std::cout << "请输入删除用户ID：";
	int id;
	IdInPut(id);
	GoToXY(40, 11);
	std::cout << "                      ";  // \b退格

	for (auto user = users.begin(); id != 0 && user != users.end(); ++user) // id!=0保证了无法删除root用户
	{
		if (user->GetID() == id)
		{
			users.erase(user); // 根据传入对象找出与之相同的对象元素然后删除此元素；
			usernumber--;  // 更改当前用户总数。
			
			break;
		}
	}

	LightSet(true);
	GoToXY(40, 11);
	std::cout << "2.删除用户";
	LightSet(false); // 避免白屏。

}


Share::Juri Usergroup::JuriInput() //  用户类别输入。
{

	while (true)
	{
		if (_kbhit()) // 按键检测
		{
			char ch = _getch();
			std::cout << ch;
			if (ch == 49 || ch == 97)
			{
				return Share::Dry;
			}
			else if (ch == 50 || ch == 98)
			{	
				return Share::Leaf;
			}
			else
			{
				return Share::Leaf;
			}

		}
	}
	
}

// 可以保证产生的ID绝对是当前用户没有使用的。
int Usergroup::ProduceId()  // 系统产生用户id
{
	for (int i = 1; i < usernumber; i++) // 这里不知道把++放在前面和后面有没有什么区别。
	{
		auto user = users.begin();
		for (; user != users.end(); ++user) // 保证了产生的ID未使用
		{
			if (user->GetID() == i)
			{
				break;
			}
		}

		if (user == users.end()) // 如果for循环不是由break出来的说明此时i可用。
		{
			return i; // 简单粗暴直接找到第一个未使用的用户ID。
		}
	}
	
	return usernumber; 
	
}

int Usergroup::JudgeSame(std::string username)  // 判重,如果用户名重复，删除掉原来的用户，以达到修改的效果。
{
	int userid = -1;
	auto user = users.begin();
	for (; user != users.end(); ++user)
	{
		if (username == user->GetName())
		{
			userid = user->GetID(); // 删除用户前先保存ID。

			users.erase(user); // 根据传入对象找出与之相同的对象元素然后删除此元素；
			usernumber--;  // 更改当前用户总数。
			break;
		}
	}

	return userid; // 如果是修改用户则这里可以保证用户ID不被修改。保证用户ID不被修改可以避免一些不必要的bug。
	
}

void Usergroup::AddUser() // 添加用户,不能添加root用户，只能存在一个root用户。
{

	if (usernumber == USER_MAX_NUMBER) // 如果当前用户数等于最大用户数则提示直接退出。
	{
		GoToXY(30, 20);
		SetFrontColor();
		std::cout << "当前已达到最大用户数，无法继续添加用户。";
		return;
	}

	User user;

	user.id = ProduceId(); // 系统产生用户ID

	GoToXY(40, 13);
	std::cout << "请输入用户名：";
	LogOnInPut(user.name, false);  // 这里直接使用了登录时的用户名输入方法
	GoToXY(40, 13);
	std::cout << "                             ";  // 获取输入后对残留回显进行清理

	if (user.GetName() == std::string("") || user.GetName() == "library" || user.GetName() == "usergroup") // 显式构造，用户名特殊处理。
	{
		user.name = "user" + std::to_string(user.GetID()); 
	}
	

	// 获取密码
	GoToXY(40, 13);
	std::cout << "请输入密码：";
	LogOnInPut(user.password, true);  // 这里直接使用了登录时的密码输入方法
	GoToXY(40, 13);
	std::cout << "                             ";   // 获取输入后对残留回显进行清理

	if (user.GetPassword() == std::string("")) // 显式构造，空处理
	{
		user.password = "404";  // 默认密码
	}
	
	// 获取用户类别。
	GoToXY(40, 13);
	std::cout << "请输入用户类别：";  //
	user.juri = JuriInput(); // 默认类别是leaf即使用用户。
	GoToXY(40, 13);
	std::cout << "                             ";   // 获取输入后对残留回显进行清理

	// 当存在重复用户名时将返回删除用户的用户ID以保证同一用户的用户ID不会被修改。
	int userid = JudgeSame(user.GetName());  // 判重,如果用户名重复，删除掉原来的用户，以达到修改的效果。
	if (userid != -1)
	{
		user.id = userid; // 不使用系统产生的ID而使用原来的ID。
	}

	users.push_back(user); // 添加用户
	usernumber++;

	// 还原选项
	LightSet(true);
	GoToXY(40, 13);
	std::cout << "3.添加用户";	
	LightSet(false); // 避免白屏。

}


void Usergroup::Init()  // 初始化（加载）用户列表
{
	std::ifstream UserIn(USER_FILE);  // 读取用户文件
	
	if (!UserIn.is_open()) // 如果用户文件打开失败
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "严重错误：未找到用户文件，系统启动失败！！！"; // 
		Sleep(3000); // 延时

		system("exit"); // 退出整个程序  // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	UserIn.seekg(std::ios::beg); //设置文件读出开始位置。 
	UserIn >> usernumber; // 读取用户数

	for (int i = 0; i < usernumber; i++) // 
	{
		User user;  // 
		user.InIt(UserIn); // 读取对象
		users.push_back(user); // 将用户加入用户组
	}
	
	UserIn.close();
}	  

void Usergroup::Save() // 用户数据保存
{
	std::ofstream UserOut(USER_FILE);  // 写入用户文件

	if (!UserOut.is_open()) // 如果用户文件打开失败
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "严重错误：未找到用户文件,所有修改将无效！！！"; // 
		Sleep(3000); // 延时

		system("exit"); // 退出整个程序  // 任何地方在退出（结束）整个程序前都要保存一些应该保存的文件。
	}

	UserOut.seekp(std::ios::beg);   // 设置文件写入开始位置。
	UserOut << usernumber << "\n";

	for (auto user = users.begin(); user != users.end(); ++user) // 
	{
		user->Save(UserOut); // 写入对象
	}

	UserOut.close();

}


// 保证了输入字符最多为10个字符
void Usergroup::LogOnInPut(std::string& cache, bool sign) // 登录输入，实现登陆时的输入以及检查操作。
{
	char buffer[11] = {}; // 临时存储
	int number = 0;

	while (true)
	{
		if(_kbhit()) // 按键检测
		{
			char ch = _getch(); // 读取一个字符
			
			if (ch == 13) // 回车键键值
			{
				cache = std::string(buffer);
				return; // 直接退出
			}
			else if (ch == 8)  // 实现删除键,当无字符时没有任何效果。
			{
				if (number > 0)
				{
					buffer[--number] = '\0';

					std::cout << "\b"; // 后退一格；
					std::cout << " ";
					std::cout << "\b";
				}
			}
			else
			{
				if ( (97 <= ch && ch <= 122) || (65 <= ch && ch <= 90) || (48 <= ch && ch <= 57)) // 限制密码字符的种类为：大小写字母，数字。
				{
					buffer[number++] = ch; // 要保证用户中的用户名最大十个字符。
					if (sign)
					{
						std::cout << "*";
					}
					else
					{
						std::cout << ch;
					}
				}
			}
		}
		if (number == 10)// 保证最大十个字符输入
		{
			cache = std::string(buffer);
			return; // 直接退出
		}
	}
}

void Usergroup::LogOnGUI() // 登陆界面
{
	system("cls");

	GoToXY(40, 5);
	std::cout << "图书管理系统";

	GoToXY(10,11);
	std::cout << "程序作者：慕容宇月";
	GoToXY(10, 12);
	std::cout << "程序简介：本系统中分两种用户：使用用户和管理用户。";
	GoToXY(10, 13);
	std::cout << "使用用户只能对自己的个人书库进行操作；";
	GoToXY(10, 14);
	std::cout << "管理用户又分两种一种是系统管理员（只有唯一的一个），一种是书库管理用户（可以有多个）；";
	GoToXY(10, 15);
	std::cout << "系统管理员既可以对用户系统进行管理还能对书库系统进行管理；";
	GoToXY(10, 16);
	std::cout << "书库管理员只能对书库系统进行管理。";
	GoToXY(10, 17);
	std::cout << "提示：首次使用时有初始化的系统管理员可以使用：用户名：root,密码：404。";
}

// 返回一个用户id然后外面根据用户id创建一个用户对象
User* Usergroup::LogOn()  // 用户登录逻辑。 返回登录用户的用户权限。
{
	system("cls");
	LogOnGUI();

	auto usersearch = users.begin(); // 迭代器返回的是一个对象指针。
	while (true)
	{
		bool sign = false;

		std::string name;
		GoToXY(34, 8);
		std::cout << "请输入用户名:";
		LogOnInPut(name, false); // 用户名输入及检查

		usersearch = users.begin();
		for (; usersearch != users.end(); ++usersearch)
		{
			if (usersearch->GetName() == name)
			{
				sign = true;
				break;
			}
		}
		LogOnGUI();
		if (sign)
		{
			break;
		}

		GoToXY(34, 9);
		std::cout << "用户不存在！！！";
	}


	while (true)
	{
		std::string password;
		GoToXY(34, 8);
		std::cout << "请输入密码:";
		LogOnInPut(password, true); // 密码输入及检查，标志位表示是否加密回显，true表示加密回显。

		if (usersearch->GetPassword() == password)
		{
			User* user = new User(*usersearch); // 创建一个动态用户对象供上层使用,将登陆用户的信息初始化。
			return user; // 返回一个用户对象其它的事情交给上层处理
		}

		LogOnGUI();

		GoToXY(34, 9);
		std::cout << "密码错误！！！";
	}

}

Usergroup::Usergroup() :usernumber(0)
{
	Init();
}

Usergroup::~Usergroup()
{
	Save();
}
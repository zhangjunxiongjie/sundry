#include "management.h"
#include "share.h"
#include "usergroup.h"
#include "library.h"
#include "bookgroup.h"
#include <iostream>
#include <conio.h>

// �������˳��˵���
extern bool into0;
extern bool into1;

void Management::GuiInit() // ����ϵͳGUI��ʼ��
{
	system("title ͼ�����ϵͳ");  //���ô��ڱ���
	
	char cmd[30] = {};
	sprintf_s(cmd, "mode con cols=%d lines=%d", WINDOWS_WIDTH, WINDOWS_TALL);  // ���ô��ڴ�С
	system(cmd); //system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�

}

void Management::Run()		// �ܵ�ִ���߼��������
{
	into0 = true;
	while (into0)
	{
		GuiInit();

		library = new Library();
		users = new Usergroup; //

		SetFrontColor();
		user = users->LogOn();  // �ڵ�½�󴴽���һ����̬�ڴ���û�����ʹ�������Ҫ�ֶ������ 

		switch (user->GetJuri())
		{
		case Share::Root:
			Root();
			break;
		case Share::Dry:
			Dry();
			break;
		case Share::Leaf:
			bookgroup = new BookGroup(user->GetName() + ".txt", library);  //ʹ�ø�������ļ����г�ʼ����
			Leaf();
			delete bookgroup;
			break;
		default:
			break;
		}

		// �ƺ�
		delete user;
		delete users;
		delete library;
	}
}


void Management::DisposeChoice(int choice) // ����ѡ�
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

void Management::RootGui(int choice) // ���û�gui
{
	LightSet(false);
	GoToXY(38, 5);
	std::cout << "������ϵͳ";

	LightSet(choice == 1); // ���ݱȽϵ�boolֵȷ���Ƿ����
	GoToXY(40, 11);
	std::cout << "1.�û�����";

	LightSet(choice == 2);
	GoToXY(40, 15);
	std::cout << "2.������";

	LightSet(choice == 3);
	GoToXY(40, 19);
	std::cout << "3.�˳���¼";

	SetFrontColor();
}

// �û���¼�����û�������У��ж��û�Ȩ�޺󣬸���Ȩ�޽������²�ͬ���û�ִ���߼���
void Management::Root() // ��ͬȨ���û���ִ���߼�
{
	int choice = 1; // ��ѡѡ��,����ѡ��

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

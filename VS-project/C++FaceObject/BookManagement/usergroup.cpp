#include "usergroup.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

extern bool into1;
extern bool into2;

void Usergroup::DisposeChoice(int choice) // ����ѡ��
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


void Usergroup::UserGroupGui(int choice)  // �û��������.����ֵ��ʾ��ǰ����ѡ�
{

	LightSet(false);
	GoToXY(38, 5);
	std::cout << "�û��������";

	LightSet(choice == 1); 
	GoToXY(40, 9);
	std::cout << "1.�鿴�û�";

	LightSet(choice == 2);
	GoToXY(40, 11);
	std::cout << "2.ɾ���û�";

	LightSet(choice == 3);
	GoToXY(40, 13);
	std::cout << "3.����û�";

	LightSet(choice == 4);
	GoToXY(40, 15);
	std::cout << "4.������һ��";

	LightSet(choice == 5);
	GoToXY(40, 17);
	std::cout << "5.�˳���¼";

	LightSet(false);  //���������
}


void Usergroup::UserGroup() // �û������߼�
{
	system("cls");
	int choice = 1; // ��ѡѡ��,����ѡ��
	UserGroupGui(choice);

	into2 = true;
	bool sign = false;  // ��־λ��ÿ����һ��ѡ�����������������ѡ�񣨼������������һ������
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



// ÿ�ν���ѡ�������ӡʱ��Ҫ�����ػ�ѡ������
void Usergroup::LookUsers() // ��������û����û�id���û������û�����
{
	GoToXY(40, 20);
	std::cout << "ID" << " " << "name" << "        " << "type";

	auto user = users.begin();
	for (int i = 21; user != users.end(); ++user, i++) // �����û���
	{
		user->LookUser(i); // ��ʽ�������
	}

	GoToXY(0, 0); // ��������û������������һ������û����浼��ѡ������ϻ���
	
	LightSet(true);
	GoToXY(40, 9);
	std::cout << "1.�鿴�û�"; // �ػ�
	LightSet(false);

}



void Usergroup::IdInPut(int& id) // id�����ɾ��ID��һ�������Լ�����롣���ֻ��������λ����
{
	id = 0; // ��ʼֵ��Ϊ0
	int number = 0;
	while (true)
	{
		if (_kbhit()) // �������
		{
			char ch = _getch();
			
			if(ch >= 48 && ch <= 57) // 
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

void Usergroup::DeleteUser() // ɾ���û�;  ֻ��ɾ���û����ݲ�����ɾ���鼮����
{

	GoToXY(40, 11);
	std::cout << "������ɾ���û�ID��";
	int id;
	IdInPut(id);
	GoToXY(40, 11);
	std::cout << "                      ";  // \b�˸�

	for (auto user = users.begin(); id != 0 && user != users.end(); ++user) // id!=0��֤���޷�ɾ��root�û�
	{
		if (user->GetID() == id)
		{
			users.erase(user); // ���ݴ�������ҳ���֮��ͬ�Ķ���Ԫ��Ȼ��ɾ����Ԫ�أ�
			usernumber--;  // ���ĵ�ǰ�û�������
			
			break;
		}
	}

	LightSet(true);
	GoToXY(40, 11);
	std::cout << "2.ɾ���û�";
	LightSet(false); // ���������

}


Share::Juri Usergroup::JuriInput() //  �û�������롣
{

	while (true)
	{
		if (_kbhit()) // �������
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

// ���Ա�֤������ID�����ǵ�ǰ�û�û��ʹ�õġ�
int Usergroup::ProduceId()  // ϵͳ�����û�id
{
	for (int i = 1; i < usernumber; i++) // ���ﲻ֪����++����ǰ��ͺ�����û��ʲô����
	{
		auto user = users.begin();
		for (; user != users.end(); ++user) // ��֤�˲�����IDδʹ��
		{
			if (user->GetID() == i)
			{
				break;
			}
		}

		if (user == users.end()) // ���forѭ��������break������˵����ʱi���á�
		{
			return i; // �򵥴ֱ�ֱ���ҵ���һ��δʹ�õ��û�ID��
		}
	}
	
	return usernumber; 
	
}

int Usergroup::JudgeSame(std::string username)  // ����,����û����ظ���ɾ����ԭ�����û����Դﵽ�޸ĵ�Ч����
{
	int userid = -1;
	auto user = users.begin();
	for (; user != users.end(); ++user)
	{
		if (username == user->GetName())
		{
			userid = user->GetID(); // ɾ���û�ǰ�ȱ���ID��

			users.erase(user); // ���ݴ�������ҳ���֮��ͬ�Ķ���Ԫ��Ȼ��ɾ����Ԫ�أ�
			usernumber--;  // ���ĵ�ǰ�û�������
			break;
		}
	}

	return userid; // ������޸��û���������Ա�֤�û�ID�����޸ġ���֤�û�ID�����޸Ŀ��Ա���һЩ����Ҫ��bug��
	
}

void Usergroup::AddUser() // ����û�,�������root�û���ֻ�ܴ���һ��root�û���
{

	if (usernumber == USER_MAX_NUMBER) // �����ǰ�û�����������û�������ʾֱ���˳���
	{
		GoToXY(30, 20);
		SetFrontColor();
		std::cout << "��ǰ�Ѵﵽ����û������޷���������û���";
		return;
	}

	User user;

	user.id = ProduceId(); // ϵͳ�����û�ID

	GoToXY(40, 13);
	std::cout << "�������û�����";
	LogOnInPut(user.name, false);  // ����ֱ��ʹ���˵�¼ʱ���û������뷽��
	GoToXY(40, 13);
	std::cout << "                             ";  // ��ȡ�����Բ������Խ�������

	if (user.GetName() == std::string("") || user.GetName() == "library" || user.GetName() == "usergroup") // ��ʽ���죬�û������⴦��
	{
		user.name = "user" + std::to_string(user.GetID()); 
	}
	

	// ��ȡ����
	GoToXY(40, 13);
	std::cout << "���������룺";
	LogOnInPut(user.password, true);  // ����ֱ��ʹ���˵�¼ʱ���������뷽��
	GoToXY(40, 13);
	std::cout << "                             ";   // ��ȡ�����Բ������Խ�������

	if (user.GetPassword() == std::string("")) // ��ʽ���죬�մ���
	{
		user.password = "404";  // Ĭ������
	}
	
	// ��ȡ�û����
	GoToXY(40, 13);
	std::cout << "�������û����";  //
	user.juri = JuriInput(); // Ĭ�������leaf��ʹ���û���
	GoToXY(40, 13);
	std::cout << "                             ";   // ��ȡ�����Բ������Խ�������

	// �������ظ��û���ʱ������ɾ���û����û�ID�Ա�֤ͬһ�û����û�ID���ᱻ�޸ġ�
	int userid = JudgeSame(user.GetName());  // ����,����û����ظ���ɾ����ԭ�����û����Դﵽ�޸ĵ�Ч����
	if (userid != -1)
	{
		user.id = userid; // ��ʹ��ϵͳ������ID��ʹ��ԭ����ID��
	}

	users.push_back(user); // ����û�
	usernumber++;

	// ��ԭѡ��
	LightSet(true);
	GoToXY(40, 13);
	std::cout << "3.����û�";	
	LightSet(false); // ���������

}


void Usergroup::Init()  // ��ʼ�������أ��û��б�
{
	std::ifstream UserIn(USER_FILE);  // ��ȡ�û��ļ�
	
	if (!UserIn.is_open()) // ����û��ļ���ʧ��
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "���ش���δ�ҵ��û��ļ���ϵͳ����ʧ�ܣ�����"; // 
		Sleep(3000); // ��ʱ

		system("exit"); // �˳���������  // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	UserIn.seekg(std::ios::beg); //�����ļ�������ʼλ�á� 
	UserIn >> usernumber; // ��ȡ�û���

	for (int i = 0; i < usernumber; i++) // 
	{
		User user;  // 
		user.InIt(UserIn); // ��ȡ����
		users.push_back(user); // ���û������û���
	}
	
	UserIn.close();
}	  

void Usergroup::Save() // �û����ݱ���
{
	std::ofstream UserOut(USER_FILE);  // д���û��ļ�

	if (!UserOut.is_open()) // ����û��ļ���ʧ��
	{
		system("cls");
		GoToXY(30, 15);
		std::cout << "���ش���δ�ҵ��û��ļ�,�����޸Ľ���Ч������"; // 
		Sleep(3000); // ��ʱ

		system("exit"); // �˳���������  // �κεط����˳�����������������ǰ��Ҫ����һЩӦ�ñ�����ļ���
	}

	UserOut.seekp(std::ios::beg);   // �����ļ�д�뿪ʼλ�á�
	UserOut << usernumber << "\n";

	for (auto user = users.begin(); user != users.end(); ++user) // 
	{
		user->Save(UserOut); // д�����
	}

	UserOut.close();

}


// ��֤�������ַ����Ϊ10���ַ�
void Usergroup::LogOnInPut(std::string& cache, bool sign) // ��¼���룬ʵ�ֵ�½ʱ�������Լ���������
{
	char buffer[11] = {}; // ��ʱ�洢
	int number = 0;

	while (true)
	{
		if(_kbhit()) // �������
		{
			char ch = _getch(); // ��ȡһ���ַ�
			
			if (ch == 13) // �س�����ֵ
			{
				cache = std::string(buffer);
				return; // ֱ���˳�
			}
			else if (ch == 8)  // ʵ��ɾ����,�����ַ�ʱû���κ�Ч����
			{
				if (number > 0)
				{
					buffer[--number] = '\0';

					std::cout << "\b"; // ����һ��
					std::cout << " ";
					std::cout << "\b";
				}
			}
			else
			{
				if ( (97 <= ch && ch <= 122) || (65 <= ch && ch <= 90) || (48 <= ch && ch <= 57)) // ���������ַ�������Ϊ����Сд��ĸ�����֡�
				{
					buffer[number++] = ch; // Ҫ��֤�û��е��û������ʮ���ַ���
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
		if (number == 10)// ��֤���ʮ���ַ�����
		{
			cache = std::string(buffer);
			return; // ֱ���˳�
		}
	}
}

void Usergroup::LogOnGUI() // ��½����
{
	system("cls");

	GoToXY(40, 5);
	std::cout << "ͼ�����ϵͳ";

	GoToXY(10,11);
	std::cout << "�������ߣ�Ľ������";
	GoToXY(10, 12);
	std::cout << "�����飺��ϵͳ�з������û���ʹ���û��͹����û���";
	GoToXY(10, 13);
	std::cout << "ʹ���û�ֻ�ܶ��Լ��ĸ��������в�����";
	GoToXY(10, 14);
	std::cout << "�����û��ַ�����һ����ϵͳ����Ա��ֻ��Ψһ��һ������һ�����������û��������ж������";
	GoToXY(10, 15);
	std::cout << "ϵͳ����Ա�ȿ��Զ��û�ϵͳ���й����ܶ����ϵͳ���й���";
	GoToXY(10, 16);
	std::cout << "������Աֻ�ܶ����ϵͳ���й���";
	GoToXY(10, 17);
	std::cout << "��ʾ���״�ʹ��ʱ�г�ʼ����ϵͳ����Ա����ʹ�ã��û�����root,���룺404��";
}

// ����һ���û�idȻ����������û�id����һ���û�����
User* Usergroup::LogOn()  // �û���¼�߼��� ���ص�¼�û����û�Ȩ�ޡ�
{
	system("cls");
	LogOnGUI();

	auto usersearch = users.begin(); // ���������ص���һ������ָ�롣
	while (true)
	{
		bool sign = false;

		std::string name;
		GoToXY(34, 8);
		std::cout << "�������û���:";
		LogOnInPut(name, false); // �û������뼰���

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
		std::cout << "�û������ڣ�����";
	}


	while (true)
	{
		std::string password;
		GoToXY(34, 8);
		std::cout << "����������:";
		LogOnInPut(password, true); // �������뼰��飬��־λ��ʾ�Ƿ���ܻ��ԣ�true��ʾ���ܻ��ԡ�

		if (usersearch->GetPassword() == password)
		{
			User* user = new User(*usersearch); // ����һ����̬�û������ϲ�ʹ��,����½�û�����Ϣ��ʼ����
			return user; // ����һ���û��������������齻���ϲ㴦��
		}

		LogOnGUI();

		GoToXY(34, 9);
		std::cout << "������󣡣���";
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
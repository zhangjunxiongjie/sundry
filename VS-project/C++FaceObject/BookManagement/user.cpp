#include "user.h"
#include <iostream>

void User::LookUser(int site) // 用户格式化输出在site行。
{
	GoToXY(40, site);
	std::cout << id;

	GoToXY(43, site);
	std::cout << name;

	GoToXY(55, site);
	switch (juri)
	{
	case Share::Root:
		std::cout << "root";
		break;
	case Share::Dry:
		std::cout << "dry";
		break;
	case Share::Leaf:
		std::cout << "leaf";
		break;
	default:
		std::cout << "error";
	}

}


std::string User::GetName() // 
{
	return name;
}

std::string User::GetPassword() // 
{
	return password;
}

int User::GetID() //
{
	return id;
}

Share::Juri User::GetJuri() // 
{
	return juri;
}


void User::Save(std::ofstream& file) // 保存到文件。
{
	int middle;
	switch (juri)
	{
	case Share::Root:
		middle = 0;
		break;
	case Share::Dry:
		middle = 1;
		break;
	case Share::Leaf:
		middle = 2;
		break;
	default:
		middle = 2;
		break;
	}

	file << id << " " << name << " " << password << " " << middle << "\n";
}

void User::InIt(std::ifstream& file)
{
	int middle;

	file >> id >> name >> password >> middle;
	
	switch (middle)
	{
	case 0:
		juri = Share::Root;
		break;
	case 1:
		juri = Share::Dry;
		break;
	case 2:
		juri = Share::Leaf;
		break;
	default:
		juri = Share::JuriError;
		break;
	}

}

User::User() :id(0), name(""), password(""), juri(Share::Leaf)
{
}

User::~User()
{
}

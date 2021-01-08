#ifndef USER_H
#define USER_H

#include "share.h"
#include "bookgroup.h"
#include "usergroup.h"
#include "public.h"
#include <fstream>
#include <string>

class User:public PublicFunction // 用户类
{
public:
	User();
	~User ();

	void InIt(std::ifstream& file); // 用文件数据初始化此对象
	void Save(std::ofstream& file); // 保存到文件。

	void LookUser(int site); // 用户格式化输出在site行。

	// 获得值
	std::string GetName(); // 
	std::string GetPassword(); // 
	int GetID(); // 
	Share::Juri GetJuri(); // 

private:

	friend class Usergroup; // Usergroup 在添加用户时需要直接访问User的属性并赋值，所以这里就直接给一个友元吧。

	int id; // 每个用户都有一个唯一且不变的ID，在创建用户时要搜索所有的用户找到最小的未使用的ID号，root用户不可删除,id为0。
	std::string name;  // 用户名
	std::string password; // 用户密码
	Share::Juri juri;  // 权限，用户创建时确定，不可改变

};

#endif 




#ifndef USERGROUP_H
#define USERGROUP_H

#include <list>
#include <string>

#include "user.h"
#include "public.h"
#include "share.h"

class User;
class Usergroup:public PublicFunction  // 用户组类用于，登录验证，权限判别及用户管理（root才能进行）
{
public:
	Usergroup();
	~Usergroup();

	// 初始化和保存。
	void Init();  // 初始化（加载）用户列表
	void Save();  // 用户数据保存

	// 用户登录。
	User* LogOn();  // 用户登录逻辑。 直到用户登录成功，返回用户类型
	void LogOnGUI(); //登陆界面
	void LogOnInPut(std::string& cache, bool sign); // 登录用户名及密码输入，实现密码*号显示。

	// 用户管理
	void UserGroup(); // 用户管理  
	void UserGroupGui(int choice);   // 用户管理界面。
	void DisposeChoice(int choice); // 处理选项

	// 用户操作。
	void LookUsers(); // 输出所有用户
 
	void IdInPut(int& id); // id输入对删除ID做一个限制性检查输入。
	void DeleteUser(); // 删除用户; // 只是删除用户数据并不会删除书籍数据

	Share::Juri JuriInput(); //  用户类别输入。
	int ProduceId(); // 系统产生用户id
	int JudgeSame(std::string username);  // 判重,如果重复，删除掉原来的用户，以达到修改的效果。
	void AddUser(); // 添加用户

private:

	std::list<User> users; // 用户组
	
	int usernumber; // 用户数

};

#endif // !USERGROUP_H

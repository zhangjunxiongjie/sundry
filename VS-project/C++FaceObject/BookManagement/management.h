#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "public.h"
#include "user.h"
#include "library.h"

class Management:public PublicFunction  // 图书管理系统类，
{
public:
	Management();
	~Management();

	void GuiInit(); // 管理系统GUI初始化

	void Run();		// 总的执行逻辑放在这里。

	void DisposeChoice(int choice); // 处理选项。
	void RootGui(int choice); // 根用户PublicFunction
	void Root(); // 不同权限用户的执行逻辑

	void Dry();

	void Leaf();

private:

	User* user; // 登录用户

	Usergroup* users; // 用户组管理。
	
	Library* library; // 书库， 因为所有用户都会使用到所以这里在上层进行实例化
	
	BookGroup* bookgroup; // 个人书库管理。使用个人书库文件进行初始化。
};


#endif
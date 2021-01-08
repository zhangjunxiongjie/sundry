#ifndef BOOKGROUP_H
#define BOOKGROUP_H

#include "public.h"
#include "book.h"
#include "library.h"
#include <string>
#include <list>


class BookGroup:public PublicFunction // 个人书库管理，对个人书库进行操作 
{
public:

	BookGroup(std::string a, Library* b);
	~BookGroup();

	void InIt(); // 初始化个人书库。
	void Save(); // 保存个人书库。

	void UserUser(); // 用户书库管理；
	void UserUserGui(int choice); //用户使用Gui;

	void DisposeChoice(int choice); //处理选项 

	void LookBooks(); // 查看所有书籍
	
	void StateInput(int& state); // 状态输入
	void AddBook(); // 添加书籍。

	void IdInPut(int& id); // id输入对删除ID做一个限制性检查输入。
	void DeleteBook(); // 删除书籍。

private:

	
	std::list<Book> books; // 书库，可在任意位置进行书籍增改

	int booknumber; // 书籍数量

	Library* library; // 用户实现书库搜索功能。

	std::string UserBookFile;  // 用户书库文件

};

#endif // !BOOKGROUP_H
#ifndef BOOK_H
#define BOOK_H

#include "share.h"
#include "public.h"
#include <string>


class Book:public PublicFunction  // 书类
{
public:
	
	Book();
	~Book();

	void InIt(std::ifstream& input); // 读取（初始化）书籍数据（书库数据初始化）
	void UserInIt(std::ifstream& input); // 用户书库数据初始化

	void Save(std::ofstream& output);  //书籍数据保存
	void UserSave(std::ofstream& output);

	int GetId();    // 获得值，用于书籍信息展示，展示的结构由上层处理。
	std::string GetBookname(); 
	std::string GetWritername();
	std::string GetPressname();
	std::string GetCategory();
	Share::BookState GetState(); // 
	void ResetState(Share::BookState s); // 重置状态

	void LookBook(int site); // 在指定行按一定格式输出书籍信息。

private:
	
	friend class Library; // 书库在添加书籍时会使用到。

	int id;   // 每本书在不同的书库中都有一个相同的唯一的ID号，以便于搜索和匹配。
	
	std::string bookname;
	std::string writername;
	std::string pressname;
	std::string category;  // 类别
	
	Share::BookState state; // 书籍的状态,仅在个人书库时有用。在书库添加书籍时不需要初始化。
};

#endif
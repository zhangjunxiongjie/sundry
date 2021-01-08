#ifndef SHARE_H
#define SHARE_H

//文件
#define USER_FILE "usergroup.txt" // 用户数据文件
#define LIBRARY_FILE "library.txt" // 书库文件

//窗口
#define WINDOWS_TALL 30    // 窗口高
#define WINDOWS_WIDTH 100   // 窗口宽

// 用户
#define USER_MAX_NUMBER 100    // 最大用户数：0~99
#define BOOK_MAX_NUMBER 10000  // 最大书籍数。

// 共享，共用
class Share // 共享类型，全局变量等
{
public:

	typedef enum Jurisdiction // 每个用户的权限枚举量
	{
		Root, // 根
		Dry,  // 干
		Leaf,  // 叶
		JuriError // 权限错误 
	}Juri;

	typedef enum BookState // 每本书在个人用户中的状态枚举量
	{
		Want, // 想读
		Reading,  // 正在读
		Read,  // 已读
		Null,  // 未添加到私人书库,显示书籍状态时使用。
		StateError // 状态错误
	}State;

};

#endif
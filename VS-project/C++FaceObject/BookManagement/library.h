#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "public.h"
#include <list>

class Library:public PublicFunction // 图书馆类，总的书库管理
{
public:
	Library();
	~Library();

	void Init(); // 初始化书库列表
	void Save(); // 书库数据保存

	void LibraryGroup(); // 书库管理主逻辑。
	void LibraryGroupGui(int choice); // GUI
	void DisposeChoice(int choice); // 选项分支处理。

	void Find(); // 管理员书库搜索（三种用户都可以使用的操作，为了简化逻辑三种用户都会显示状态）
	void FindUser(std::list<Book>& userbooks); // 用户书库搜索,额外处理。
	void FindGui(int choice); // GUI
	void FindDisposeChoice(int choice); // 选项分支处理。

	void IdInput(int& id); // ID输入。
	void IdFind(); // ID查找主逻辑
	Book* IdFindUser(int id); // 给用户添加书籍使用的ID查询逻辑独立快


	void BookNameFind(); // 书名查找；
	void WriterNameFind(); // 作者查找；
	void PressNameFind(); // 出版社查找。
	void CategoryFind(); // 类别查找。

	int ProduceId(); // 专门用于产生id
	void AddBook(); // 添加书籍（书籍ID由系统生成）（添加书籍时要对书籍的一些参数做一些限制，保证20个字符及以下）

	void DeleteBook(); // 删除书籍(只能根据书籍ID删除)

	void ImportData(); // 导入数据。

private:

	std::list<Book> books; // 书库，可在任意位置进行书籍增改

	int booknumber; // 书籍数量
};

#endif

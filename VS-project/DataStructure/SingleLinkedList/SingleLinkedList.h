#pragma once
// 单链表的实现。

class SINGLELIST
{
private:
	typedef struct NODE
	{
		int value;
		struct NODE* next;
	} NODE;
	typedef NODE* NODEPOINT; // 更名

	NODEPOINT Head, Tail;
	int Size;

	void ReqMemory(NODEPOINT& point); // 申请内存。
	void RemMemory(NODEPOINT& point); // 释放内存。

	void ListDestroy(); // 破坏

public:
	SINGLELIST();

	void ListClear(); // 清空
	int ListSize(); // 链表元素个数，

	bool ListInsNext(const int& inssite, const int& data); // 插入
	bool ListPushBack(const int& data); // 添加 可以由 ListInsNext 实现。

	int ListRemNext(const int& remsite); // 移除 
	int ListPopBack(); // 移除。 可以由 ListRemNext 实现。

	int ListFind(const int& data); // 返回位置。

	int ListData(const int& site);  // 输出位置为 site 的数据值。

	void ListCout(); // 输出。

	~SINGLELIST();

};
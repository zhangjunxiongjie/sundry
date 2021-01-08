// SingleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 单链表的实现。

#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

int SINGLELIST::ListData(const int& site) {  // 输出位置为 site 的数据值。
	int value;
	if (site >= Size || site < 0)
	{
		value = -1;
	}
	else
	{
		int count = site;
		NODEPOINT move = Head;
		while (count)
		{
			move = move->next;
			count--;
		}
		value = move->value;
	}
	return value;
}

void SINGLELIST::ListCout() { // 输出。
	for (int i = 0; i < Size; i++)
	{
		cout << ListData(i) << ":";
	}
	cout << endl;

	/*
	NODEPOINT move = Head;
	while (move)
	{
		cout << move->value << ":";
		move = move->next;
	}
	cout << endl;
	*/
}

void SINGLELIST::ReqMemory(NODEPOINT& point) {  // 申请内存。
	point = (NODE*) new NODE; 
}

void SINGLELIST::RemMemory(NODEPOINT& point) {   // 释放内存。
	delete point;
}

SINGLELIST::SINGLELIST()
{
	Head = nullptr;
	Tail = nullptr;
	Size = 0;
}

void SINGLELIST::ListDestroy() { // 破坏,清空。
	NODEPOINT move = Head;
	while (move)
	{
		NODEPOINT movelast = move;
		move = move->next;
		RemMemory(movelast);
	}
}

void SINGLELIST::ListClear() { // 清空
	ListDestroy(); // 清空。
	SINGLELIST(); // 初始化。
}

int SINGLELIST::ListSize() { // 链表元素个数，
	return Size;
}

bool SINGLELIST::ListInsNext(const int& inssite, const int& data) { // 插入
	NODEPOINT p;
	ReqMemory(p);
	p->value = data;

	if (inssite > Size || inssite < 0) // 插入位置超过节点个数。
	{
		return false;
	}
	else // 这里既可以加到头结点尾节点更可以加到中间结点。
	{
		int count = inssite;
		NODEPOINT move = Head;
		NODEPOINT movelast = move;
		while (count)
		{
			movelast = move;
			move = move->next;
			count--;
		}
		
		if (move == Head) // 添加到头结点处。
		{
			NODEPOINT buffer = Head;
			Head = p;
			Head->next = buffer;
			
			if (Tail == nullptr) // 添加第一个节点。
			{
				Tail = Head;
			}
		}
		else if (move == nullptr) // 添加到尾部。
		{
			Tail->next = p;
			Tail = Tail->next;
			Tail->next = nullptr;
		} 
		else // 添加到中间位置。
		{
			movelast->next = p;
			p->next = move;
		}
	}

	Size++;
	return true;
}

bool SINGLELIST::ListPushBack(const int& data) { // 添加
	NODEPOINT p;
	ReqMemory(p);

	p->next = nullptr;
	p->value = data;

	if (Size == 0)
	{
		Head = p;
		Tail = p;
	}
	else
	{
		Tail->next = p;
		Tail = Tail->next;
	}
	
	Size++;

	return true;
}

int SINGLELIST::ListRemNext(const int& remsite) { // 移除 即可以移除第一个也可以移除最后一个。
	int value;

	if (Size == 0 || remsite >= Size || remsite < 0)
	{
		value = -1;
		return value; // Size 不减。
	}
	else if(remsite == 0)
	{
		value = Head->value;

		if (Size == 1)
		{	
			RemMemory(Head);

			Head = nullptr;
			Tail = nullptr;
		}
		else
		{
			NODEPOINT buffer = Head;
			
			Head = Head->next;

			RemMemory(buffer);
		}
	}
	else
	{
		NODEPOINT move = Head;
		NODEPOINT movelast = move ;
		int count = remsite;
		while (count)
		{
			movelast = move;
			move = move->next;
			count--;
		}

		value = move->value;

		if (move == Tail)
		{
			Tail = movelast;
			Tail->next = nullptr;
		}
		else
		{
			movelast->next = move->next;
		}

		RemMemory(move);
	}

	Size--;
	return value;
}

int SINGLELIST::ListPopBack() { // 移除。
	int value;

	if (Size == 0)
	{
		value = -1;
		return value;
	}
	else if (Size == 1)
	{
		value = Tail->value;

		RemMemory(Head);

		Tail = nullptr;
		Head = nullptr;
	}
	else
	{
		value = Tail->value;

		NODEPOINT move = Head;
		while (move->next != Tail)
		{
			move = move->next;
		}

		RemMemory(Tail);
		
		Tail = move;
		Tail->next = nullptr;
	}
	
	Size--;

	return value;
}

int SINGLELIST::ListFind(const int& data) { // 返回位置。
	NODEPOINT move = Head;
	int count = 0;
	while (move && move->value != data)
	{
		move = move->next;
		count++;
	}
	
	if (move == nullptr)
	{
		return - 1;
	}
	else
	{
		return count;
	}
}

SINGLELIST::~SINGLELIST()
{
	ListDestroy();
}


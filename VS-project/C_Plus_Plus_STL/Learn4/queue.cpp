// 类方法定义。
#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs) // 初始化
{
	front = rear = nullptr;  // 空指针
	items = 0;
}

Queue::~Queue()  // 释放队列指针内存空间
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const // 是否为空
{
	return items == 0;
}

bool Queue::isfull() const // 是否为满
{
	return items == qsize;
}

int Queue::queuecount() const // 返回item数，当前队列项目数 
{
	return items;
}

bool Queue::enqueue(const Item& item) // 塞入队列
{
	if (isfull())
		return false;

	Node* add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;

	if (front == nullptr)
		front = add;
	else
		rear->next = add;

	rear = add;

	return true;
}

bool Queue::dequeue(Item& item) // 取出队列
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

void Customer::set(long when) // 重置处理时间，
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}


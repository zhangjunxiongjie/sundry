// 队列类声明 
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer 
{
private:
	long arrive; // 加入队列的时刻
	int processtime; // 客户需要的服务时间

public:
	Customer() { arrive = processtime = 0; }

	void set(long when);

	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node  
	{
		Item item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };

	Node* front; // 头指针
	Node* rear; // 尾指针
	int items;  // 当前项目数
	const int qsize; // 队列最高总数。
	
	Queue(const Queue& q) : qsize(0) {} // 拷贝构造函数
	Queue& operator=(const Queue& q) {} // 赋值重载函数

public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

#endif

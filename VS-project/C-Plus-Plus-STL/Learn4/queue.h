// ���������� 
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer 
{
private:
	long arrive; // ������е�ʱ��
	int processtime; // �ͻ���Ҫ�ķ���ʱ��

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

	Node* front; // ͷָ��
	Node* rear; // βָ��
	int items;  // ��ǰ��Ŀ��
	const int qsize; // �������������
	
	Queue(const Queue& q) : qsize(0) {} // �������캯��
	Queue& operator=(const Queue& q) {} // ��ֵ���غ���

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

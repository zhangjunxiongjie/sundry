// QueueSimulate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 队列模拟 ATM机客户服务队列模拟

#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MIN_PER_HR = 60;  // 每小时六十分钟

bool newcustomer(double x); // 一个随机时间向队列增加一项

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0)); // 设置随机数种子（seed）。

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	// cout << "Enter maximum size of queue:";
	cout << "请键入队列大小：";

	int qs;
	cin >> qs;  // 队列最大可容纳客户数
	Queue line(qs);

	// cout << "Enter the number of simulation hours:";
	cout << "请键入模拟时间（小时）：";

	int hours;
	cin >> hours; // 模拟的小时数
	long cyclelimit = MIN_PER_HR * hours; // 模拟的分钟数

	// cout << "Enter the average number of customers per hour:";
	cout << "请键入每小时平均客户数：";

	double perhour;
	cin >> perhour; // 每小时平均的客户数
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour; // 平均每 min_per_cust 分钟到来一个客户

	Item temp;
	long turnaways = 0; // 未加入队列的客户总数
	long customers = 0; // 加入队列的客户总数
	long served = 0; // 已经服务的客户数
	long sum_line = 0; // 队列客户数对时间的积分（每分钟的队列客户数的和） 
	int wait_time = 0; // 当前客户需要的服务时间
	long line_wait = 0; // 所有客户等待的总时间

	for (int cycle = 0; cycle < cyclelimit; cycle++) // 每一次循环为模拟的一分钟
	{
		if (newcustomer(min_per_cust)) // 如果返回true
		{
			if (line.isfull()) // 队列满
				turnaways++;
			else // 队列未满
			{
				customers++;
				temp.set(cycle); // cycle 加入队列的时刻
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty()) // 当前客户服务完成
		{
			line.dequeue(temp);
			wait_time = temp.ptime(); // 当前客户需要的处理时间
			line_wait += cycle - temp.when(); // 加上当前客户等待的时间
			served++; 
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
		
	}

	if (customers > 0)
	{
		// cout << "customers accepted:" << customers << endl; // 加入队列的客户总数
		cout << "加入队列的客户总数：" << customers << endl;
		
		// cout << "  customers served:" << served << endl; // 已经被服务的客户总数
		cout << "被服务的客户总数：" << served << endl;
		
		// cout << "         turnaways:" << turnaways << endl; // 未加入队列的客户总数
		cout << "未加入队列的客户数：" << turnaways << endl;

		// cout << "average queue size:";
		cout << "队列的平均客户数：";

		// 格式化输出
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);

		cout << (double)sum_line / cyclelimit << endl; // 平均每分钟队列的客户数
		
		// cout << "average wait time:";
		cout << "被服务客户平均等待时间：";

		cout << (double)line_wait / served << " minutes\n"; // 每个被服务的客户平均的等待时间

	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	system("pause");
	return 0;
}

bool newcustomer(double x) // 返回一个bool值，平均每x次调用返回一个true。
{
	return (std::rand() * x / RAND_MAX < 1);
}


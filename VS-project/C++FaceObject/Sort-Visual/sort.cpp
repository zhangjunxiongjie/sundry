//这个程序用于实现多种排序算法的可视化。
//这个程序暂不能实现先留在这，下面的程序是一个多线程程序的实例

/*
首先要明确的是，得有一个对序列的可视化的函数，传入函数一个数组序列，函数能够根据数组序列对数组进行可视化，但要注意每次的可视化都必须对原有输出进行清除！
如果这样做不同排序方法之间就不能将结果共存（且不能够比较），只能这样每一次都是对单一数组序列进行输出，当所有排序算法均排序结束时可以再次使用数组可视化
对每一个有序续租再次实现可视化。可是这样只能够在最后查看排序结果并无实际意义！而且各种排序之间不能够对比着来看！！！
*/

/*
即使使用了c++的多线程使所有排序并行进行了，也还存在控制台的资源竞争问题，不能够实现多排序过程的共同可视化
*/

#include <iostream>
#include <thread> // 线程库。

using namespace std;  //命名空间

void output(int i)
{
	cout << i << endl;
}

int main()
{
	
	for (uint8_t i = 0; i < 4; i++)
	{
		thread t(output, i);
		t.detach();
	}

	system("Pause");
	return 0;
}
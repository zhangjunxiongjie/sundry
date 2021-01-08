// 汉诺塔问题求解 
//

#include <iostream>
#define numOfDisks 10

using namespace std;

void Move(int n, char x, char y)
{
	cout << "move " << n << " from " << x << " to " << y << endl;
}

void Hannoi(int n, char a, char b, char c)// 通过b将n个盘子从a移动到c。
{
	if (n == 1)
	{
		Move(n, a, c); // 如果只有一个盘子则可以直接移动
	}
	else
	{
		Hannoi(n - 1, a, c, b); // 先将n-1个盘子通过c从a移动到b。
		Move(n, a, c); // 直接将第n个盘子从a移动到c。
		Hannoi(n - 1, b, a, c); // 再将n-1个盘子通过a从b移动到c。
	}
}

int main()
{
	Hannoi(numOfDisks, 'a', 'b', 'c');

	system("pause");
	return 0;
}

// EightQueen八皇后问题求解。
//

#include <iostream>
#include <conio.h> // 向量容器
using namespace std;

#define MAX 8

int sum = 0;

class QueenPuzzle
{
public:
	void printOut(); // 打印结果
	int IsValid(int n); // 判断第n个皇后放置后是否可行。
	void placeQueen(int i); // 递归，放置皇后。

private:

	int queens[MAX];
};

void QueenPuzzle::printOut() // 打印结果
{
	for (int j = 0; j < MAX; j++)
	{
		for (int i = 0; i < MAX; i++)
		{
			if (i == queens[j])  // queens[j]的值表示第j行的皇后放置的列数。
			{
				cout << "Q ";
			}
			else
				cout << "O ";
		}
		cout << endl;
	}
}

int QueenPuzzle::IsValid(int n) // 判断第n个皇后放置后是否可行。
{
	for (int i = 0; i < n; i++)
	{
		if (queens[i] == queens[n])
		{
			return 0;
		}
		
		if (abs(queens[i] - queens[n]) == abs(n - i)) // 这里后面因为n-i必为正数所以这个abs(求绝对值)可以省略。
		{
			return 0;
		}
		
		/*
		if (queens[i] - queens[n] == (i - n) || queens[i] - queens[n] == (n - i))
		{
			return 0;
		}
		*/
	}
	return 1;
}

void QueenPuzzle::placeQueen(int i) // 递归，放置皇后。
{
	if (i == MAX) // 此时每一行的皇后都已放置完毕，0~i-1。递归终止条件。
	{
		sum++;
		cout << "第" << sum << "组解：" << endl;
		printOut();
		return;
	}

	for (int j = 0; j < MAX; j++) // 依次将皇后放置在每一列。
	{
		queens[i] = j; // 将皇后放置在第i行j列。或者说第i行的皇后放置在第j列。

		if (IsValid(i)) // 如果当前放置合法，则继续放置下一行的皇后。
		{
			placeQueen(i + 1);
		}
	}
}

int main()
{
	QueenPuzzle queen;

	queen.placeQueen(0); // 从第0行开始放皇后。

	system("pause");
	return 0;
}

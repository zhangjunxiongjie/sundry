// 拉丁方阵问题，
//

#include <iostream>
using namespace std;

int main()
{
	int count;
	cout << "方阵阶数：";
	cin >> count;

	int* matrix = new int[count * count]; // 一维数组模拟二维数组

	for (int i = 0; i < count; i++) // 初始化第一行。
	{
		matrix[i] = i + 1;
	}

	for (int i = 1; i < count; i++)
	{
		for (int j = 0, f = i; j < count; j++)
		{
			matrix[i * count + j] = matrix[f];
			if (f == count - 1) //
			{
				f = 0;
			}
			else
			{
				f++;
			}
		}
	}


	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout << matrix[i * count + j] << " ";
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
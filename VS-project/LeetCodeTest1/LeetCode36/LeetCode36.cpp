//用于测试力扣的题解代码
// 【36】有效的数独。 

#include <iostream> //这个程序可以以九个3*3矩阵的小矩阵输出9*9矩阵的大矩阵

int main()
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf_s("%d:%d ", i % 3 * 3 + j / 3, j % 3 + i / 3 * 3);
		}
		printf_s("\n");
	}

	system("Pause"); //pause暂停
	return 0;
}
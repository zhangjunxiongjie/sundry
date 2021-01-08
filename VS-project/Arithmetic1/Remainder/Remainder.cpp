//使用加法实现乘法。(只考虑算法实现)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int multiplier1, multiplier2;
	int result = 0;  
	int temporary_multiple;   //临时倍数
	int temporary_multiplier; //临时乘数

	printf_s("请输入两个乘数:");
	scanf_s("%d %d", &multiplier1, &multiplier2);

	temporary_multiple = 1;
	temporary_multiplier = multiplier1;

	while (true)
	{
		if (multiplier2 >= temporary_multiple)
		{
			multiplier2 -= temporary_multiple;
			result += temporary_multiplier;
		}
		else if (temporary_multiple != 1)
		{
			temporary_multiple = 1;
			temporary_multiplier = multiplier1;
		}
		else
		{
			break;
		}

		if (temporary_multiple + temporary_multiple <= multiplier2)
		{
			temporary_multiple += temporary_multiple;
			temporary_multiplier += temporary_multiplier;
		}
	}

	printf_s("乘法结果为:%d\n", result);

	system("Pause");   //调用DOS命令暂停程序

	return 0;
}


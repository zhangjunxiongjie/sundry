//使用减法实现对数值的整除。
//需要注意的是两个除数的符号。（或者说注意余数的符号）（这里余数均规定为正数）
//这里并不考虑溢出（或者其他问题）主要是写出思路。（不考虑0，不考虑负数变正数溢出）

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dividend, divisor;  //divisor：除数，dividend：被除数。
	int sign; //用于记录结果的符号
	int result = 0; //存储结果
	int temporary_divisor; //临时除数
	int temporary_multiple; //临时倍数
	printf_s("请输入除数和被除数:");
	scanf_s("%d %d", &divisor, &dividend);  //保证输入一个符合要求的数这里注重实现就不考虑差错处理
	//这里因为要将负数取相反数，简便起见就不考虑溢出的问题（因为负数比正数多一个）
	if (dividend < 0 && divisor > 0) //这里使用条件语句将所有可能的负数变为正数
	{
		sign = 1;
		dividend = -dividend;
	}
	else if (dividend > 0 && divisor < 0)
	{
		sign = 1;
		divisor = -divisor;
	}
	else if (divisor < 0 && dividend < 0)
	{
		dividend = -dividend;
		divisor = -divisor;
	}
	//临时变量初始化
	temporary_multiple = 1;
	temporary_divisor = divisor;
	while (true)//算法核心，这里并没有使用简单的逐个去减，而是在减的过程中逐渐减的越来越多。直到不符合条件时瞬间降回原来的值。
	{           //另一个思路是当不符合条件时逐渐减掉多余部分而不是一下子打回最初的除数。
		if (temporary_divisor <= dividend)
		{
			dividend -= temporary_divisor;
			result += temporary_multiple;
		}
		else if(temporary_multiple != 1)
		{
			temporary_multiple = 1;
			temporary_divisor = divisor;
		}
		else
		{
			break;
		}
		if (temporary_divisor + temporary_divisor <= dividend)
		{
			temporary_divisor += temporary_divisor;
			temporary_multiple += temporary_multiple;
		}

	}

	printf_s("求得整出结果为:%d\n", result);

	system("Pause");   //调用DOS命令暂停程序

	return 0;
}
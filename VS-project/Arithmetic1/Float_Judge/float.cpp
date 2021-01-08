//这个程序用于实现输入未知数的判断，判断其是浮点数还是整数
//这里有两个方法可以使用：1.使用二分查找精确找出这个数的周边整数，如果在两个整数之间就是一个浮点数，如果等于某一个整数就是一个整数；
//2.根据浮点数和整数的区别：整数就是小数部分全为零的小数，取未知数小数部分进行判断如果全部为零则为整数否则为浮点数。
//这里使用第一种精确二分查找的方法。

#include <iostream>

#include <limits.h>  //这个头文件定义了基本数据类型的数值范围的宏


//这里存在的问题就是能够判断的数值大小是受限的，受限于数据类型能够存储的数值范围
bool Float_judge(double it)//这个函数用于判断数的整和浮。使用了二分查找精确查找传入数的数值大小，用以判断是整数还是浮点数。
{
	bool result;//result：结果.浮点数返回true，整数返回false；

	long int left = LONG_MIN, right = LONG_MAX;   //这里的左右值取决于类型能够容纳的最大范围，这里使用了基本数据类型的最大值和最小值
	 
	while (true)
	{
		if (left == it || right == it)
		{
			result = false;
			break;
		}
		else if (right - left == 1 && left < it && right > it)
		{
			result = true;
			break;
		}
		else
		{
			//printf("%ld:%ld:%ld:%f\n", left, right, (left + right) / 2, it);
			if ((left + right) / 2 > it)
			{
				right = (left + right) / 2;
			}
			else if((left + right) / 2 < it)
			{
				left = (left + right) / 2;
			}
			else
			{
				result = false;
				break;
			}
		}
		printf("%ld:%ld.\n", left, right);

	}

	return result;
}

int main()
{
	double target;  //target：目标； 这里为了使所有输入的数都能够正确的得到判断，采用了这个语言能使用的最大数据类型来存储这个未知数。
	//当然其实这里完全可以使用字符输入的做法，将数值的所有位数均当做一个字符处理。但是如果这样的话这个程序就毫无意义了，
	//另一方面这里假设是在写一个函数给这个函数传入一个数，这个函数的功能就是判断这个数的浮整。
	
	scanf_s("%lf", &target);

	printf_s("%lf###%d", target, Float_judge(target));

	system("Pause"); //调用系统命令，system:系统；pause：暂停。
	return 0;
}





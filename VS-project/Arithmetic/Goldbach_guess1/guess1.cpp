/*这个版本使用另一种时间复杂度较高的算法即：
"定义一个函数用于判断一个数是否是素数然后循环小于输入数的所有数依次判断循环数i和a-i（a是输入数）是否是素数
直到同时是素数时退出循环。"
*/
/*相比两种算法这一种算法更易于将所有符合条件的项找出来，因为是对所有可能进行遍历找到符合条件的项更全面。
！！！前面分析有问题。第一个版本并没有错并且可以找出所有符合条件的项，这一版本有错，这一版本实际找重了
这一版本把两个数字反过来后依然作为不同的一项实际两个数字完全相同，所以这一版本得到了第一版本的两倍的结果项。
*/
//因为这一版本实际将一项的两数交换作为另一项故这一版本的每一次输出都有偶数项

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool Prime(int wr)   //传入一个数,判断这个数是不是素数
{
	double wy = pow(wr, 0.5);// 计算x的y次幂
	bool wt=true;
	int i=2;
	while (i < wy)
	{
		if (wr%i == 0)
		{
			wt = false;
			break;
		}
		i++;
	}
	return wt;
}



int main()
{
	int ty, tr;   //ty用于存储输入的数，tr用于存储大于且与ty/2相邻的素数下标
	int i,num=0;
	while (!scanf_s("%d", &ty) || ty <= 6 || ty % 2 == 1);
	
	for (i = 2; i < ty; i++)
	{
		tr = ty - i;
		if (Prime(i) && Prime(tr))
		{
			printf("%d+%d=%d\n", i, tr, ty);
			num++;
			//break;
		}
	}
	printf("%d\n", num);
	system("Pause");
	return 0;
}


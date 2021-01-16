/*哥德巴赫猜想:一个大于六的偶数一定能由两个素数相加得到。
此程序用于输入一个大于六的偶数输出哥德巴赫猜想中的两个素数。
一种方法:先求出小于输入数的所有素数存储于一个数组，再求素数过程中找到与输入数一半的数相邻（大或小）那个素数记录下标，
然后在这个数周围进行遍历求得这两个数两个。
另一种方法:定义一个函数用于判断一个数是否是素数然后循环小于输入数的所有数依次判断循环数i和a-i（a是输入数）是否是素数
直到同时是素数时退出循环。
注意输入数字判断必须大于六不能等于！
*/
/*
*/


#include <stdio.h>
#include <stdlib.h>

#define N 10000

int Prime(int* we,int wr,int* lenr)   //传入一个数和一个数组，求得这个数的素数存储于这个数组中,返回大于输入数一半的那个素数的坐标。
{
	int wy = wr / 2, wt = 0, i, j, len;
	we[0] = 2;
	len = 1;
	for ( i= 3; i< wr; i++)
	{
		for ( j = 0; j < len; j++)
		{
			if (i%we[j] == 0)
				break;
		}
		//printf("%d\n",j);
		if (j == len)  //判断是否为素数
		{
			if (i >= wy && wt == 0) //如果是素数且大于wr的一半且wt为初值
				wt = len;
			we[len] = i;
			len++;
			//printf("%d ", we[len - 1]);
		}
	}
	*lenr = len;
	return wt;
}



int main()
{
	int ty,tr;   //ty用于存储输入的数，tr用于存储大于且与ty/2相邻的素数下标
	int i,num=0,len;
	int tf[N];
	while (!scanf_s("%d", &ty) || ty <= 6 || ty % 2 == 1);
	tr = Prime(tf, ty,&len);
	i = tr - 1;
//	while (0<=i&&i<=len)
	while (tf[i] + tf[tr] != ty)
	{
		if (tf[i] + tf[tr] < ty)
			tr++;
		else if (tf[i] + tf[tr] > ty)
			i--;
	/*	else if (tf[i] + tf[tr] == ty)
		{
			printf("%d+%d=%d\n", tf[i], tf[tr], ty);
			num++;
			tr++;
			//i--;
		}*/
	}
	printf("%d+%d=%d\n", tf[i], tf[tr], ty);
	//printf("%d\n", num);

	system("Pause");
	return 0;
}



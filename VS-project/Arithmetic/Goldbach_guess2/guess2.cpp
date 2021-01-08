/*这一版本结合前两个版本的优点使用一个更加优化的方法：
即不遍历全部可能而是遍历所有素数，并在素数中使用二分查找查找是否有a-i即与素数i相加等于a的素数，
当a-i小于a/2时从前往后遍历否则从后往前遍历。
找到后则对这两个数进行标记。
*/
//这一版本中程序需要找出所有符合条件的项。先使用遍历查找。
//可以在匹配对应项（查找）时使用二分查找。
/*问题：还有一点小问题这一版本为所有不重复项但是却在有的时候总的结果项不等于第二版本的一半。还有待解决。
*/
/*
第一版本：先建立素数表从素数表中间开始向两边查找符合条件的项；
第二版本：遍历所有小于输入数的值判断这个值和输入值与这个值的差是否是否是素数；（存在项重复的问题）
第三版本：先建立素数表在这个素数表中遍历，然后查找素数表中是否存在输入值与这个值之间的差这个值。
*/
#include <stdio.h>
#include <stdlib.h>

#define N 10000

int Tf[N][2];  //这里之所以把它放在全局是为了使它的初值为零。

int Prime( int wr, int* lenr)   //传入一个数,求得这个数的素数存储于全局数组中,返回大于输入数一半的那个素数的坐标。
{
	int wy = wr / 2, wt = 0, i, j, len;
	Tf[0][0] = 2;
	len = 1;
	for (i = 3; i < wr; i++)
	{
		for (j = 0; j < len; j++)
			if (i%Tf[j][0] == 0)
				break;
		if (j == len)  //判断是否为素数
		{
			if (i >= wy && wt == 0) //如果是素数且大于wr的一半且wt为初值
				wt = len;
			Tf[len][0] = i;
			len++;
		}
	}
	*lenr = len;
	return wt;
}

bool Mate(int lenr,int ti,int te)//用于匹配输入数是否在素数数组中,传入素数数组长度，素数数组中间值下标，以及匹配素数，从最后一个值向前遍历至中间值下标
{
	bool Tt=false;
	int i;
	for (i = lenr - 1; i >= ti; i--)
	{
		while (Tf[i][1] == -1)   //这里数组的另一个值用于跳过已经匹配的值。
			i += Tf[i][1];
		if (Tf[i][0] == te)
		{
			Tt = true;
			Tf[i][1] = -1;
			break;
		}
	}



	return Tt;
}


int main()
{
	int ty, tr;   //ty用于存储输入的数，tr用于存储大于且与ty/2相邻的素数下标
	int i, num = 0, len;    //用于存储素数数组的长度
	
	while (!scanf_s("%d", &ty) || ty <= 6 || ty % 2 == 1);
	tr = Prime( ty, &len );    //tr用于存储大于且与ty/2相邻的素数下标，

	for (i = 0; i < tr; i++)   //只用遍历到tr位置，素数由前往后遍历，匹配数由后往前遍历遍历到tr
	{
		if (Mate(len, tr, ty - Tf[i][0]))
		{
			printf("%d+%d=%d\n", Tf[i][0], ty - Tf[i][0], ty);
			num++;
		}
	}
	
	printf("%d\n", num);

	system("Pause");
	return 0;
}


//计算n+nn+nnn+...
#include <stdio.h>
int main()
{
	int i1 = 1, i2, n, t, sum; //i1,i2分别是内外循环的‘表征’
	long int jh = 0;		   //jh是总的和
	printf("请分别输入位数和积数：");
	scanf("%d,%d", &n, &t); //n是位数和数字的个数，t是那个数
	do
	{
		for (i2 = 1; i2 <= i1; i2++) //内循环计算出第几个数的数值
		{
			if (i2 > 1)
				sum = t + sum * 10;
			else
				sum = t;
		}
		printf("%d ", sum);
		jh = jh + sum;
		i1++;
	} while (i1 <= n);
	printf("\n%ld\n", jh);
	return 0;
}

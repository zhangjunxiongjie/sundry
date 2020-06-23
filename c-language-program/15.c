#include <stdio.h>
void main()
{
	int a, b, c, d; //整型变量的定义与使用//
	unsigned u;		//指定u为无符号整型变量//
	a = 12;
	b = -24;
	u = 10;
	c = a + u;
	d = b + u;
	printf("%d,%d\n", c, d);
}

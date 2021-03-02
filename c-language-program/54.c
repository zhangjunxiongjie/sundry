#include <stdio.h> //函数简单的递归调用//
int main()
{
	int jc(int x);
	int m, t, k;
	scanf("%d", &k);
	t = k * k;
	m = jc(t);
	printf("%d\n", m);
	return 0;
}

int jc(int x) //实现阶乘//
{
	int z;
	if (x == 1)
		z = 1;
	else
		z = jc(x - 1) * x;
	return (z);
}

#include <stdio.h> //计算2+22+222...//
#include <math.h>  //应用到函数的调用//
main()
{
	int th(int x, int y);
	int a, s, sum = 0;
	double k, t;
	scanf("%d,%lf", &a, &t);
	while (t >= 0.0)
	{
		k = t;
		s = th(a, k);
		sum = sum + s;
		t = t - 1.0;
	}
	printf("%d\n", sum);
}

int th(int x, int y) //实现对单个值的求得//
{
	int s;
	for (s = 0; y >= 0.0; y--)
		s = s + x * pow(10, y);
	return (s);
}

//求最大公约数
#include <stdio.h>
int main()
{
	int m, n, a[50], b[50], c[50], i, t, f;
	scanf("%d,%d", &m, &n);

	for (t = 0, i = m; i > 0; i--) //计算两数的约数
		if (m % i == 0)
		{
			a[t] = i;
			t++;
		}
	for (f = 0, i = n; i > 0; i--) //
		if (n % i == 0)
		{
			b[f] = i;
			f++;
		}
	for (m = 0, i = 0; m < t; m++) //两数的约数比较，并将两数约数中相同的数放入数组c[]中
		for (n = 0; n < f; n++)
			if (a[m] == b[n])
			{
				c[i] = a[m];
				i++;
			}
	t = c[0];
	for (f = 1; f < i; f++) //将两数共同拥有的约数中的最大值放入t中
		if (t < c[f])
			t = c[f];
	printf("%d\n", t);
	return 0;
}

//求两数的最大公约数
#include <stdio.h>
int main()
{
	void digui(int a, int b); //使用了递归调用，和一个特殊算法
	int m, n, t;
	scanf("%d,%d", &m, &n);
	if (m < n)
	{
		t = n;
		n = m;
		m = t;
	}
	digui(m, n);
	return 0;
}

void digui(int a, int b)
{
	int m, n;
	if (a % b == 0)
		printf("%d\n", b);
	else
	{
		m = b;
		n = a % b;
		digui(m, n); //***此调用函数必须在开头定义两个变量用于存放a，b中较小数和两者的余数作为实参传给下一层递归函数
	}				 //不能直接把a，b作为digui的实参，因为在digui中a，b存在且作为了形参***
}

//求中位数
#include <stdio.h>
int main()
{
	int i, t, a[50];
	double m;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
		scanf("%d", a + i);
	if (t % 2 == 0) //判断这组数一共有多少个数
		m = (a[(t - 1) / 2] + a[(t + 1) / 2]) / 2;
	else //再利用相应的方法求其中位数并放入m中
		m = a[(t - 1) / 2];
	printf("%5.3f\n", m);
	return 0;
}

//求两个数的最小公倍数
#include <stdio.h>
int main()
{
	int m, n, i, t, f, a[50], b[50], c[50];
	scanf("%d,%d", &m, &n);
	for (i = 1; i <= n; i++) //求出m在1-n倍的所有倍数放入a[]数组中
		a[i - 1] = i * m;
	for (i = 1; i <= m; i++) //
		b[i - 1] = i * n;

	for (t = 0, i = 0; t < m; t++) //在对方整数内倍数的相同值放入数组c[]中
		for (f = 0; f < n; f++)
			if (a[f] == b[t])
			{
				c[i] = a[f];
				i++;
			}
	t = c[0];
	for (f = 1; f < i; f++) //找出在它们共同拥有公倍数中的最小值放入t中
		if (t > c[f])
			t = c[f];
	printf("%d\n", t);
	return 0;
}
#include <stdio.h> //�����򵥵ĵݹ����//
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

int jc(int x) //ʵ�ֽ׳�//
{
	int z;
	if (x == 1)
		z = 1;
	else
		z = jc(x - 1) * x;
	return (z);
}

#include <stdio.h> //����2+22+222...//
#include <math.h>  //Ӧ�õ������ĵ���//
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

int th(int x, int y) //ʵ�ֶԵ���ֵ�����//
{
	int s;
	for (s = 0; y >= 0.0; y--)
		s = s + x * pow(10, y);
	return (s);
}

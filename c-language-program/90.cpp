//计算一个数的位数
#include <stdio.h>
int main()
{
	int n, m, i = -1, a;
	scanf("%d", &a);
	while (m != 0 || n != 0)
	{
		m = a % 10;
		n = a / 10;
		a = a / 10;
		i++;
	}
	printf("%d\n", i);
	return 0;
}

//对输入的数进行处理输出
#include <stdio.h>
int main()
{
	int i[10], cc[10];
	int f, t1 = 0, t2, f1 = 0;
	while (t1 < 10)
	{
		scanf("%d", cc + t1);
		t1++;
	}
	for (t1 = 0; t1 < 10; t1++)
	{
		f = cc[t1] % 42;
		if (f1 == 0)
		{
			f1 = f1 + 1;
			i[0] = cc[t1];
		}
		else
			for (t2 = 0; t2 < f1; t2++)
			{
				if (f == i[t2])
				{
					i[f1] = cc[t1];
					f1++;
				}
			}
	}
	printf("%d\n", f1);
	return 0;
}

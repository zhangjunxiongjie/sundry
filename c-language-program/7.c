//���һ����������ɵ��й��ɵľ���
#include <stdio.h>
int main()
{
	int i, t;
	for (i = 1; i <= 4; i++)
	{
		for (t = i; t < i + 27 * i; t = t + i)
		{
			printf(" %d  ", t);
			if (t >= 10)
				printf("\b");
			if (t >= 100)
				printf("\b");
		}
		printf("\n");
	}
	return 0;
}
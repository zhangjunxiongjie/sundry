//����n+nn+nnn+...
#include <stdio.h>
int main()
{
	int i1 = 1, i2, n, t, sum; //i1,i2�ֱ�������ѭ���ġ�������
	long int jh = 0;		   //jh���ܵĺ�
	printf("��ֱ�����λ���ͻ�����");
	scanf("%d,%d", &n, &t); //n��λ�������ֵĸ�����t���Ǹ���
	do
	{
		for (i2 = 1; i2 <= i1; i2++) //��ѭ��������ڼ���������ֵ
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

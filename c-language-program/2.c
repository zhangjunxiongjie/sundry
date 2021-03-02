//用contiune语句提前结束本次循环
//输出不能被三整除的数
#include <stdio.h>
int main()
{
	int n, i = 0;
	for (n = 100; n <= 196; n++)
	{
		if (n % 3 == 0)
			continue;
		printf("%d ", n);
		i++;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#define SUM 100000 //指定符号常量SUM代表100000
int main()
{
	float amount, aver, total;
	int i;
	for (i = 1, total = 0; i <= 1000; i++)
	{
		printf("please enter amount:");
		scanf("%f", &amount);
		total = total + amount;
		if (total >= SUM)
			break; //break  提前终止整个循环
	}
	aver = total;
	printf("num=%d\naver=%10.2f\n", i, aver);
	return 0;
}
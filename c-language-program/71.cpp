// 产生两位数的随机数

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int a = rand();
	printf("%d\n", a % 100);
	return 0;
}

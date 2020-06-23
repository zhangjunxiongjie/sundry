#include <stdio.h>    /*用第三个数与前面一个数之差与另一个数比较来判断
第三个数是否大于另两个数之和 ,以避免两数相加放在一个变量中出现数据溢出的情况*/
int main()
{
	long int a[10][3];
	int count,i;
	scanf("%d",&count);
	for(i=0;i<count;i++)
		scanf("%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2]);
	for(i=0;i<count;i++)
	{
		if(a[i][2]-a[i][1]<a[i][0])
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}
	return 0;
}


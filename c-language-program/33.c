//输入n个数，从这n个数中取出数值大小在前k个数的这k个数
#include <stdio.h>
int main()
{
	int n;	   //总的数值个数
	int k = 5; //取出的先多少个数
	//printf("n=");
	//scanf ("%d",&n);
	//printf("k=");
	//scanf ("%d",&k);
	int a[10000]; //储存数值总个数的数组
	int i = 0, c, jhzj;
	int b[5];	  //储存输出的前k个数
	while (i < n) //输入所有n个数值
	{
		scanf("%d", &a[i]);
		i++;
	}
	for (i = 0; i < k; i++) //将输入的n个数中前k个数赋给b[]数组作为初始值
	{
		b[i] = a[i];
	}
	for (c = 0; c < k; c++) //先对初始的输出数组b[]进行排序，确保最后输出能够始终是由大到小
	{
		i = ++c;
		while (i < k)
		{
			if (b[c] < b[i])
			{
				jhzj = b[i];
				b[i] = b[c];
				b[c] = jhzj;
			}

			i++;
		}
	}						//
	for (i = k; i < n; i++) //将数组a[]中后面的数依次与每一个b[]数组中没一个数比较
	{
		c = 0;
		while (c < k)
		{
			if (a[i] > b[c])
			{
				jhzj = b[c];
				b[c] = a[i];
				a[i] = jhzj;
				c++;
				//printf("%d ",b[c]);
			}
			else
			{
				c++;
			}
		}
	}						 //
	for (i = 1; i <= k; i++) //输出b[]数组
	{
		printf("%d ", b[i - 1]);
		//if(i%4==0)
		//printf("\n");
		//else
		//printf(" ");
	} //
	printf("\n");
	return 0;
}
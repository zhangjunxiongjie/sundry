//输出整个乘法表
//右对齐
#include <stdio.h>
int main ()
{
int i,t;
i=1;
while(i<=9)
{
	for(t=1;t<=i;t++)
	{
		printf("%d*%d=%d",t,i,t*i);
		if(t==i)           //判断是否到句末
		{
			printf("\n");  
		}
		else
        {
			if((t*i)/10!=0)           //当没有到句末时间隔前面结果为两位数时输出一个空格
			{
				printf(" ");
			}
			else
			{
				printf("  ");          
			}
		}
	}
	i++;
}
return 0;
}
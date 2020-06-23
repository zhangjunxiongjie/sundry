#include <stdio.h>
int main (void)
{
	int i,i1,i2,h,t;
	int a[100];
	char ch;
	scanf("%d\n",&i);
	t=i;
	for(i1=0,h=1;(ch=getchar())!='\n'&&i1<=i;)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(ch!=' ')
		{
			a[i1-1]=a[i1-1]+ch-48;
		}
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i2=0;i2<i1;i2++)
	{
		if(a[i2]!=0)
		{
			for(h=i2+1;h<i1;h++)
			{
			    if(a[i2]==a[h])
				{
				    a[h]=0;
			    	i--;
				}
			}
		}
	}
    for(i1=0;i1<t;i1++)
	{
		for(i2=i1+1;i2<t;i2++)
		{
			if(a[i1]>a[i2])
			{
				h=a[i1];
				a[i1]=a[i2];
				a[i2]=h;
			}
		}
	}
    printf("%d\n",i);
	for(h=0;h<t;h++)
	{
		if(a[h]!=0)
		{
			printf("%d",a[h]);
		    if(h<t-1)
				printf(" ");
		}
	}
	printf("\n");
return 0;
}

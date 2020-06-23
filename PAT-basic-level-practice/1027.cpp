#include <stdio.h>
int main ()
{
	int i1,i2,h,n,m;
	int a[2];
	char ch;
	for(a[0]=0,h=0,n=1;(ch=getchar())!='\n';)
	{
		if(h==0&&ch!=' ')
		{
			a[0]=a[0]*10+ch-48;
		}
		else if(h==1&&ch!=' ')
		{
			if(n==1)
				a[1]=ch-48;
			else if(n==0)
				a[1]=a[1]*10+ch-48;
		}
		if(ch==' ')
			h=1;
		if(ch==' ')
			n=1;
		else
			n=0;
	}
	m=a[0];
	n=1;
	while(a[0]>=n*2)
	{
		if(n==1)
			a[0]=a[0]-n;
		else
			a[0]=a[0]-n*2;
		n=n+2;
	}
	n=n-2;
	if(m>=2)
	{
		for(i1=n,i2=0;i1>=1;i1=i1-2,i2++)
		{
			for(h=i2;h>0;h--)
				printf(" ");
			for(h=i1;h>0;h--)
				printf("%c",a[1]);
			printf("\n");
		}
		for(i1=3;i1<=n;i1=i1+2,i2--)
		{
			for(h=i2-2;h>0;h--)
				printf(" ");
			for(h=i1;h>0;h--)
				printf("%c",a[1]);
			printf("\n");
		}
	printf("%d\n",a[0]);
	}
	else if(m<=1)
	{	
		if(m==1)
			printf("%c\n",a[1]);
		printf("0\n");
	}
	return 0;
}

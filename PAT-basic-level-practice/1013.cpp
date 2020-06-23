#include <stdio.h>
int main (void)
{
	int a[2],b[10000],n;
	int i1,i2,h;
	char ch;
	for(i1=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			a[i1-1]=a[i1-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0,n=1;i1<=a[1];n++)
	{
		for (i2=2;i2<=n-1;i2++)
			if(n%i2==0) break;
		if(i2>=n)
		{
			b[i1]=n;
			i1++;
		} 
	}
	for(i1=a[0],i2=0;i1<=a[1];i1++,i2++)
	{
		if((i2+1)%10!=0&&i1!=a[1])
		   printf("%d ",b[i1]);
		else if((i2+1)%10==0)
			printf("%d\n",b[i1]);
		else if(i1==a[1])
			printf("%d\n",b[i1]);

	}
	return 0;
}


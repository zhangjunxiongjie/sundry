#include <stdio.h>
int main ()
{
	int i,i1,i2,h,t,n;
	char ch;
	int a[1000][16],b[1000];
	scanf("%d\n",&n);
	for(i1=0;i1<n;i1++)
	{
		for(i2=1,h=0,t=0;(ch=getchar())!='\n';)
		{
			if(h==0&&ch!=' ')
			{
				a[i1][i2]=ch-48;
				i2++;
			}
			if(h==1&&ch!=' ')
			{
				if(t==1)
					a[i1][0]=ch-48;
				else if(t==0)
					a[i1][0]=a[i1][0]*10+ch-48;
			}
			if(h==2&&ch!=' ')
			{
				if(t==1)
					a[i1][15]=ch-48;
				else if(t==0)
					a[i1][15]=a[i1][15]*10+ch-48;
			}
			if(ch==' ')
				h++;
			if(ch==' ')
				t=1;
			else
				t=0;
		}
	}
	scanf("%d\n",&i);
    for(i1=0,h=1;(ch=getchar())!='\n'&&i1<=i;)
	{
		if(h==1&&ch!=' ')
		{
			b[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			b[i1-1]=b[i1-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0;i1<i;i1++)
	{
		for(i2=0;i2<n;i2++)
		{
			if(b[i1]==a[i2][0])
			{
				for(h=1;h<15;h++)
					printf("%d",a[i2][h]);
				printf(" %d\n",a[i2][15]);
			}
		}
	}
/*	for(i1=0;i1<n;i1++)
	{
		for(i2=0;i2<16;i2++)
			printf("%d ",a[i1][i2]);
		printf("\n");
	}*/
	return 0;
}

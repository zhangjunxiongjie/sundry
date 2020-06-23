#include <stdio.h>
int main (void)
{
	int i,i1,i2,i3,i4;
	int h,t;
	int a[100],b[500][500];
	char ch;
	for(i1=0,h=1;(ch=getchar())!='\n'&&i1<=5;)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h!=1&&ch!=' ')
		{
			a[i1-1]=(a[i1-1]*10)+ch-48;
		}
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0,h=1;(ch=getchar())!='\n'&&i2<=a[1];)
		{
			if(h==1&&ch!=' ')
			{
				b[i1][i2]=ch-48;
				i2++;
			}
			else if(h!=1&&ch!=' ')
			{
				b[i1][i2-1]=(10*b[i1][i2-1])+ch-48;
			}
			if(ch==' ')
			{
				h=1;
			}
			else
				h=0;
		}
	}
/*	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[1];i2++)
			printf("%d ",b[i1][i2]);
		printf("\n");
	}
*/
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[1];i2++)
		{
			if(b[i1][i2]<=a[3]&&b[i1][i2]>=a[2])
			{
				b[i1][i2]=a[4];
			}
		}
	}
    /*for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[1];i2++)
			printf("%d ",b[i1][i2]);
		printf("\n");
	}*/
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[1];i2++)
		{
			if(b[i1][i2]/10==0)
				printf("00");
			else if(b[i1][i2]/100==0)
				printf("0");
			if(i2<a[1]-1)
			    printf("%d ",b[i1][i2]);
			else
				printf("%d",b[i1][i2]);
		}
		printf("\n");
	}
return 0;
}
	


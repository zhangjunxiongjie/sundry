#include <stdio.h>
int main (void)
{
	int a[1000];
	int i1,i2,h;
	float i,b3;
	int b[5]={0,0,0,0,0},pd[5]={0,0,0,0,0};
	char ch;
	for(i1=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			a[i1-1]=(a[i1-1]*10)+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
/*	for(i2=1;i2<i1;i2++)
		printf("%d ",a[i2]);*/
	for(i2=1,h=1,i=0.0;i2<i1;i2++)
	{
		if(a[i2]%10==0)
		{
			b[0]=b[0]+a[i2];
			pd[0]=1;
		}
		if(a[i2]%5==1)
		{
			b[1]=b[1]+(h*a[i2]);
			h=-h;
			pd[1]=1;
		}
		if(a[i2]%5==2)
		{
			b[2]++;
			pd[2]=1;
		}
		if(a[i2]%5==3)
		{
			b[3]=b[3]+a[i2];
			i=i+1.0;
			pd[3]=1;
		}
		if(a[i2]%5==4)
		{
			if(b[4]<a[i2])
				b[4]=a[i2];
			pd[4]=1;
		}
	}
	b3=b[3]/i;
	for(i1=0;i1<5;i1++)
	{
		if(i1!=4&&pd[i1]==1&&i1!=3)
		{
			printf("%d ",b[i1]);
		}
		else if(i1==3&&pd[i1]==1)
			printf("%.1f ",b3);
		else if(i1==4&&pd[i1]==1)
			printf("%d\n",b[i1]);
		else if(pd[i1]==0)
		{
			if(i1!=4)
				printf("N ");
			else
				printf("N\n");
		}
	}
	return 0;
}

	

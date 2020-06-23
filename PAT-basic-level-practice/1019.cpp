#include <stdio.h>
int main ()
{
	int pd(int* z);
	void zx(int* z);
	void jx(int* z);
	int i,t,h,it;
	char ch;
	int a[5];
	for(i=1;(ch=getchar())!='\n';i++)
		a[i]=ch-48;
	if(i!=5)
	{
		for(;i<5;i++)
			a[i]=0;			//当输入的数字并非四位数时其余数字均为零！
	}
	a[0]=i;
	if(pd(a));
	else
		while(h!=6174)
		{
			jx(a);
			for(i=1,t=0;i<a[0];i++)
			{
				printf("%d",a[i]);
				t=t*10+a[i];
			}
			printf(" - ");
			zx(a);
			for(i=1,it=0;i<a[0];i++)
			{
				printf("%d",a[i]);
				it=it*10+a[i];	
			}
			printf(" = ");
			h=t-it;
			if(h>999)
				printf("%d\n",h);
			else if(h>99)
				printf("0%d\n",h);
			else if(h>9)
				printf("00%d\n",h);
			else if(h>0)
				printf("000%d\n",h);
			a[0]=5;
			a[1]=h/1000;
			a[2]=(h/100)%10;
			a[3]=(h/10)%10;
			a[4]=h%10;
		}
	return 0;
}

int pd(int* z)
{
	int i2,i1;
	for(i1=1;i1<z[0];i1++)
		for(i2=i1+1;i2<z[0];i2++)
			if(z[i1]!=z[i2])
				return 0;
	for(i1=1;i1<z[0];i1++)
		printf("%d",z[i1]);
	printf(" - ");
	for(i1=1;i1<z[0];i1++)
		printf("%d",z[i1]);
	printf(" = 0000\n");
	return 1;
}

void zx(int* z)
{
	int i1,i2,zj;
	for(i1=1;i1<z[0];i1++)
		for(i2=i1+1;i2<z[0];i2++)
			if(z[i1]>z[i2])
			{
				zj=z[i1];
				z[i1]=z[i2];
				z[i2]=zj;
			}
}

void jx(int* z)
{
	int i1,i2,zj;
	for(i1=1;i1<z[0];i1++)
		for(i2=i1+1;i2<z[0];i2++)
			if(z[i1]<z[i2])
			{
				zj=z[i1];
				z[i1]=z[i2];
				z[i2]=zj;
			}
}

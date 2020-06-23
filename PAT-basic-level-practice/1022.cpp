//进制转化，得商取余
#include <stdio.h>
int main ()
{
	int lw(int f); //得到10的次方
	int i,h,t;
	int a[3],b[100000];
	char ch;
	for(i=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i]=ch-48;
			i++;
		}
		else if(h==0&&ch!=' ')
			a[i-1]=a[i-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else 
			h=0;
	}
	a[0]=a[0]+a[1];
	for(i=0;a[0]!=0;i++)
	{
		b[i]=a[0]%a[2];
		a[0]=a[0]/a[2];
	}
	for(h=0,t=0;h<i;h++)
		t=t+b[h]*lw(h);
	printf("%d\n",t);
	return 0;
}

int lw(int f)
{
	int i;
	for(i=1;f>0;f--)
		i=i*10;
	return i;
}

#include <stdio.h>
int main ()
{
	int i,i1,i2,h;
	char ch;
	int a[100000][2];
	scanf("%d\n",&i);
	for(i1=0;i1<i;i1++)
		for(i2=0,h=1;(ch=getchar())!='\n';)
		{
			if(h==1&&ch!=' ')
			{
				a[i1][i2]=ch-48;
				i2++;
			}
			else if(h==0&&ch!=' ')
				a[i1][i2-1]=a[i1][i2-1]*10+ch-48;
			if(ch==' ')
				h=1;
			else
				h=0;
		}
//	for(i1=0;i1<i;i1++)
//		printf("%d %d\n",a[i1][0],a[i2][1]);
	for(i1=0;i1<i;i1++)
	{
		for(i2=i1+1;i2<i;i2++)
		{
			if(a[i1][0]==a[i2][0])
			{
				a[i1][1]=a[i1][1]+a[i2][1];
				a[i2][0]=0;
				a[i2][1]=0;
			}
		}
	}
	h=0;
	for(i1=0;i1<i;i1++)
	{
		if(a[h][1]<a[i1][1])
			h=i1;
	}
	printf("%d %d\n",a[h][0],a[h][1]);
	return 0;
}


//ÁíÒ»ÖÖËã·¨ 
#include <stdio.h>
int main ()
{
	int i,i1,i2,h,i3,t;
	char ch;
	int a[100000][2],b[10000][2];
	scanf("%d\n",&i);
	for(i1=0,i3=0;i1<i;i1++)
	{
		for(i2=0,h=1;(ch=getchar())!='\n';)
		{
			if(h==1&&ch!=' ')
			{
				a[i1][i2]=ch-48;
				i2++;
			}
			else if(h==0&&ch!=' ')
				a[i1][i2-1]=a[i1][i2-1]*10+ch-48;
			if(ch==' ')
				h=1;
			else
				h=0;
		}
		for(t=0,i2=0;i2<i3;i2++)
		{
			if(b[i2][0]==a[i1][0])
			{
				b[i2][1]=b[i2][1]+a[i1][1];
			//	printf("%d ",a[i1][0]);
				t=1;
			}
		}
		if(t==0)
		{
			b[i3][0]=a[i1][0];
			b[i3][1]=a[i1][1];
			i3++;
		}
		
	}
//	for(i1=0;i1<i3;i1++)
//		printf("%d %d\n",b[i1][0],b[i1][1]);
	for(h=0,i1=0;i1<i3;i1++)
		if(b[h][1]<b[i1][1])
			h=i1;
	printf("%d %d\n",b[h][0],b[h][1]);
	return 0;
}



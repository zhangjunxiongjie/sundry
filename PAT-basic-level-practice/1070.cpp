#include <stdio.h>
int main ()
{
void px(float* a1,int iz);//调用函数进行排序传入数组对数组进行排序,对数组进行操作无需返回值 
int i,i1=0,i2=1;
char ch;
float a[100],t;
scanf("%d\n",&i);
while((ch=getchar())!='\n')
{
	if(i2==1&&ch!=' ')
	{
		a[i1]=ch-48;
		i1++;
	}
	else if(i2==0&&ch!=' ')
	{
		a[i1-1]=(a[i1-1]*10)+ch-48;
	}
	if(ch==' ')
	{
		i2=1;
	}
	else
		i2=0;
}
px(a,i);
for(i1=0;i1<i-1;i1++)
{
	if(i1==0)
	   t=(a[i1]+a[i1+1])/2.0;
	else
	   t=(t+a[i1+1])/2.0;
}
i=t/1;
printf("%d\n",i);
return 0;
}

void px(float* a1,int iz)
{
	int jh,i,i1,it;
	for(i=0;i<iz;i++)
	{
		jh=a1[i];
		for(i1=i,it=i;i1<iz;i1++)
		{
			if(a1[i]>a1[i1])
			{
				a1[i]=a1[i1];
				it=i1;
			}
		}
		a1[it]=jh;
	}
}



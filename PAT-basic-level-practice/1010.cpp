//多种错误，格式错误，答案错误 
#include <stdio.h>
int main (void)
{
	int a[100];
	int i,i1,i2,m,h,t;
	char ch;
	for(i2=0;i2<100;i2++)
		a[i2]=0;
	for(h=1,i1=1,m=0,t=0;(ch=getchar())!='\n';)
	{
		if(t!=m)
		{
			t=m;
			i1++;
		}
		if(h==1&&t==m&&ch!=' '&&ch!='-')
		{
			a[i1-1]=(a[i1-1]*10)+ch-48;
		}
		else if(h==-1&&t==m&&ch!=' '&&ch!='-')
		{
			a[i1-1]=(a[i1-1]*10)-ch+48;
		//	printf("%d\n",a[i1-1]);
		}
		if(ch==' ')
		{
			h=1;
		//	if(a[i1-1]!=0)
			    m++;
		}
		else if(ch=='-')
		{
			h=-1;
		}
	}
	for(i2=0;i2<i1;i2=i2+2)
	{
		if(a[i2]*a[i2+1]!=0&&a[i2+1]!=0)
		{
			if(i2<i1-2)
				printf("%d %d ",a[i2]*a[i2+1],a[i2+1]-1);
			else
				printf("%d %d",a[i2]*a[i2+1],a[i2+1]-1);
		}
	}
/*	for(i2=0;i2<i1;i2++)
		printf("%d ",a[i2]);*/
	printf("\n");

    return 0;
}



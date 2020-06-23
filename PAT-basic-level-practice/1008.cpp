//将一个数组中的元素向右移N格，将后N个元素移动到最前面 
#include <stdio.h>
int main (void)
{
   	int i1,i2;
	int h;
	int a[2],b[100],zj[100];
    char ch;
	for(h=1,i1=0;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h!=1&&ch!=' ')
			a[i1-1]=(a[i1-1]*10)+ch-48;			
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	a[1]=a[1]%a[0];      //当右移动的位数大于数字的总个数时与右移一个小于总个数的右移数有相同效果 
	for(i1=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			b[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			b[i1-1]=(b[i1-1]*10)+ch-48;	    
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0,i2=a[0]-a[1];i2<a[0];i1++,i2++)
		zj[i1]=b[i2];
	for(i1=a[0]-a[1]-1,i2=a[0]-1;i1>=0;i1--,i2--)
		b[i2]=b[i1];
	for(i1=0;i1<a[1];i1++)
		b[i1]=zj[i1];
	for(i1=0;i1<a[0];i1++)
	{
		if(i1<a[0]-1)
			printf("%d ",b[i1]);
		else
			printf("%d",b[i1]);
	}
    printf("\n");
	return 0;
}

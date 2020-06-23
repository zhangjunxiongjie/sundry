#include <stdio.h>
int main ()
{
	int i,i1,i2,i3,i4,t;
	int a[10000],b[10000][2];
	char ch;
	scanf("%d\n",&i);
	for(i1=1,i2=1;(ch=getchar())!='\n';)
	{
		if(i2==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(i2!=1&&ch!=' ')
		{
			a[i1-1]=a[i1-1]*10+ch-48;
		}
		if(ch==' ')
			i2=1;
		else
			i2=0;
	}
	
	for(i1=1;i1<=i;i1++)
	{
		if(a[i1]>i1)
	    	a[i1]=a[i1]-i1;
		else
			a[i1]=i1-a[i1];
	}
	for(i1=0;i1<i;i1++)
		b[i1][1]=1;
	for(i1=1,i3=0;i1<=i;i1++)
	{
		if(a[i1]!=-1)
		{
			b[i3][0]=a[i1];
	    	for(i2=i1+1;i2<=i;i2++)
			{
		    	if(a[i1]==a[i2])
				{
				    b[i3][1]++;
			    	a[i2]=-1;
				}

			}
			i3++;
		}
	}
	for(i1=0;i1<i3;i1++)
		for(i2=i1+1;i2<i3;i2++)
			if(b[i1][0]<b[i2][0])
				for(i4=0;i4<2;i4++)
				{
					t=b[i1][i4];
					b[i1][i4]=b[i2][i4];
					b[i2][i4]=t;
				}
	for(i1=0;i1<i3;i1++)
	{
		if(b[i1][1]>1)
			printf("%d %d\n",b[i1][0],b[i1][1]);
	}
	return 0;
}



#include <stdio.h>
int main ()
{
	int i1,i2,h;
	int a[2],b[1000][2],ch;
	float c[1000],t;
	for(i1=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			a[i1-1]=a[i1-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else 
			h=0;
	}
	for(i1=0;i1<2;i1++)
	{
		for(i2=0;(ch=getchar())!='\n';)
		{
			if(h==1&&ch!=' ')
			{
				b[i2][i1]=ch-48;
				i2++;
			}
			else if(h==0&&ch!=' ')
				b[i2-1][i1]=b[i2-1][i1]*10+ch-48;
			if(ch==' ')
				h=1;
			else 
				h=0;
		}	
	}
	for(i1=0;i1<a[0];i1++)
		c[i1]=((float)(b[i1][1]))/((float)(b[i1][0]));
	for(t=0;a[1]!=0;)
	{
		for(h=0,i1=0;i1<a[0];i1++)
			if(c[h]<c[i1])
				h=i1;
		c[h]=0;
		if(a[1]<=b[h][0])
		{
			t=t+b[h][1]*a[1]/(float)(b[h][0]);
		    a[1]=0;
		}
		else 
		{
			t=t+b[h][1];
			a[1]=a[1]-b[h][0];
		}
	}
	printf("%.2f\n",t);
	return 0;
}

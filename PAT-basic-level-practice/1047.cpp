#include <stdio.h>
int main (void)
{
	int i1,i2,i3;
	int h,t;
	int b[1000][3];
	char ch;
	scanf("%d\n",&h);
	for(i1=0;i1<h;i1++)
	{
		for(i2=0,t=1;(ch=getchar())!='\n'&&i2<=3;)
		{
			if(t==1&&ch!=' '&&ch!='-')
			{
				b[i1][i2]=ch-48;
			//	printf("%d ",b[i1][i2]);
				i2++;
			}
			else if(t!=1&&ch!=' '&&ch!='-')
			{
				b[i1][i2-1]=(b[i1][i2-1]*10)+ch-48;
			//	printf("%d ",b[i1][i2-1]);
			}
			if(ch==' '||ch=='-')
			    t=1;
			else
				t=0;
		}
	}
/*	for(i1=0;i1<h;i1++)
	{
		for(i2=0;i2<3;i2++)
			printf("%d ",b[i1][i2]);
		printf("\n");
	}*/
	for(i1=0;i1<h;i1++)
	{
		if(b[i1][2]!=0)
		{
			for(i2=i1+1;i2<h;i2++)
			{
				if(b[i1][0]==b[i2][0])
				{
					b[i1][2]=b[i1][2]+b[i2][2];
					b[i2][2]=0;
				}
			}
		}
	}
/*	for(i1=0;i1<h;i1++)
	{
		for(i2=0;i2<3;i2++)
			printf("%d ",b[i1][i2]);
		printf("\n");
	}*/
	h=b[0][2];
	t=0;
	for(i1=0;i1<h;i1++)
		if(h<b[i1][2])
		{
			h=b[i1][2];
		    t=b[i1][0];
		}
	printf("%d %d\n",t,h);


return 0;
}

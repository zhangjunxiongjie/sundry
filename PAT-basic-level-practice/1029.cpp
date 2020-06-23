#include <stdio.h>
int main ()
{
	int i,i1,i2,h;
	char ch,a[2][80],b[2],c[80];
	for(i1=0;i1<2;i1++)
	{
		for(i2=0;(ch=getchar())!='\n';)
			if(ch!=' ')
			{
				if(ch<='z'&&ch>='a')
					a[i1][i2]=ch-32;
				else
					a[i1][i2]=ch;
				i2++;
			}
		b[i1]=i2;
	}
/*	for(i1=0;i1<b[0];i1++)
		printf("%c",a[0][i1]);
	printf("\n");
	for(i1=0;i1<b[1];i1++)
		printf("%c",a[1][i1]);
	printf("\n");*/
	for(i1=0,i=0;i1<b[0];i1++)
	{
		for(i2=0,h=0;i2<b[1];i2++)
		{
			if(a[0][i1]==a[1][i2])
			{
				h=1;
				break;
			}
		}
		if(h==0)
		{
			for(i2=0;i2<i;i2++)
				if(c[i2]==a[0][i1])
				{
					h=1;
					break;
				}
			if(h==0)
			{
				c[i]=a[0][i1];
				i++;
				printf("%c",a[0][i1]);
			}
		}
	}
	printf("\n");
	return 0;
}


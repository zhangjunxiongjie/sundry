#include <stdio.h>
int main()
{
	int i,h;
	char ch;
	int a[10000],b[10000][2];
	for(i=0;i<10000;i++)
		b[i][1]=0;
	scanf("%d\n",&a[0]);
	for(i=1,h=1;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&h==1)
		{
			a[i]=ch-48;
			i++;
		}
		else if(ch!=' '&&h==0)
			a[i-1]=a[i-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i=0,h=1;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&h==1)
		{
			b[i][0]=ch-48;
			i++;
		}
		else if(ch!=' '&&h==0)
			b[i-1][0]=b[i-1][0]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
/*	for(i=1;i<=a[0];i++)
		printf("%d ",a[i]);
	printf("\n");
	for(i=1;i<=b[0][0];i++)
		printf("%d ",b[i][0]);
	printf("\n");*/
	for(i=1;i<=b[0][0];i++)
	{
		for(h=1;h<=a[0];h++)
		{
			if(a[h]==b[i][0])
				b[i][1]++;
		}
	}
	for(i=1;i<=b[0][0];i++)
	{
		if(i==b[0][0])
			printf("%d\n",b[i][1]);
		else
			printf("%d ",b[i][1]);
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int i,max,h;
	char ch;
	int N=0,p=0,a[100000];
	for(h=0;(ch=getchar())!='\n';)
	{
		if(h==0&&ch!=' ')
			N=N*10+ch-48;
		else if(h==1&&ch!=' ')
			p=p*10+ch-48;
		if(ch==' ')
			h++;
	}
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
	for(i=0;i<N;i++)
		for(h=i+1;h<N;h++)
			if(a[i]>a[h])
			{
				max=a[i];
				a[i]=a[h];
				a[h]=max;
			}
	for(i=0,max=0;i<N/2;i++)
		for(h=N-1;h>i;h--)
			if(a[i]*p>=a[h]&&h-i+1>max)
				max=h-i+1;
	printf("%d\n",max);
	return 0;
}

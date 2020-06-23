#include <stdio.h>
int main()
{
	int pd(int* z);
	int i,t,h;
	char ch;
	int a[1001],b[1001];
	for(i=1000;(ch=getchar())!='\n';i--)
	{	
		a[i]=ch-48;
	}
	a[0]=i;
	b[0]=i;
	for(i=1;i<=a[0];i++)
	{
		a[i]=0;
		b[i]=0;
	}
	i=0;
	while(!pd(a)&&i<10)
	{
		for(t=1000;t>a[0];t--)
			printf("%d",a[t]);
		printf(" + ");
		for(t=a[0]+1;t<1001;t++)
			printf("%d",a[t]);
		printf(" = ");
		for(t=1000,h=a[0]+1;t>a[0];t--,h++)
			b[t]=a[t]+a[h];
		for(t=1000;t>a[0];t--)
			if(b[t]>=10)
			{
				b[t-1]++;
				b[t]=b[t]%10;
				if(t==b[0]+1)
					b[0]--;
			}
		for(t=b[0]+1,h=1000;t<1001;t++,h--)
		{
			printf("%d",b[t]);
			a[h]=b[t];
		}
		a[0]=b[0];
		printf("\n");
		i++;
	}
	if(pd(a))
	{
		for(t=b[0]+1,h=1000;t<1001;t++,h--)
			printf("%d",b[t]);
		printf(" is a palindromic number.\n");
	}
	else
		printf("Not found in 10 iterations.\n");
	return 0;
}

	int pd(int* z)
	{
		int i,t;
		for(i=z[0]+1,t=1000;i<1001;i++,t--)
		{
			if(z[i]!=z[t])
				return 0;
			if(i==t)
				break;
		}
		return 1;
	}

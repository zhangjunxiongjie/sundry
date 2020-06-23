#include <stdio.h>
int main ()
{
	int i1,h;
	long int a[3],i;
	char ch;
	for(h=1,i1=0;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' ')
			a[i1-1]=(a[i1-1]*10)+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	i=a[1]-a[0];
	h=i/100;
	if(i%100>=50)
		h=h+1;
	if(h>=60*60)
	{
		a[0]=h/3600;
		if(a[0]>9)
			printf("%ld:",a[0]);
		else
			printf("0%ld:",a[0]);
	}
	else
	{
		a[0]=0;
		printf("00:");
	}
	if(h>=60)
	{
		a[1]=(h-a[0]*3600)/60;
		if(a[1]>9)
			printf("%ld:",a[1]);
		else
			printf("0%ld:",a[1]);
	}
	else
	{	
		a[1]=0;
		printf("00:");
	}
	a[2]=h-a[0]*3600-a[1]*60;
	if(a[2]>9)
		printf("%ld\n",a[2]);
	else
		printf("%0ld\n",a[2]);
//	printf("%ld %ld\n",a[0],a[1]);
	return 0;
}

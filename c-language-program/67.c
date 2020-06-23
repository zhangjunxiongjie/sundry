#include <stdio.h>
int main ()
{
	int a[10]={10,25,42,32,15,72,45,96,34,12};
	int i=0,n=1,h;
	do
	{
		if(i==9)
		{
			i=0;
			n=0;
		}
		if(a[i]<a[i+1])
		{
			h=a[i];
			a[i]=a[i+1];
			a[i+1]=h;
			n=1;
		}
		i++;
	}
	while(i!=9||n!=0);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
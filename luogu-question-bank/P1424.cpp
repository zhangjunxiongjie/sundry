#include <stdio.h>
int main()
{
	int x,n;
	int num;
	scanf("%d%d",&x,&n);
	if(x<=5)
		num=(6-x)*250;
	else
		num=0;
	x=n-8+x; 
	if(x>=7)
	{
		num+=(x/7)*250*5;
		x=x-7*(x/7);
	}
	if(x<5)
		num+=x*250;	
	else
		num+=5*250;

	printf("%d\n",num);
	return 0;
}




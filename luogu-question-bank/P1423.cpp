#include <stdio.h>
int main()
{
	int i=0;
	float ty;
	double tr=0.0,tz=2.0;
	scanf("%f",&ty);
	while(tr<ty)
	{
		tr+=tz;
		tz=tz*0.98;
		i++;
	}
	printf("%d\n",i);
	return 0;
} 

//Fibonacci数列
#include <stdio.h>
int main ()
{
	int i,f1=1,f2=1,f3,t=1;
	int f;
	printf("%d",f1);
	for(i=2;i<=40;i++)          
	{   
		if(t%2==0)             //数列的排列方式
		{
			for(f=0;f<=1*t;f++)
				printf(" ");
			printf("%d",f2);
			t++;
		}
		else
			printf("   %d",f2),t++;
		if(t%2==0||i==25)
			printf("\n");
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	return 0;
}
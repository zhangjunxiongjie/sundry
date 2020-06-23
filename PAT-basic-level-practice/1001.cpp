#include <stdio.h>
int main ()
{
int de (int t,int f);
int i,f1=0;
scanf("%d",&i);
i=de(i,f1);
printf("%d\n",i);
return (0);
}

int de (int t,int f) 
{
	if(t!=1)
	{   
		f=f+1;
		if(t%2==0)
		{
          t=t/2;      
		}
	    else
		{
          t=(3*t+1)/2;
		}
		f=de(t,f);
	}
return (f);
}

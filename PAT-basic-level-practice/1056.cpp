/*给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。
要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。*/
#include <stdio.h>
int main ()
{
char c1;
int jh=0;
int c[30],i,i1,i2;
scanf("%d\n",&i);
for(i2=1,i1=0;(c1=getchar())!='\n'&&i1<i;)
	{
	   if(i2==1&&c1!=' ')
	   {
	    	c[i1]=c1-48;
		    i1++;
	   }
	   else if(i==0&&c1!=' ')
	   {
	        c[i1-1]=(c[i1-1]-48)*10+c1-48;
	   }
	   if(c1==' ')
		    i2=1;	
	   else
		    i2=0;
	}
for(i1=0;i1<i;i1++)
{
	for(i2=0;i2<i;i2++)
	{
		jh=jh+c[1]*10+c[i2];
	}
} 
for(i2=0;i2<i;i2++)
jh=jh-c[i2]*10-c[i2];
printf("%d\n",jh);
return 0;
}

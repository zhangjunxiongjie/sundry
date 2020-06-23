//划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。
//如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。
#include <stdio.h>
int main ()
{
int wj1=0,wj2=0;
int a[20][4];
int t;
char i;
int i1,i2,i3;
scanf("%d",&t);
for(i1=0;i1<t;i1++)
{
	for(i2=0,i3=1;(i=getchar())!='\n';)
	{
		if(i3==1&&i!=' ')
	    {
		   a[i1][i2]=i-48;
		   i2++;
     	}
	    else if(i3==0&&i!=' ')
	    {
		   a[i1][i2-1]=(a[i1][i2-1])*10+i-48;
		}
		if(i==' ')
		   i3=1;	
        else
		   i3=0;
	}
}
for(i1=0;i1<t;i1++)
{
   if(a[i1][0]+a[i1][2]==a[i1][1]||a[i1][0]+a[i1][2]==a[i1][3])
   {
      if(a[i1][1]==a[i1][3])
	     continue;
	  else if(a[i1][0]+a[i1][2]==a[i1][1])  
	     wj2++;
	  else if(a[i1][0]+a[i1][2]==a[i1][3])
	     wj1++;    	
   }
}
printf("%d %d\n",wj1,wj2);
return 0;
} 

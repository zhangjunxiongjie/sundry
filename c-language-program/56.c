#include <stdio.h>    //简单的分段函数
int main()
{
int hs(int x,int a);
int x,a,y;
scanf("%d",&x);
if(x<10)
a=2;
else
a=3;
y=hs(x,a);
if(x<0)
y=y-1;
if(x>=10)
y=y+1;
printf("%d\n",y);
}

int hs(int x,int a)
{
int z;
z=a*x;
return z;
}
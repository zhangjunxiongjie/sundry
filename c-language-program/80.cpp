//迭代法求解一个数的平方根 
#include <stdio.h>
#include <math.h>
int main ()
{
double x1,x2,a;
scanf("%lf",&a);
x1=a/2.0;
x2=(x1+a/x1)/2.0;
for(;fabs(x1-x2)>=1e-5;)
{
  x1=x2;
  x2=(x1+a/x1)/2.0;
  
}
printf("%2.1f 的平方根是：%8.6f",a,x1);
return 0;
} 

#include<stdio.h>//判断三数是否能组成三角形若能则计算三角形面积//
#include<math.h>
int main()
{
int a,b,c,t;
double S;
scanf("%d,%d,%d",&a,&b,&c);
if(a<b)
{
 t=a;
 a=b;
 b=t;
}
if(a<c)
{
 t=a;
 a=c;
 c=t;
}
if(b<c)
{
 t=b;
 b=c;
 c=t;
}
if(a+b>c&&a-b<c)
 if(a+c>b&&a-c<b)
  if(b+c>a&&b-c<a)
  {
  S=(a+b+c)/2;
  S=sqrt(S*(S-a)*(S-b)*(S-c));
  printf("%lf\n",S);
  }
  else printf("这三个数组成的三条边不能构成三角形\n"); //应用什么语句应该可以使一个语句实现三个else语句的效果//
 else printf("这三个数组成的三条边不能构成三角形\n");
else printf("这三个数组成的三条边不能构成三角形\n");
return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
double a,b,c,s,area;
a=3.67;
b=5.43;
c=6.21;
s=(a+b+c)/2;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("%f\n",area);
return 0;
}


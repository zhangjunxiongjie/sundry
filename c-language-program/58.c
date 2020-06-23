#include <stdio.h>     //根据三角形的三边判断三角形是什么三角形
main()
{
   int a,b,c;
   printf("请输入三角形的三边：");
   scanf("%d",&a);    //间断输入，先后输入确认键隔开
   scanf("%d",&b);
   scanf("%d",&c);
   if((a+b)>c&&(b+c)>a&&(a+c)>b)
   {
    printf("这三边可以组成三角形!\n");
    if (a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
    {
     printf("这是个直角三角形!\n");
    }
    if ((a==b)&&(b==c))
    {
     printf("这是个等边三角形!\n");
    }
    if (a==b||a==c||c==b)
    {
     printf("这是个等腰三角形!\n");
    }
   }
   else
    printf("这三条边无法组成三角形!\n");
}
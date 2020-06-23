#include<stdio.h>  //调用函数求平均值，和最大值；
int main()        //指针的偏移量需要整数（即指针必须和整数进行加减）
{
float max(float *a,float n);
float qpjs(float *b,float n);
float zdz,pjs,x,c[10];
int i;
printf("请输入数组中数值的个数:");
scanf("%f",&x);
printf("请输入%f个数：",x);
for(i=0;i<x;i++)
scanf ("%f",&c[i]);
zdz=max(c,x);
pjs=qpjs(c,x);
printf("%f,%f\n",zdz,pjs);
return 0;
}


float max(float *a,float n)  //求最大者//
{
float i;
int t;
i=*a;
for(t=1;t<n;t++)
if (i<*(a+t))
i=*(a+t);
return i;
}

float qpjs(float *b,float n)  //求平均数//
{
float sum=*b,t;
int i;
for(i=1;i<n;i++)
sum=sum+*(b+i);
t=sum/n;
return t;
}



#include <stdio.h>  //求十个数的平均数和其中最大的数//
main ()
{
int c[10],i=0,max;
float average=0.0;
printf("请输入十个数：");
for(;i<10;i++)
scanf("%d",&c[i]);   //在输入值的格式上，此语句并不能很好的连续输入初始值//
i=i-1;
for(;i>=0;i--)
average=average+c[i];
average=average/10.0;
i++;
max=c[i];
while(i<10)
{if(c[i]>max)
max=c[i];
i++;}
printf("%f,%d\n",average,max);
}


#include<stdio.h>  //调用函数求最大值和平均值（int整型格式）
int main()
{
int max(int a[],int n);
int qpjs(int b[],int n);
int zdz,n=10,i,pjs;
int c[10];
for(i=0;i<n;i++)
scanf ("%d",&c[i]);
zdz=max(c,n);
pjs=qpjs(c,n);
printf("%d,%d\n",zdz,pjs);
return 0;
}


int max(int a[],int n)//求最大者//
{
int i,t;
i=a[0];
for(t=1;t<n;t++)
if(i<a[t])
i=a[t];
return i;
}

int qpjs(int b[],int n)//求平均数,平均数是整数格式//
{
int i,sum=b[0];
for(i=1;i<n;i++)
sum=sum+b[i];
i=sum/n;
return i;
}

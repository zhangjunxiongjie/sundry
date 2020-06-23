#include <stdio.h>   //输入若干个数字并将所有数字前后倒置输出
int main()
{
void fun1(int *b,int c);
void fun2(int *b,int c);
int a[200],n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",a+i);
if(n%2==0)      //判断数值的单双，以区分倒置的方法
fun1(a,n);
else
fun2(a,n);
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
return 0;
}


void fun1(int *b,int c)   //两个调用函数分别对数组单双不同的一组数进行倒置
{
void fun(int *d,int *l);   //除主函数外其与函数可以相互之间进行调用
int t;                     //调用函数必须事先在函数内进行函数调用声明
for(t=0;t<(c/2);t++)       //而被调用函数必须进行定义
fun(b+t,b+c-t-1);
}

void fun2(int *b,int c)  
{
void fun(int *d,int *l);
int t;
for(t=0;t<(c-1)/2;t++)
fun(b+t,b+c-1-t);
}

void fun(int *d,int *l)  //进行对应位置的数值交换
{
int c;
c=*d;
*d=*l;
*l=c;
}




#include<stdio.h>//任意输入一个三位数得到三个数倒置（一种）//
int main ()
{
int a,b,c,t;
scanf ("%d",&a);
b=a%100;
c=a%10; 
t=(b-c)*0.1;
b=t;
a=(a-b)*0.01;
printf("%d,%d,%d\n",c,b,a);
return 0;
}


#include<stdio.h>//任意输入一个三位数得到三个数倒置（二种）//
int main ()
{
int a,b,c,t;
scanf ("%d",&a);
c=a/100;
b=(a-c*100)/10;
a=a-c*100-b*10;
printf("%d,%d,%d\n",a,b,c);
return 0;
}
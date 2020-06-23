#include<stdio.h> //计算数列2/1,3/2,5/3,8/5,13/8,21/13的前二十项之和//
int main()    //如何以分数结果输出//
{
float n,t,k,s,sum;  //以小数结果输出//
n=1.0;
k=2.0;
sum=0.0;
s=0.0;
for(;s<=20;s++)
{
sum=sum+k/n;
t=n+k;
n=k;
k=t;
}
printf ("%f\n",sum);
return 0;
}
#include<math.h> //程序计算三角形面积//
#include<stdio.h>
void main()
{
float a,b,c,s,area;
scanf ("%f,%f,%f",&a,&b,&c);
s=(a+b+c)*0.5;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("area=%f\n",area);
}


#include <stdio.h>  //给出三角形三边长用公式求出三角形面积
#include <math.h>   //函数库的调用的预处理
int main()
{
double a,b,c,s,area;    //定义变量类型，双精度
a=3.67;
b=5.43;
c=6.21;
s=(a+b+c)/2;
area=sqrt(s*(s-a)*(s-b)*(s-c));    //调用math函数库的sqrt（开二次根）函数
printf("a=%f\tb=%f\tc=%f\t",a,b,c);  //\t表示下一输出结果后移八个制表符，“两输出结果相隔六个制表符”
printf("area=%f\n",area);
return 0;
}

#include<stdio.h>   //自增与或并运算符的使用
void main()
{
int a=0,b=0,c=0;
if(++a>0||++b>0)
++c;
printf ("\na=%d,b=%d,c=%d\n",a,b,c);
}
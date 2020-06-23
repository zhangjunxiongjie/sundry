#include<stdio.h>
void main ()
{
int x=1,y=2,z,a,b,c,d;
z=++x||++y;//因为x=2而后面是或运算即可知z=1，后者（++y）未执行//
printf ("x=%d\n",x);
printf ("y=%d\n",y);
a=-1;b=-2;
c=++a&&b++;//与上述同理后者未执行//
printf("a=%d\n",a);
printf("b=%d\n",b);
x=-8;
y=0<=x<=10; //关系运算符自左至右，赋值运算符自右至左//
printf("y=%d\n",y);
}
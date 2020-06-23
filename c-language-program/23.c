#include<stdio.h>
void main ()
{
    int x=40,y=4,z=4;
    x=y==z; //‘y==z’语句的真假的逻辑值赋给x//
    printf("%d\n",x);
    x=x==(y=z);//'x==(y=z)'将z的值赋给y再判断x==y的真假将其逻辑值赋给x//
    printf("%d\n",x);
}
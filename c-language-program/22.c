#include<stdio.h>
void main ()
{
    int a=10,b=0;
    if(a==12)            //'=='表示等于'='表示赋值。简单的选择语句//
    {
        a=a+1;
        b=b+1;
    }
    else
    {
        a=a+4;
        b=b+4;
    }
    printf("%d,%d\n",a,b);
}

#include<stdio.h>
void main ()
{
    int a,b,max;
    b=3;
    a=b%2;   //b除以2取余数赋给a//
    max=(a>b)?b:a;//当括号内的条件成立时将冒号前者的值赋给max。选择语句//
    do    //两种循环语句，需要注意循环的语句范围和循环语句的条件有内镶嵌条件语句的意思，当条件成立循环继续否知退出循环//
    {
        ++a;
        max=max+a;}
    while(a<10);
    
    printf("%d,%d\n",a,max);
}

#include<stdio.h>
void main ()
{
    int a,b,max;
    b=3;
    a=b%2;   
    max=(a>b)?b:a;
    while(a<10)
    {
        ++a;
        max=max+a;
    }
    printf ("%d,%d\n",a,max);
}


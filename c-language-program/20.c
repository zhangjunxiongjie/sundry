
#include<stdio.h>
void main ()
{
    int x=10,y;//逗号运算符（顺序求值运算符）自左至右//
    y=5+(x++,x+8);       //括号内的语句按顺序（自左至右）执行//
    printf("%d，%d\n",x,y);
}
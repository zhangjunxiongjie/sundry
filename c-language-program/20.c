
#include<stdio.h>
void main ()
{
    int x=10,y;//�����������˳����ֵ���������������//
    y=5+(x++,x+8);       //�����ڵ���䰴˳���������ң�ִ��//
    printf("%d��%d\n",x,y);
}
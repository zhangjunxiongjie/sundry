#include<stdio.h>
void main ()
{
    int a=10,b=0;
    if(a==12)            //'=='��ʾ����'='��ʾ��ֵ���򵥵�ѡ�����//
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

#include<stdio.h>
void main ()
{
    int x=40,y=4,z=4;
    x=y==z; //��y==z��������ٵ��߼�ֵ����x//
    printf("%d\n",x);
    x=x==(y=z);//'x==(y=z)'��z��ֵ����y���ж�x==y����ٽ����߼�ֵ����x//
    printf("%d\n",x);
}
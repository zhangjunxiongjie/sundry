#include<stdio.h>
void main ()
{
    int a,b,max;
    b=3;
    a=b%2;   //b����2ȡ��������a//
    max=(a>b)?b:a;//�������ڵ���������ʱ��ð��ǰ�ߵ�ֵ����max��ѡ�����//
    do    //����ѭ����䣬��Ҫע��ѭ������䷶Χ��ѭ����������������Ƕ����������˼������������ѭ��������֪�˳�ѭ��//
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


#include<stdio.h>
void main ()
{
int x=1,y=2,z,a,b,c,d;
z=++x||++y;//��Ϊx=2�������ǻ����㼴��֪z=1�����ߣ�++y��δִ��//
printf ("x=%d\n",x);
printf ("y=%d\n",y);
a=-1;b=-2;
c=++a&&b++;//������ͬ�����δִ��//
printf("a=%d\n",a);
printf("b=%d\n",b);
x=-8;
y=0<=x<=10; //��ϵ������������ң���ֵ�������������//
printf("y=%d\n",y);
}
#include <stdio.h>   //�������ɸ����ֲ�����������ǰ�������
int main()
{
void fun1(int *b,int c);
void fun2(int *b,int c);
int a[200],n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",a+i);
if(n%2==0)      //�ж���ֵ�ĵ�˫�������ֵ��õķ���
fun1(a,n);
else
fun2(a,n);
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
return 0;
}


void fun1(int *b,int c)   //�������ú����ֱ�����鵥˫��ͬ��һ�������е���
{
void fun(int *d,int *l);   //�������������뺯�������໥֮����е���
int t;                     //���ú������������ں����ڽ��к�����������
for(t=0;t<(c/2);t++)       //�������ú���������ж���
fun(b+t,b+c-t-1);
}

void fun2(int *b,int c)  
{
void fun(int *d,int *l);
int t;
for(t=0;t<(c-1)/2;t++)
fun(b+t,b+c-1-t);
}

void fun(int *d,int *l)  //���ж�Ӧλ�õ���ֵ����
{
int c;
c=*d;
*d=*l;
*l=c;
}




#include<stdio.h>//��������һ����λ���õ����������ã�һ�֣�//
int main ()
{
int a,b,c,t;
scanf ("%d",&a);
b=a%100;
c=a%10; 
t=(b-c)*0.1;
b=t;
a=(a-b)*0.01;
printf("%d,%d,%d\n",c,b,a);
return 0;
}


#include<stdio.h>//��������һ����λ���õ����������ã����֣�//
int main ()
{
int a,b,c,t;
scanf ("%d",&a);
c=a/100;
b=(a-c*100)/10;
a=a-c*100-b*10;
printf("%d,%d,%d\n",a,b,c);
return 0;
}
#include<stdio.h>  //���ú�����ƽ��ֵ�������ֵ��
int main()        //ָ���ƫ������Ҫ��������ָ�������������мӼ���
{
float max(float *a,float n);
float qpjs(float *b,float n);
float zdz,pjs,x,c[10];
int i;
printf("��������������ֵ�ĸ���:");
scanf("%f",&x);
printf("������%f������",x);
for(i=0;i<x;i++)
scanf ("%f",&c[i]);
zdz=max(c,x);
pjs=qpjs(c,x);
printf("%f,%f\n",zdz,pjs);
return 0;
}


float max(float *a,float n)  //�������//
{
float i;
int t;
i=*a;
for(t=1;t<n;t++)
if (i<*(a+t))
i=*(a+t);
return i;
}

float qpjs(float *b,float n)  //��ƽ����//
{
float sum=*b,t;
int i;
for(i=1;i<n;i++)
sum=sum+*(b+i);
t=sum/n;
return t;
}



#include <stdio.h>  //��ʮ������ƽ����������������//
main ()
{
int c[10],i=0,max;
float average=0.0;
printf("������ʮ������");
for(;i<10;i++)
scanf("%d",&c[i]);   //������ֵ�ĸ�ʽ�ϣ�����䲢���ܺܺõ����������ʼֵ//
i=i-1;
for(;i>=0;i--)
average=average+c[i];
average=average/10.0;
i++;
max=c[i];
while(i<10)
{if(c[i]>max)
max=c[i];
i++;}
printf("%f,%d\n",average,max);
}


#include<stdio.h>  //���ú��������ֵ��ƽ��ֵ��int���͸�ʽ��
int main()
{
int max(int a[],int n);
int qpjs(int b[],int n);
int zdz,n=10,i,pjs;
int c[10];
for(i=0;i<n;i++)
scanf ("%d",&c[i]);
zdz=max(c,n);
pjs=qpjs(c,n);
printf("%d,%d\n",zdz,pjs);
return 0;
}


int max(int a[],int n)//�������//
{
int i,t;
i=a[0];
for(t=1;t<n;t++)
if(i<a[t])
i=a[t];
return i;
}

int qpjs(int b[],int n)//��ƽ����,ƽ������������ʽ//
{
int i,sum=b[0];
for(i=1;i<n;i++)
sum=sum+b[i];
i=sum/n;
return i;
}

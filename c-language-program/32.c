#include<math.h> //����������������//
#include<stdio.h>
void main()
{
float a,b,c,s,area;
scanf ("%f,%f,%f",&a,&b,&c);
s=(a+b+c)*0.5;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("area=%f\n",area);
}


#include <stdio.h>  //�������������߳��ù�ʽ������������
#include <math.h>   //������ĵ��õ�Ԥ����
int main()
{
double a,b,c,s,area;    //����������ͣ�˫����
a=3.67;
b=5.43;
c=6.21;
s=(a+b+c)/2;
area=sqrt(s*(s-a)*(s-b)*(s-c));    //����math�������sqrt�������θ�������
printf("a=%f\tb=%f\tc=%f\t",a,b,c);  //\t��ʾ��һ���������ư˸��Ʊ����������������������Ʊ����
printf("area=%f\n",area);
return 0;
}

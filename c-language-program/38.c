#include<stdio.h>//�ж������Ƿ������������������������������//
#include<math.h>
int main()
{
int a,b,c,t;
double S;
scanf("%d,%d,%d",&a,&b,&c);
if(a<b)
{
 t=a;
 a=b;
 b=t;
}
if(a<c)
{
 t=a;
 a=c;
 c=t;
}
if(b<c)
{
 t=b;
 b=c;
 c=t;
}
if(a+b>c&&a-b<c)
 if(a+c>b&&a-c<b)
  if(b+c>a&&b-c<a)
  {
  S=(a+b+c)/2;
  S=sqrt(S*(S-a)*(S-b)*(S-c));
  printf("%lf\n",S);
  }
  else printf("����������ɵ������߲��ܹ���������\n"); //Ӧ��ʲô���Ӧ�ÿ���ʹһ�����ʵ������else����Ч��//
 else printf("����������ɵ������߲��ܹ���������\n");
else printf("����������ɵ������߲��ܹ���������\n");
return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
double a,b,c,s,area;
a=3.67;
b=5.43;
c=6.21;
s=(a+b+c)/2;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("%f\n",area);
return 0;
}


#include <stdio.h>     //���������ε������ж���������ʲô������
main()
{
   int a,b,c;
   printf("�����������ε����ߣ�");
   scanf("%d",&a);    //������룬�Ⱥ�����ȷ�ϼ�����
   scanf("%d",&b);
   scanf("%d",&c);
   if((a+b)>c&&(b+c)>a&&(a+c)>b)
   {
    printf("�����߿������������!\n");
    if (a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
    {
     printf("���Ǹ�ֱ��������!\n");
    }
    if ((a==b)&&(b==c))
    {
     printf("���Ǹ��ȱ�������!\n");
    }
    if (a==b||a==c||c==b)
    {
     printf("���Ǹ�����������!\n");
    }
   }
   else
    printf("���������޷����������!\n");
}
//�����������ֵ�ƽ������������-1ʱ��������
#include <stdio.h>
int main ()
{
int sum=0,count=0,number=0;
while(number!=-1)            //�ж�����������Ƿ���-1
{
  sum+=number;
  count++;                   //�����������ֵĸ���
  scanf("%d",&number);      //ѭ���ڵ��������
}
sum=sum/(count-1);
printf("%d\n",sum);
return 0;
}
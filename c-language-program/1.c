//�ж�ĳһ���Ƿ�Ϊ����

#include <stdio.h>
#include <stdbool.h>  //ʹ���߼�������leap�����߼�������ture��false����Ԥ�������

int main ()
{
	int year;
	bool leap;  //�����߼�����
	scanf ("%d",&year);    //�������
	if(year%4==0)
	{
		if(year%100==0)
		{ 
			if(year%400==0)
			leap=true;    //�߼�������1��
			else
			leap=false;   //�߼�������0��
		}
		else
			leap=true;
	}
	else
	leap=false;
	if(leap=true)
	   printf("%d is not ",year);
	else
	   printf("%d is ",year);
	printf("a leap year.\n");
	return 0;
}

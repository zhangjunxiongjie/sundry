// ���Բ���һ��������������¡� 

#include <stdio.h>
#include <stdlib.h>                  // δ֪ͷ�ļ� 
#include <time.h>

int main ()
{
    srand(time(0));                    // ����������ĸ�ӹ��� 
    int number= rand()%100;            // �������������� 
    int count=0,a=0;
    printf("���Ѿ������һ��һ�����ڵ�������\n");
	do
	{
	  printf("������һ��һ�����ڵ�������");
	  scanf("%d",&a);
	  count++;
	  if(a>number)
	    printf("�������������,");
	  else
	    if(a<number) 
	      printf("���������С��,");
	}
	while(a!=number);
	printf("��ϲ�㣬�¶��ˡ�");
	printf("���ܼƲ���%d�Ρ�",count);
	return 0; 
}

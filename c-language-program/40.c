//��������˷���
//�Ҷ���
#include <stdio.h>
int main ()
{
int i,t;
i=1;
while(i<=9)
{
	for(t=1;t<=i;t++)
	{
		printf("%d*%d=%d",t,i,t*i);
		if(t==i)           //�ж��Ƿ񵽾�ĩ
		{
			printf("\n");  
		}
		else
        {
			if((t*i)/10!=0)           //��û�е���ĩʱ���ǰ����Ϊ��λ��ʱ���һ���ո�
			{
				printf(" ");
			}
			else
			{
				printf("  ");          
			}
		}
	}
	i++;
}
return 0;
}
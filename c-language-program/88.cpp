#include <stdio.h>
#include <windows.h>
int main()
{
	int a;
	while(1)
	{
		a =	GetKeyState(VK_SHIFT);//��ȡĳ��״̬ 
		if( a < 0 )		//���ĳ�������� 
		{
			printf("%d",a);	
		}
	}
 	return 0;
} 

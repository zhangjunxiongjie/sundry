//ʹ�üӷ�ʵ�ֳ˷���(ֻ�����㷨ʵ��)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int multiplier1, multiplier2;
	int result = 0;  
	int temporary_multiple;   //��ʱ����
	int temporary_multiplier; //��ʱ����

	printf_s("��������������:");
	scanf_s("%d %d", &multiplier1, &multiplier2);

	temporary_multiple = 1;
	temporary_multiplier = multiplier1;

	while (true)
	{
		if (multiplier2 >= temporary_multiple)
		{
			multiplier2 -= temporary_multiple;
			result += temporary_multiplier;
		}
		else if (temporary_multiple != 1)
		{
			temporary_multiple = 1;
			temporary_multiplier = multiplier1;
		}
		else
		{
			break;
		}

		if (temporary_multiple + temporary_multiple <= multiplier2)
		{
			temporary_multiple += temporary_multiple;
			temporary_multiplier += temporary_multiplier;
		}
	}

	printf_s("�˷����Ϊ:%d\n", result);

	system("Pause");   //����DOS������ͣ����

	return 0;
}


//���ڲ������۵�������
// ��36����Ч�������� 

#include <iostream> //�����������ԾŸ�3*3�����С�������9*9����Ĵ����

int main()
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf_s("%d:%d ", i % 3 * 3 + j / 3, j % 3 + i / 3 * 3);
		}
		printf_s("\n");
	}

	system("Pause"); //pause��ͣ
	return 0;
}
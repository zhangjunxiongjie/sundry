// �������������ʵ�ֺ���ʽʮ�������㷨��
//ʵ��ð������


#include <iostream>
#include <time.h>

#define NUM 10
#define MAX 100

void Random_initial(int* object) //��������������ʼ��
{
	srand((unsigned)time(NULL)); //��ʼ�����������

	for (int number = 0; number < NUM; number++)
	{
		object[number] = rand() % MAX;
	}
}

void Printf_list(int* result)//��ʽ���������
{
	for (int number = 0; number < NUM; number++)
	{
		printf("%d", result[number]);
		if (number % 10 + 1 == 0)
			printf("\n");
		else
		{
			printf(":");
		}
	}
	printf("\n");
}

void Bubbling_initial(int* target)//ԭʼ��ð������
{
	int number,count,middle;
	for (count = 0; count < NUM; count++)
	{
		for (number = 0; number < NUM - count - 1; number++)//ÿ���һ����ѭ������β����һ�����ŵ�����ȷ��λ��
		{
			if (target[number] > target[number + 1])
			{
				middle = target[number];
				target[number] = target[number + 1];
				target[number + 1] = middle;
			}
		}
	}

}


int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Bubbling_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}

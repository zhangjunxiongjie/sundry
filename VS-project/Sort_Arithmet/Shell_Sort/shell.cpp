//ʵ��ϣ������
//ϣ������Ҳ��һ�ֲ����������Ǽ򵥲������򾭹��Ľ�֮���һ������Ч�İ汾��Ҳ��Ϊ��С��������

#include <iostream>
#include <time.h>

#define NUM 15
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

void Shell_initial(int* target)//ԭʼ��ϣ������
{
	int gap = NUM / 2; // �״�����
	while (gap > 0)
	{
		for (int group = 0; group < gap; group++) // ��Ҫ���в�������ķ���ѭ�����˴���ÿ�������ڿ���ѡ�����˵����򷽷�����һ��Ҫʹ�ò�������
		{
			for (int member = group + gap; member < NUM; member+=gap) // ��������ʹ�ò��������㷨��
			{
				int inster_value = target[member];
				int inster_site = member; // ����ѭ����֤�˳�����inster_siteֵ���ǲ���λ�á�
				while (inster_site >= gap && target[inster_site - gap] > inster_value) // Ѱ�Ҳ���λ��instersite��
				{
					target[inster_site] = target[inster_site - gap];
					inster_site -= gap;
				}
				target[inster_site] = inster_value;
			}
		}
		gap = gap / 2; // ��С��࣬����ÿ��ĳ�Ա������
	}
}


int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Shell_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



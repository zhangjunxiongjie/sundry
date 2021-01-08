// �ǵݹ�ʵ�ֹ鲢����

#include <iostream>
#include <time.h>

#define NUM 20
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

void Assistant_Merge(int* target, int left0, int right0, int left1, int right1) // �����鲢������������Ԫ�ز�������Ԫ�ء�
{
	// �ϲ㱣֤��ǰһ����������ߣ���һ���������ұߣ���������������š�
	int left = left0; // ������㣨����Ҫ�����յ㣬��Ϊ��������ĺϲ����߼��ϵ����ŵ�λ�ò��ı��Ұ��š�����
 	
	int assis[NUM]; // �������顣 
	int cursor = 0; // ��������ָ�롣
	while (left0 < right0 && left1 < right1) // ��ĳһ��Ԫ�ص���߽�ʱ���˳���
	{
		if (target[left0] <= target[left1]) // ���ڷ����Ᵽ֤�����Ԫ�ص����λ�ò���ı䡣
		{
			assis[cursor++] = target[left0++];
		}
		else
		{
			assis[cursor++] = target[left1++];
		}
	}
	if (left0 < right0) // ��֤�鲢�ܹ�ȫ����ɡ�
	{
		while (left0 < right0)
		{
			assis[cursor++] = target[left0++];
		}
	}
	else
	{
		while (left1 < right1)
		{
			assis[cursor++] = target[left1++];
		}
	}

	for (int i = 0; i < cursor; i++) // �Ż�ԭ����
	{
		target[left++] = assis[i];
	}
}
void Merge_initial(int* target)//ԭʼ�Ĺ鲢����
{
	int gap = 1; // �鲢������Ԫ�ظ�����
	while (gap < NUM) // 
	{
		int i = 0;
		while (i + gap + gap <= NUM)
		{
			Assistant_Merge(target, i, i + gap, i + gap, i + gap + gap);

			i = i + gap + gap;
		}
		if (i + gap < NUM) // ��ʱ˵�����һ�鲻������Ҫ���⴦������ǵ����ڶ��鲻�����ùܡ�
		{
			Assistant_Merge(target, i, i + gap, i + gap, NUM);
		}

		gap *= 2; // ÿ�ν��ϲ����Ԫ�ظ�������������
	}

}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Merge_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



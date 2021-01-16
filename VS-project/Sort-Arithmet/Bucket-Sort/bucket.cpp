/*
Ͱ�����ǶԼ�������ĸĽ���������������Ķ���ռ��ȴ���СԪ��ֵ�����Ԫ��ֵ���������򼯺���Ԫ�ز������ε����ģ���ɢ�ֲ�����
���Ȼ�пռ��˷������Ͱ�������������������˷����������Сֵ�����ֵ֮���ÿһ��λ������ռ䣬
����Ϊ��Сֵ�����ֵ֮��ÿһ���̶���������ռ䣬����������Ԫ��ֵ��С����������µĿռ��˷������

����ֵͨ��ӳ�亯���õ�Ͱ�±ꡣȻ�����Ͱ�С�

����Ͱ����Ĳ��ԣ���ӳ�亯�����Ƚϼ򵥽���ֵ����ֱ����ΪͰ������Ȼ�������֤������ֵ�����һ��Ͱ�ڡ�

Ͱ����Ĳ��Կ��Խ�һ�������Ż�����ʹ��ֵ�����ܵľ��ȷֲ���ÿһ��Ͱ�ڣ��Լ�С��һ������ĸ�����
*/

#include <iostream>
#include <vector>
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


void Bucket_initial(int* target)//ԭʼ��Ͱ���򣨲����Ǹ�����
{
	int divisor = MAX / (NUM - 1); // ʹ�����ֵ����������ʹ���ֵ�����һ������Ͱ�ڡ�

	// ��ʼ��Ͱ��
	std::vector<int> bucket[NUM] = { {} }; // bucket_number = NUM; ��ֵ��������ΪͰ��������
	for (int i = 0; i < NUM; i++) // װ��Ͱ�ڡ�
	{
		// target[count] / divisor ȷ������Ͱ��λ�á�С����ǰ���Ͱ�ڣ������ں����Ͱ�ڡ�
		bucket[target[i] / divisor].push_back(target[i]);
	}

	// ���װ��Ͱ�ں�ÿ��Ͱ�������ֵ���������ǿ���ֱ��ʹ�ñȽ��������������򡣷���Ҳ����ʹ�õݹ�ķ�������������Ͱ����
	for (int i = 0; i < NUM; i++) 
	{
		if (bucket[i].size() > 1)
		{
			for (int j = 0; j < bucket[i].size(); j++) // �����ǰͰ����ֵ��������1���������
			{
				int min = j;
				for (int z = j + 1; z < bucket[i].size(); z++) // �ҳ�δ������������С����һ����ֵ��
				{
					if (bucket[i].at(min) > bucket[i].at(z))
					{
						min = z;
					}
				}
				// ��ֵ������
				int middle = bucket[i].at(min);
				bucket[i].at(min) = bucket[i].at(j);
				bucket[i].at(j) = middle;
			
			}
		}
	}

	int number = 0;
	for (int i = 0; i < NUM; i++) // ��Ͱ�е���ֵ��������С�
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			target[number++] = bucket[i].at(j);
		}
	}
}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Bucket_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}



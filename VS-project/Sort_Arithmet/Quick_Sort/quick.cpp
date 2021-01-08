//�ǵݹ�ʵ�ֿ�������ʹ�ö��б�����Ҫ���������䣩
//��������Quicksort���Ƕ�ð�������һ�ָĽ���

#include <iostream>
#include <time.h>
#include <queue> // ʹ�ö��м�¼��׼Ԫ�ص�λ�á�

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

// ���ػ�׼Ԫ�ص�λ�á�
int Assistant_Quick(int* target, int left, int right)
{
	int i = left, j = right - 1; // ����ͷ�ֱ�ʼ�Ŵ��ں�С�ڻ�׼Ԫ�ص�����󲻰��ҡ�
	int pivot = target[left]; // ��׼���׼���ѡȡ���Ծ������㷨��Ч��
	while (i < j) // �����ں�С�ڻ�׼Ԫ�ص���ֿ����ڻ�׼Ԫ�ص���ͷ��
	{
		while (i < j && target[j] >= pivot) j--; // �ҳ�С�ڻ�׼Ԫ�ص������Ǵ��ڵ��ڵĻ������ѭ��������������ŵ�ǰ�档
		if (i < j)
		{
			int middle = target[i];
			target[i] = target[j];
			target[j] = middle;
		}

		while (i < j && target[i] <= pivot) i++; // �ҳ����ڻ�׼Ԫ�ص���
		if (i < j)
		{
			int middle = target[i];
			target[i] = target[j];
			target[j] = middle;
		}
	}
	
	return i; // ����ѭ�����ʽi==jӦ���ǳ�������i��λ��Ӧ�þ���pivot��λ�á�
}
void Quick_initial(int* target)//ԭʼ�Ŀ�������
{
	typedef struct border
	{
		int left;
		int right;
	}Border; // �߽�ṹ�塣

	std::queue<Border> pivot_list; // ��ŷ������׼Ԫ�ص�λ�á�
	
	pivot_list.push({ 0, NUM }); // 
	while (!pivot_list.empty()) // 
	{
		int left = pivot_list.front().left; // ȡ����Ҫ���з��������䡣
		int right = pivot_list.front().right;
		pivot_list.pop();

		int pivot = Assistant_Quick(target, left, right); // ���з��������ػ�׼Ԫ�ص�λ�á�
		
		if (pivot - left >= 2) // ����Ҫ��������Ԫ�ط����û���ٽ��з����ı�Ҫ��
		{
			pivot_list.push({left, pivot}); // ��߽�������ұ߽粻������ 
		}
		if (right - (pivot + 1) >= 2) // ����Ҫ��������Ԫ�ط����û���ٽ��з����ı�Ҫ��
		{
			pivot_list.push({pivot + 1, right}); // pivot�ǻ�׼Ԫ�ص�λ�ã��Ѿ��ƶ�����ȷλ����������������
		}
	}
}

int main()
{
	int target[NUM];

	Random_initial(target);

	Printf_list(target);

	Quick_initial(target);

	Printf_list(target);

	system("Pause");

	return 0;
}




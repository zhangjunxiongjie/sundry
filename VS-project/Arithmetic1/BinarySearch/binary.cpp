//�����Ŀ���ڽ���һ��Ӧ�ö��ֲ��ҵ���Ŀ��
//�������������У���Ϊ���������ô�޿ɱ����ʹ�ö��ֲ��Ҿ���һ��������ѡ��
//������������������飬�ڼ�������ֵʱʹ�ö��ֲ��ң�����ʵ�ֶ��ֲ����㷨�����Ҳ���λ�á�
//���������������������Ȼ���Զ���ո���߻��н������롣

//ʵ���˶�����ֵ�����㷨��˳����ң��������ң����ֲ��ң���


//ʼ�ն��������뼸����֮��Ͳ�������������⣿����Ϊʲô��ô���£�����
//������ڶ��ֲ��ҷ��ز��������ǣ�����
//�����ѽ���Ƕ��ֲ����ǿ��ܵ�����Ƚ϶��м������û���뵽��

//ʵ�������������ú�����һ�����ڲ��Ҳ���λ�ã���һ�����ڽ�������ֵ�������ƣ�һ����������������С�
//����һ�����뺯��



#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct //����һ�����뺯�����صĽṹ��
{
	bool execute = false;
	int temporary_get;
}Returned;


Returned scanf_r()
{
	Returned result;
	char temporary_char;
	int sign = 0, temporary_result = 0;

	//bool flag = false;
	//��������ݴ��Ǿ�Ҫ���ӵö��ˣ����ﲻ�����ݴ����ּ�ֵ��һ���ո���߻���
	for (int i = 0; ((temporary_char = getchar()) >= '0' && temporary_char <= '9') || temporary_char == '-'; i++) //�ݴ��Խϲ����������֮��ֻ����һ���ո����һ�����з�
	{
		result.execute = true;//���û�н������ѭ���ͽ�����������뺯����ֱ���ж�Ϊ����ʧ�ܡ�
		//temporary_str[i] = temporary_char;
		if (temporary_char == '-')
			sign = 1;
		else
		{
			temporary_result = temporary_result * 10 + temporary_char - 48;
		}
	} 

	if (sign)
		result.temporary_get = 0 - temporary_result;
	else
		result.temporary_get = temporary_result;

	return result;
}


//ֱ����ֵ��targetС����ֵ��target��������ֵ��һ�������ҵ���ֵͬʱ��
int dichotomy_find(const int* it, const int target)//����������ڷ��ز���λ��
{
	int result;
	int left = 1, right = it[0] - 2; //���һ�����Ǵ��������
	bool flag = true;

	if (it[right] <= target) //���¼����������������������߱���С��С����ֻ��һ�����ǵ��������������
	{
		result = right + 1;
		flag = false;
	}
	else if(it[left] >= target)
	{
		result = left;
		flag = false;
	}
	else if (it[0] == 3)
	{
		result = right + 1;
		flag = false;
	}

	while (flag)  //����ʹ�õĶ��ֲ�������ܶ࣡����
	{
		int middle = (left + right) / 2;
	
		if (it[middle] >= target)  
		{
			right = middle;
		}
		else if(it[middle] < target)
		{
			left = middle;
		}

		if (it[left] == target || it[right] == target)
		{
			if (it[left] == target)
				result = left;
			else
				result = right;
			break;
		}
		else if (right - left == 1 && it[left] < target && it[right] > target)
		{
			result = right;
			break;
		}
		
	}

	return result;
}


//�η����ң��ȴӵ�һ��λ�ÿ�ʼ�Ƚ�Ȼ�����λ���Դη������������ӣ��뿴��ϸʵ�֡�
int power_find(const int* it, const int target)//���뽨��������Ͳ������ֵ�����ز����λ�á�
{//��Ҫע����������һ��Ԫ���������С������ǰ�����и��������һ��Ԫ����Ҫ�������ֵ��ʵ��������Ĵ����������ʡ�Բ�����ֵ
	int result;
	int series = 1;//head�仯�ļ�������ָ����������
	int head = 1, tail = 1;  //������ʵ�����и����Ż����㷨�����ݲ�����ֵ��ͷβ��ֵ��С�ıȽϾ����Ǵ�ͷ��ʼ���һ��Ǵ�β��ʼ���ҡ����ﲻ�پ���ʵ��
	//��Ϊ��ʹ���ƺ������Ӹ�Ч������������ͬ����ֵʱ���²������ֵ����ں���
	
	if (target < it[1])
	{
		return 1;
	}

	while (true)
	{
		if (target >= it[tail])
		{
			if (target == it[tail] && (tail + 1 > it[0] - 2 || target < it[tail + 1]))
			{
				result = tail + 1;
				break;
			}
			else if (target == it[tail])
			{
				continue;    //�˳���ǰѭ��ʹseriesΪ1ʹ��tail����һ��
			}
			else if(target < it[tail + 1])
			{
				result = tail + 1;
				break;
			}

			head = tail;
		}

		if (head == tail && head + series * 2 <= it[0] - 2)
		{
			series *= 2;
			//printf("$%d$", series);
		}
		else if(head + 1 <= it[0] - 2)
			series = 1;
		else
		{
			result = head + 1;
			break;
		}
		
		tail = series + head;
	}

	return result;
}

int order_find(const int* it, const int target)  //˳�����
{
	int result;
	if (target < it[1])
		return 1;
	for (int i = 1; i <= it[0] - 2; i++)
	{
		if (i + 1 > it[0] - 2 || target < it[i + 1])
		{
			result = i + 1;
			break;
		}
	}
	return result;
}

//�Ӳ���λ�ÿ�ʼ����
int retrude(int* it, const int location)  //��locationλ�ú����������ֵ������ƣ�����ֵ��ʾִ��״̬�������-1���ɹ���1������ԭ�򣿣�
{
	if (it[0] == 100) //���
		return -1;
	for (int i = it[0]; i > 0 && i > location; i--)
	{
		it[i] = it[i - 1];
	}

	return 1;
}

void print(const int* it)//��������������С�
{
	for (int i = 1; i < it[0]; i++)
	{
		printf_s("%d:", it[i]);
		if (i % 10 == 0)
			printf("\n");
	}
	printf("\n");
}

int main()
{
	int Object[100];   //���������һ����ֵ��
	int input, count;
	for (count = 1; count < 100; count++)
	{
		/*
		scanf_s("%d", &temporary_get);
		if (temporary_get == 123)
			break;
		*///���Ϊ�˼���ֱ��ʹ��scanf_s�������룬����ʹ�ù����з��ֻ�����Щ���⣬�������������뼸������Ͳ��������ˣ����������δ�õ������
		//����Ϊ�˹�������������ֱ��ʹ���ַ����ת������ֵ���ں�����ʵ�֣�
		
		Returned temporary = scanf_r();//���λس������κβ��淶�����붼���������������
		if (temporary.execute)
			input = temporary.temporary_get;
		else
			break;

		Object[count] = input;
		
		Object[0] = count + 1;  //���������һ��λ�����ڴ洢���ȡ�
		
		if (count != 1)
		{
			//int location = dichotomy_find(Object, input);  ���ֲ���
			//int location = power_find(Object, input);   //��������
			int location = order_find(Object, input);   //˳�����

			if (retrude(Object, location) != 1)
			{
				printf_s("�쳣�˳�������");
				print(Object);
				return 0;
			}
			else
			{
				Object[location] = input;
			}
			/*
			print(Object);
			printf("#%d\n", location);
			*/
		}
		//print(Object);
	}
	print( Object );
	system("Pause");   //����DOS������ͣ����

	return 0;
}






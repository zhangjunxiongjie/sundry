/*ʹ���������ַ�ʽ��ʾ��������
	  _____4_____
	 |           |
   __5__       __8__
  |	    |     |     |
 _1_   _3_   _2_   _9_
|   | |   | |   | |   |
1   2 3   4 5   6 7   8

*/
/*
�д��Ż���
����������Σ������⻹�࣬��ӡ�ո���Ե����ó�������һ��ģ�顣
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 30
int tree[N] = { 8,1,3,2,6,8,8,1,3,2,6,8,1,3,2,5,0,2,1,6,8,1,3,2,6,8,8,1,3,2 };
int Coun = 0;   //������
int Conu;   //���һ���Ԫ��������


struct MyStruct
{
	int tail = 0;
	int list[N*2][2];   //һ�������洢ÿ�����ֵ��±꣬һ�������洢������Χ�����ַ��ĸ���
	int hear = 0;
}Box;  //�洢ÿ�������ַ���λ����Ϣ����Ӧ��ķ����ַ�λ����Ϣ�����ɱ���������ַ�λ�õõ���


void Calcul()   //ʹ��N��������ļ���
{
	int Nr = 1;  //�洢Coun������Ӧ���ܵ����ָ���
	while (Nr < N + 1)
	{
		Nr *= 2;
		Coun++;
	}
	Conu = Nr / 2;
}

void printfr(int tr, int ty)   //���ڴ�ӡ����ÿ�е�'_'��������ʼλ�ü����Ÿ�����
{
	int i;
	printf("\r");//��Ϊ�ǴӺ���ǰ�������ÿ�����ʱ��Ҫ��ÿ�е���ʼλ�ÿ�ʼ�����
	for (i = 0; i < tr; i++)
		printf(" ");
	for (i = 0; i < ty; i++)
		printf("_");
}

void printfd()//���ڴ�ӡ��|����������
{
	int Tr = Box.hear,Ty=Box.tail;
	int i;
	for (; Tr < Ty; Tr++)
	{
		printf("\r");
		for (i = 0; i < Box.list[Tr][0]; i++)
			printf(" ");
		printf("|");
	}
}



int main()
{
	int Ntt = 0;   //��ǰ����
	int Ji = 1;  //ÿ�����ָ���
	int Hi;     //Ntt���Ӧ��������ָ���
	int i = 0, j;
	Calcul();
	Box.list[Box.tail][0] = (Conu / 2 * 5 + Conu / 2 - 2) / 2;   //��һ����ַ�λ�á�
	Box.list[Box.tail][1] = (Box.list[Box.tail][0] - 1) / 2;
	Box.tail++;
	while(Ntt < Coun)  //����
	{
		Hi = int(pow(2.0, Ntt));
		for (i = Ji - 1; i >= Ji - Hi; i--)   //ÿ�������ָ���
		{
			if (N > (i + 1) * 2)   //�����ǰ������ֵ���������������������
			{
				printfr(Box.list[Box.hear][0] + 1, Box.list[Box.hear][1]);
				Box.list[Box.tail][0] = Box.list[Box.hear][0] + Box.list[Box.hear][1] + 1;
				if (0 == (Box.list[Box.hear][1] - 1) / 2)
					Box.list[Box.tail][1] = 1;
				else
					Box.list[Box.tail][1] = (Box.list[Box.hear][1] - 1) / 2;
			
				Box.tail++;
			}
	
			//Sleep(300);
			if (N > i)   //�����ǰ��������ֲ�Ϊ�ռ�����
			{
				printf("\r");
				for (j = 0; j < Box.list[Box.hear][0]; j++)    //�������Ű�����ո�Ĳ����������Ϊһ��ģ��
					printf(" ");
				Box.hear++;
				printf("%d", tree[i]);
			}
			//Sleep(300);
			//printf("N=%d,(i + 1) * 2 - 1=%d", N, (i + 1) * 2 - 1);
			//Sleep(300);
			if (N > (i + 1) * 2 - 1)  //�����ǰ������ֵ��ұ�����������������ַ�
			{
				printfr(Box.list[Box.hear - 1][0] - Box.list[Box.hear - 1][1], Box.list[Box.hear - 1][1]);
				Box.list[Box.tail][0] = Box.list[Box.hear - 1][0] - Box.list[Box.hear - 1][1]-1;
				if (0 == (Box.list[Box.hear - 1][1] - 1) / 2)
					Box.list[Box.tail][1] = 1;
				else
					Box.list[Box.tail][1] = (Box.list[Box.hear - 1][1] - 1) / 2;
				Box.tail++;
			}
			//Sleep(300);
		}
		printf("\n");
		printfd();
		printf("\n");
		Ji = 2 * Ji + 1;  //ÿ���һ����һ������������һ��
		Ntt++;
	}

	system("Pause");   //����DOS������ͣ����
	return 0;
}

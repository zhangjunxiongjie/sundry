//��һ�汾���ڶ�binary_tree������ȫ�ع���ʹԭ�ȵĳ����ܹ���Ӧ��λ��������
//���ˣ��ܹ���Ӧ�ڵ���ֵ��ͬλ���Ķ��������ӻ����������ɡ�

/*
�������һ���������������Ǿ����ϲ���ڵ����ֵλ��ʵ�������ܵ��²��������ڵ������˵ģ�����������Ʒ������ɱ����ȱ�ݣ�Ψһ���ܹ����׽������İ취����ȫ���ع�
��Ҫ�ı����и��ڵ��Ҷ�ڵ�ļ��㷽����ʹ����ܹ����϶��µ����Ϸ��ڵ�ı��·��ڵ�����������ҲҪ�ܹ����¶��ϵ����·��ڵ�ı��Ϸ��ڵ�����������
���ﲻ�ټ������ֻ�������ܹ�ʵ�ָ���׳�����ƵĶ��������ӻ���
*/

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
1-n��;
1.���϶��������ϲ��ͷ��λ�á�����Ҫ�Ƚ��������ַ�����У��������У�һ�����ÿһ������λ����Ȼ�����ͷ�ڵ�������Լ������������λ���ж�ͷ���λ�á�
�ݹ�Ĺ��̣����ϲ�ͷ���λ��Ҫ�����²�ͷ����Լ�Ҷ�ӽڵ������ڵ㡣һ���ݹ�Ҫ������ЩҪ��������е���ֵλ�á�Ҫע�����Ҷ��㲻���������
2.����ͷ���λ����á�_����|���������ŵ�λ�ã�Ҫע�����Ҫ�Ӻ���ǰ��ʼ��������ܴ�ǰ������Ϊ���߻��ڸ�ǰ���������ݡ�
3.�ݹ�õ���ͷ����Լ�Ҷ�ڵ�λ��Ӧ���ǿ�ʼ�����λ�á�
*/

/*
����˼·���ԣ�Ӧ���ȼ�������еĽڵ���ֵλ����Ȼ�������������ݽڵ�����������Լ�Ҷ�ڵ���ýڵ������ʼλ�ã�Ȼ���ٸ��ݽڵ���ʼλ���ж�_|���ַ��ŵ���ʼλ�á�
Ҫע��������ӽڵ㣨���������ڳ���˫��λʱӦ����󿿣������ӽڵ㣨�������ڳ���˫��λʱӦ����ǰ��������Ϊ�˱���ǰ���������Ҷ�ڵ���������������Ҷ�ڵ㿿��һ��
��Ϊ������С������Ҷ���֮��ֻ���һ���ո񣬶�ͬһ��С����������Ҷ�ڵ�֮����������ڵ㡣
������ʾ��������|_�����λ��Ӧ����������ڵ��Լ����ڽڵ��λ��ȷ��������Ӧ�ø����ļ����ҹ���
*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 30
int tree[N] = { 128,2,45693,-68,789,2,123,31223,245,-62,-18,10,1,31,821,1,3,2,5,150,2,31,6,36,-4,4747,45,5,-345645456,345 };
//int tree[N] = { 81,123,3,12,4,561 };

int series_num;  //�洢�������ܵļ�����

struct XY_place {
	int XY;			//�ڵ�Ŀ�ʼ���λ��
	int Place;      //��Ӧ�ڵ����ֵλ��
//	int Left_wide;   //���ҵĿ����ڼ��������ڵ�Ŀ�ʼ���λ�á�
//	int Right_wide;
}Node[N * 2];//Ϊ�˱������һ��ȱ�����Ҫʹ����һ���XY��Ա������ȡ��������

int Node_Place(int Node_number)  //����ڵ����ֵ�����ؽڵ����ֵλ�����������š�
{
	int count = 0;
	int sign = 0;
	if (Node_number < 0)
	{
		sign = 1;
		Node_number = -Node_number;
	}
	else if (Node_number == 0)
		return 1;
	while (Node_number > 0)
	{
		Node_number /= 10;
		count++;
	}
	if (sign)   //�����ֵΪ��������Ҳ����λ�����档
		return count + 1;
	else
		return count;
	
}

int Node_Number(int series)  //���ش��뼶�������ۣ���󣩽ڵ����
{
	int count = 1;
	if (series == 1)
		return 1;
	while (series > 1)
	{
		count *= 2;
		series--;
	}
	return count;
}

int Series_initial(int series)//���뼶�����ص�ǰ������Ӧ�ĵ�һ��Ԫ�ص�λ�á�
{

	int count = 0;
	for (int i = 1; i < series; i++)
	{
		count += Node_Number(i);
	}

	return count;
}

int Series_Number(int Nr)   //���������С���������ɶ������ļ���
{
	int count = 1;  //�ӵ�һ����ʼ,����һ��
	for (int number = 1; number < Nr; )//Ҫע�����N�������ܵ�Ԫ�ظ���������������
	{
		count++;
		number += Node_Number(count);
	}

	return count;
}

//���뵱ǰ����Ľڵ����λ�õĲ���
//�ڼ��㵹���ڶ���ʱ��������һ��һ������ˣ�Ҫ��������������
//1.���ڵ�Ŀ�ʼ���λ������Ҷ�ڵ��ĩβ���һ���ո�
//2.���ڵ�������λ������Ҷ�ڵ�Ŀ�ʼ���λ�����һ���ո�
//3.��������֮���Ҷ�ڵ㿪ʼλ�úͽ���λ�����һ���ո�
//4.�ϲ���ڵ��λ�����������������ڵ���м�λ�ã�
//5.|_��������ǰ��ʼ��λ��ĳһ�ڵ��м�λ�õ��Ϸ���������λ��ǰ�߷��ź�֮���һ���ڵ�Ŀ�ʼλ��֮�䡣
//6.������Ԫ����ɵĶ�����������������ʱȱ�һλ��ֵ���㡣
void Node_XY(int series)//ֻ���㵹���ڶ��㿪ʼ���ϵ��������ڵ�Ŀ�ʼ���λ�á����һ�����⴦����������ݴ��Լ�鱣ֻ֤��һ���������ʱ����ȷ�����
{
	int ser_init = Series_initial(series);   //�õ���ǰ��ĵ�һ��Ԫ���±�
	if (series == series_num - 1)//�����ǰ������ǵ����ڶ���Ľڵ㿪ʼ�����λ�á���ô�͵��������
	{
		for (int i = ser_init; i < ser_init + Node_Number(series); i++)//��ÿһ��Ԫ�ؼ��㿪ʼ���λ��
		{
			if (i == ser_init)//�����һ��λ��
			{
				
				if(i * 2 + 1 < N && i * 2 + 2 >= N)  //���ֻȱ��һ��
				{
					Node[i * 2 + 2].Place = 1;  //����ȱ���ڷ���ʱ�ͽ�ȱ��ĳ�ֵ���ϣ���Ϊ�������ڵ�ʱ���ܻ��õ�
				}
				else  if(i * 2 + 1 >= N && i * 2 + 2 >= N)//���ȱ�����
				{

					Node[i * 2 + 1].Place = 1;
					Node[i * 2 + 2].Place = 1;
				}

				Node[i * 2 + 1].XY = 0;  //���һ���һ���ڵ���ʼλ��Ϊ��,���ӽڵ����ʼλ��
				
			}
			else//���㵹���ڶ������ڵ�������ʼλ�á�
			{

				if (i * 2 + 1 < N && i * 2 + 2 >= N)
				{
					Node[i * 2 + 2].Place = 1;
				}
				else if(i * 2 + 1 >= N && i * 2 + 2 >= N) //���ȱ�����
				{

					Node[i * 2 + 1].Place = 1;
					Node[i * 2 + 2].Place = 1;
				}
				Node[i * 2 + 1].XY = Node[i * 2 + 1 - 1].XY + Node[i * 2 + 1 - 1].Place + 1;//��һ�������ӽڵ���ǰһ�������ӽڵ�֮�����һ���ո�

			}
			Node[i].XY = Node[i * 2 + 1].XY + Node[i * 2 + 1].Place + 1;//���ڵ����ʼλ�á�
			Node[i * 2 + 2].XY = Node[i].XY + Node[i].Place + 1;//���ӽڵ����ʼλ�á�
		}
	}
	else
	{
		for (int i = ser_init; i < ser_init + Node_Number(series); i++)//������ǵ����ڶ�����ô�Ͳ��ý���һ��λ���ó�������Դ�
		{
			int middle = ((Node[2 * i + 2].XY + Node[2 * i + 2].Place / 2) - (Node[2 * i + 1].XY + Node[2 * i + 1].Place / 2)) / 2; //�ȼ�����м�λ�á�

			Node[i].XY = Node[2 * i + 1].XY + Node[2 * i + 1].Place / 2 + middle - Node[i].Place / 2;  
//�������һ���������������Ǿ����ϲ���ڵ����ֵλ��ʵ�������ܵ��²��������ڵ������˵ģ�����������Ʒ������ɱ����ȱ�ݣ�Ψһ���ܹ����׽������İ취����ȫ���ع�
//��Ҫ�ı����и��ڵ��Ҷ�ڵ�ļ��㷽����ʹ����ܹ����϶��µ����Ϸ��ڵ�ı��·��ڵ�����������ҲҪ�ܹ����¶��ϵ����·��ڵ�ı��Ϸ��ڵ�����������
//���ﲻ�ټ������ֻ�������ܹ�ʵ�ָ���׳�����ƵĶ��������ӻ���
		}
	}
}

void Printf_null(int number)//��ӡnumber���ո�
{
	for (; number > 0; number--)
	{
		printf(" ");
	}
}

void Printf_across(int number,int sign)//���ƺ���
{
	
	for (; number > 0; number--)
	{
		if (sign < N)
			printf("_");
		else	
			printf(" ");
	}
	
}
/*
void Printf_vertical(int number)//������
{
	for (; number > 0; number--)
	{
		printf("|");
	}
}
*/
void Printf_sign(int sign)//���뵱ǰ�ڵ��Ԫ���±���ƽڵ��Լ�_|���ţ������Ƶ����һ��ʱ���⴦��
{
	
	printf("\r"); //��ÿ�е���ʼλ�ÿ�ʼ��ӡ
		
	int init = Node[2 * sign + 1].XY + Node[2 * sign + 1].Place / 2 + 1;
	Printf_null(init);//��ӡ�ո�
	Printf_across(Node[sign].XY - init, 2 * sign + 1);//���ƺ�
	printf("%d",tree[sign]);
	Printf_across(Node[2 * sign + 2].XY + Node[2 * sign + 2].Place/2 - Node[sign].XY - Node[sign].Place, 2 * sign +2);//���ƺ�
	
	
}

void Printf_sign1(int sign)//���뵱ǰ�ڵ��Ԫ���±���ƽڵ��Լ�_|���ţ������Ƶ����һ��ʱ���⴦��
{

	printf("\r"); //��ÿ�е���ʼλ�ÿ�ʼ��ӡ
	Printf_null(Node[sign].XY);//��ӡ�ո�
	printf("%d", tree[sign]);

}
void Printf_sign2(int sign)
{
	printf("\r");
	Printf_null(Node[sign].XY + Node[sign].Place/2);
	printf("|");
}

void Tree_Draw()//ʹ��ǰ��õ�����ʼ���λ�ã��Զ��������л��ơ�
{
	for (int i = 1; i <= series_num;i++)//����
	{

		if (i < series_num)
		{
			for (int j = Series_initial(i) + Node_Number(i) - 1; j >= Series_initial(i); j--)//����ÿһ���ڵ㣬�Ӻ���ǰ��ʼ���ơ�
			{
				Printf_sign(j);

			}

			printf("\n");

			for (int j = Series_initial(i + 1) + Node_Number(i + 1) - 1; j >= Series_initial(i + 1); j--)
			{
				if(j < N)
					Printf_sign2(j);
			}
			
		}
		else
		{
			for (int j = Series_initial(i) + Node_Number(i) - 1; j >= Series_initial(i); j--)//����ÿһ���ڵ㣬�Ӻ���ǰ��ʼ���ơ�
			{
				if (j < N)
					Printf_sign1(j);
			}
		}
		printf("\n");
	}
}


void Node_main()    //����������ڵõ�ÿһ���ڵ�Ŀ�ʼ�����λ�ú�ûһ���ڵ����ֵλ�����ȼ���ÿһ���ڵ����ֵλ��Ȼ�����¶��ϵļ���ÿһ���ڵ�����λ��
{
	
	for (int i = 0; i < N; i++)  //�ȼ����ÿһ�ڵ����ֵλ��
	{
		Node[i].Place = Node_Place(tree[i]);
	}
	series_num = Series_Number(N);  //������Ԫ�ظ����õ���ɵĶ������ļ�����
	
	//printf("%d", Series_Number(N));
	
	/*
	for (int i = 1; i <= series_num; i++)
		printf("%d:", Series_initial(i));
	*/
	
	for (int i = series_num - 1; i >= 1 ; i--)
	{
		Node_XY(i);
	}
	
	/*
	for (int i = 0; i < N; i++)
	{
		printf("%d:%d\n", Node[i].XY,Node[i].Place);
	}
	*/

	Tree_Draw();  //���ж������Ļ��ơ�

}


int main()
{
	/*��ֵλ����������
	for (int i = 0; i < 10; i++)
		printf("%d:",Node_Place(tree[i]));
	*/
	/*���ݼ��������ڵ��������
	for (int i = 1; i < 10; i++)
	{
		printf("%d:", Node_Number(i));
	}
	*/
	Node_main();


	/*
	for (int i = 0; i < N; i++)
		printf("%d:", Node[i].Place);
	*/

	system("Pause");   //����DOS������ͣ����
	return 0;
}


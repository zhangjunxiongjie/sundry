/*��°ͺղ���:һ����������ż��һ����������������ӵõ���
�˳�����������һ����������ż�������°ͺղ����е�����������
һ�ַ���:�����С�������������������洢��һ�����飬���������������ҵ���������һ��������ڣ����С���Ǹ�������¼�±꣬
Ȼ�����������Χ���б��������������������
��һ�ַ���:����һ�����������ж�һ�����Ƿ�������Ȼ��ѭ��С���������������������ж�ѭ����i��a-i��a�����������Ƿ�������
ֱ��ͬʱ������ʱ�˳�ѭ����
ע�����������жϱ�����������ܵ��ڣ�
*/
/*
*/


#include <stdio.h>
#include <stdlib.h>

#define N 10000

int Prime(int* we,int wr,int* lenr)   //����һ������һ�����飬���������������洢�����������,���ش���������һ����Ǹ����������ꡣ
{
	int wy = wr / 2, wt = 0, i, j, len;
	we[0] = 2;
	len = 1;
	for ( i= 3; i< wr; i++)
	{
		for ( j = 0; j < len; j++)
		{
			if (i%we[j] == 0)
				break;
		}
		//printf("%d\n",j);
		if (j == len)  //�ж��Ƿ�Ϊ����
		{
			if (i >= wy && wt == 0) //����������Ҵ���wr��һ����wtΪ��ֵ
				wt = len;
			we[len] = i;
			len++;
			//printf("%d ", we[len - 1]);
		}
	}
	*lenr = len;
	return wt;
}



int main()
{
	int ty,tr;   //ty���ڴ洢���������tr���ڴ洢��������ty/2���ڵ������±�
	int i,num=0,len;
	int tf[N];
	while (!scanf_s("%d", &ty) || ty <= 6 || ty % 2 == 1);
	tr = Prime(tf, ty,&len);
	i = tr - 1;
//	while (0<=i&&i<=len)
	while (tf[i] + tf[tr] != ty)
	{
		if (tf[i] + tf[tr] < ty)
			tr++;
		else if (tf[i] + tf[tr] > ty)
			i--;
	/*	else if (tf[i] + tf[tr] == ty)
		{
			printf("%d+%d=%d\n", tf[i], tf[tr], ty);
			num++;
			tr++;
			//i--;
		}*/
	}
	printf("%d+%d=%d\n", tf[i], tf[tr], ty);
	//printf("%d\n", num);

	system("Pause");
	return 0;
}



//����n����������n������ȡ����ֵ��С��ǰk��������k����
#include <stdio.h>
int main()
{
	int n;	   //�ܵ���ֵ����
	int k = 5; //ȡ�����ȶ��ٸ���
	//printf("n=");
	//scanf ("%d",&n);
	//printf("k=");
	//scanf ("%d",&k);
	int a[10000]; //������ֵ�ܸ���������
	int i = 0, c, jhzj;
	int b[5];	  //���������ǰk����
	while (i < n) //��������n����ֵ
	{
		scanf("%d", &a[i]);
		i++;
	}
	for (i = 0; i < k; i++) //�������n������ǰk��������b[]������Ϊ��ʼֵ
	{
		b[i] = a[i];
	}
	for (c = 0; c < k; c++) //�ȶԳ�ʼ���������b[]��������ȷ���������ܹ�ʼ�����ɴ�С
	{
		i = ++c;
		while (i < k)
		{
			if (b[c] < b[i])
			{
				jhzj = b[i];
				b[i] = b[c];
				b[c] = jhzj;
			}

			i++;
		}
	}						//
	for (i = k; i < n; i++) //������a[]�к������������ÿһ��b[]������ûһ�����Ƚ�
	{
		c = 0;
		while (c < k)
		{
			if (a[i] > b[c])
			{
				jhzj = b[c];
				b[c] = a[i];
				a[i] = jhzj;
				c++;
				//printf("%d ",b[c]);
			}
			else
			{
				c++;
			}
		}
	}						 //
	for (i = 1; i <= k; i++) //���b[]����
	{
		printf("%d ", b[i - 1]);
		//if(i%4==0)
		//printf("\n");
		//else
		//printf(" ");
	} //
	printf("\n");
	return 0;
}
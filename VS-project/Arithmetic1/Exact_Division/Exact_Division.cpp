//ʹ�ü���ʵ�ֶ���ֵ��������
//��Ҫע��������������ķ��š�������˵ע�������ķ��ţ��������������涨Ϊ������
//���ﲢ����������������������⣩��Ҫ��д��˼·����������0�������Ǹ��������������

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dividend, divisor;  //divisor��������dividend����������
	int sign; //���ڼ�¼����ķ���
	int result = 0; //�洢���
	int temporary_divisor; //��ʱ����
	int temporary_multiple; //��ʱ����
	printf_s("����������ͱ�����:");
	scanf_s("%d %d", &divisor, &dividend);  //��֤����һ������Ҫ���������ע��ʵ�־Ͳ����ǲ����
	//������ΪҪ������ȡ�෴�����������Ͳ�������������⣨��Ϊ������������һ����
	if (dividend < 0 && divisor > 0) //����ʹ��������佫���п��ܵĸ�����Ϊ����
	{
		sign = 1;
		dividend = -dividend;
	}
	else if (dividend > 0 && divisor < 0)
	{
		sign = 1;
		divisor = -divisor;
	}
	else if (divisor < 0 && dividend < 0)
	{
		dividend = -dividend;
		divisor = -divisor;
	}
	//��ʱ������ʼ��
	temporary_multiple = 1;
	temporary_divisor = divisor;
	while (true)//�㷨���ģ����ﲢû��ʹ�ü򵥵����ȥ���������ڼ��Ĺ������𽥼���Խ��Խ�ࡣֱ������������ʱ˲�併��ԭ����ֵ��
	{           //��һ��˼·�ǵ�����������ʱ�𽥼������ಿ�ֶ�����һ���Ӵ������ĳ�����
		if (temporary_divisor <= dividend)
		{
			dividend -= temporary_divisor;
			result += temporary_multiple;
		}
		else if(temporary_multiple != 1)
		{
			temporary_multiple = 1;
			temporary_divisor = divisor;
		}
		else
		{
			break;
		}
		if (temporary_divisor + temporary_divisor <= dividend)
		{
			temporary_divisor += temporary_divisor;
			temporary_multiple += temporary_multiple;
		}

	}

	printf_s("����������Ϊ:%d\n", result);

	system("Pause");   //����DOS������ͣ����

	return 0;
}
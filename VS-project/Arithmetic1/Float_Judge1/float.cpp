//�������ʹ�õڶ��ַ���ʵ����ֵ�ж�
//����������򵥵�ʹ���˲�ͬ�ķ���ʵ������ֵ�������ж����߸���ǧ�ǰ�߾�ȷ���ҵ��˴�����ֵ�ķ�ΧȴҲ������һ��ʱ�临�Ӷȣ�
//������Ȼ�ܹ�����Ķ���ֵ�����жϣ�����Ҳ����һЩ���⡣

#include <iostream>

bool Float_judge(double it);

bool Float_judge(double it)//Ϊ�˱�������Ը�λ�����ֽ����ж�
{
	bool result = false;  
	
	long long int  middle = 100000;

	int count = 0;//������������С����ȡ��λ��
	while (count < 6)
	{
		if (it > middle || it < -middle)//������������¶��п������
		{
			long long int itr = long long int(it / middle);
			it = it - itr * middle;  //�жϸ�λ���֣��������
		}

		it = it * 10;
		if (int(it) % 10 != 0)
		{
			result = true;
			break;
		}
		printf("###%lf\n",it);
		count++;
	}

	return result;
}

int main()
{
	double target;

	scanf_s("%lf", &target);

	printf_s("%lf###%d\n", target, Float_judge(target));

	system("Pause");
	return 0;
}
//这个程序使用第二种方法实现数值判断
//这两个程序简单的使用了不同的方法实现了数值浮整的判断两者各有千秋，前者精确地找到了传入数值的范围却也牺牲了一点时间复杂度，
//后者虽然能够极快的对数值进行判断，但是也存在一些问题。

#include <iostream>

bool Float_judge(double it);

bool Float_judge(double it)//为了避免溢出对高位的数字进行切断
{
	bool result = false;  
	
	long long int  middle = 100000;

	int count = 0;//计数器，控制小数点取出位数
	while (count < 6)
	{
		if (it > middle || it < -middle)//这里两种情况下都有可能溢出
		{
			long long int itr = long long int(it / middle);
			it = it - itr * middle;  //切断高位部分，避免溢出
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
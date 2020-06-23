//利用函数之间的调用和switch语句计算提成
//函数之间存在多级嵌套调用
#include <stdio.h>
int main()
{
	int xsw(int a); //<100000
	int dsw(int a); //100000
	int esw(int a); //200000
	int ssw(int a); //400000
	int lsw(int a); //600000
	int ybw(int a); //100000    求解提成函数的声明
	long int n, tc;
	char ch = 'z';
	printf("请输入总的利润：");
	scanf("%d", &n);
	if (n < 100000)
		ch = 'a';
	else if (n < 200000)
		ch = 'b';
	else if (n < 400000)
		ch = 'c';
	else if (n < 600000)
		ch = 'd';
	else if (n < 1000000)
		ch = 'e';
	else if (n > 1000000)
		ch = 'f';
	printf("%c\n", ch);
	switch (ch) //根据ch的字符判断应该使用的计算提成的函数
	{
	case 'a':
		tc = xsw(n);
		break;
	case 'b':
		tc = dsw(n);
		break;
	case 'c':
		tc = esw(n);
		break;
	case 'd':
		tc = ssw(n);
		break;
	case 'e':
		tc = lsw(n);
		break;
	case 'f':
		tc = ybw(n);
		break;
	default:
		printf("输入错误！"); //当输入的利润值不在求解范围时，输出‘输入错误’
	}
	printf("得到提成为：%d\n", tc);
	return 0;
}

int ybw(int a) //1000000
{
	int lsw(int a); //600000
	int sum;
	sum = lsw(1000000) + (a - 1000000) * 0.01;
	return (sum);
}

int lsw(int a) //600000
{
	int ssw(int a); //400000
	int sum;
	sum = ssw(600000) + (a - 600000) * 0.015;
	return (sum);
}

int ssw(int a) //400000
{
	int esw(int a); //200000
	int sum;
	sum = esw(400000) + (a - 400000) * 0.03;
	return (sum);
}

int esw(int a) //200000
{
	int dsw(int a); //100000
	int sum;
	sum = dsw(200000) + (a - 200000) * 0.05;
	return (sum);
}

int dsw(int a) //100000
{
	int xsw(int a); //<100000
	int sum;
	sum = xsw(100000) + (a - 100000) * 0.075;
	return (sum);
}

int xsw(int a) //<100000
{
	int sum;
	sum = a * 0.1;
	return (sum);
}

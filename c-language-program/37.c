#include <stdio.h> //另类选择语句的使用
int main()
{
	float x, y;
	char t;
	scanf("%f", &x);
	if (x < 1)
		t = 'A';
	else if (x < 10)
		t = 'B';
	else
		t = 'C';
	switch (t)
	{
	case 'A':
		y = x;
		break;
	case 'B':
		y = 2 * x - 1;
		break;
	case 'C':
		y = 3 * x - 11;
		break;
	}
	printf("%f\n", y);
	return 0;
}

#include <stdio.h> //另类选择语句的使用
int main()
{
	int a, b;
	char k;
	printf("a=");	  //可以做这样的尝试先输出‘a=’输入数字之后按回车在同一行输出‘b=’再输入数字//
	scanf("%d,", &a); //接着在第二行输出‘输入运算符：’输入运算符后回车即可输出结果//
	printf("b=");	  //程序做了一些修改但仍不能达到预期//
	scanf("%d,", &b);
	fflush(stdin); //此处的‘fflush’？？？//
	printf("输入运算符:\n");
	scanf("%c", &k);
	switch (k)
	{
	case '+':
		printf("结果为%d\n", a + b);
		break;
	case '-':
		printf("结果为%d\n", a - b);
		break;
	case '*':
		printf("结果为%d\n", a * b);
		break;
	case '/':
		printf("结果为%d\n", a / b);
		break;
	}
	return 0;
}
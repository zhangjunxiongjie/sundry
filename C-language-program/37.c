#include <stdio.h> //����ѡ������ʹ��
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

#include <stdio.h> //����ѡ������ʹ��
int main()
{
	int a, b;
	char k;
	printf("a=");	  //�����������ĳ����������a=����������֮�󰴻س���ͬһ�������b=������������//
	scanf("%d,", &a); //�����ڵڶ��������������������������������س�����������//
	printf("b=");	  //��������һЩ�޸ĵ��Բ��ܴﵽԤ��//
	scanf("%d,", &b);
	fflush(stdin); //�˴��ġ�fflush��������//
	printf("���������:\n");
	scanf("%c", &k);
	switch (k)
	{
	case '+':
		printf("���Ϊ%d\n", a + b);
		break;
	case '-':
		printf("���Ϊ%d\n", a - b);
		break;
	case '*':
		printf("���Ϊ%d\n", a * b);
		break;
	case '/':
		printf("���Ϊ%d\n", a / b);
		break;
	}
	return 0;
}
//Ī�������С����

#include <stdio.h>
int main()
{
	float score;
	scanf("%f", &score); //�ڱ༭���������˴��ַ��&������ʱĳһ����ִ�г��ִ���
	bool a, b;			 //bool����a��bΪ�߼�����
	a = (score >= 60);
	b = (score <= 69); //��69>=score���߼�ֵ����b
	if (a == true && b == true)
		printf("The grade is C\n");
	return 0;
}

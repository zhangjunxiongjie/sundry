//�ж������ַ�������ĸ���ֿո�������ĸ��������
#include <stdio.h>
#include <string.h> //�����ַ������Ⱥ�����ͷ�ļ�
int main()			//������һ���ַ������䱣�����ַ�����a�����У�Ȼ�����ж�
{
	int cd, i;
	int szgs = 0, zfgs = 0, kggs = 0, qtgs = 0;
	char a[100];
	gets(a);		//�ַ����������
	cd = strlen(a); //���ַ������ȣ��ܵ��ַ��������ĺ���
	for (i = 0; i < cd; i++)
	{
		if ('0' <= a[i] && a[i] <= '9') //���ֵ��ж�
			szgs++;
		else if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //��ĸ���ж�
			zfgs++;
		else if (a[i] == ' ') //�ո���жϣ��˴�ע��Ⱥű�д���˸�ֵ����
			kggs++;
		else //����
			qtgs++;
	}
	puts(a);			//�ַ���������
	printf("%d\n", cd); //����ַ������ܵ��ַ�����
	printf("��ĸ������%d\n", zfgs);
	printf("���ָ�����%d\n", szgs);
	printf("�ո������%d\n", kggs);
	printf("����������%d\n", qtgs);
	return 0;
}

#include <stdio.h>
#include <string.h> //�ⶨ�ַ������Ⱥ�����ͷ�ļ�
int main()
{
	int szgs = 0, zfgs = 0, kggs = 0, qtgs = 0;
	char b, a[20]; //��ʱ����������ַ���
	int i, cd;
	for (i = 0; (b = getchar()) != '\n'; i++) //ÿ����һ���ַ�������ַ���ʱ�������ַ�����a��
	{										  //ÿ����һ���ַ�ѭ�����ж�һ�Σ�ֱ������س�ʱ�˳�ѭ����������
		a[i] = b;
		if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z'))
			zfgs++;
		else if ('0' <= a[i] && a[i] <= '9')
			szgs++;
		else if (a[i] == ' ')
			kggs++;
		else
			qtgs++;
	}
	cd = strlen(a); //�ⶨ�ַ�������
	puts(a);		//�ַ���������
	printf("%d\n", cd);
	printf("��ĸ������%d\n", zfgs);
	printf("���ָ�����%d\n", szgs);
	printf("�ո������%d\n", kggs);
	printf("����������%d\n", qtgs);
	return 0;
}

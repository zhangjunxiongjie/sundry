//�ж�Ӣ�������Ƿ���Ե�С����

#include <stdio.h>

char Back(char ch)
{
	switch (ch)
	{
	case ']':
		return '['; //Ӣ������ ���޷�ʶ�����������ַ�
	case '}':
		return '{';
	case ')':
		return '(';
	case '>':
		return '<';
	default:
		return '0';
	}
	return '0';
}

int main()
{
	char bracket[200], ch;
	int base[100]; //����������λ��
	int count, tag = 0, i = 0;
	for (count = 0; (ch = getchar()) != '\n'; count++)
		bracket[count] = ch;
	while (i <= count)
	{
		if (bracket[i] == '[' || bracket[i] == '{' || bracket[i] == '(' || bracket[i] == '<')
		{
			base[tag] = i;
			tag++;
		}
		if (bracket[i] == ']' || bracket[i] == '}' || bracket[i] == ')' || bracket[i] == '>')
		{
			if (bracket[base[tag - 1]] != Back(bracket[i]))
			{
				printf("false\n");
				return 0;
			}
			else
				tag--;
		}
		i++;
	}
	printf("true\n");
	return 0;
}

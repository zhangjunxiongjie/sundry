//判断英文括号是否配对的小程序

#include <stdio.h>

char Back(char ch)
{
	switch (ch)
	{
	case ']':
		return '['; //英文括号 ，无法识别中文括号字符
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
	int base[100]; //储存左括号位置
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

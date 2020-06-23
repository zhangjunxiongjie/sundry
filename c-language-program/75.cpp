//按规则给选手分配对手
#include <stdio.h>
int main()
{
	char a[3] = {'A', 'B', 'C'}, b[3] = {'X', 'Y', 'Z'};
	char ds[6];
	int i, t;
	for (i = 0, t = 0; i < 6; t++, i += 2)
	{
		ds[i] = a[t];
	}
	for (i -= 1; i >= 0; i -= 2)
	{
		if (i = 5)
			for (t = 0; t < 3; t++)
				if (b[t] != 'Z' && b[t] != 'Z')
				{
					ds[i] = b[t];
					b[t] = ' ';
				}
				else if (i = 1)
					for (t = 0; t < 3; t++)
						if (b[t] != 'X' && b[t] != ' ')
						{
							ds[i] = b[t];
							b[t] = ' ';
						}
						else if (i = 3)
							for (t = 0; t < 3; t++)
								if (b[t] != ' ')
								{
									ds[i] = b[t];
									b[t] = ' ';
								}
	}
	for (i = 0; i < 6; i += 2)
		printf("%c 的对手是 %c 。\n", ds[i], ds[i + 1]);
	return 0;
}

#include <stdio.h>
int main()
{
	int i = 0, ir;
	int max=1, maxi;
	int NU[10000],TU;
	scanf("%d",&TU);
	while(i<TU)
		scanf("%d",&NU[i++]);
	i=0;
	while(i < TU)
	{
		ir = i;
		while (NU[i]  < NU[i + 1])
		{
			i++;
			if (i > TU)
				break;
		}
		if (i - ir + 1 > max)
		{
			max = i - ir + 1;
			maxi = ir;
		}
		else
			i++;
	}
	printf("%d\n", max);
	return 0;
}

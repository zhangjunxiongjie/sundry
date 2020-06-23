#include <stdio.h>
int main()
{
	int i=0,j,tf,num,at[100];
	scanf("%d",&num);
	while(i<num)
	{
		scanf("%d",&at[i++]);
		for(j=0,tf=0;j<i-1;j++)
			if(at[j]<at[i-1])
				tf++;
		printf("%d ",tf);
	}
	return 0;
}

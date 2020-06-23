#include <stdio.h>
int main()
{
	int at[10],H;
	int i,num;
	for(i=0;i<10;i++)
		scanf("%d",at+i);
	scanf("%d",&H);
	for(i=0,num=0;i<10;i++)
		if(at[i]<=H+30)
			num++;
	printf("%d\n",num);
	return 0;
}

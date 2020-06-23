#include <stdio.h>
int main()
{
	int i=0,ch,at[100];
	while(scanf("%d",&ch)&&ch!=0)
	{
		at[i]=ch;
		i++;
	}
	ch=i-1;
	while(ch>=0)
		printf("%d ",at[ch--]);
	return 0;
} 

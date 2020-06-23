#include <stdio.h>
int main()
{
	int move[200];
	char ch;
	int right=0,count=0,i,tag;
	while((ch=getchar())!=' ')
		count=count*10+ch-48;
	while((ch=getchar())!=' '&&ch!='\n')
		right=right*10+ch-48;
	right=right%(count);
	for(i=0,tag=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&tag==0)
			move[i]=ch-48;
		if(ch!=' '&&tag==1)
			move[i]=move[i]*10+ch-48;
		if(ch==' ')
		{
			tag=0;
			i++;
		}	
		else
			tag=1;
	}
	for(i=0;i<count;i++)
	{
		if(i<count-right)
			move[100+i+right]=move[i];
		else
		 	move[100+i+right-count]=move[i];
	}
	for(i=100;i<100+count;i++)
	{
		printf("%d",move[i]);
		if(i<100+count-1)
			printf(" ");			
	}	
	return 0;
}

#include <stdio.h>
typedef struct{
		char ch;
		int nape;
	}single;

int main()
{
	single derivative[100];
	int i,tag,count=0;
	char ch;
	for(i=0,tag=0;(ch=getchar())!='\n';)
	{
		if(ch!='-'&&ch!=' '&&tag==0)
			derivative[i].nape=ch-48;
		if(ch!='-'&&ch!=' '&&tag==1)
			derivative[i].nape=derivative[i].nape*10+ch-48;
		if(ch==' ')
		{
			tag=0;
			i++;
		}
		else
			tag=1;
		if(ch=='-')
			derivative[i].ch='-';	
	}
	count=i+1;
	for(i=0;i<count;i=i+2)
	{
		if(derivative[i+1].nape!=0&&derivative[i].ch!='-'&&derivative[i+1].ch!='-')
		{
			printf("%d %d",derivative[i].nape*derivative[i+1].nape,derivative[i+1].nape-1);
			if((i!=count-1&&i+3!=count-1)||(i+3==count-1&&derivative[i+3].nape!=0))
				printf(" ");
		}
		else if(derivative[i+1].nape!=0&&derivative[i].ch=='-'&&derivative[i+1].ch=='-')
		{
			printf("%d -%d",derivative[i].nape*derivative[i+1].nape,derivative[i+1].nape+1);
			if((i!=count-1&&i+3!=count-1)||(i+3==count-1&&derivative[i+3].nape!=0))
				printf(" ");
		}
		else if(derivative[i+1].nape!=0&&derivative[i].ch!='-')
		{
			printf("-%d -%d",derivative[i].nape*derivative[i+1].nape,derivative[i+1].nape+1);
			if((i!=count-1&&i+3!=count-1)||(i+3==count-1&&derivative[i+3].nape!=0))
				printf(" ");
		}
		else if(derivative[i+1].nape!=0&&derivative[i+1].ch!='-')
		{
			printf("-%d %d",derivative[i].nape*derivative[i+1].nape,derivative[i+1].nape-1);
			if((i!=count-1&&i+3!=count-1)||(i+3==count-1&&derivative[i+3].nape!=0))
				printf(" ");
		}
	}
	if(count==2&&derivative[1].nape==0&&derivative[0].nape==0)
		printf("0 0");
	return 0;
}


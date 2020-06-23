#include <stdio.h>
int main()
{
	int derivative[100];
	int i,tag,count=0,sign;
	char ch;
	for(i=0,tag=0,sign=0;(ch=getchar())!='\n';)
	{
		if(ch!='-'&&ch!=' '&&tag==0)
			derivative[i]=ch-48;
		if(ch!='-'&&ch!=' '&&tag==1)
			derivative[i]=derivative[i]*10+ch-48;
		if(ch==' '&&sign==1)
			derivative[i]=0-derivative[i];
		if(ch==' ')
		{
			tag=0;
			i++;
			sign=0;
		}
		if(ch!=' '&&ch!='-')
			tag=1;
		if(ch=='-')
			sign=1;	
	}
	if(sign==1)
		derivative[i]=0-derivative[i];
	count=i+1;
	for(i=0;i<count;i=i+2)
	{
		if(derivative[i+1]!=0)
		{
			printf("%d %d",derivative[i]*derivative[i+1],derivative[i+1]-1);
			if((i!=count-1&&i+3!=count-1)||(i+3==count-1&&derivative[i+3]!=0))
				printf(" ");
		}
	}
	if(count==2&&derivative[1]==0&&derivative[0]==0)
		printf("0 0");
	return 0;
} 

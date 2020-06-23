#include <stdio.h>
int main()
{
	int tf=0,i=0,j=1;
	char ch,at[13];
	while((ch=getchar())!='\n')
	{
		if(i!=1&&i!=5&&i<11)
		{
			tf+=(ch-48)*j;
	//		printf("%d:%d\t",ch-48,j);
			j++;
		}	
		at[i++]=ch;
	}
//	printf("%d\n",tf%11);
	if(tf%11==at[12]-48||(tf%11==10&&at[12]=='X'))
		printf("Right\n");
	else if(tf%11!=10)
	{
		for(i=0;i<12;i++)
			printf("%c",at[i]);
		printf("%d\n",tf%11);
	}
//		printf("%s\b%d\n",at,tf%11);
	else
	{
		for(i=0;i<12;i++)
			printf("%c",at[i]);
		printf("X\n");
	}
//		printf("%s\bX\n");
	return 0;
} 




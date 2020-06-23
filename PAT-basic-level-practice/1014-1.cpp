//1014

#include <stdio.h>
int main()
{
	char ch,date[4][60];
	int count,i,tag=0;
	for(count=0;count<4;count++)
	for(i=0;(date[count][i]=getchar())!='\n';i++);
	
	for(i=0;date[0][i]!='\n'&&date[1][i]!='\n';i++)
	{
		if(date[0][i]==date[1][i]&&date[0][i]<='G'&&date[0][i]>='A')
		{
			switch(date[1][i])
			{
			case'A':printf("MON ");break;
			case'B':printf("TUE ");break;
			case'C':printf("WED ");break;
			case'D':printf("THU ");break;
			case'E':printf("FRI ");break;
			case'F':printf("SAT ");break;
			case'G':printf("SUN ");break;
		//	default:printf("ยาย๋ณ๖ดํ");	
			}
			tag=1;
		}
		if(date[0][i]==date[1][i]&&tag==1&&((date[0][i]<='N'&&date[0][i]>='A')||(date[0][i]<='9'&&date[0][i]>='0')))
		{
			if(date[0][i]<='9') 
				printf("0%c:",date[0][i]);
			else
				printf("%d:",date[0][i]-54);
			break;	
		}
	}
	for(i=0;date[2][i]!='\n'&&date[3][i]!='\n';i++)
	{
		if(date[2][i]==date[3][i]&&((date[3][i]<='Z'&&date[3][i]>='A')||(date[3][i]>='a'&&date[3][i]<='z')))
		{
			if(i<10)
				printf("0%d",i);
			if(i>=10)
				printf("%d",i);
		}	
	//	printf("\n");
	//	printf("%c,%c\n",date[2][i],date[3][i]);
	}
return 0;	
} 

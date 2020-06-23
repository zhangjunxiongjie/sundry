//这是无论字符是否存在都有对应列的程序 

//未解决 

#include <stdio.h>

/*
struct {
	char ch;
	int num;
}ChNum[24];
*/

int main()
{
	char at[4][101];
	int CharNum[27];
	int Class[101];   //保存每一行的最后一个字母位置 
	int itr,it;
	for(it=0;it<27;it++)
		CharNum[it]=0;
	for(it=0;it<4;it++)
	{
		for(itr=0;(at[it][itr]=getchar())!='\n';itr++);
		
		for(itr=0;at[it][itr]!='\n';itr++)
		{
			if(at[it][itr]>='A'&&at[it][itr]<='Z')
			{
			//	printf("%d:",at[it][itr]-100);
				CharNum[at[it][itr]-64]++;
				if(CharNum[at[it][itr]-64]>CharNum[0])   //CharNum[0]存储字母个数最多的个数 
				{
					CharNum[0]=CharNum[at[it][itr]-64];
					
				}
			}	
		
		}
		//printf("\n");
	}	
	//printf("%d\n",CharNum[0]);
	
	
	/*
	for(it=1;it<27;it++)
		printf("%d ",CharNum[it]); 
	
	printf("\n");
	*/
	for(it=CharNum[0];it>0;it--)
	{
		for(itr=1;itr<27;itr++)
			if(CharNum[itr]>=it)
				Class[it]=itr; 
	//	printf("%d ",Class[it]);
	}
	//printf("\n");
	for(it=CharNum[0];it>=0;it--)
	{
		for(itr=1;it&&itr<=Class[it];itr++)
		{
			if(CharNum[itr]>=it)
				printf("*");
			else
				printf(" ");
			if(itr<Class[it])
				printf(" ");
		}
		for(itr=65;!it&&itr<=90;itr++)
			if(itr!=90)
				printf("%c ",itr);
			else
				printf("%c",itr);
		if(it)
			printf("\n");				
	}
	
	return 0;
}

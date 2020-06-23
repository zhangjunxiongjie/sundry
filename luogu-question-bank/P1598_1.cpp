//这是只显示存在字母的对应列的代码 

//未解决 

#include <stdio.h>

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
			
				CharNum[at[it][itr]-64]++;
				if(CharNum[at[it][itr]-64]>CharNum[0])   //CharNum[0]存储字母个数最多的个数 
				{
					CharNum[0]=CharNum[at[it][itr]-64];
					
				}
			}	
		
		}
		
	}	
	
	for(it=CharNum[0];it>0;it--)
	{
		for(itr=1;itr<27;itr++)
		{
			if(CharNum[itr]>=it)
				Class[it]=itr; 
			if(CharNum[itr]==0)
				Class[it]--;	
		}	
		
	}

	for(it=CharNum[0];it>=0;it--)
	{
		for(itr=1;it&&itr<=Class[it];itr++)
		{
			if(CharNum[itr]>=it)
				printf("*");
			else if(CharNum[itr]>0)
				printf(" ");
			if(CharNum[itr]>0&&itr<Class[it])
				printf(" ");
		}
		for(itr=1;!it&&itr<=26;itr++)
		{
			if(CharNum[itr]>0&&itr!=26)
				printf("%c ",itr+64);
			if(CharNum[itr]>0&&itr==26)
				printf("%c",itr+64);
		}	
		if(it)
			printf("\n");				
	}
	
	return 0;
}





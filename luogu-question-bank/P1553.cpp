//Î´½â¾ö²İÄâÂğ£¡£¡£¡
 
#include <stdio.h>

int main()
{
	char at[22];
	int it,falg,itr,ite;
	int flg;
	char ch;
	
	
	for(it=0,falg=0;(ch=getchar())!='\n';it++)
	{
		at[it]=ch;
		if(ch<'0'||ch>'9')
		{
			falg=1;
			itr=it;	
		}	
	}
	if(falg)
	{
		flg=0;
		ite=itr-1;
		while(ite>=0)
		{
			if(!flg&&at[ite]!='0')
				flg=1;
			if(flg)
				putchar(at[ite]);
			ite--;
		}
		if(at[itr]=='%')
			putchar('%');
		else if(at[itr]=='/')
		{
			putchar('/');
			flg=0;
			ite=it-1;
			while(ite>itr)
			{
				if(!flg&&at[ite]!='0')
					flg=1;
				if(flg)
					putchar(at[ite]);
				ite--;
			}	
		}
		else if(at[itr]=='.')
		{
			putchar('.');
			ite=it-1;
			while(at[itr+1]=='0')
				itr++;
			while(ite>itr)
			{
				putchar(at[ite]);
				ite--;
			}
		}
	}
	else
	{
		flg=0;
		ite=it-1;
		while(ite>=0)
		{
			if(!flg&&at[ite]!='0')
				flg=1;
			if(flg)
				putchar(at[ite]);
			ite--;
		}	
	}

	return 0;
}












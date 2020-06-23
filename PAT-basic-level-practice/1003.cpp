#include <stdio.h>

int pd1(char *p)
{
	int i=0;
	while(p[i]!='\0')
		i++;
	if(i==3)
	{
		if(p[0]=='P')
		{
			if(p[1]=='A')
			{
				if(p[2]=='T')
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int pd2(char *p)
{
	int i,hh=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='P')
		{
			if(p[i+1]=='A')
			{
				if(p[i+2]=='T')
				{
					for(hh=0,i=i+3;p[i]!='\0';i++)
					{
						if((i==i+3&&p[i]=='A')||(hh=1&&p[i]=='A'))
							hh=1;
						else
							return 0;	
					}
					if(p[i]=='\0')
						return 1;	
				}
			}
		}
		if((i==0&&p[i]=='A')||(hh=1&&p[i]=='A'))
			hh=1;
		else
			return 0;	
	}
}






int pd3(char *p)
{
	int i,biaoji=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='P')
		{
			for(;p[i]!='\0';i++)
			{	
				if(p[i]=='T'&&biaoji>=2)
				{
					i++;
					for(;p[i]!='\0';i++)
					{
						
						if(p[i]!='A')
							return 0;	
					}
					if(p[i]=='\0')
						return 1;	
				}
				biaoji++;
				if(biaoji>=4)
					return 0;
 			}
		}
		if(p[i]!='A')
			return 0;		
	}
	return 0;
}



int main()
{
	int jishu,i;
	char a[10][101];
	scanf("%d",&jishu);
	for(i=0;i<jishu;i++)
	{
		scanf("%s",a[i]);
	}
	for(i=0;i<jishu;i++)
	{
		if(pd1(a[i])||pd2(a[i])||pd3(a[i]))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}



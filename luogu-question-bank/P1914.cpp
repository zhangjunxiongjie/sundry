#include <stdio.h>

int main()
{
	int nu,it;
	char at[51];
	scanf("%d\n%s",&nu,at);
	while(nu>=26)
		nu-=26;
	for(it=0;at[it]!='\0';it++)
	{
		if(at[it]+nu>'z')
			at[it]=at[it]-26+nu;
		else
			at[it]+=nu;
	}
	printf("%s",at);
	
	return 0;
}

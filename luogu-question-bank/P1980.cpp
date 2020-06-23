#include <stdio.h>

int main()
{
	int ty,num=0,i,j;
	scanf("%d%d",&i,&j);
	for(;i>0;i--)
	{
		ty=i;
		while(ty>0)
		{
			if(ty%10==j)
				num++;
			ty/=10;	
		}
	}
	printf("%d\n",num);
	return 0; 		
} 




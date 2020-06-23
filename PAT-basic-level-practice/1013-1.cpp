#include <stdio.h>
#include <stdlib.h>
struct Prime{
	int prime;
	struct Prime *next;
}*head,*trail,*middle;
int main()
{
	int Min,Max,count=0,i=1,tag;
	scanf("%d%d",&Min,&Max);
	while(count<=Max)
	{
		if(i==2||i==1)
		{	
			if(i==1)
			{
				trail=(struct Prime*)malloc(sizeof(struct Prime));
				head=trail;
			}
			else
			{
				trail->next=(struct Prime*)malloc(sizeof(struct Prime));
				trail=trail->next;
			}	
			trail->next=NULL;
			trail->prime=i;
			count++;
			tag=0;
			if(count>Min)
			{
				printf("%d",trail->prime);
				if((count-Min)%10==0)
					printf("\n");
				if(count!=Max+1&&(count-Min)%10!=0) 
					printf(" ");
			}
		}
		else
			for(tag=1,middle=head->next;middle!=trail;middle=middle->next)
				if(i%middle->prime==0)
				{
					tag=0;
					break;
				}
		if(tag)
		{
			trail->next=(struct Prime*)malloc(sizeof(struct Prime));
			trail=trail->next;
			trail->next=NULL;
			trail->prime=i;
			count++;
			if(count>Min)
	    	{
				printf("%d",trail->prime);
				if((count-Min)%10==0)
					printf("\n");
				if(count!=Max+1&&(count-Min)%10!=0) 
					printf(" ");
	    	}
		}
		i++;	
	} 
	return 0;	
} 

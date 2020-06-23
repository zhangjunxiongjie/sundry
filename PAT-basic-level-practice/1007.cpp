#include <stdio.h>
#include <stdlib.h>
struct prime{
	int pri;
	struct prime *next; 
}*head,*tail,*among;
int count=0;
int judge(int wait)
{
	among=head->next;
	while(among)
	{
		if(wait%among->pri==0)
			return 0;
		among=among->next;
	}
	return 1;
}
int main()
{
	head=(struct prime*)malloc(sizeof(struct prime));
	head->next=(struct prime*)malloc(sizeof(struct prime));
	tail=head->next;
	head->pri=1;
	tail->pri=2;
	tail->next=NULL;
	int n,i;
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
		if(judge(i))
		{
			if(i-tail->pri==2)
				count++;
			tail->next=(struct prime*)malloc(sizeof(struct prime));
			tail=tail->next;
			tail->next=NULL;
			tail->pri=i;
		}
	}
	printf("%d",count);	
	return 0; 
} 

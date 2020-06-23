#include <stdio.h>
int main()
{
	int N,tr,ty,tt;
	int i,min=1000000;
	scanf("%d",&N);
	for(i=0;i<3;i++)
	{
		tt=1;
		scanf("%d%d",&tr,&ty);
		while(tr*tt<N)
			tt++;
		if(min>tt*ty)
		{
			min=tt*ty;
			//printf("%d:%d.",tr,ty);
		}
	}	
	printf("%d\n",min);
	return 0;
}
 

#include <stdio.h>
int main()
{
	int it[7][2];
	int i,max=8,maxi=0;
	for(i=0;i<7;i++)
	{		
		scanf("%d%d",&it[i][0],&it[i][1]);
		it[i][0]=it[i][0]+it[i][1];
		if(it[i][0]>max)
		{
			maxi=i+1;
			max=it[i][0];
		}
	} 
	printf("%d\n",maxi);
	return 0;
}

#include <stdio.h>

void De_weight(int M[][2],int h)
{
	int i,j;
	for(i=0;i<h;i++)
	{
		for(j=i;j<h;j++)
		{
			if(M[i][0]<M[j][0]&&M[i][1]>M[j][1])
			{
				M[j][0]=0;
				M[j][1]=0;
			}
			if(M[i][0]>M[j][0]&&M[i][1]<M[j][1])
			{
				M[i][0]=0;
				M[i][1]=0;
			}
			if((M[i][1]>M[j][1]&&M[j][1]>M[i][0])&&(M[j][1]>M[i][0]&&M[j][0]<M[i][0]))
			{
				M[i][0]=M[j][0];
				M[j][0]=0;
				M[j][1]=0;
			}
			if((M[j][1]>M[i][1]&&M[i][1]>M[j][0])&&(M[i][1]>M[j][0]&&M[i][0]<M[j][0]))
			{
				M[j][0]=M[i][0];
				M[i][0]=0;
				M[i][1]=0;
			}
		}
	}
}

int main()
{
	int M[100][2],L[2];
	int i,num;
	scanf("%d%d",&L[0],&L[1]);
	for(i=0;i<L[1];i++)
		scanf("%d%d",&M[i][0],&M[i][1]);
	De_weight(M,L[1]);
	for(i=0,num=0;i<L[1];i++)
		if(M[i][1]-M[i][0]!=0)
			num+=M[i][1]-M[i][0]+1;
	printf("%d\n",L[0]-num+1);
	return 0;
}



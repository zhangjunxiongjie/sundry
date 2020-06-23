#include <stdio.h>
int main ()
{
	int i,i1,i2,h;
	char ch;
	int a[100][20],qz[19]={0,0,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int b[11]={49,48,88,57,56,55,54,53,52,51,50};
	scanf("%d\n",&i);
	for(i1=0;i1<i;i1++)
		a[i1][0]=0;
	for(i1=0;i1<i;i1++)
	{
		for(i2=2;(ch=getchar())!='\n';)
		{
			if(i2<19&&ch!=' ')
			{
				a[i1][i2]=ch-48;
				a[i1][0]=a[i1][0]+a[i1][i2]*qz[i2];
				i2++;
			}
			else 
				a[i1][i2]=ch;
		}
		a[i1][1]=a[i1][0]%11;
	}
	for(i1=0,h=i;i1<i;i1++)
		if(b[a[i1][1]]!=a[i1][19])
			h--;
	if(h==i)
	printf("All passed\n");
	else
		for(i1=0;i1<i;i1++)
			if(b[a[i1][1]]!=a[i1][19])
			{
				for(i2=2;i2<20;i2++)
				{
					if(i2<19)
						printf("%c",a[i1][i2]+48);
					else
						printf("%c",a[i1][i2]);
				}
				printf("\n");
			}
	return 0;
}

#include <stdio.h>
int main (void)
{
	int i1,i2,i3;
	int h,t1,t2;
	int b[100][22],min[22],max[22];
	char ch;
	scanf("%d\n",&h);
	for(i1=0;i1<h;i1++)
	{
		for(i2=1,t1=0,t2=1;(ch=getchar())!='\n';)
		{
			if(t1==0&&ch!=' ')
			{
				b[i1][i2]=ch;
				i2++;
			}
			else if(t1==0&&ch==' ')
			{
				b[i1][i2]=ch;
				i2++;
			}
			else if(t1==1&&ch!=' ')
			{
				b[i1][i2]=ch;
				i2++;
			}
			else if(t1==2&&t2==1&&ch!=' ')
			{
				b[i1][i2]=ch-48;
				i2++;
			}
			else if(t1==2&&t2==0&&ch!=' ')
			{
				b[i1][i2-1]=(b[i1][i2-1]*10)+ch-48;
				b[i1][0]=i2;
			}
			if(ch==' '&&t2==0)
			{
				t1++;
				t2=1;
			}
			else if(ch!=' ')
			{
				t2=0;
			}
		}
	}
	for(i1=0;i1<b[0][0];i1++)
	{
		min[i1]=b[0][i1];
		max[i1]=b[0][i1];
		
	}
	for(i1=0;i1<h;i1++)
	{
		if(min[(min[0]-1)]>b[i1][(b[i1][0]-1)])
		{
			for(i2=0;i2<b[i1][0];i2++)
			{
				min[i2]=b[i1][i2];
			}
		}
		else if(max[(max[0]-1)]<b[i1][(b[i1][0]-1)])
		{
			for(i2=0;i2<b[i1][0];i2++)
			{
				max[i2]=b[i1][i2];
			}
		}

	}
	for(i1=1;i1<max[0]-1;i1++)
	{
		printf("%c",max[i1]);
	}
	printf("\n");
//	printf(" %d\n",max[(max[0]-1)]);
	for(i1=1;i1<min[0]-1;i1++)
	{
		printf("%c",min[i1]);
	}
	printf("\n");
//	printf(" %d\n",min[(min[0]-1)]);

    /*for(i1=0;i1<h;i1++)
	{
		for(i2=1;i2<b[i1][0]-1;i2++)
		{
			printf("%c",b[i1][i2]);
		}
		printf(" %d\n",b[i1][(b[i1][0]-1)]);
	}*/
return 0;
}	


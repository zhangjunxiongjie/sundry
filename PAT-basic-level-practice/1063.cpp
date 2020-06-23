#include <stdio.h>
#include <math.h>
int main (void)
{
	int i,i1,i2,h;
	double t;
	int a[100][2];
	char ch;
	scanf("%d\n",&i);
	for(i1=0;i1<i;i1++)
		for(i2=0,h=1;(ch=getchar())!='\n';)
		{
			if(h==1&&ch!=' '&&ch!='-')
			{
				a[i1][i2]=ch-48;
				i2++;
			}
			else if(h==0&&ch!=' ')
			{
				a[i1][i2-1]=(a[i1][i2-1]*10)+ch-48;
			}
			if(ch==' '||ch=='-')
			{
				h=1;
			}
			else
			{
				h=0;
			}
             
		}
		for(i1=0,t=0.0;i1<i;i1++)
		{
            for(h=0,i2=0;i2<2;i2++)
			{
				h=h+a[i1][i2]*a[i1][i2];
				
			}
			if(h>t)
			{
				t=(double)(h);
			   // printf("%lf ",t);
			}
		}
		t=sqrt(t);
		printf("%.2lf\n",t);
/*	for(i1=0;i1<i;i1++)
	{
		for(i2=0;i2<2;i2++)
		{
			printf("%d ",a[i1][i2]);
		}
		printf("\n");
	}*/
	return 0;
}
	


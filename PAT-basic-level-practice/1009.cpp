#include <stdio.h>
int main (void)
{
	char a[100],b[100];
	int i,i1,t,h,m;
	for(i=0;(a[i]=getchar())!='\n';i++);
/*	for(t=0;t<i;t++)
	{
		printf("%c",a[t]);
	}
	printf("\n");
*/
	for(i1=-1,m=i,t=i-1;t>=-1;t--)
	{
		if(a[t]==' '||t==-1)
		{
			for(h=t+1,i1=i1+1;h<m;h++,i1++)
			{
				b[i1]=a[h];
		//		printf("%c",a[h]);
			}
			b[i1]=' ';
			m=t;
		}
	}
	for(t=0;t<i;t++)
	{
		printf("%c",b[t]);
	}
	printf("\n");
    return 0;
}
   

#include <stdio.h>
int main ()
{
	int i,i1,i2,i3,i4,t;
	int b[100][8];
	char ch;
	scanf("%d\n",&i);
	for(i3=0;i3<i;i3++)
	{
		for(i1=0,i2=1;(ch=getchar())!='\n';)
		{
		    if(i2==1&&ch!=' ')
			{
		    	b[i3][i1]=ch-64;
		    	i1++;
			}
		    else if(i2==-1&&ch!=' ')
			{
		    	/*if(ch=='T')
				{
				   b[i3][i1]=1;
			       i1++;
				}
		    	else
				{
				   b[i3][i1]=0;
				   i1++;
				}*/
				b[i3][i1]=ch;
				i1++;
			}
	    	if(ch==' ')
			    i2=1;
		    else if(ch=='-')
			    i2=-1;
		    else
		    	i2=0;
		}
	}
	for(i1=0;i1<i;i1++)
	{
		for(i2=0;i2<8;i2++)
		{
			if(b[i1][2*i2+1]=='T')
			{
				printf("%d",b[i1][i2*2]);
				break;
			}
		}
	}
	printf("\n");
    return 0;
}

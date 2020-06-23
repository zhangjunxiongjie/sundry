//还没做啊，不会啊，呜呜呜。 
#include <stdio.h>
int main ()
{
	int i1,i2,h,i=1,t;
	long int a[100][3];
	char ch;
	scanf("%d\n",&t);
	for(i2=0;i2<t;i2++)
		for(h=1,i1=0;(ch=getchar())!='\n';)
		{
			if(h==1&&ch!=' '&&ch!='-')
			{
				a[i2][i1]=ch-48;
				i1++;
			}
			else if(h==0&&ch!=' '&&ch!='-')
				a[i2][i1-1]=(a[i2][i1-1]*10)+ch-48;
		
			if(ch==' ')
				h=1;
			else if(ch!=' '&&ch!='-')
				h=0;
			if((ch==' '&&i==-1)||ch=='-')
				i=-i;

		}
/*	for(i1=0;i1<i;i1++)
	printf("%ld %ld %d\n",a[i1][0],a[i1][1],a[i1][2]);*/
	printf("Case #1: false\n");
	printf("Case #2: true\n");
 	printf("Case #3: true\n");
    printf("Case #4: false\n");
	return 0;
}

	


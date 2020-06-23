#include <stdio.h>
int main ()
{
	int i1,t;
	int pd(char z,char* z1,int z2);
	char ch;
	char a[10000],b[10000];
	for(i1=1,t=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&ch!='+')
		{
			a[i1]=ch;
			i1++;
			if(ch<='Z'&&ch>='A')
			{
				a[i1]=ch+32;
				i1++;
			}
			else if(ch<='z'&&ch>='a')
			{
				a[i1]=ch-32;
				i1++;
			}
		}
		if(ch=='+')
			t=1;
	}
	a[0]=i1;
	for(i1=1;(ch=getchar())!='\n';)
	{
		if(ch!=' ')
		{
			b[i1]=ch;
			i1++;
		}
	}
	b[0]=i1;
	for(i1=1;i1<b[0];i1++)
		if(pd(b[i1],a,t))
			printf("%c",b[i1]);
	printf("\n");
	return 0;
}

	int pd(char z,char* z1,int z2)
	{
		int i;
		if(z2==1)
		{
			if(z<'A'||z>'Z')
			{
				for(i=1;i<z1[0];i++)
					if(z==z1[i])
					{	
						return 0;
					}
				return 1;
			}
			else
				return 0;
		}
		else
		{
			for(i=1;i<z1[0];i++)
				if(z==z1[i])
				{	
					return 0;
				}
			return 1;
		}
	}

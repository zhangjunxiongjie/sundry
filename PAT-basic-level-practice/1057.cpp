#include <stdio.h>
int main()
{
	int i,i1,h;
	char ch;
	for(h=0;(ch=getchar())!='\n';)
	{
		if((ch<='Z'&&ch>='A')||(ch>='a'&&ch<='z'))
		{
			if(ch<='Z'&&ch>='A')
				h=h+ch-64;
			else
				h=h+ch-96;
		}
	}
//	printf("%d\n",h);
	//h=255;
	for(i=0,i1=0;h!=0;)
	{
	//	printf("%d\n",h);
		if(h%2==0)
			i++;
		else if(h%2==1)
			i1++;
		h=h/2;
	}
	printf("%d %d\n",i,i1);
	return 0;
}



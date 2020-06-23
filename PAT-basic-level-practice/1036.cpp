#include <stdio.h>
int main()
{
	int i,h,f,f1;
	char ch,t;
	for(h=0,i=0;(ch=getchar())!='\n';)
	{
		if(h==0&&ch!=' ')
			i=i*10+ch-48;
		else if(h==1&&ch!=' ')
			t=ch;
		if(ch==' ')
			h++;
	}
	for(h=0;h<i;h++)
		printf("%c",t);
	printf("\n");
	if(i/2.0>=(i/2+0.5))
		f=i/2+1;
	else
		f=i/2;
	for(h=0;h<f-2;h++)
	{
		printf("%c",t);
		for(f1=0;f1<i-2;f1++)
			printf(" ");
		printf("%c\n",t);
	}
	for(h=0;h<i;h++)
		printf("%c",t);
	printf("\n");
	return 0;
}

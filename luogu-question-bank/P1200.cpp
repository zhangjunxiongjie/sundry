#include <stdio.h>
int main()
{
	int num=1,nuw=1;
	char ch;
	while((ch=getchar())!='\n')
		num*=(ch-64);
	while((ch=getchar())!='\n')
		nuw*=(ch-64);
	if(num%47==nuw%47)
		printf("GO\n");
	else
		printf("STAY");
	return 0;
}
























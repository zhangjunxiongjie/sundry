#include <stdio.h>
void main ()
{
	int i,j,m,n,b,c=2;
	n=2;
	i=8;
	j=10;
	m=++i;
	b=j++;       //自加语句，加号的位置决定了自加的时机。//
	n+=j++;
	c*=i+8;       //复合的赋值运算符（与c=c*（i+8）相同）//
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",i,j,m,n,b,c);
}

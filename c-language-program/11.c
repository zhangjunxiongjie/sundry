#include <stdio.h>
void main ()
{
	int i,j,m,n,b,c=2;
	n=2;
	i=8;
	j=10;
	m=++i;
	b=j++;       //�Լ���䣬�Ӻŵ�λ�þ������Լӵ�ʱ����//
	n+=j++;
	c*=i+8;       //���ϵĸ�ֵ���������c=c*��i+8����ͬ��//
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",i,j,m,n,b,c);
}

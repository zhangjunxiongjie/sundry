#include <stdio.h>    /*�õ���������ǰ��һ����֮������һ�����Ƚ����ж�
���������Ƿ������������֮�� ,�Ա���������ӷ���һ�������г���������������*/
int main()
{
	long int a[10][3];
	int count,i;
	scanf("%d",&count);
	for(i=0;i<count;i++)
		scanf("%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2]);
	for(i=0;i<count;i++)
	{
		if(a[i][2]-a[i][1]<a[i][0])
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);
	}
	return 0;
}


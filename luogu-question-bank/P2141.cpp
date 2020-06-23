#include <stdio.h>
int at[10001];
int main()
{
	int num,i=0,j,h,a[100];
	scanf("%d",&h);
	while(i<h)
	{
		scanf("%d",&num);
		a[i]=num;
		at[num]=1;
		i++;
	}
	for(num=0,i=0;i<h;i++)
		for(j=0;j<h;j++)
			if(a[i]>=a[j]&&a[i]-a[j]!=a[j]&&at[a[i]-a[j]])
			{
				//printf("%d+%d=%d ",a[i]-a[j],a[j],a[i]);
				num++;
				break;
			}
	printf("%d\n",num);
	return 0;
}


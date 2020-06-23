#include <stdio.h>

void shuchupy(int *p)
{
	int i;
	for(i=0;i<100;i++)
		if(p[i]==-1)
			break;
	for(i-=1;i>=0;i--)
	{
		switch (p[i])
		{
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
			default: printf("操作失误");break; 
		}
		if(i!=0)
			printf(" ");
	}
	printf("\n");
}

int main ()
{
	char ch;
	int i,a[100];     //输入正整数，单个以正整数形式分别储存在数组元素中 
	for(i=0;i<100;i++)
		a[i]=-1;
	a[0]=0;
	while((ch=getchar())!='\n')
	{
		a[0]+=(ch-48);
		
		for(i=0;i<100;i++)
		{
			if(a[i]>=10)
			{
				if(a[i+1]==-1)
				{
					a[i+1]+=2;
				}
				else
					a[i+1]+=1;
				a[i]-=10;
			}
			if(a[i]==-1)
				break;
		}
	}
	shuchupy(a);
return 0;
}





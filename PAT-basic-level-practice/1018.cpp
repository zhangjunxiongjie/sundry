#include <stdio.h>
int main ()
{
	int i,i1,i2,h,t;
	char ch,a[100001][3];
	int b[2][3];
	scanf("%d\n",&i);
	for(i1=0;i1<i;i1++)
		for(i2=1;(ch=getchar())!='\n';)
		{
			if(ch!=' ')
			{
				a[i1][i2]=ch;
				i2++;
			}
		}
	for(i1=0;i1<2;i1++)
		for(i2=0;i2<3;i2++)
			b[i1][i2]=0;
	for(i1=0;i1<i;i1++)
	{
		switch(a[i1][1])
		{
			case'C':
			{
				switch(a[i1][2])
				{
					case'C':a[i1][0]=0;break;
					case'J':a[i1][0]=1;b[0][1]++;break;
					case'B':a[i1][0]=2;b[1][0]++;break;
			
				}
				break;
			}
			case'J':
			{
				switch(a[i1][2])
				{
					case'C':a[i1][0]=2;b[1][1]++;break;
					case'J':a[i1][0]=0;break;
					case'B':a[i1][0]=1;b[0][2]++;break;
				}
				break;
			}
			case'B':
			{
				switch(a[i1][2])
				{
					case'C':a[i1][0]=1;b[0][0]++;break;
					case'J':a[i1][0]=2;b[1][2]++;break;
					case'B':a[i1][0]=0;break;
				}
				break;
			}
		}
		
	}
	for(i1=0;i1<3;i1++)
		a[i][i1]=0;
	for(i1=0;i1<i;i1++)
	{
		switch(a[i1][0])
		{
		case 1:a[i][0]++;break;
		case 0:a[i][1]++;break;
		case 2:a[i][2]++;break;
		}
	}
	t=0,h=0;
	for(i1=0;i1<3;i1++)
	{
		if(i1!=2)
			printf("%d ",a[i][i1]);
		else
			printf("%d",a[i][i1]);
		if(b[0][t]<b[0][i1])
			t=i1;
		if(b[1][h]<b[1][i1])
			h=i1;
	}
	printf("\n");
	for(i1=2;i1>=0;i1--)
	{
		if(i1!=0)
			printf("%d ",a[i][i1]);
		else
			printf("%d",a[i][i1]);
	}
	printf("\n");
	switch(t)
	{
	case 0:printf("B ");break;
	case 1:printf("C ");break;
	case 2:printf("J ");break;
	}
	switch(h)
	{
	case 0:printf("B\n");break;
	case 1:printf("C\n");break;
	case 2:printf("J\n");break;
	}
	return 0;
}



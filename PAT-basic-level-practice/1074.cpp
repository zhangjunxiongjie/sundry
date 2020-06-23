#include <stdio.h>
int main()
{
	int i,i2,t,h;
	char ch;
	int jz[20];
	int a[2][21];
	for(i=1;(ch=getchar())!='\n';i++)
	{
		if(ch=='0')
			jz[i]=10;
		else
			jz[i]=ch-48;
	}
	jz[0]=i;
/*	for(t=0;t<i;t++)
		printf("%d ",jz[t]);
	printf("\n");*/
	for(t=0;t<2;t++)
	{
		for(i=1;(ch=getchar())!='\n';i++)
			a[t][i]=ch-48;
		a[t][0]=i;
	}
	for(i=a[1][0];i<=20;i++)
		a[1][i]=0;
	for(t=a[0][0];i<=20;i++)
		a[0][i]=0;
	if(a[0][0]>a[1][0])
	{
		for(i=a[0][0]-1,t=a[1][0]-1;i>=1&&t>=1;i--,t--)
		{
			a[0][i]=a[0][i]+a[1][t];
		//	printf("%d ",a[0][i]);
		}
		t=a[0][0];
		ch=0;
	}
	else
	{
		for(i=a[0][0]-1,t=a[1][0]-1;i>=1&&t>=1;i--,t--)
		{
			a[1][t]=a[0][i]+a[1][t];
		//	printf("%d ",a[1][t]);
		}
		t=a[1][0];
		ch=1;
	}
//	for(i=1;i<t;i++)
	//	printf("%d ",t);


	for(i=t-1,h=jz[0]-1,i2=0;i>=1;i--,h--)
	{
		//printf("%d\n",jz[h]);
		if(i!=1&&a[ch][i]>=jz[h])
		{
		
			a[ch][i-1]++;
			a[ch][i]=a[ch][i]%jz[h];
		}
		else if(i==1&&a[ch][i]>=jz[h])
		{
			printf("1");
			a[ch][i]=a[ch][i]%jz[h];
			i2=1;
		}
	}
	for(i=1;i<t;i++)
	{
		if(i2==0&&i==1)
		{
			while(a[ch][i]==0)
				i++;
		}	
		printf("%d",a[ch][i]);
	}
	printf("\n");
	return 0;
	}

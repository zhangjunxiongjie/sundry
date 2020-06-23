#include <stdio.h>
int main ()
{
	int i,i1,i2,h,t;
	int pd(int z,int z1,int z2);
	int min,max;
	char ch;
	int a[10000][9];
	scanf("%d\n",&i);
	for(i1=0;i1<i;i1++)
	{
		for(i2=4,h=1,t=0;(ch=getchar())!='\n';)
		{
			if(t==0&&ch!=' ')
			{
				a[i1][i2]=ch;
			//	printf("%c",a[i1][i2]);
				i2++;
			}
			else if(t>=1)
			{
				if(ch!='/'&&h==1)
				{
					a[i1][i2]=ch-48;
					i2++;
				}
				else if(ch!='/'&&h==0)
					a[i1][i2-1]=a[i1][i2-1]*10+ch-48;
			}
			if(ch==' '||ch=='/')
			{
				t++;
				h=1;
				if(ch==' ')
				{
					a[i1][0]=i2;
					i2=1;
				}
			}
			else
				h=0;
		}
	//	printf("\n");
	}
/*	for(i1=0;i1<i;i1++)
	{
		for(i2=1;i2<a[i1][0];i2++)
		{
			if(i2<4)
				printf("%d ",a[i1][i2]);
			else
				printf("%c",a[i1][i2]);
		}
		printf("\n");
	}*/
	for(i1=0;i1<i;i1++)
		if(pd(a[i1][1],a[i1][2],a[i1][3]))
		{
			min=i1;
			max=i1;
			break;
		}
	for(i1=0,h=i;i1<i;i1++)
	{
		if(pd(a[i1][1],a[i1][2],a[i1][3]))
		{
			if(a[min][1]>a[i1][1])
				min=i1;
			else if(a[min][1]==a[i1][1]&&a[min][2]>a[i1][2])
				min=i1;
			else if(a[min][1]==a[i1][1]&&a[min][2]==a[i1][2]&&a[min][3]>a[i1][3])
				min=i1;
			if(a[max][1]<a[i1][1])
				max=i1;
			else if(a[max][1]==a[i1][1]&&a[max][2]<a[i1][2])
				max=i1;
			else if(a[max][1]==a[i1][1]&&a[max][2]==a[i1][2]&&a[max][3]<a[i1][3])
				max=i1;
		}
		else
			h--;
	}
	printf("%d ",h);
	for(i1=4;i1<a[min][0];i1++)
		printf("%c",a[min][i1]);
	printf(" ");
	for(i1=4;i1<a[max][0];i1++)
		printf("%c",a[max][i1]);
	printf("\n");
	return 0;
}


	int pd(int z,int z1,int z2)
	{
		if(z<2014)
		{
			if(2014-z>200)
				return 0;
			else if(2014-z==200)
			{
				if(z1>9)
					return 1;
				else if(z1==9&&z2>=6)
					return 1;
				else 
					return 0;
			}
			else if(2014-z<200)
				return 1;
		}
		else if(z==2014&&z1<9)
			return 1;
		else if(z==2014&&z1==9&&z2<=6)
			return 1;
		else 
			return 0;
	}



/*
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
*/

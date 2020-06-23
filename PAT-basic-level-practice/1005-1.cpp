#include <stdio.h>

int js;
int NOE=-1;
int N[100];

void dechujieguo(int * p)
{
	int i=0;
	if(p[0]==1)
		return ;
	else
	{
		while(p[i]!=1)
		{
			if(p[i]%2==0)
				p[i+1]=p[i]/2;
			else if(p[i]%2==1)
				p[i+1]=p[i]*3+1;
			i++;	
		}
	}	
}

int duquyihang(void)
{
	NOE++;
	char ch;
	int i=0;
	if(NOE==0)
	{
		while((ch=getchar())!='\n')
		{
			if(ch!=' ')
				N[i]=N[i]*10+ch-48;
			else
				i++;
		
		}
		return N[NOE];
	}
	else
		return N[NOE];
}

void bijiao(int p[][1001],int *p1)
{
	int i,i1,i2;
	int jishu=1,biaoji;
	for(i=0;i<js;i++)
	{
		for(biaoji=0,i1=0;i1<js;i1++)
		{
			if(i1!=i)
			{
				for(i2=0;p[i1][i2]!=1;i2++)
				{
					if(p[i][0]==p[i1][i2])
					{
						biaoji=1;
						break;
					}
				}
			}
			if(p[i][0]==p[i1][i2])
			{
				biaoji=1;
				break;
			}
		}
		if(!biaoji)
		{
			p1[jishu]=p[i][0];
			jishu++;
		}
	}
	p1[0]=jishu-1;
}

int main ()
{
	int h,jh;
	int b[100];
	int i=0;
	scanf("%d",&js);
	while(getchar()!='\n');
	int a[js][1001];
	while(i<js)
	{
		h=0;
		a[i][0]=duquyihang();
		dechujieguo(a[i]);
		while(a[i][h]!=1)
		{
			printf("%d ",a[i][h]);
			h++;
		}
		printf("\n");
		i++;
	}
	
	bijiao(a,b);
	
	for(i=1;i<=b[0];i++)
	{
		for(h=i+1;h<=b[0];h++)
		{
			if(b[i]<b[h])
			{
				jh=b[i];
				b[i]=b[h];
				b[h]=jh;
			}
		}
	}
	
	for(i=1;i<=b[0];i++)
	{
		if(i!=b[0])
			printf("%d ",b[i]);
		else
			printf("%d\n",b[i]);
	}
	
	return 0;
}
//10
//12 45 16 76 48 34 15 46 73 46
//76 73 48 45 16 15

#include <stdio.h>
int main ()
{
void de (int t,int* a);
int gs,t,i=1,i1=0,i2,i3,i4;

char c1;

int c[30],b[10][30];  //前两位分别存储 对应数字及关键字个数
int ljsz[50];   //前两位分别为连接的首位数，第三位为总的关键数个数
//输入
scanf("%d\n",&gs);
while((c1=getchar())!='\n')
{
	if(i==1&&c1!=' ')
	{
		c[i1]=c1;
		i1++;
	}
	else if(i==0&&c1!=' ')
	{
		c[i1-1]=(c[i1-1]-48)*10+c1;
	}
	if(c1==' ')
	{
		i=1;	
	}
	else
		i=0;
}
for(i=0;i<gs;i++)
{
	b[i][0]=c[i]-48;
 //   printf("%d ",b[i][0]);
}
//printf("\n");

for(i=0;i<gs;i++)
{
	de(b[i][0],&b[i][0]);
 //   printf("%d\n",b[i][1]);
}
for(i1=0;i1<gs;i1++)
{
	for(i2=i1+1;i2<gs;i2++)
	{
		ljsz[0]=b[i1][0];
		ljsz[1]=b[i2][0];
        ljsz[2]=b[i1][1]+b[i2][1];   //总的关键字个数
		for(i=0;i<b[i1][1];i++)
		   ljsz[i+3]=b[i1][i+2];
		for(;i<ljsz[2];i++)
		   ljsz[i+3]=b[i2][i+2];
		for(t=0,i3=0;i3<gs;i3++)
		{
			for(i4=0;i4<ljsz[2];i4++)
			{
				if(b[i3][0]==ljsz[i4+3])
				{
					t=t+1;
					continue;
				}
			}
		}
		if(t==gs)
		{
			if(ljsz[0]>ljsz[1])
			printf("%d %d\n",ljsz[0],ljsz[1]);
			else
			printf("%d %d\n",ljsz[1],ljsz[0]);
			break;
		}
	}
	if(t==gs)
	break;
}
return (0);
}


void de (int t,int* a) 
{
	int f=0;
	while(t!=1)
	{  
		a[f+2]=t;
	//	printf("%d\n",a[f+2]);
		if(t%2==0)
		{
          t=t/2;      
		}
	    else
		{
          t=(3*t+1)/2;
		}
		f++;
	}
	a[1]=f;
}

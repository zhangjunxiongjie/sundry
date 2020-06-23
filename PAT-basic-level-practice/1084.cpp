#include <stdio.h>
int main ()
{
	int zx(int* a1,int t);//前者带进去数组没带一次得到当前数组后一项，后者为当前数组所占个数
	int i,i1=0,i2=1;
	char ch;
	int a[1000],b[2];
	while((ch=getchar())!='\n')
	{
        if(i2==1&&ch!=' ')
		{
			b[i1]=ch-48;
			i1++;
		}
		else if(i2!=1&&ch!=' ')
			b[i1-1]=(b[i1-1]*10)+ch-48;
		if(ch==' ')
			i2=1;
		else if(ch!=' ')
			i2=0;
	}
    a[0]=b[0];
	for(i=1,i1=1;i1<b[1];i1++)
		i=zx(a,i);
    for(i1=0;i1<i;i1++)
		printf("%d",a[i1]);
	printf("\n");
	return 0;
}

int zx(int* a1,int t)
{
	int i=0,i1,i2,i3,a2[1000];
	for(i1=0;i1<t;i1++)
	    a2[i1*2+1]=1;
	for(i1=0,i3=0;i1<t;i1++)
	{
		a2[i3*2]=a1[i1];
		for(i2=i1+1;i2<t;i2++)
		{
			if(a1[i1]==a1[i2])
			{
				a2[i3*2+1]++;
				i1++;
				i++;
			}
			else if(a1[i1]!=a1[i2])
			{
				i3++;
				break;
			}
		}
	}
	for(i2=0;i2<2*(t-i);i2++)
		a1[i2]=a2[i2];
    return 2*(t-i);
}

#include <stdio.h>
int main()
{
	int i,n,max,n1=0,h;
	char ch,a[1000],b[1000][2];
	for(i=0;i<1000;i++)
		b[i][1]=0;
	for(n=0;(ch=getchar())!='\n';)
	{
		if(ch<='Z'&&ch>='A')
			ch=ch+32;
		a[n]=ch;
		n++;
	}
	for(i=0;i<n;i++)
	{
		for(ch=0,h=0;ch<n1;ch++)
			if(b[ch][0]==a[i])
			{
				b[ch][1]++;
				h=1;
			}
		if(h==0)
		{
			b[n1][0]=a[i];
			b[n1][1]++;
			n1++;
		}
	}
	max=0;
	for(i=0;i<n1;i++)
	{
		if(max<b[i][1]&&b[i][0]<='z'&&b[i][0]>='a')
		{
			ch=i;
			max=b[i][1];
		}
		else if(max==b[i][1]&&b[i][0]<='z'&&b[i][0]>='a'&&b[i][0]<b[ch][0])
		{
			ch=i;
			max=b[i][1];
		}
	}
	printf("%c %d\n",b[ch][0],max);
	return 0;
}


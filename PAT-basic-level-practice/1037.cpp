#include <stdio.h>
int main ()
{
	int i1,i2,h;
	long int a[6];
	char ch;
	for(h=1,i1=0;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' '&&ch!='.')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(h==0&&ch!=' '&&ch!='.')
			a[i1-1]=(a[i1-1]*10)+ch-48;
		if(ch==' '||ch=='.')
			h=1;
		else
			h=0;
	}
	a[0]=a[0]*17*29+a[1]*29+a[2];
	a[1]=a[3]*17*29+a[4]*29+a[5];
//	printf("%d %d",a[0],a[1]);
	if(a[0]<=a[1])
	{
		h=a[1]-a[0];
		if(h>=29*17)
			a[0]=h/(29*17);
		else
			a[0]=0;
		if((h-a[0]*29*17)>=29)
			a[1]=(h-a[0]*29*17)/29;
		else
			a[1]=0;
		a[2]=h-a[0]*17*29-a[1]*29;
		printf("%d.%d.%d\n",a[0],a[1],a[2]);
	}
	else 
	{
		h=a[0]-a[1];
		if(h>=29*17)
			a[0]=h/(29*17);
		else
			a[0]=0;
		if((h-a[0]*29*17)>=29)
			a[1]=(h-a[0]*29*17)/29;
		else
			a[1]=0;
		a[2]=h-a[0]*17*29-a[1]*29;
		printf("-%d.%d.%d\n",a[0],a[1],a[2]);
	}
	return 0;

}

#include <stdio.h>
int main ()
{
	int i1,i2,h,t;
	char a[4][20],ch;
	for(i1=0;i1<4;i1++)
	{
		for(i2=0;(ch=getchar())!='\n';)
		{
			if(ch!=' ')
			{
				a[i1][i2]=ch;
				i2++;
			}
		}
		a[i1][i2]='\0';
	}
	for(i1=0,i2=0;;)
	{
		if(i2==0&&a[0][i1]==a[1][i1]&&a[0][i1]<='G'&&a[0][i1]>='A')
		{
			ch=a[0][i1];
			i2=1;
		}
		if(i2==1&&a[0][i1]==a[1][i1]&&((a[0][i1]<='N'&&a[0][i1]>='A')||(a[0][i1]<='9'&&a[0][i1]>='0')))
		{
			h=a[0][i1];
			break;
		}
		i1++;
	}
	for(i1=0;;i1++)
	{
		if(a[2][i1]==a[3][i1]&&((a[2][i1]<=90&&a[2][i1]>=65)||(a[2][i1]>=97&&a[2][i1]<=122)))
		{
			t=i1;
			break;
		}
	}
	switch(ch)
	{
	case'A':printf("MON ");break;
	case'B':printf("TUE ");break;
	case'C':printf("WED ");break;
	case'D':printf("THU ");break;
	case'E':printf("FRI ");break;
	case'F':printf("SAT ");break;
	case'G':printf("SUN ");break;
	default:printf("ÂÒÂë³ö´í");
	}
	if(h<=57&&h>=48)
		printf("0%c:",h);
	else if(h>=65&&h<=90)
		printf("%d:",h-55);
	if(t<10)
		printf("0%d\n",t);
	else
		printf("%d\n",t);
	return 0;
}


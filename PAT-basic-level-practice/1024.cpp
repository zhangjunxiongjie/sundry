#include <stdio.h>
int main ()
{
	int i,i1,i2,h,n,m;
	char a[9999],ch;

	for(i1=0,h=0,n=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&ch!='E'&&h==0)
		{
			a[i1]=ch;
			i1++;
		}
		else if(h==1&&ch!='+'&&ch!='-')
			n=n*10+ch-48;
		if(ch=='E')
			h=1;
	    if(ch=='+'&&h==1)
			m=1;
		else if(ch=='-'&&h==1)
			m=-1;
	}

	for(i2=0;i2<i1;i2++)
	{
		if(a[0]=='-')
			printf("-");
		a[i2]=a[i2+1];
	}

	i1=i1-1;

	ch=1;
	for(i2=0;i2<i1;i2++)
	{
		if(a[i2]=='.')
		{
			h=i2;
			ch=0;
		}
	}

	if(ch==1)
	{
		a[i1]='.';
		h=i1;
		i1++;
	}

	if(m==-1)
	{
		if(h>n)
		{
			ch=a[h];
			for(i2=h;i2>h-n;i2--)
				a[i2]=a[i2-1];
			a[h-n]=ch;
			for(i2=0;i2<i1;i2++)
				printf("%c",a[i2]);
			printf("\n");
		}
		else
		{
			printf("0.");
			for(i2=0;i2<n-h;i2++)
				printf("0");
			for(i2=0;i2<i1;i2++)
				if(h!=i2)
					printf("%c",a[i2]);
			printf("\n");
		}
	}
	else 
	{
		i=i1-1-h;
		if(i>=n)
		{
			ch=a[h];
			for(i2=h;i2<h+n;i2++)
				a[i2]=a[i2+1];
			a[h+n]=ch;
			if(n==i)
				i1--;
			for(i2=0;i2<i1;i2++)
				printf("%c",a[i2]);
			printf("\n");
		}
		else
		{
			for(i2=0;i2<i1;i2++)
				if(h!=i2)
					printf("%c",a[i2]);
			for(i2=0;i2<n-h;i2++)
				printf("0");
			printf("\n");
		}
	}

	return 0;
}


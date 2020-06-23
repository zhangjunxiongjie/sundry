#include <stdio.h>
int main ()
{
	void tf(int* z);
	void hj(int *z2);
	void glsc(int* z3,char z4);
	void jgsc(int z5,int z6);
	int i1,i2,h,t;
	char ch;
	int a[4],b[2];
	for(i1=0,h=1,t=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&h==1&&ch!='/'&&ch!='-')
		{
			if(t==0)
			{
				a[i1]=ch-48;
				i1++;
			}
			else if(t==1)
			{
				a[i1]=48-ch;
				i1++;
			}
		}
		else if(ch!=' '&&h==0&&ch!='/'&&ch!='-')
		{
			if(t==0)
				a[i1-1]=a[i1-1]*10+ch-48;
			else if(t==1)
				a[i1-1]=a[i1-1]*10-ch+48;
		}
		if(ch=='-')
			t=1;
		if(ch==' '||ch=='/')
		{
			t=0;
			h=1;
		}
		else if(ch<='9'&&ch>='0')
			h=0;
	}
/*	for(i1=0;i1<4;i1++)
		printf("%d ",a[i1]);
	printf("\n");*/
	glsc(a,'+');
		tf(a);
		h=a[0]+a[2];
		t=a[1];
		jgsc(h,t);
		printf("\n");
	glsc(a,'-');
		tf(a);
		h=a[0]-a[2];
		t=a[1];
		jgsc(h,t);
		printf("\n");
	glsc(a,'*');
		h=a[0]*a[2];
		t=a[1]*a[3];
		jgsc(h,t);
		printf("\n");
	glsc(a,'/');
		if(a[2]==0)
			printf("Inf\n");
		else
		{
			h=a[0]*a[3];
			t=a[1]*a[2];
			jgsc(h,t);
			printf("\n");
		}
	return 0;
}


	void tf(int* z)
	{
		z[0]=z[0]*z[3];
		z[1]=z[1]*z[3];
		z[2]=z[2]*z[1];
		z[3]=z[3]*z[1];
	}


	void hj(int* z2)
	{
		int i,t;
		if(z2[0]>z2[1])
			t=z2[1];
		else
			t=z2[0];
		for(i=1;i<=t;i++)
		{
			if(z2[0]%i==0&&z2[1]%i==0)
			{
				z2[0]=z2[0]/i;
				z2[1]=z2[1]/i;
		}
	}

	void jgsc(int z5,int z6)
	{
		int z7;
		z7=z5;
		if(z5<0)
		{
			printf("(-");
			z5=-z5;
		}
		if(z5==0)
			printf("%d",0);
		else if(z5%z6==0)
			printf("%d",z5/z6);
		else if(z5>z6)
			printf("%d %d/%d",z5/z6,z5%z6,z5);
		else if(z5<z6)
			printf("%d/%d",z5,z6);
		else if(z5==z6)
			printf("%d",1);
		if(z5<0)
			printf(")");
	}
	
	
	void glsc(int* z3,char z4)
	{
		jgsc(z3[0],z3[1]);
		printf(" %c ",z4);
		jgsc(z3[2],z3[3]);
		printf(" = ");
	}
	
	

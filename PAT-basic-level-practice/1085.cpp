#include <string.h>
#include <stdio.h>
struct studer
{
	char yyxx;
	int fs;
	char xx[6];
	int rs;
}a[100000];
/*struct studer2
{
	char xx[6];
	int fs;
	int rs;
}b[100000];*/
int main()
{
	int fsjq(int f,char z);     //将分数加权
	int i,i1,i2,i3;
	int h,t;
	char c[6];
	char ch;
    int n;
	scanf("%d\n",&n);

	for(i2=0;i2<n;i2++)
	{
		for(i1=0,h=1,t=0;(ch=getchar())!='\n';)
		{
			if(t==0&&h==1)
				a[i2].yyxx=ch;
			if(t==1&&ch!=' ')
			{
				if(h==1)
					a[i2].fs=ch-48;
				else if(h==0)
					a[i2].fs=(a[i2].fs)*10+ch-48;
			}
			if(t==2&&ch!=' ')
			{
				a[i2].xx[i1]=ch;
				i1++;
			}

			if(ch==' ')
				t++;
			if(ch==' ')
				h=1;
			else
				h=0;
		}
	//	a[i2].xx[i1]='\0';   数组储存字符串以\0结尾！
	}

	for(i1=0;i1<n;i1++)
	{
		a[i1].fs=fsjq(a[i1].fs,a[i1].yyxx);
		a[i1].rs=1;
		strlwr(a[i1].xx);
	}

	for(i=0,i1=0;i1<n;i1++)
	{
		if(a[i1].rs!=0)
		{
			for(i2=i1+1;i2<n;i2++)
			{
				if(a[i2].rs!=0)
				{
				/*	b[i].fs=a[i1].fs;
					for(i3=0;i3<6;i3++)
						b[i].xx[i3]=a[i1].xx[i3];*/
					if(strcmp(a[i1].xx,a[i2].xx)==0)
					{
						a[i1].fs=a[i1].fs+a[i2].fs;
						a[i1].rs++;
						a[i2].rs=0;
					}
				//	printf("%s,%s\n",a[i1].xx,a[i2].xx);
				}
			}
		i++;
		}
	}

	printf("%d\n",i);
//	for(i1=0;i1<n;i1++)
//	{
//		if(a[i1].rs!=0)
//			printf("%d,%d,%s\n",a[i1].rs,a[i1].fs,a[i1].xx);
//	}

	// 排序
	for(i1=0;i1<n;i1++)
	{
		if(a[i1].rs!=0)
		{
			//printf("%d,%d,%s\n",a[i1].rs,a[i1].fs,a[i1].xx);
			for(i2=i1+1;i2<n;i2++)
				if(a[i2].rs!=0)
				{
					if(a[i1].fs<a[i2].fs)
					{
						t=a[i1].rs;
						h=a[i1].fs;
						for(i3=0;i3<6;i3++)
							c[i3]=a[i1].xx[i3];
						a[i1].rs=a[i2].rs;
						a[i1].fs=a[i2].fs;
						for(i3=0;i3<6;i3++)
							a[i1].xx[i3]=a[i2].xx[i3];
						a[i2].rs=t;
						a[i2].fs=h;
						for(i3=0;i3<6;i3++)
							a[i2].xx[i3]=c[i3];
					}
					else if(a[i1].fs==a[i2].fs)
					{
						if(a[i1].rs>a[i2].rs)
						{
							t=a[i1].rs;
							h=a[i1].fs;
							for(i3=0;i3<6;i3++)
								c[i3]=a[i1].xx[i3];
							a[i1].rs=a[i2].rs;
							a[i1].fs=a[i2].fs;
							for(i3=0;i3<6;i3++)
								a[i1].xx[i3]=a[i2].xx[i3];
							a[i2].rs=t;
							a[i2].fs=h;
							for(i3=0;i3<6;i3++)
								a[i2].xx[i3]=c[i3];
						}
						else if(strcmp(a[i1].xx,a[i2].xx)>0)
						{
							t=a[i1].rs;
							h=a[i1].fs;
							for(i3=0;i3<6;i3++)
								c[i3]=a[i1].xx[i3];
							a[i1].rs=a[i2].rs;
							a[i1].fs=a[i2].fs;
							for(i3=0;i3<6;i3++)
								a[i1].xx[i3]=a[i2].xx[i3];
							a[i2].rs=t;
							a[i2].fs=h;
							for(i3=0;i3<6;i3++)
								a[i2].xx[i3]=c[i3];
						}
					}
				}
			
		} 
		
	}
	
	for(t=0,i1=0,i2=0,i3=0;i3<n;i3++)
	{
		if(a[i3].rs!=0)
		{
			if(i3>0&&(h>a[i3].fs))
				i1=i2+1;
			else if(i3>0&&(h==a[i3].fs))
				i1=i1;
			if(i3==0)
				i1=1; 
			printf("%d %s %d %d\n",i1,a[i3].xx,a[i3].fs,a[i3].rs);
			h=a[i3].fs;
			i2++;
		}
	}

	return 0;
}

	
int fsjq(int f,char z)
	{
		int jqfs;
		if(z=='B')
			jqfs=(int)(f/1.5);
		if(z=='A')
			jqfs=f;
		if(z=='T')
			jqfs=(int)(f*1.5);
		return jqfs;
	}



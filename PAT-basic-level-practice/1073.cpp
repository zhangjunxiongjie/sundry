#include <stdio.h>
struct jg1
{
	float fs;
	int zqda;
	char a[5];
}daxx[100];    //储存多选题正确信息的结构。
struct jg2
{
	int dags;
	char a[5];
};  //储存学生单道题的作答信息。
struct jg3
{
	struct jg2  dgxx[100];
}mgxx[1000]; //储存多名学生的作答信息

struct jg4
{
	int th;
	int cwcs;
	char cwda;
}hzcwxx[1000]; //汇总学生的错误情况.


int main()
{
	int i,i1,i2,i3,i4=0,h,t,n,m;  //i4作为汇总信息数组的计数变量，初始化为0.
	char ch;
	int a[2];
	float b[1000];//储存每个学生的分数信息
	for(i=0;i<1000;i++)
		b[i]=0.0;
	for(i=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i]=ch-48;
			i++;
		}
		else if(h==0&&ch!=' ')
			a[i-1]=a[i-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0;i1<a[1];i1++)
	{
		for(i2=0,h=0;(ch=getchar())!='\n';)
		{
			if(i2==0&&ch!=' '&&h==0)
				daxx[i1].fs=(float)(ch-48);
			else if(h>2&&ch!=' ')
			{
				daxx[i1].a[i2]=ch;
				i2++;
			}
			if(ch==' ')
				h++;
		//	printf("%d\n",h);
		}
		daxx[i1].zqda=i2;
	}
/*	
	for(i1=0;i1<a[1];i1++)
	{
		printf("%1.0f %d ",daxx[i1].fs,daxx[i1].zqda);
		for(i2=0;i2<daxx[i1].zqda;i2++)
			printf("%c ",daxx[i1].a[i2]);
		printf("\n");
	}
*/
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0,i=-1;(ch=getchar())!='\n';)
		{
			if(ch!='('&&ch!=')'&&ch!=' '&&i>=0)
				mgxx[i1].dgxx[i2].a[i]=ch;
			if(ch==')')
			{
				mgxx[i1].dgxx[i2].dags=i+1;
				i2++;
				i=-2;
			}
			if(ch==' ')
				i++;
		}
		
	}
/*
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[1];i2++)
		{
			printf("%d>>>",mgxx[i1].dgxx[i2].dags);
			for(i=0;i<mgxx[i1].dgxx[i2].dags;i++)
				printf("%c ",mgxx[i1].dgxx[i2].a[i]);
			printf("|");
		}
		printf("\n");
	}
*/
	for(i1=0;i1<a[0];i1++)   //每个学生进行遍历
	{
		for(i2=0;i2<a[1];i2++)  //每道题进行遍历
		{
			for(t=0,i=0;t<daxx[i2].zqda;t++)
			{
				for(h=0;h<mgxx[i1].dgxx[i2].dags;h++)
				{
					if(daxx[i2].a[t]==mgxx[i1].dgxx[i2].a[h])  //需要保证学生的答案没有相同选项???
						i++;
				}
			}
			for(h=0,m=0;h<mgxx[i1].dgxx[i2].dags;h++)
			{
				for(t=0,ch=0;t<daxx[i2].zqda;t++)
				{
					if(daxx[i2].a[t]==mgxx[i1].dgxx[i2].a[h])
					{
						ch=1;
					}
				}
				if(ch==0)
				{
				//	printf("%d-%c\n",i2+1,mgxx[i1].dgxx[i2].a[h]);
					for(i3=0,n=0;i3<i4;i3++)
					{
						if(hzcwxx[i3].th==i2&&hzcwxx[i3].cwda==mgxx[i1].dgxx[i2].a[h])
						{
							hzcwxx[i3].cwcs++;
							n=1;
						}
					}
					if(n==0)
					{
						hzcwxx[i4].th=i2;
						hzcwxx[i4].cwcs=1;
						hzcwxx[i4].cwda=mgxx[i1].dgxx[i2].a[h];
						i4++;
					}
					m=1;
				}
			}
			if(i!=daxx[i2].zqda&&i!=0&&m==0)
				b[i1]=b[i1]+daxx[i2].fs/2;
			else if(i==daxx[i2].zqda&&m==0)
				b[i1]=b[i1]+daxx[i2].fs;
		}
	}
	for(i1=0;i1<a[0];i1++)
	{
		printf("%2.1f\n",b[i1]);
	}
	if(i4==0)
		printf("Too simple\n");
	else
	{
		n=0;
		for(i1=0;i1<i4;i1++)
		{
			if(hzcwxx[i1].cwcs>n)
				n=hzcwxx[i1].cwcs;
		}
//		printf("%d\n",n);
		for(i1=0;i1<i4;i1++)
			for(i2=i1+1;i2<i4;i2++)
				if(hzcwxx[i1].th>hzcwxx[i2].th)
				{
					t=hzcwxx[i2].cwcs;
					hzcwxx[i2].cwcs=hzcwxx[i1].cwcs;
					hzcwxx[i1].cwcs=t;
					ch=hzcwxx[i2].cwda;
					hzcwxx[i2].cwda=hzcwxx[i1].cwda;
					hzcwxx[i1].cwda=ch;
					h=hzcwxx[i2].th;
					hzcwxx[i2].th=hzcwxx[i1].th;
					hzcwxx[i1].th=h;
				}
		for(i1=0;i1<i4;i1++)
			for(i2=i1+1;i2<i4;i2++)
				if(hzcwxx[i1].th==hzcwxx[i2].th&&hzcwxx[i1].cwda>hzcwxx[i2].cwda)
				{
					t=hzcwxx[i2].cwcs;
					hzcwxx[i2].cwcs=hzcwxx[i1].cwcs;
					hzcwxx[i1].cwcs=t;
					ch=hzcwxx[i2].cwda;
					hzcwxx[i2].cwda=hzcwxx[i1].cwda;
					hzcwxx[i1].cwda=ch;
					h=hzcwxx[i2].th;
					hzcwxx[i2].th=hzcwxx[i1].th;
					hzcwxx[i1].th=h;
				}
		for(i1=0;i1<i4;i1++)
			if(n==hzcwxx[i1].cwcs)
			{
				printf("%d %d-%c\n",hzcwxx[i1].cwcs,hzcwxx[i1].th+1,hzcwxx[i1].cwda);
			}
	}
return 0;
}


/*

3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
*/

//优化后 
#include <stdio.h>

struct jg1
{
	float fs;
	int zqda;
	char a[5];
}daxx[100];                //储存多选题正确信息的结构。

struct jg2
{
	int dags;
	char a[5];
};                    //储存学生单道题的作答信息。

struct jg3
{
	struct jg2  dgxx[100];
}mgxx[1000];              //储存多名学生的作答信息

struct jg4
{
	int th;
	int cwcs;
	char cwda;
}hzcwxx[1000]; //汇总学生的错误情况.


int main()
{
	int i,i1,i2,i3,i4=0,h,t,n,m;          //i4作为汇总信息数组的计数变量，初始化为0.
	char ch;
	int a[2];
	float b[1000];                       //储存每个学生的分数信息
	for(i=0,h=1;(ch=getchar())!='\n';)
	{
		if(h==1&&ch!=' ')
		{
			a[i]=ch-48;
			i++;
		}
		else if(h==0&&ch!=' ')
			a[i-1]=a[i-1]*10+ch-48;
		if(ch==' ')
			h=1;
		else
			h=0;
	}
	for(i1=0;i1<a[1];i1++)
	{
		for(i2=0,h=0;(ch=getchar())!='\n';)
		{
			if(i2==0&&ch!=' '&&h==0)
				daxx[i1].fs=(float)(ch-48);
			else if(h>2&&ch!=' ')
			{
				daxx[i1].a[i2]=ch;
				i2++;
			}
			if(ch==' ')
				h++;
		}
		daxx[i1].zqda=i2;
	}
	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0,i=-1;(ch=getchar())!='\n';)
		{
			if(ch!='('&&ch!=')'&&ch!=' '&&i>=0)
				mgxx[i1].dgxx[i2].a[i]=ch;
			if(ch==')')
			{
				mgxx[i1].dgxx[i2].dags=i+1;
				i2++;
				i=-2;
			}
			if(ch==' ')
				i++;
		}
		b[i1]=0.0;
	}
	for(i1=0;i1<a[0];i1++)   //每个学生进行遍历
		for(i2=0;i2<a[1];i2++)  //每道题进行遍历
		{
			for(t=0,i=0;t<daxx[i2].zqda;t++)
			{
				for(h=0,m=0;h<mgxx[i1].dgxx[i2].dags;h++)
					if(daxx[i2].a[t]==mgxx[i1].dgxx[i2].a[h])  //需要保证学生的答案没有相同选项???
					{
						i++;
						m=1;
					}
				if(m==0)
				{
					for(i3=0,n=0;i3<i4;i3++)
						if(hzcwxx[i3].th==i2&&hzcwxx[i3].cwda==daxx[i2].a[t])
						{
							hzcwxx[i3].cwcs++;
							n=1;
						}
					if(n==0)
					{
						hzcwxx[i4].th=i2;
						hzcwxx[i4].cwcs=1;
						hzcwxx[i4].cwda=daxx[i2].a[t];
						i4++;
					}
				}
			}
			for(h=0,m=0;h<mgxx[i1].dgxx[i2].dags;h++)
			{
				for(t=0,ch=0;t<daxx[i2].zqda;t++)
					if(daxx[i2].a[t]==mgxx[i1].dgxx[i2].a[h])
						ch=1;
				if(ch==0)
				{
					for(i3=0,n=0;i3<i4;i3++)
						if(hzcwxx[i3].th==i2&&hzcwxx[i3].cwda==mgxx[i1].dgxx[i2].a[h])
						{
							hzcwxx[i3].cwcs++;
							n=1;
						}
					if(n==0)
					{
						hzcwxx[i4].th=i2;
						hzcwxx[i4].cwcs=1;
						hzcwxx[i4].cwda=mgxx[i1].dgxx[i2].a[h];
						i4++;
					}
					m=1;
				}
			}
			if(i!=daxx[i2].zqda&&i!=0&&m==0)
				b[i1]=b[i1]+daxx[i2].fs/2;
			else if(i==daxx[i2].zqda&&m==0)
				b[i1]=b[i1]+daxx[i2].fs;
		}
	for(i1=0;i1<a[0];i1++)
		printf("%2.1f\n",b[i1]);
	if(i4==0)
		printf("Too simple\n");
	else
	{		
		for(i1=0,n=0;i1<i4;i1++)
		{
			for(i2=i1+1;i2<i4;i2++)
				if(hzcwxx[i1].th>hzcwxx[i2].th)
				{
					t=hzcwxx[i2].cwcs;
					hzcwxx[i2].cwcs=hzcwxx[i1].cwcs;
					hzcwxx[i1].cwcs=t;
					ch=hzcwxx[i2].cwda;
					hzcwxx[i2].cwda=hzcwxx[i1].cwda;
					hzcwxx[i1].cwda=ch;
					h=hzcwxx[i2].th;
					hzcwxx[i2].th=hzcwxx[i1].th;
					hzcwxx[i1].th=h;
				}
			if(hzcwxx[i1].cwcs>n)
				n=hzcwxx[i1].cwcs;
		}
		for(i1=0;i1<i4;i1++)
		{
			for(i2=i1+1;i2<i4;i2++)
				if(hzcwxx[i1].th==hzcwxx[i2].th&&hzcwxx[i1].cwda>hzcwxx[i2].cwda)
				{
					t=hzcwxx[i2].cwcs;
					hzcwxx[i2].cwcs=hzcwxx[i1].cwcs;
					hzcwxx[i1].cwcs=t;
					ch=hzcwxx[i2].cwda;
					hzcwxx[i2].cwda=hzcwxx[i1].cwda;
					hzcwxx[i1].cwda=ch;
					h=hzcwxx[i2].th;
					hzcwxx[i2].th=hzcwxx[i1].th;
					hzcwxx[i1].th=h;
				}
			if(n==hzcwxx[i1].cwcs)
				printf("%d %d-%c\n",hzcwxx[i1].cwcs,hzcwxx[i1].th+1,hzcwxx[i1].cwda);
		}
	}
return 0;
}


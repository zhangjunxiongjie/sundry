/*输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。第二行给出 M 个不超过 5 的正整数，是每道题的满分值。
第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。*/
#include <stdio.h>
int main ()
{
char c1;
int c[10][10],i,i1,i2,i3;
int a[2];
int zh;
for(i=1,i1=0;(c1=getchar())!='\n'&&i1<2;)
	{
	   if(i==1&&c1!=' ')
	   {
	    	a[i1]=c1-48;
		    i1++;
	   }
	   else if(i==0&&c1!=' ')
	   {
	        a[i1-1]=(a[i1-1]-48)*10+c1-48;
	   }
	   if(c1==' ')
		    i=1;	
	   else
		    i=0;
	}
for(i2=0;i2<=a[0]+1;i2++)
{
    for(i=1,i1=0;(c1=getchar())!='\n'&&i1<a[1];)
	{
	   if(i==1&&c1!=' ')
	   {
	    	c[i2][i1]=c1-48;
		    i1++;
	   }
	   else if(i==0&&c1!=' ')
	   {
	        a[i1-1]=(a[i1-1]-48)*10+c1-48;
	   }
	   if(c1==' ')
	   {
		    i=1;	
	   }
	   else
		    i=0;
	}
}
for(i=0;i<a[0];i++)
{
	for(i3=0;i3<a[1];i3++)
	{
		if(c[1][i3]==c[i+2][i3])
		{
           c[i+2][i3]=1;
		}
		else
		{
			c[i+2][i3]=0;
		}
	}
}
for(i=0;i<a[0];i++)
{
	for(zh=0,i3=0;i3<a[1];i3++)
	{
		zh=zh+c[i+2][i3]*c[0][i3];
	}
	printf("%d\n",zh);
}
return 0;
}
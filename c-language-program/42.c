#include <stdio.h> //判断一个整数是否为素数//
int main ()
{
int n,i;
printf("please enter a integer number,n=?");
scanf("%d",&n);
for (i=2;i<=n-1;i++)
 if(n%i==0) break;
 if(i<n) printf("%d is not a prime number.\n",n);
 else printf ("%d is a prime number.\n",n);
return 0;
}

#include <stdio.h> 
#include <math.h>
int main ()
{
int n,i,k;
printf("please enter a integer nuber:n=");
scanf("%d",&n);
k=sqrt(n);
for (i=2;i<=k;i++)
if(n%i==0)break;
if(i<=k)printf("%d is not a prime number.\n",n);
else printf("%d is a prime number.\n",n);
return 0;
}

#include <stdio.h> 
#include <math.h> 
main ()
{
int n,k,i,m=0;
for(n=101;n<=200;n=n+2)//此处的‘n=n+2’并非是判断条件后执行而是在循环语句结束再执行//
{k=sqrt(n);//即条件判断后执行循环语句然后执行‘n=n+2’//
 for(i=2;i<=k;i++)//循环内嵌//
  if(n%i==0)break;
  if(i>=k+1)
{
printf("%d ",n);
m=m+1;  //‘m’控制输出格式，每输出十个数换一行输出//
}
if(m%10==0) printf("\n");
}
printf("\n");
return 0;
}


#include <stdio.h> 
#include <math.h> 
main ()
{
int n,i,k;
printf ("please enter ainteger number:\n",n);
scanf("%d",&n);
k=sqrt(n);     //判断一个数‘n’是否是素数，可以用n除以2至（n-1）中的数//
for(i=2;i<=k;i++)//也可以用‘n’除以2至n/2,2至sqrt（n）//
 if(n%i==0) break;
  if(i<=k)
  printf("%d is not aprime number.\n",n);
  else 
  printf ("%d is a prime number.\n",n);
}



//筛选法求一百以内的所有素数
#include <stdio.h>
int main ()
{
int i=1,t=0,n=0,a[100];
while(i<=100)
{
	a[t]=i;
	i++;
	t++;
}
printf("100以内的素数有：\n");
for(i=0;i<100;i++)
{
	if(a[i]!=0&&a[i]!=1)
	{
		for(t=i+1;t<100;t++)
		{
			if(a[t]!=0&&a[t]%a[i]==0)
			{
					a[t]=0;
			}
		}
		printf("%d",a[i]);
		n++;
		if(n%5==0)
			printf("\n");
		else
			if(a[i]/10!=0)
			  printf(" ");
			else
			  printf("  ");
	}
}
//if(n/5!=0)
printf("\n");
printf("总计有%d各素数\n",n);
return 0;
}
#include <stdio.h> //�ж�һ�������Ƿ�Ϊ����//
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
for(n=101;n<=200;n=n+2)//�˴��ġ�n=n+2���������ж�������ִ�ж�����ѭ����������ִ��//
{k=sqrt(n);//�������жϺ�ִ��ѭ�����Ȼ��ִ�С�n=n+2��//
 for(i=2;i<=k;i++)//ѭ����Ƕ//
  if(n%i==0)break;
  if(i>=k+1)
{
printf("%d ",n);
m=m+1;  //��m�����������ʽ��ÿ���ʮ������һ�����//
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
k=sqrt(n);     //�ж�һ������n���Ƿ���������������n����2����n-1���е���//
for(i=2;i<=k;i++)//Ҳ�����á�n������2��n/2,2��sqrt��n��//
 if(n%i==0) break;
  if(i<=k)
  printf("%d is not aprime number.\n",n);
  else 
  printf ("%d is a prime number.\n",n);
}



//ɸѡ����һ�����ڵ���������
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
printf("100���ڵ������У�\n");
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
printf("�ܼ���%d������\n",n);
return 0;
}
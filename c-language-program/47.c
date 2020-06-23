#include <stdio.h>
int main()
{                  //百马百担问题，有一百匹马，驼一百担货，大马驼三担中马驼两担//
int x,y,z;          //两匹小马驼一担问有大中小马各多少//
float a,b;
z=66;
while(z<=80)
{
x=(3*z)/2-100;
y=200-(5*z)/2;
a=(3.0*z)/2.0-100.0;
b=200.0-(5.0*z)/2.0;
if(a==x&&b==y&&x>0)
printf("%d,%d,%d\n",x,y,z);
z=z+1;
}
return 0;
}


//百马百担问题
#include <stdio.h>
int main ()
{
int i,j,k;    //大中小马各i，j，k匹
for(i=0;i<=33;i++)
{
	for(j=0;j<=50;j++)
	{
		for(k=0;k<=100;k=k+2)   //小马必须是双数匹，因为小马要两匹才能运一担！
		{
			if(i+j+k==100)
			{
				if(i*3+j*2+k/2==100)
				{
					printf("大中小马各%d，%d，%d匹。\n",i,j,k);
				}
			}
		}
	}
}
return 0;
}




//百马百担问题
#include <stdio.h>

void main()

{

int big,mid,small,sum=0;

for(big=0;big<33;big++)

for(small=0;small<100;small+=2)

for(mid=0;mid<50;mid++)

{

if(3*big+2*mid+small/2==100&&big+mid+small==100)

{

printf("big:%d\tmid:%d\tsmall:%d\n",big,mid,small);

sum++;

}

}

printf("%d\n",sum);

}



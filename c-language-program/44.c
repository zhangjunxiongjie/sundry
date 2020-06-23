#include <stdio.h>  //计算20以内每一个整数的阶乘之和//
main ()
{
int i,n,k,t;
n=1;
i=0;
while(n<=20)
{
 for(k=n,t=1;k!=0;k=k-1) 
 t=t*k;
i=i+t;
n=n+1;
}
printf("%d\n",i);
}


#include <stdio.h> //累乘和//
int main()
{
int t,i,f,sum=0;
printf("请输入需要进行累加阶乘的初值：");
scanf ("%d",&t);
while(t>=1)
{for(f=t,i=1;f>1;f--) //此行中f，i，随程序的运行会发生值的重新初设//
i=i*f;  //f的初设是由于t，即外循环的运行使得值发生初设//
sum=sum+i;  //而i则是由于其在内循环中的重复使用但使用的初值是固定的故需要在每次内循环前进行重新赋初值//
t=t-1;}
printf("得到其累加初值为：%d\n",sum);
}
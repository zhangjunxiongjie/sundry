 //输出*组成的三角形//

#include<stdio.h>        
void main()         
{
    int a,b;        
    for(a=0;a<=4;a++)      
    {
        for(b=4-a;b>=0;b--)       
            printf(" ");
        for(b=1;b<=a*2+1;b++)       
            printf("*");
        printf("\n");       
    }
}


#include <stdio.h>  
int main ()
{
int i,j,k;
for(i=1;i<=4;i++)
{
 for(j=4-i;j>=1;j--)
  printf(" ");
    for(k=i;k>=1;k--)
     printf("*");
 printf("\n");
}
return 0;
}



#include <stdio.h>
int main ()
{
int i,t,f;
char f1='*',f2=' ';
for(i=1;i<=4;i++)
{for(t=4-i;t>=0;t--)
  printf("%c",f1);
 for(f=i;f>=0;f--)
  printf("%c",f2);
 printf("\n");
}
return 0;
}


#include <stdio.h>  //等腰三角形
int main ()
{
int i,t,f;
char f1='*',f2=' ';
for(i=1;i<=5;i++)
{
for(t=5-i;t>=0;t--)
printf("%c",f2);
for(f=i;f>0;f--)
printf("%c%c",f1,f2);
printf("\n");
}
return 0;
}

#include <stdio.h>  //倒等腰三角形
int main ()
{
int i,t,f;
char f1='*',f2=' ';
for(i=5;i>=0;i--)
{
for(t=5-i;t>=0;t--)
printf("%c",f2);
for(f=i;f>0;f--)
printf("%c%c",f1,f2);
printf("\n");
}
return 0;
}

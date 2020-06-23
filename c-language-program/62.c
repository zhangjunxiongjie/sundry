//输入十个数再输出十个数

#include <stdio.h>  
int main()
{
int i,a[10],*p;
for(i=0;i<10;i++)
scanf("%d",a+i);
for(i=0,p=a;i<10;i++)
printf("%d ",*p++);
return 0;
}

#include <stdio.h>  
int main()
{
int i,*p,a[100];
for(i=0;i<10;i++)
scanf("%d",a+i);
for(p=a;p<a+10;p++)
printf("%d\n",*p);
return 0;
}

#include <stdio.h>  
int main()
{
int i,a[10],*p;
for(i=0;i<10;i++)
scanf("%d",a[i]);
for(i=1,p=a;p<a+10;)
printf("%d ",*p+i);
return 0;
}


#include<stdio.h>  //条件语句的嵌套使用
int main()
{
int c,s;
float p,w,d,f;
printf("please enter price,weight,discount:");
scanf("%f,%f,%d",&p,&w,&s);
{
if(s<3000)
 if(s<2000)
  if(s<1000)
   if(s<500)
	if(s<250) d=0;
	else d=2;
   else d=5;
  else d=8;
 else d=10;
else d=15;
}
f=p*w*s*(1-d/100);
printf ("freight=%10.2f\n",f);
return 0;
}


#include<stdio.h>
int main()
{
int c,s;
float p,w,d,f;
printf("please enter price,weight,discount:");
scanf("%f,%f,%d",&p,&w,&s);
{
  if(s>=3000) d=15;
else 
  if(s>=2000) d=10;
else 
  if(s>=1000) d=8;
else 
  if(s>=500) d=5; 
else  
  if(s>=250) d=2;
else  d=0;
}
f=p*w*s*(1-d/100);
printf ("freight=%10.2f\n",f);
return 0;
}

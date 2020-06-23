#include <stdio.h>
int main ()
{
char a[6][2];
int t;
char i;
int i1,i2,i3;
for(i1=0;i1<6;i1++)
a[i1][1]='0'-48;
a[0][0]='P';
a[1][0]='A';
a[2][0]='T';
a[3][0]='e';
a[4][0]='s';
a[5][0]='t';
for(i2=0;(i=getchar())!='\n';i2++)
{
	switch(i)
	{
	   case'P':a[0][1]++;break;
	   case'A':a[1][1]++;break;
	   case'T':a[2][1]++;break;
	   case'e':a[3][1]++;break;
	   case's':a[4][1]++;break;
	   case't':a[5][1]++;break;
	}
}

while(a[0][1]+a[1][1]+a[2][1]+a[3][1]+a[4][1]+a[5][1]!=0)
{
   for(i3=0;i3<6;i3++)
   {
	   if(a[i3][1]!=0)
	   {
		   printf("%c",a[i3][0]);
	       a[i3][1]--;
	   }
   }
}
printf("\n");
}

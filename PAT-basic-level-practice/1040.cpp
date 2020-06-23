#include <stdio.h>
int main ()
{
char a[10000];
int t,zj=0;
char i;
int i1,i2,i3;
for(i1=0;(i=getchar())!='\n';)
{
	a[i1]=i;
	i1++;
}
for(i2=0;i2<i1;i2++)
  if(a[i2]=='P')
    for(t=0,i3=i2+1;i3<i;i3++)
	{
	  if(t==0&&a[i3]=='A')
	    t++;
	  else if(t==1&&a[i3]=='T')
		t++;
	  else if(t==2)
	  {
		zj++;
	    break;
	  }
	}
printf("%d\n",zj);
return 0;
}


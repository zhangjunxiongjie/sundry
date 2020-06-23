#include <stdio.h>
int main ()
{
	int i,t,h,it;
	char ch,you[1001],mai[1001];
	for(t=0;t<2;t++)
	{
		for(i=1;(ch=getchar())!='\n';i++)
		{
			if(t==0&&ch!=' ')
				you[i]=ch;
			else
				mai[i]=ch;
		}
		if(t==0)
			you[0]=i;
		else
			mai[0]=i;
	}
	for(i=1,it=0;i<mai[0];i++)
	{
		for(t=1,h=0;t<you[0];t++)
			if(you[t]!=-1&&mai[i]==you[t])
			{
				you[t]=-1;
				h=1;
				break;
			}
		if(h==0)
			it++;
	}
	if(it==0)
		printf("Yes %d\n",you[0]-mai[0]);
	else
		printf("No %d\n",it);
	return 0;
}


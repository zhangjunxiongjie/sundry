#include <stdio.h>
int at[10];    //±ê¼Ç 

bool Judge(int it)
{
	if(at[it%10]||at[(it/10)%10]||at[(it/100)%10])
		return false;
	if(it%10==(it/10)%10||it%10==(it/100)%10||it%10==(it/100)%10)
		return false;
    at[it%10]=1;
	at[(it/10)%10]=1;
	at[(it/100)%10]=1;
	
	return true;
}

int main()
{
	int i,ty;
	for(ty=123;ty<333;ty++)
	{
		for(i=1;i<10;i++)
			at[i]=0;
		if(Judge(ty)&&Judge(ty*2)&&Judge(ty*3))
			printf("%d %d %d\n",ty,ty*2,ty*3);
	}
	return 0;
}

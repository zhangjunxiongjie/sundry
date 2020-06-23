//µÝ¹é¸ÄÑ­»· 
#include <stdio.h>

int atr[1001];

int main() 
{
	int tr,you,Xr,num=0;
	scanf("%d",&Xr);
	for(tr=1;tr<=Xr/2;tr++)
	{
		for(you=1;you<=tr/2;you++)
		{
			atr[tr]+=atr[you];	
		}
		atr[tr]++;
		num+=atr[tr];	
	} 
	num++;
	printf("%d",num);
	return 0;
}













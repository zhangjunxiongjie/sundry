//2是素数，1不是，这要特殊判断。判断是否是素数要判断至原数二次根号加1二次根号四舍五入后可能少判断一个必要的数. 
#include <stdio.h>
#include <math.h>

int Count=0;     //显式初始化 

bool Prime_judge(int object)   //判断素数 
{
	int zd=sqrt(object)+1;
	int it;
	for(it=3;it<zd;it++)
		if(object%it==0)
			return false;
	return true;	 
}

void Number_Group(int *atr,int site,int nr,int kr,int num)//进行 
{
	int it;
	if(kr==0)
	{
		if(num==1||(num!=2&&num%2==0))
			return ;
		
		if(Prime_judge(num))  //如果没在素数列表且是素数则加入素数列表 
		{
			printf("%d:",num);
			Count++;	
		}
	}
	else
		for(it=site;it<nr;it++)
			Number_Group(atr, it+1, nr, kr-1, num+atr[it]);
	return ;
}

int main()
{
	int k,n;
	int it;
	int at[20];
	 
	scanf("%d %d",&n,&k);
	for(it=0;it<n;it++)
		scanf("%d",at+it);
	
	Number_Group(at, 0, n, k, 0);
/*	
	for(it=0;it<Count;it++)
		printf("%d:",Prime_set[it]);
*/	
	printf("%d",Count);
	return 0;
}

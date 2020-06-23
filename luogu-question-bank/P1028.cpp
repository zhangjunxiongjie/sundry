//这个题使用了递归但是如果仅仅使用递归，却不能有效地解决问题
// 因为一个很大的数使用递归所需的时间一点都不少
//但是很容易发现实际上递归所做的很多工作是重复的，那么好，
//把做过的工作记录下来下次再要做重复工作时，直接使用记录的做过的工作的结果 
 
#include <stdio.h>

int Halve_add(int tr);

int atr[1001];

int main()
{
	int num,you;
	scanf("%d",&you);
	printf("%d",Halve_add(you));
	return 0;
}

int Halve_add(int tr)
{
	int it,num;
	if(tr==1)
	{
		atr[1]=1;
		return 1;
	}
	for(it=1,num=1;it<=tr/2;it++)
	{
		if(!atr[it])
			atr[it]=Halve_add(it);
		num+=atr[it];
	}
	return num;
}

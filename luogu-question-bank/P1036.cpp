//2��������1���ǣ���Ҫ�����жϡ��ж��Ƿ�������Ҫ�ж���ԭ�����θ��ż�1���θ������������������ж�һ����Ҫ����. 
#include <stdio.h>
#include <math.h>

int Count=0;     //��ʽ��ʼ�� 

bool Prime_judge(int object)   //�ж����� 
{
	int zd=sqrt(object)+1;
	int it;
	for(it=3;it<zd;it++)
		if(object%it==0)
			return false;
	return true;	 
}

void Number_Group(int *atr,int site,int nr,int kr,int num)//���� 
{
	int it;
	if(kr==0)
	{
		if(num==1||(num!=2&&num%2==0))
			return ;
		
		if(Prime_judge(num))  //���û�������б�������������������б� 
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

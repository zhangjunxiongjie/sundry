//�����ʹ���˵ݹ鵫���������ʹ�õݹ飬ȴ������Ч�ؽ������
// ��Ϊһ���ܴ����ʹ�õݹ������ʱ��һ�㶼����
//���Ǻ����׷���ʵ���ϵݹ������ĺܶ๤�����ظ��ģ���ô�ã�
//�������Ĺ�����¼�����´���Ҫ���ظ�����ʱ��ֱ��ʹ�ü�¼�������Ĺ����Ľ�� 
 
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

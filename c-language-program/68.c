//ʵ��ʮ�����ڵĽ���ת����
#include <stdio.h>
int main ()
{
	int lw(int f,int f1);   //�õ�f��f1�η�
	int i1,i2,h;
	char a[20],b[20],ch;
	int n,m;
//	printf("����һ������ת����С������ֱ������� �������� �Լ�Ҫת��Ϊ�Ľ����Կո�ָ���\n");
	for(h=0,i1=0,n=0,m=0;(ch=getchar())!='\n';)
	{
		if(h==0&&ch!=' ')
		{
			if(ch<='9'&&ch>='0')
			{
				a[i1]=ch-48;
			//	printf("%d ",a[i1]);
			}
			else
				a[i1]=ch-55;
			i1++;
		}
		else if(h==1&&ch!=' ')
			n=n*10+ch-48;
		else if(h==2&&ch!=' ')
			m=m*10+ch-48;
		if(ch==' ')
			h++;
	}
	for(h=0,i2=0;i2<i1;i2++)
	{
		h=h+a[i2]*lw(n,i1-i2-1);   //�Ȼ�Ϊʮ���Ƶ���
	}
//	printf("%d\n",h);
	for(i2=0;h!=0;i2++)
	{
		b[i2]=h%m;
		h=h/m;
//		printf("%d ",b[i2]);
	}
	if(m<=10)
	{
		for(i1=i2-1;i1>=0;i1--)
			printf("%d",b[i1]);
		printf("\n");
	}
	else if(m<=16)
	{
		for(i1=i2-1;i1>=0;i1--)
		{
			if(b[i1]<=15&&b[i1]>=10)
				switch(b[i1])
				{	
					case 10:b[i1]='A';break;
					case 11:b[i1]='B';break;
					case 12:b[i1]='C';break;
					case 13:b[i1]='D';break;
					case 14:b[i1]='E';break;
					case 15:b[i1]='F';break;
				}
			else
				b[i1]=b[i1]+48;
			printf("%c",b[i1]);
		}
		printf("\n");
	}
return 0;
}

int lw(int f,int f1)
{
	int i;
	for(i=1;f1>0;f1--)
		i=i*f;
//	printf("%d ",i);
	return i;
}
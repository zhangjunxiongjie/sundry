// ����һ�����������ַ�������λ��ÿλ���֣������� 

#include <stdio.h>
int main ()
{
	int qws(long int a);
	void scs(long int b,int z[]);
	long int t;
	int ws,i;         //ws  ��ʾ������t��λ�� 
	printf ("������һ�����������֣�"); 
	scanf("%ld",&t);   //����һ������ 
	ws=qws(t);
	int z[ws];   //����z��������������t���������� 
	scs(t,z);
	printf("�������λ����%d\n",ws);
	printf("ÿλ����Ϊ��"); 
	
	for(i=ws-1;i>=0;i--)
	    printf("%d,",z[i]);
	
	printf("\n���������ǣ�");
	
	for(i=i+1;i<ws;i++)
	    printf("%d",z[i]);
	
	return 0;
}

int qws(long int a)  //�����ֵ�λ�� 
{                     //�������κ����ֵ�λ�� 
	int m,i=-1;
	while(a!=0||m!=0)
	{
	    m=a%10;
	    a/=10;
	    i++;
	}
	return (i);
}

void scs(long int b,int z[])   //�������ֵ�ûλ����������z�������� 
{
	int qws(long int a);   //����ָ��֪ʶ��֪�����е���ֱ�Ӵ����������������� 
	int ws,i=0;
	ws=qws(b);
	while(i<ws)
	{
	    z[i]=b%10;
	    b/=10;
	    i++;
	}
}

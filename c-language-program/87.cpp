//ʵ�ֵ������� ����������ͷ�ڵ㣬β�ڵ㣻
//�����ڵ�֮����ͷ���β�ڵ��ָ��null
// β�ڵ��ʶ����ָ��ָ��null
//ʵ������ڵ�Ĳ��룬ɾ���ض��ڵ� ���Լ������ض��ڵ� 
//����ָ�� 
#include <stdio.h>
#include <stdlib.h> 

typedef struct jgt{   
	int xuhao;     //���  
	char mc[10];  //���� 
	struct jgt* exye;   //ָ����һ�ڵ�ָ�� 
}JGT; 

void zz(JGT *p)     //����β�ڵ㣬�����ڵ� 
{
	p->exye=(JGT *)malloc(sizeof(JGT));  //����һ��ռ佫��ַ����β�ڵ㣻 
	p->exye->exye=NULL; 
} 

JGT* cz(JGT* p,int p1)  //���ҽڵ㣬��ͷ�ڵ�ĵ�ַ�Ͳ��ҵĵڼ����ڵ� 
{
	int i;
	for(i=1;i<p1;i++) 
		p=p->exye;
	return p;
}

void cr(JGT* p,JGT* pp)     //����ڵ� �����뵽����Ľڵ��ַ��������ڵ�ǰ��ڵ�ĵ�ַ 
{
	JGT* p1;       //pΪ����ڵ����һ�ڵ㣬ppΪҪ����ڵ㣻 
	p1=p->exye;
	p->exye=pp;
	pp->exye=p1;
}

void cr1(JGT* p)     //�������ڵ�ǰ��ڵ㣬�ڴ˺��������ӽڵ� 
{
	
	JGT *p1;        
	p1=p->exye;   //�Ƿ��ܲ��뵽β�ڵ� 
	zz(p);
	p->exye->exye=p1;
}

void sc(JGT* p)   //ɾ���ڵ� ������Ҫɾ���ڵ����һ�ڵ��׵�ַ 
{
	JGT* p1;
	p1=p->exye;
	p->exye=p1->exye;
	free(p1);        //��ɾ���ĵĽڵ�free���� 
} 

void jieweishuru(JGT *p,int *i)   //����ͷָ��ͽڵ���� 
{
	JGT *p1;
	p1=cz(p,*i);
	zz(p1);
//	p1=p1->exye;
	printf("������������������ƿո����:");
	scanf("%d%s",&p1->xuhao,&p1->mc);
//	printf("%d\n",*i);
	*i=*i+1;
//	printf("%d\n",*i);
}

void charushuru(JGT *p,int *i)  //����ͷ��㣬���ڵ���� 
{
	int t;
	JGT *p1;
	printf("������뵽�ڼ����ڵ��");
	scanf("%d",&t);
	p1=cz(p,t);    //����Ҫ���뵽�Ǹ��ڵ����
	cr1(p1);
	p1=p1->exye;
	printf("������������������ƿո����:");
	scanf("%d%s",&p1->xuhao,&p1->mc);
	*i=*i+1;
}

void shanchu(JGT *p,int *i)   //����ͷ��㣬�ͽڵ������
{
	int t;
	JGT *p1;
	printf("����ɾ���ڵ㣺");
	scanf("%d",&t);
	p1=cz(p,t-1);  //����ɾ���ڵ����һ�ڵ㡣
	sc(p1);
	*i=*i-1; 
} 

void tishishuru(JGT *p,int *i)    //����ͷ���ͽڵ���� 
{
	int t=0,t1;   //�����Ƿ���ȷ�ı�־ 
	while(t==0) 
	{
		printf("1.��β���룬2.�������룻");
		printf("3.ɾ����4.����������\n") ;
		printf("��ѡ��");
		scanf("%d",&t1);
		switch(t1)
		{
			case 1: jieweishuru(p,i),t=0;break;
			case 2: charushuru(p,i),t=0;break;    //���������Ƿ�֧�ֲ��뵽ͷ��� 
			case 3: shanchu(p,i),t=0;break;
			case 4: t=1;break; 
			default: printf("����ʧ��"),t=0;break; 
		}
	}
}

int main ()
{
	JGT *hear;  //ָ���׽ڵ��ָ�� 
	JGT *p;
	int i=1,t;
	hear=(JGT*)malloc(sizeof(JGT));
	hear->exye=NULL;
	
	tishishuru(hear,&i);    //i�ڵ���� 
//	printf("%d\n",i);
/*	for(t=1;t<i;t++)  //����������� 
	{
		p=cz(hear,t);
		printf("%d,%s  \n",p->xuhao,p->mc);		
	}*/	
	p=hear;	
	while(p->exye!=NULL)
	{
		printf("%d,%s  \n",p->xuhao,p->mc);	
		p=p->exye;
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct jgt{   
	char xm[11];       
	char xh[11];  //学号 
	int cj; 
	struct jgt* exye;   //指向下一节点指针 
}JGT;

void zz(JGT *p)     //传入尾节点，增长节点 
{
	p->exye=(JGT *)malloc(sizeof(JGT));   
	p->exye->exye=NULL; 
} 

void min(JGT *p)
{
	JGT *min;
	min=p;
	for(;p->exye!=NULL;)
	{
		if(p->cj>min->cj)
		{
			min=p;
		}
		p=p->exye;
	}
	printf("%s %s\n",min->xm,min->xh);
}

void max(JGT *p)
{
	JGT *max;
	max=p;
	for(;p->exye!=NULL;)
	{
		if(p->cj<max->cj)
		{
			max=p;
		}
		p=p->exye;
	}
	printf("%s %s\n",max->xm,max->xh);
}

void shuruhanshu(JGT *p)
{
	char ch;
	int i1,i2,i;
	p->cj=0;
	for(i=0,i1=0,i2=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&i==0)
		{
			p->xm[i1]=ch;
			i1++;
		}
		else if(i==1&&ch!=' ')
		{
			p->xh[i2]=ch;
			i2++;
		}
		else if(i==2&&ch!=' ')
			p->cj=p->cj*10+(ch-48);
		if(ch==' ')
		{
			i++;
		}
	}
	p->xm[i1]='\0';
	p->xh[i2]='\0';
}


int main()
{
	int h,i;
	JGT *tou,*wei,*mm;
	tou=(JGT *)malloc(sizeof(JGT));
	wei=tou;
	scanf("%d",&h);
	getchar();
	for(i=0;i<h;i++)
	{
		shuruhanshu(wei);
		zz(wei);
		wei=wei->exye;
	}
	mm=tou;
/*	while(mm->exye!=NULL)
	{
		printf("%s %s %d\n",mm->xm,mm->xh,mm->cj);
		mm=mm->exye;
	}*/
	min(tou);
	max(tou);
	return 0;
}


//实现单向链表 主函数中有头节点，尾节点；
//创建节点之初，头结点尾节点均指向null
// 尾节点标识是其指针指向null
//实现链表节点的插入，删除特定节点 ，以及搜索特定节点 
//二级指针 
#include <stdio.h>
#include <stdlib.h> 

typedef struct jgt{   
	int xuhao;     //序号  
	char mc[10];  //名称 
	struct jgt* exye;   //指向下一节点指针 
}JGT; 

void zz(JGT *p)     //传入尾节点，增长节点 
{
	p->exye=(JGT *)malloc(sizeof(JGT));  //申请一块空间将地址传给尾节点； 
	p->exye->exye=NULL; 
} 

JGT* cz(JGT* p,int p1)  //查找节点，给头节点的地址和查找的第几个节点 
{
	int i;
	for(i=1;i<p1;i++) 
		p=p->exye;
	return p;
}

void cr(JGT* p,JGT* pp)     //插入节点 ，插入到后面的节点地址，及插入节点前面节点的地址 
{
	JGT* p1;       //p为插入节点的上一节点，pp为要插入节点； 
	p1=p->exye;
	p->exye=pp;
	pp->exye=p1;
}

void cr1(JGT* p)     //传入插入节点前面节点，在此函数中增加节点 
{
	
	JGT *p1;        
	p1=p->exye;   //是否能插入到尾节点 
	zz(p);
	p->exye->exye=p1;
}

void sc(JGT* p)   //删除节点 ，传入要删除节点的上一节点首地址 
{
	JGT* p1;
	p1=p->exye;
	p->exye=p1->exye;
	free(p1);        //将删除的的节点free掉； 
} 

void jieweishuru(JGT *p,int *i)   //传入头指针和节点个数 
{
	JGT *p1;
	p1=cz(p,*i);
	zz(p1);
//	p1=p1->exye;
	printf("先输入序号再输入名称空格隔开:");
	scanf("%d%s",&p1->xuhao,&p1->mc);
//	printf("%d\n",*i);
	*i=*i+1;
//	printf("%d\n",*i);
}

void charushuru(JGT *p,int *i)  //传入头结点，及节点个数 
{
	int t;
	JGT *p1;
	printf("输入插入到第几个节点后：");
	scanf("%d",&t);
	p1=cz(p,t);    //查找要插入到那个节点后面
	cr1(p1);
	p1=p1->exye;
	printf("先输入序号再输入名称空格隔开:");
	scanf("%d%s",&p1->xuhao,&p1->mc);
	*i=*i+1;
}

void shanchu(JGT *p,int *i)   //传入头结点，和节点个数；
{
	int t;
	JGT *p1;
	printf("输入删除节点：");
	scanf("%d",&t);
	p1=cz(p,t-1);  //查找删除节点的上一节点。
	sc(p1);
	*i=*i-1; 
} 

void tishishuru(JGT *p,int *i)    //传入头结点和节点个数 
{
	int t=0,t1;   //输入是否正确的标志 
	while(t==0) 
	{
		printf("1.结尾输入，2.插入输入；");
		printf("3.删除，4.结束操作。\n") ;
		printf("请选择：");
		scanf("%d",&t1);
		switch(t1)
		{
			case 1: jieweishuru(p,i),t=0;break;
			case 2: charushuru(p,i),t=0;break;    //插入输入是否支持插入到头结点 
			case 3: shanchu(p,i),t=0;break;
			case 4: t=1;break; 
			default: printf("操作失误"),t=0;break; 
		}
	}
}

int main ()
{
	JGT *hear;  //指向首节点的指针 
	JGT *p;
	int i=1,t;
	hear=(JGT*)malloc(sizeof(JGT));
	hear->exye=NULL;
	
	tishishuru(hear,&i);    //i节点个数 
//	printf("%d\n",i);
/*	for(t=1;t<i;t++)  //输出所有内容 
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

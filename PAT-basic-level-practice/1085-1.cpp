#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct jgt{   
	char zkzh[7];    
	float df; 
	char xx[7];
	struct jgt* exye;  
}JGT; 

typedef struct jgt1{   
	char zkzh[7];   
	float df; 
	int df1;  
	int pm; 
	char xx[7];
	int i; 
	struct jgt1* exye; 
}JGT1; 

void zz(JGT *p)
{
	p->exye=(JGT *)malloc(sizeof(JGT));   
	p->exye->exye=NULL; 
}

void dzx(char *p)
{
	while(*p)
	{
		if(*p<='Z'&&*p>='A')
		{
			*p+=32;
		} 
		p++;
	}
}

JGT *shuru()
{
	int fof;
	int i=0;
	JGT *tou=NULL,*wei=NULL;
	if(scanf("%d",&fof)==1);
	while(i<fof)
	{
		if(wei==NULL)
		{
			wei=(JGT *)malloc(sizeof(JGT));
			wei->exye=NULL;
			tou=wei;
		}
		else
		{
			zz(wei);
			wei=wei->exye;
		}
		if(scanf("%s%f%s",wei->zkzh,&wei->df,wei->xx)==3);
		dzx(wei->xx);
		switch (wei->zkzh[0])
		{
			case 66: wei->df/=1.5;break;
			case 65: break; 
			case 84: wei->df*=1.5;break;
			default: printf("出现问题！");
		}
		i++;
	}	
	return tou;
}

int cz(JGT *p,JGT1 *p1)
{
	if(p1==NULL)
		return 1;
	else
	{
		while(p1)
		{
			if(!strcmp(p1->xx,p->xx))
			{
				p1->df+=p->df;
				p1->i++;
				return 0;
			}
			p1=p1->exye;
		}
	}	
	return 1;
}    

JGT1 *zj(JGT *p)
{
	JGT1 *tou=NULL,*wei=NULL;
	while(p)
	{
		if(cz(p,tou))
		{
			if(wei==NULL)
			{
				wei=(JGT1 *)malloc(sizeof(JGT1));
				wei->exye=NULL;
				tou=wei;
			}
			else
			{
				wei->exye=(JGT1 *)malloc(sizeof(JGT1));
				wei=wei->exye;
				wei->exye=NULL;
			}
			strcpy(wei->xx,p->xx);
			strcpy(wei->zkzh,p->zkzh);
			wei->df=p->df;
			wei->i=1;
		}
		p=p->exye;
	}
	return tou;		
}

void jh(JGT1 *p,JGT1 *p1)
{
	JGT1 j;
	j=*p1;
	*p1=*p;
	*p=j;
	j.exye=p->exye;
	p->exye=p1->exye;
	p1->exye=j.exye;
}

int main() 
{
	int y=0,i=0;
	JGT *h;
	JGT1 *j,*k,*d;
	h=shuru();
	j=zj(h);
	k=j;
	d=j;
	while(j)
	{
		y++;
		k=j;
		while(k)
		{
			k->df1=(int)k->df;
			if(k->df1>j->df1)
			{
				jh(k,j);	
			}
			else if(k->df1==j->df1&&k->i<j->i)
			{
				jh(k,j);
			}
			else if(k->df1==j->df1&&k->i==j->i&&k->xx[0]<j->xx[0])
			{
				jh(k,j);
			}
			k=k->exye;
		}
		j=j->exye;
	}
	printf("%d\n",y);
	while(d)
	{
		i++;
		if(i==1)
			d->pm=1;
		else if(i!=1&&d->df1==k->df1)
			d->pm=k->pm;
		else
			d->pm=i;
		printf("%d %s %d %d\n",d->pm,d->xx,d->df1,d->i);
		k=d;	
		d=d->exye;
	}
	return 0;
}

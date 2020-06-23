#include <stdio.h>
#include <stdlib.h>  
#include <math.h>   
typedef struct jg{
	int chazhi;
	int geshu;
	int biaoji;
	struct jg *xyjd;	
}JG;
void zz(JG *p)
{
	p->xyjd=(JG*)malloc(sizeof(JG));
	p->xyjd->xyjd=NULL;
}
JG *cz(JG *p,int i)
{
	while(p)
	{
		if(p->chazhi==i)
			return p;
		p=p->xyjd;
	}
	return p;
}
int main ()
{
	JG *tou=NULL,*wei,*p,*p1;
	char ch;
	int i,t,h,f,biaoji=0,jishu=0;
	scanf("%d",&f);
	getchar();
	for(i=1,h=0;(ch=getchar())!='\n';)
	{
		if(ch!=' '&&h==0)
			t=ch-48;
		else if(ch!=' '&&h==1)
			t=t*10+ch-48;
		if(ch==' ')
		{
			t=abs(t-i);
			p=cz(tou,t);
			if(p)
				p->geshu++;	
			else if(i==1&&biaoji==0)
			{
				tou=(JG*)malloc(sizeof(JG));
				tou->xyjd=NULL;
				wei=tou;
				wei->chazhi=t;	
				wei->geshu=1;
				biaoji=1;
				jishu++;
				wei->biaoji=1;
			}
			else
			{
				zz(wei);
				wei=wei->xyjd;
				wei->chazhi=t;	
				wei->geshu=1;
				wei->biaoji=1;
				jishu++;
			}
			h=0;
			i++;
		}
		else
			h=1;
	}
	i=0;
	while(i<jishu)
	{ 
		p1=tou;
		p=tou;
		while(p)
		{
			if(p->chazhi>p1->chazhi&&p->biaoji==1)
				p1=p;
			p=p->xyjd;
		}
		if(p1->geshu>1)
		{
			printf("%d %d\n",p1->chazhi,p1->geshu);
			p1->biaoji=0;
		}
		else
			p1->biaoji=0;
		i++;
	}
	return 0;
}

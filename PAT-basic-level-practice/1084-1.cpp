#include <stdio.h>
#include <stdlib.h> 

typedef struct jg{
	int t;
	struct jg *xyjd;
}JG;
void zz(JG *p);
void zx(JG *p);  //前者带进去数组每带一次得到当前数组后一项，后者为当前数组所占个数

int main ()
{
	JG *tou,*p;
	tou=(JG*)malloc(sizeof(JG));
	tou->xyjd=NULL;
	int i,i1=0,i2=1;
	char ch;
	int b[2];
	while((ch=getchar())!='\n')
	{
        if(i2==1&&ch!=' ')
		{
			b[i1]=ch-48;
			i1++;
		}
		else if(i2!=1&&ch!=' ')
			b[i1-1]=(b[i1-1]*10)+ch-48;
		if(ch==' ')
			i2=1;
		else if(ch!=' ')
			i2=0;
	}
    tou->t=b[0];
	for(i1=1;i1<b[1];i1++)
		zx(tou);
	p=tou;
    while(p)
    {
    	printf("%d",p->t);
    	p=p->xyjd;
	}
	printf("\n");
	return 0;
}

void zx(JG *p)
{
	int i;
	JG *p1,*jilu;
	while(p)
	{
		if(!p->xyjd)
		{
			zz(p);
			p->xyjd->t=1;
			break;
		}
		p1=p->xyjd;
		i=1;
		while(p1)
		{
			if(p->t==p1->t)
			{
				i++;
				jilu=p1;
				p1=p1->xyjd;
				free(jilu);	
			}
			else
				break;
		}
		zz(p);
		p=p->xyjd;
		p->xyjd=p1;
		p->t=i;
		p=p->xyjd;	
	}	
}
void zz(JG *p)
{
	p->xyjd=(JG*)malloc(sizeof(JG));
	p->xyjd->xyjd=NULL;
}

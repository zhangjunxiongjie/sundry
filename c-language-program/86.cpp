//实现可变数组
//先输入是否继续输入标志y，若不继续输入则输入其它字符
//去掉了输入判断字符，以空格判断下一次输入
#include <stdio.h>
#include <stdlib.h>

typedef struct
{ //结构体，含可变数组首地址和可变数组元素个数
	int *sdz;
	int yszgs;
	int ysgs;
} jgt;

void zz(jgt *sp) //重新申请一块更大的内存 ,sp为大数组
{
	sp->sdz = (int *)malloc((sp->yszgs + 5) * sizeof(int));
	sp->yszgs += 5;
	//	printf("%p\n",sp->sdz);
}

void fz(jgt sp, jgt *sp1) //将原数组中的内容复制到新的内存空间中
{
	int i;
	for (i = 0; i < sp.ysgs; i++) //
	{
		//	printf("%d ",sp.sdz[i]);
		sp1->sdz[i] = sp.sdz[i];
	}
	//	printf("\n");
	free(sp.sdz); //任何malloc到的空间都要free掉。
}

void sxysz(jgt *sp, jgt sp1) //sp为小数组，sp1为大数组
{
	//	printf("%d %d %d %d %d\n",sp1.sdz[]);
	//   free(sp->sdz);
	sp->sdz = sp1.sdz;
	sp->yszgs = sp1.yszgs;
	sp->ysgs = sp1.ysgs;
}

void tishishuru(jgt *p, jgt *p1)
{
	int *t1;
	int t, i;
	//	printf("数组总计五个元素，每次增加五个。\n");
	printf("本程序由可变数组实现。\n");
	printf("请输入整型元素信息以空格隔开，结束请在结尾输入非整型字符：\n");
	while (1)
	{
		t1 = p1->sdz;
		t = p1->yszgs;
		//	printf("%d",p1->yszgs);
		i = scanf("%d%d%d%d%d", &t1[t - 5], &t1[t - 4], &t1[t - 3], &t1[t - 2], &t1[t - 1]);
		p1->ysgs += i;
		if (i != 5)
			break;
		sxysz(p, *p1);
		//	printf("%d %d %d %d %d\n",p->sdz[t-5],p->sdz[t-4],p->sdz[t-3],p->sdz[t-2],p->sdz[t-1]);
		zz(p1);
		//	printf("%d %d %d %d %d\n",t1[0],t1[1],t1[2],t1[3],t1[4]);
		fz(*p, p1);
		//	printf("%d %d %d %d %d\n",t1[0],t1[1],t1[2],t1[3],t1[4]);

		//	printf("%p\n",p1->sdz);
	}
}

//输入首字符y代表继续输入即申请一个更大的数组空间，其他代表结束输入
int main()
{
	jgt p, p1; //p小一点的数组，p1大一点的数组，
	int i;
	p1.sdz = p.sdz = (int *)malloc(5 * sizeof(int));
	p1.yszgs = p.yszgs = 5;
	p1.ysgs = p.ysgs = 0;

	tishishuru(&p, &p1);

	for (i = 0; i < p1.ysgs; i++)
	{
		printf("%5d", p1.sdz[i]);
		if ((i + 1) % 5 == 0 && i != 0)
			printf("\n");
	}
	//	printf("\n%d %d\n",p1.ysgs,p1.yszgs);
	return 0;
}

//ʵ�ֿɱ�����
//�������Ƿ���������־y�������������������������ַ�
//ȥ���������ж��ַ����Կո��ж���һ������
#include <stdio.h>
#include <stdlib.h>

typedef struct
{ //�ṹ�壬���ɱ������׵�ַ�Ϳɱ�����Ԫ�ظ���
	int *sdz;
	int yszgs;
	int ysgs;
} jgt;

void zz(jgt *sp) //��������һ�������ڴ� ,spΪ������
{
	sp->sdz = (int *)malloc((sp->yszgs + 5) * sizeof(int));
	sp->yszgs += 5;
	//	printf("%p\n",sp->sdz);
}

void fz(jgt sp, jgt *sp1) //��ԭ�����е����ݸ��Ƶ��µ��ڴ�ռ���
{
	int i;
	for (i = 0; i < sp.ysgs; i++) //
	{
		//	printf("%d ",sp.sdz[i]);
		sp1->sdz[i] = sp.sdz[i];
	}
	//	printf("\n");
	free(sp.sdz); //�κ�malloc���Ŀռ䶼Ҫfree����
}

void sxysz(jgt *sp, jgt sp1) //spΪС���飬sp1Ϊ������
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
	//	printf("�����ܼ����Ԫ�أ�ÿ�����������\n");
	printf("�������ɿɱ�����ʵ�֡�\n");
	printf("����������Ԫ����Ϣ�Կո�������������ڽ�β����������ַ���\n");
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

//�������ַ�y����������뼴����һ�����������ռ䣬���������������
int main()
{
	jgt p, p1; //pСһ������飬p1��һ������飬
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

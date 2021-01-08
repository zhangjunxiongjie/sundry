//��ʹ�õݹ鳢�ԶԹ�����������������򣨼��������ȣ���ԭ��Ԫ�أ��ӱ���������ʾʹ���˵ݹ顣
//��Ҫ�ֶ���������
//����Ԫ�ز�ȷ����������һ��ԭ��Ԫ�أ����ɲ��Ԫ�أ�Ҳ������һ���ӱ��Ȳ�ȷ�����ӱ�
/*��ʼ�����뺯��Genlist_scanf()��
������һ���ܹ��ȵ�������ǹ������γ�ʼ���أ�����ֻ�������ˣ�������ôдһ�����������ڳ�ʼ��һ�������
���������Ҫ�������ܵ�Ԫ�ظ���������㣩��Ȼ������ÿһ��Ԫ��������ÿһ��Ԫ����һ������һ��ԭ��Ԫ�أ�����Ǳ�͵ݹ�����������
��������ԭ��Ԫ��ֵ��
*/
/*�������Genlist_print()��
Ϊ��ȷ��ǰ�ں����Թ����ĳ�ʼ���Ƿ�ɹ�дһ�������������Ϊ�ж���ȵķ���ʹ��ѭ��������ʹ�õݹ鷽�����ÿһ���ֵ��
*/
/*�����Ⱥ���Depth_solve()  ����������Լ����һ����ջ�洢ÿһ�����һԪ�ص�ַ�Է���ص�ÿһ�������һ���Ԫ�ص���һ��λ�á�
���������һ����ջ�洢ÿһ�����ȡ�
���ϵ���һ�ַ�����ֻʹ��һ����ÿ�����²����룬����ȵ���������ʱ�뵱ǰ�����ȱȽ�ȡ�ϴ��ߡ�����ʹ�ú���Depth_solver()ʵ��һ�¡�
*/
/*ʹ�÷ǵݹ�Թ����ı��������ǣ����������Ԫ�ص������ӱ�ʱʹ�ö�ջ��¼�ӱ����һ��Ԫ��ָ�벢���˳���ǰ�Ե�ǰ��Ԫ�صı�����
ʹ����������ж��ƶ�ָ����Ƿ���null�����˵���ϲ���������Ҫ�Ѷ�ջ�е��²���һԪ��ָ�뽻���ƶ�����ָ����ȥ�������������˵����һ�㲢û��
������ȴ�˳�����˵�������ӱ��ˣ��ý�ָ�����Ϊ�ӱ��ͷָ��ȥ�����Ǹ��ӱ�
*/
/*����һ���ܲٵ������⣬������������ʱMovrֵΪNULL������Ȼ������жϴ�ʱ�ж�Ϊ,��һ�����������ջ��ָ�뽻��Movrͬʱһ��ɵ�Ƶ�bug����ֻҪ
Tier_deep[Top] < Tier_deep[Top + 1] + 1������������ͻ�����Tier_deep[Top]��������ٵ���ʱ��������һ�㻹Ҫ��һ������
*/
//�ܲٵ��������ˡ�����



#include <stdio.h>
#include <stdlib.h>

#define Nt 20   //����ָ���ջ�Ĵ�С�����������ȡ�

typedef enum { ATOM, LIST } ElemTag;					 /* ö���������ͣ�ATOM=0����ʾԭ�ӣ�LIST=1����ʾ�ӱ�*/
typedef struct GLNode
{
	ElemTag Tag;										 /*��־λtag��������ԭ�ӽ��ͱ���*/
	union        //��������������
	{
		int atom;									/*ԭ�ӽ���ֵ��atom*/
		struct GLNode * hp;							/*�����ָ����htp*/
	} atom_htp;											/* atom_htp ��ԭ�ӽ���ֵ��atom�ͱ����ָ����htp����������*/
	struct GLNode* Next;      //ָ����һ��Ԫ�ص�ָ�롣
}Gene, *GList;       //�����������ͺ�ָ�����͡�

int NUMBER = sizeof(Gene);   //�����ڵ��С

// Tierÿ��Ĳ�����
GList Genlist_scanf(int Tier)   //��ʼ�����뺯��
{
	GList heart,tail;		//ÿ�㷵�ص�ͷָ��,�ͳ�ʼ��ÿ��Ԫ�ص�βָ�롣
	int NUOM;			//ÿ��ݹ��Ԫ�ظ���
	int it=0;				//ѭ���ƶ�����
	int flg;			//Ԫ�����ͱ�־
	printf("�������%d��Ԫ�ظ�����", Tier);
	scanf_s("%d", &NUOM);
	if (NUOM == 0)
		return NULL;
	heart = (GList)malloc(NUMBER);
	tail = heart;
	while (true)
	{
		printf("�������%d��ĵ�%d��Ԫ�ص�Ԫ�����ࣨ0��ԭ�ӣ�1���ӱ���",Tier,it+1);
		scanf_s("%d", &flg);
		if (flg)
		{
			tail->Tag = LIST;      //������
			tail->atom_htp.hp = Genlist_scanf(Tier+1);
		}
		else
		{
			tail->Tag = ATOM;      //������
			printf("�������%d��ĵ�%d��Ԫ�ص�ֵ��",Tier,it+1);
			scanf_s("%d", &flg);     //��Ϊֵ����ʱ����
			tail->atom_htp.atom = flg;    //ȡ�������Ա��
		}
		it++;
		if (it >= NUOM)
			break;
		tail->Next=(GList)malloc(NUMBER);
		tail = tail->Next;
	}
	tail->Next = NULL;
	return heart;
}

void Genlist_print(GList heary) //�������
{
	GList tail=heary;
	printf("(");
	while (tail != NULL)
	{
		if (tail->Tag == ATOM)
			printf("%d ", tail->atom_htp.atom);
		else
			Genlist_print(tail->atom_htp.hp);
		tail = tail->Next;
	}
	printf(") ");

}

int Depth_solve(GList hearu)    //�������ȵķ����е�������ʹ�ö�ջ���ǵݹ�ʵ�����������
{
	int DEP=0;     //��ȱ�����
	int Top=1;     //��ջ����
	GList Nextr[Nt];    //����ָ���ջ�����ڴ洢ÿһ�����һָ�롣
	int Tier_deep[Nt];    //�洢ÿһ�����ȡ�����ԭ��Ԫ�ز��Ե�ǰ����ȸ��ģ������ӱ�Ԫ���ж����뵱ǰ��������С�����򣨸��ǣ��滻��
	GList  Movr;    //�����ƶ�ָ�롣Moveÿһ���ͷָ�룬Movrÿһ����ƶ�ָ�롣
	Movr = hearu;
	Tier_deep[Top-1] = 0;
	Tier_deep[Top] = 0;
	Nextr[Top-1] = NULL;
	printf("\n");
	while (Movr != NULL || Top > 0)
	{
		for(;Movr!=NULL;Movr=Movr->Next)
		{
			if (Movr->Tag == LIST)
			{
				Nextr[Top++] = Movr->Next;
				Tier_deep[Top] = 0;
				break;
			}
			printf("%d ",Movr->atom_htp.atom);
		}
		if (Movr != NULL)
			Movr = Movr->atom_htp.hp;
		else
		{
			Movr = Nextr[--Top];
			if (Tier_deep[Top] < Tier_deep[Top + 1] + 1)
				Tier_deep[Top] = Tier_deep[Top + 1] + 1;
		}
		//printf("\nTop:%d\n",Top);
	}
	//printf("\nTier_deep[Top]:%d\n", Tier_deep[Top]);
	DEP = Tier_deep[Top];
	return DEP;
}

int Depth_solver(GList hearu)    //���ϵ���������ȵ��㷨���ҵķ�����Ϊ���Ƶ�������ͬ�������ﲻ���ؽ���Ŀ��������Ϊһ���������������������
{
	int DEP=1;      //��ǰ������
	int Dep = 1;   //��ǰ����
	int Top = 1;     //��ջ����
	GList Nextr[Nt];    //����ָ���ջ�����ڴ洢ÿһ�����һָ�롣
	GList  Movr;    //�����ƶ�ָ�롣Moveÿһ���ͷָ�룬Movrÿһ����ƶ�ָ�롣
	Movr = hearu;
	Nextr[Top-1] = NULL;
	printf("\n");
	while (Movr != NULL || Top > 0)    
	{
		while (Movr!=NULL)
		{
			if (Movr->Tag == LIST)
			{
				Nextr[Top++] = Movr->Next;
				break;
			}
			printf("%d ", Movr->atom_htp.atom);
			Movr = Movr->Next;
		}
		if (Movr == NULL)   
		{
			Movr = Nextr[--Top];
			Dep--;
		}
		else
		{
			Movr = Movr->atom_htp.hp;
			Dep++;
		}
		if (DEP < Dep)
			DEP = Dep;
	}
	
	return DEP;
}


int main()
{
	GList hear;    //����һ�������ָ��
	hear = Genlist_scanf(1);
	Genlist_print(hear);
	//Depth_solve(hear);
	printf("\n��������Ϊ%d��\n", Depth_solver(hear));

	system("Pause");   //����DOS������ͣ����
	return 0;
}

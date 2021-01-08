//不使用递归尝试对广义表进行深度搜索（或（即）求解深度）。原子元素，子表。广义表的显示使用了递归。
//需要手动输入广义表。
//表中元素不确定即可能是一个原子元素（不可拆分元素）也可以是一个子表长度不确定的子表。
/*初始化输入函数Genlist_scanf()。
遇到了一个很狗比的事情就是广义表如何初始化呢？？？只能输入了！！！那么写一个函数把用于初始化一个广义表
这个函数需要先输入总的元素个数（最外层），然后输入每一个元素先输入每一个元素是一个表还是一个原子元素，如果是表就递归调用这个函数
否则输入原子元素值。
*/
/*输出函数Genlist_print()。
为了确定前期函数对广义表的初始化是否成功写一个输出函数（因为判断深度的方法使用循环故这里使用递归方法输出每一层的值域）
*/
/*求解深度函数Depth_solve()  这个函数是自己想的一个堆栈存储每一层的下一元素地址以方便回到每一层进入下一层的元素的下一个位置。
我这里的另一个堆栈存储每一层的深度。
书上的另一种方法是只使用一个数每次向下层深入，到深度到达最大深度时与当前最大深度比较取较大者。这里使用函数Depth_solver()实现一下。
*/
/*使用非递归对广义表的遍历方法是：遍历广义表元素当出现子表时使用堆栈记录子表的下一个元素指针并且退出当前对当前层元素的遍历，
使用条件语句判断移动指针变是否是null如果是说明上层遍历完成需要把堆栈中的下层下一元素指针交给移动遍历指针拿去遍历，如果不是说明这一层并没有
遍历完却退出来了说明又有子表了，得将指针更改为子表的头指针去遍历那个子表。
*/
/*发现一个很操蛋的问题，当最外层遍历完时Movr值为NULL可是依然会进行判断此时判断为,上一层结束即将堆栈顶指针交给Movr同时一个傻逼的bug就是只要
Tier_deep[Top] < Tier_deep[Top + 1] + 1这个条件成立就会重置Tier_deep[Top]。真他妈操蛋此时处于最外一层还要加一！！！
*/
//很操蛋，不管了。。。



#include <stdio.h>
#include <stdlib.h>

#define Nt 20   //设置指针堆栈的大小，必须大于深度。

typedef enum { ATOM, LIST } ElemTag;					 /* 枚举数据类型，ATOM=0，表示原子；LIST=1，表示子表*/
typedef struct GLNode
{
	ElemTag Tag;										 /*标志位tag用来区别原子结点和表结点*/
	union        //联合体数据类型
	{
		int atom;									/*原子结点的值域atom*/
		struct GLNode * hp;							/*表结点的指针域htp*/
	} atom_htp;											/* atom_htp 是原子结点的值域atom和表结点的指针域htp的联合体域*/
	struct GLNode* Next;      //指向下一个元素的指针。
}Gene, *GList;       //定义广义表类型和指针类型。

int NUMBER = sizeof(Gene);   //广义表节点大小

// Tier每层的层数。
GList Genlist_scanf(int Tier)   //初始化输入函数
{
	GList heart,tail;		//每层返回的头指针,和初始化每个元素的尾指针。
	int NUOM;			//每层递归的元素个数
	int it=0;				//循环移动变量
	int flg;			//元素类型标志
	printf("请输入第%d层元素个数：", Tier);
	scanf_s("%d", &NUOM);
	if (NUOM == 0)
		return NULL;
	heart = (GList)malloc(NUMBER);
	tail = heart;
	while (true)
	{
		printf("请输入第%d层的第%d个元素的元素种类（0：原子，1：子表）：",Tier,it+1);
		scanf_s("%d", &flg);
		if (flg)
		{
			tail->Tag = LIST;      //？？？
			tail->atom_htp.hp = Genlist_scanf(Tier+1);
		}
		else
		{
			tail->Tag = ATOM;      //？？？
			printf("请输入第%d层的第%d个元素的值域：",Tier,it+1);
			scanf_s("%d", &flg);     //作为值域临时变量
			tail->atom_htp.atom = flg;    //取联合体成员。
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

void Genlist_print(GList heary) //输出函数
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

int Depth_solve(GList hearu)    //这个求深度的方法有点类似于使用堆栈而非递归实现深度搜索。
{
	int DEP=0;     //深度变量。
	int Top=1;     //堆栈顶。
	GList Nextr[Nt];    //设置指针堆栈。用于存储每一层的下一指针。
	int Tier_deep[Nt];    //存储每一层的深度。对于原子元素不对当前层深度更改，对于子表元素判断其与当前深度熟大熟小，大则（覆盖）替换。
	GList  Movr;    //设置移动指针。Move每一层的头指针，Movr每一层的移动指针。
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

int Depth_solver(GList hearu)    //书上的用于求深度的算法与我的方法颇为相似但不尽相同，故这里不再重建项目但将其作为一个方法放置在这个函数中
{
	int DEP=1;      //当前最大层数
	int Dep = 1;   //当前层数
	int Top = 1;     //堆栈顶。
	GList Nextr[Nt];    //设置指针堆栈。用于存储每一层的下一指针。
	GList  Movr;    //设置移动指针。Move每一层的头指针，Movr每一层的移动指针。
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
	GList hear;    //定义一个广义表指针
	hear = Genlist_scanf(1);
	Genlist_print(hear);
	//Depth_solve(hear);
	printf("\n广义表深度为%d。\n", Depth_solver(hear));

	system("Pause");   //调用DOS命令暂停程序
	return 0;
}

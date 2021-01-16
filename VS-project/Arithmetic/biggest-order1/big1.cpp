/*这里使用递归（堆栈亦可行）方法求解一个随机序列的最大有序序列的数值个数。需要记录最大有序序列的有序个数和头坐标。
优化的地方：在判断递归结束时使用了一个条件判断即：(hand - right) * 2 < Mt，这个判断使得在传入递归的
左右值差的两倍都小于Mt（进入递归时的最大有序序列个数）时不再进行递归因为如果左右值差的两倍已经达到已经判断过的左右值边界，
就算有一个有序序列数值个数也不会大于左右差值两倍的个数，故无需再对此时的左右值进行左右枚举判断也不再需要向下继续递归。
需要注意的地方是：不能超过数组的左右边界，如果rig和han分别到达数组左右端点此时需要判断前者的前一个数是否位于rig序列，后者同上，
此时的判断会使数组超界！！！，所以要先判断是否到达数组边界如果到达数组边界就不能在进行后续判断。
*/
/*这个算法求解随机序列的最大有序数值个数的算法复杂度在最差情况下为O(TU)即遍历整个数组。
*/

#include <stdio.h>
#include <stdlib.h>

#define TU 40

int NU[TU] = { 5,1,2,7,4,3,5,1,2,6,9,7,8,4,5,8,2,3,4,5,7,6,4,8,3,5,1,9,2,5,6,9,3,4,5,6,7,2,1,5 };     //随机序列

int Mt=1, Mi;   //全局变量用于记录最大有序序列头坐标和有序个数

void Mid_big(int right,int hand)   //此函数传入左右值遍历其中间值的旁边是否有序
{
	int it = (right + hand) / 2;
	int rig = it, han = it;
	if ((hand - right) * 2 < Mt)
		return;
	while ((rig > 0 && NU[rig] - 1 == NU[rig - 1]) || (han < TU-1 && NU[han] + 1 == NU[han + 1]))
	{
		if (rig > 0 && NU[rig] - 1 == NU[rig - 1])
			rig--;
		if (han < TU-1 && NU[han] + 1 == NU[han + 1])
			han++;
	}
	if (han - rig + 1 > Mt)
	{
		Mi = rig;
		Mt = han - rig + 1;
	}
	Mid_big(right+1, it);
	Mid_big(it, hand-1);

}


int main()
{
	Mid_big(0, TU);
	printf("%d,%d\n", Mt, Mi);

	system("Pause");   //调用DOS命令暂停程序

	return 0;
}



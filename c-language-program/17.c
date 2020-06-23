#define PRICE 30 //符号常量（用#define指令指定一个符号名称代表一个常量）//
#include <stdio.h>
void main() //void main,main,int main.前两者无返回值，后者有（return 0）//
{
	int num, total;
	num = 10;
	total = num * PRICE;
	printf("TOTAL=%d\n", total);
}
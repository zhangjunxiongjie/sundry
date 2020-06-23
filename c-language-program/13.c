#include <stdio.h>
void main()
{
	printf ("0123456789\n");
	printf ("  ab c\tde\rf\tg\n");
	printf ("h\ti\b\bj k\n");              //转义字符的使用//
	printf ("i\b\b\n");
}

#include <stdio.h>  //转义字符的使用问题
void main ()
{
	printf ("1234567812345678\n");
	printf("*\t");
	printf("Very good!\n");
	printf("c\b\v");
	printf("a\n");
}

#include <stdio.h>  
int main()
{
	int a[1];
	int b;
	printf ("%d\n",a[1]);  //未赋初值变量直接输出
	printf ("%d\n",b);
	return 0;
}


//一：仅当“\t”转义字符的使用使"目标字符"经过某些字符时所经过的字符均会被空格所覆盖
//必须有目标字符经过如果没有目标字符仅有转移字符则不会覆盖空格
//二：对于定理一在任何情况下很成立且可多次覆盖
//三：任何转义字符均作用于当前位置，而非某一字符。
//"\b":退格   "\t"：到下一个tab位置“水平制表符”“一个制表符八个字节”。
// "\r":到本行开头；"\v":到垂直位置的下一个制表符。  "\\":输出"\"字符。
//"\t"：并不是退八格而是到下一个水平制表符。
//不能给未赋地址的指针赋值，可能会造成数据丢失
//莫名其妙的小程序

#include <stdio.h>
int main()
{
	float score;
	scanf("%f", &score); //在编辑过程中忘了打地址符&，编译时某一程序执行出现错误。
	bool a, b;			 //bool定义a，b为逻辑变量
	a = (score >= 60);
	b = (score <= 69); //将69>=score的逻辑值赋给b
	if (a == true && b == true)
		printf("The grade is C\n");
	return 0;
}

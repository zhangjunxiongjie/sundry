//判断某一年是否为闰年

#include <stdio.h>
#include <stdbool.h>  //使用逻辑变量（leap）和逻辑常量（ture，false）的预处理语句

int main ()
{
	int year;
	bool leap;  //定义逻辑变量
	scanf ("%d",&year);    //输入年份
	if(year%4==0)
	{
		if(year%100==0)
		{ 
			if(year%400==0)
			leap=true;    //逻辑常量：1；
			else
			leap=false;   //逻辑常量：0；
		}
		else
			leap=true;
	}
	else
	leap=false;
	if(leap=true)
	   printf("%d is not ",year);
	else
	   printf("%d is ",year);
	printf("a leap year.\n");
	return 0;
}

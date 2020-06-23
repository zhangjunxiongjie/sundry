// 电脑产生一个随机数，我来猜。 

#include <stdio.h>
#include <stdlib.h>                  // 未知头文件 
#include <time.h>

int main ()
{
    srand(time(0));                    // 产生随机数的附庸语句 
    int number= rand()%100;            // 产生随机数的语句 
    int count=0,a=0;
    printf("我已经想好了一个一百以内的整数。\n");
	do
	{
	  printf("请输入一个一百以内的整数：");
	  scanf("%d",&a);
	  count++;
	  if(a>number)
	    printf("你输入的数大了,");
	  else
	    if(a<number) 
	      printf("你输入的数小了,");
	}
	while(a!=number);
	printf("恭喜你，猜对了。");
	printf("你总计猜了%d次。",count);
	return 0; 
}

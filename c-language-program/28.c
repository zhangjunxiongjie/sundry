//计算输入数字的平均数，当输入-1时结束输入
#include <stdio.h>
int main ()
{
int sum=0,count=0,number=0;
while(number!=-1)            //判断输入的数字是否是-1
{
  sum+=number;
  count++;                   //计算输入数字的个数
  scanf("%d",&number);      //循环内的输入语句
}
sum=sum/(count-1);
printf("%d\n",sum);
return 0;
}
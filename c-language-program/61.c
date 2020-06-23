#include <stdio.h> //
int main()
{
float score;
scanf("%f",&score);
_Bool a,b;    //_Bool逻辑运算符
a=score>=60;  //此处将score>=60的逻辑值赋给a
b=score<=69;
if(a&&b)
printf("The grade is C\n.");
return 0;
}

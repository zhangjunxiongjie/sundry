#include <stdio.h> //
int main()
{
float score;
scanf("%f",&score);
_Bool a,b;    //_Bool�߼������
a=score>=60;  //�˴���score>=60���߼�ֵ����a
b=score<=69;
if(a&&b)
printf("The grade is C\n.");
return 0;
}

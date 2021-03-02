#include <stdio.h> //条件语句的范围，如何用符号将条件语句与非条件语句区分，隔开。//
int main()         //条件语句仅包含条件关键字及往后第一个分号内的语句（无括号情况）//
{
    int a = 5, b = 3, s = a; //可以用中括号或者将条件执行语句与条件关键字键入同行语句之间用逗号隔开//
    if (a < b)
        s = b; //不键入同一行也可以通过用逗号隔开来使语句包含于条件语句内//
    s *= s;
    printf("%d\n", s);
    return 0;
}

#include <stdio.h>
int main()
{
    int a = 5, b = 3, s = a;
    if (a < b)
    {
        s = b;
        s *= s;
    }
    printf("%d\n", s);
    return 0;
}

#include <stdio.h>
int main()
{
    int a = 5, b = 3, s = a;
    if (a < b)
        s = b, s *= s;
    printf("%d\n", s);
    return 0;
}
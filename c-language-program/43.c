#include <stdio.h> //任意输入一个数判断其是否是“水仙花数”//
main()
{
    int t, a, b, c, n;
    printf("请输入一个三位数:");
    scanf("%d", &t);
    a = t / 100;
    b = t / 10;
    b = (b * 10 - a * 100) / 10;
    c = t - a * 100 - b * 10;
    n = a * a * a + b * b * b + c * c * c;
    if (t == n)
        printf("%d 是一个水仙花数\n", t);
    else
        printf("%d 并不是一个水仙花数\n", t);
}
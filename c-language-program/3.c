#include <stdio.h>
int main()
{
    int max(int x, int y);
    int a, b, c;
    scanf("%d,%d", &a, &b); //a,b值的任意输入语句//
    c = max(a, b);
    printf("max=%d\n", c);
    return 0;
}
int max(int x, int y)
{
    int z;
    if (x > y)
        z = x; //条件语句//
    else
        z = y;
    return (z);
}
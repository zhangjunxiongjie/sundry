
#include <stdio.h> //判断一个数的所有因子的和是否等于其本身“完数”//
int main()         //并输出它的因子//
{
    int t, n, k, s;
    scanf("%d", &n);
    k = 1;
    t = 0;
    while (k < n)
    {
        if (n % k == 0)
            t = t + k;
        k = k + 1;
    }
    if (n == t) //当n==t即此数是一个完数时，输出其所有因子。此处输出因子的语句存在问题，判断语句准确//
    {
        printf("%d its factors are：", n);
        for (k = 1, s = 0; k < n; k++)
        {
            if (n % k == 0)
                printf(" %d ", k);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h> //判断一个数的所有因子的和是否等于其本身“完数”//
int main()         //并输出它的因子//
{
    int t, n, k, s;
    scanf("%d", &n);
    k = 1;
    t = 0;
    while (k < n)
    {
        if (n % k == 0)
            t = t + k;
        k = k + 1;
    }
    if (n == t)
        printf("%d its factors are.\n", n);
    else
        printf("%d its factors are not.\n", n);
    return 0;
}

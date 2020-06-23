//求π的值
#include <stdio.h>
#include <math.h>
int main()
{
    int sign1 = -1, sign2 = -1;
    long int i1 = 0, i2 = 0;
    double pi1 = 1.0, n1 = 3.0, term1;
    double pi2 = 1.0, n2 = 3.0, term2;
    term1 = sign1 / n1;
    term2 = sign2 / n2;
    while (fabs(term1) >= 1e-6) //判断term的绝对值是否大于1e-6
    {                           //当term的值小于1e-6时计算机视为零值即无法对小于1e-6的数进行运算。
        pi1 = pi1 + term1;      //不能直接写为“>=0”会出错
        term1 = sign1 * term1 * n1 / (n1 + 2);
        n1 = n1 + 2;
        i1++;
    }
    while (fabs(term2) >= 1e-8) //
    {
        pi2 = pi2 + term2;
        term2 = sign2 * term2 * n2 / (n2 + 2);
        n2 = n2 + 2;
        i2++;
    }
    pi1 = 4 * pi1;
    pi2 = 4 * pi2;
    printf("pi1=%10.8f\t", pi1);
    printf("总计计算了%ld次\n", i1);
    printf("pi2=%10.8f\t", pi2);
    printf("总计计算了%ld次\n", i2);
    return 0;
}
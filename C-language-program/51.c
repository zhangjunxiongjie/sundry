#include <stdio.h> //计算k的累加和与k*k的累加和与1/k的累加和的和//
int main()
{
    int i, j, k;
    float n, t, sum;
    k = 0;
    j = 0;
    t = 0.0;
    for (i = 100; i >= 1; i--)
        k = k + i;
    for (i = 50; i >= 1; i--)
        j = j + i * i;
    for (n = 10.0; n >= 1; n--)
        t = t + 1.0 / n;
    sum = t + j + k;
    printf("%f\n", sum);
    return 0;
}

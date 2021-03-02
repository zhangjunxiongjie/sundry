#include <stdio.h> //pi（圆周率）值的计算//
#include <math.h>  //pi=1-1/3+1/5-1/7+...-1/（n+2）//
main()
{
    float trem, pi, sign, n;
    sign = 1.0;
    n = 1.0;
    pi = 1.0;
    while (fabs(trem) >= 1e-6)
    {
        sign = -sign;
        n = n + 2;
        trem = sign / n;
        pi = pi + trem;
    }
    pi = pi * 4;
    printf("%f\n", pi);
}

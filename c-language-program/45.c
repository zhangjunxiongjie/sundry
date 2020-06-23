#include <stdio.h> //º∆À„2+22+222...//
#include <math.h>
main()
{
    int a, s, sum = 0;
    double k, t;
    scanf("%d,%lf", &a, &t);
    while (t >= 0.0)
    {
        k = t;
        for (s = 0; k >= 0.0; k--)
            s = s + a * pow(10, k);
        sum = sum + s;
        t = t - 1.0;
    }
    printf("%d\n", sum);
}

#include <stdio.h>
#include <math.h>
int main()
{
    int n = 5, a = 2, t = 1, s, sum = 0;
    double k;
    while (t <= n)
    {
        for (k = 0.0; k < t; k++)
        {
            s = a * pow(10.0, k);
            sum = sum + s;
        }
        t = t + 1;
    }
    printf("%d\n", sum);
    return 0;
}
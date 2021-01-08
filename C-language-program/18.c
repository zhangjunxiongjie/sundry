//求解一元二次方程的根（实根或虚根）
#include <stdio.h>
#include <math.h>
int main()
{
    void qsg(int a, int b, int c); //调用函数求实根
    void qyg(int a, int b);        //
    void qxg(int a, int b, int c); //调用函数求虚根
    int m, n, f, d;
    scanf("%d,%d,%d", &m, &n, &f);
    d = n * n - 4 * m * f;
    if (d > 0) //判断Δ的范围
        qsg(m, n, f);
    else //根据条件语句的判断在不同条件下
    {
        if (d == 0)
            qyg(m, n);
        else //使用不同的被调用函数来求解方程根
            qxg(m, n, f);
    }
    return 0;
}

void qsg(int a, int b, int c) //对三个不同条件下对方程求解的被调用函数进行定义
{
    double x1, x2, d;
    d = b * b - 4 * a * c;
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    printf("x1=%5.3f,x2=%5.3f\n", x1, x2);
}

void qyg(int a, int b)
{
    double x1;
    x1 = -b / (2 * a);
    printf("x1=x2=%5.3f\n", x1);
}

void qxg(int a, int b, int c)
{
    double e, f;
    e = -b / (2 * a);
    f = sqrt(4 * a * c - b * b) / 2 * a;
    printf("x1=%5.3f-%5.3fi\n", e, f);
    printf("x2=%5.3f+%5.3fi\n", e, f);
}
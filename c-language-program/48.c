
#include <stdio.h> //�ж�һ�������������ӵĺ��Ƿ�����䱾��������//
int main()         //�������������//
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
    if (n == t) //��n==t��������һ������ʱ��������������ӡ��˴�������ӵ����������⣬�ж����׼ȷ//
    {
        printf("%d its factors are��", n);
        for (k = 1, s = 0; k < n; k++)
        {
            if (n % k == 0)
                printf(" %d ", k);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h> //�ж�һ�������������ӵĺ��Ƿ�����䱾��������//
int main()         //�������������//
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

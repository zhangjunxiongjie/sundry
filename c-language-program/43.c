#include <stdio.h> //��������һ�����ж����Ƿ��ǡ�ˮ�ɻ�����//
main()
{
    int t, a, b, c, n;
    printf("������һ����λ��:");
    scanf("%d", &t);
    a = t / 100;
    b = t / 10;
    b = (b * 10 - a * 100) / 10;
    c = t - a * 100 - b * 10;
    n = a * a * a + b * b * b + c * c * c;
    if (t == n)
        printf("%d ��һ��ˮ�ɻ���\n", t);
    else
        printf("%d ������һ��ˮ�ɻ���\n", t);
}
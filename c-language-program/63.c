#include <stdio.h> //ʵ�ֶ�ʮ�������������,����ָ�룬�ڵ��ú����е�����һ��������
int main()         //�ڰ����������ú����β�������ú�����ʵ��ʱ�����ܴ���ֵ.
{
    void sort(int *p, int n);
    int a[10], i;
    printf("enter array:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    sort(a, 10);
    printf("The sorted array:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

void sort(int *p, int n)
{
    void jh(int *a, int *b);
    int i, t;
    for (t = 0; t < n; t++)
        for (i = t + 1; i < n; i++)
            if (*(p + t) > *(p + i))
                jh(p + t, p + i);
}

void jh(int *a, int *b)
{
    int f;
    f = *a;
    *a = *b;
    *b = f;
}
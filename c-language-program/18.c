//���һԪ���η��̵ĸ���ʵ���������
#include <stdio.h>
#include <math.h>
int main()
{
    void qsg(int a, int b, int c); //���ú�����ʵ��
    void qyg(int a, int b);        //
    void qxg(int a, int b, int c); //���ú��������
    int m, n, f, d;
    scanf("%d,%d,%d", &m, &n, &f);
    d = n * n - 4 * m * f;
    if (d > 0) //�жϦ��ķ�Χ
        qsg(m, n, f);
    else //�������������ж��ڲ�ͬ������
    {
        if (d == 0)
            qyg(m, n);
        else //ʹ�ò�ͬ�ı����ú�������ⷽ�̸�
            qxg(m, n, f);
    }
    return 0;
}

void qsg(int a, int b, int c) //��������ͬ�����¶Է������ı����ú������ж���
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
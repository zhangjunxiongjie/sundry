//��е�ֵ
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
    while (fabs(term1) >= 1e-6) //�ж�term�ľ���ֵ�Ƿ����1e-6
    {                           //��term��ֵС��1e-6ʱ�������Ϊ��ֵ���޷���С��1e-6�����������㡣
        pi1 = pi1 + term1;      //����ֱ��дΪ��>=0�������
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
    printf("�ܼƼ�����%ld��\n", i1);
    printf("pi2=%10.8f\t", pi2);
    printf("�ܼƼ�����%ld��\n", i2);
    return 0;
}
#include <stdio.h> //�������ķ�Χ������÷��Ž���������������������֣�������//
int main()         //�����������������ؼ��ּ������һ���ֺ��ڵ���䣨�����������//
{
    int a = 5, b = 3, s = a; //�����������Ż��߽�����ִ������������ؼ��ּ���ͬ�����֮���ö��Ÿ���//
    if (a < b)
        s = b; //������ͬһ��Ҳ����ͨ���ö��Ÿ�����ʹ�����������������//
    s *= s;
    printf("%d\n", s);
    return 0;
}

#include <stdio.h>
int main()
{
    int a = 5, b = 3, s = a;
    if (a < b)
    {
        s = b;
        s *= s;
    }
    printf("%d\n", s);
    return 0;
}

#include <stdio.h>
int main()
{
    int a = 5, b = 3, s = a;
    if (a < b)
        s = b, s *= s;
    printf("%d\n", s);
    return 0;
}
#include <stdio.h> //���ͬʱ�ܱ�3,7��������//
main()
{
    int i, j = 0;
    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 7 == 0)
        {
            printf("%d\t", i);
            j = j + 1;
            if (j % 10 == 0)
                printf("\n");
        }
    }
}

#include <stdio.h> //������в��ܱ�3�������߲��ܱ�7��������//
main()
{
    int i, j = 0;
    for (i = 1; i <= 100; i++)
    {
        if (i % 3 != 0 || i % 7 != 0)
        {
            printf("%d\t", i);
            j = j + 1;
            if (j % 10 == 0)
                printf("\n");
        }
    }
}
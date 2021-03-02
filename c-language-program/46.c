#include <stdio.h> //输出同时能被3,7整除的数//
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

#include <stdio.h> //输出所有不能被3整除或者不能被7整除的数//
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
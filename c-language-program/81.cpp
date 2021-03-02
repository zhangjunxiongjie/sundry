// 分组排序，希尔排序法

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void shellSort(int array[], int size)
{
    int i = size;
    int j, k, tmp;
    for (i = size / 2; i > 0; i = i / 2)
    { // i 为分组间隔，间隔是越来越小的
        // std::cout << "i:" << i << std::endl;
        for (j = i; j < size; j++)
        { // 对每一个分组进行排序，多次遍历每一个分组
            // 冒泡式移动直到达到正确位置。
            for (k = j - i; k >= 0; k = k - i)
            { // 将后面同一组的元素往前面已经排好序元素插入。
                if (array[k + i] >= array[k])
                { // 遇到的第一个元素一定是最大的那个元素
                    break;
                }
                else
                { // 如果插入元素比遇到的第一个元素小那么就一步一步往前移。
                    tmp = array[k];
                    array[k] = array[k + i];
                    array[k + i] = tmp;
                }
            }
        }
    }
}

int main()
{

    int array[20];
    int range = 500;
    for (int i = 0; i < 100; i++)
    {
        array[i] = rand() % range + 1;
    }
    int size = sizeof(array) / sizeof(array[0]);

    clock_t start = clock();
    shellSort(array, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    for (int i : array)
    {
        std::cout << i << ":";
    }
    std::cout << std::endl;

    printf("Data Sorted\n");
    printf("%s\n", "Shell Sort Big O Notation:\n--> Best Case: O(n log(n))\n--> Average Case: depends on gap sequence\n--> Worst Case: O(n)\n");
    printf("Time spent sorting: %f\n", time_spent);

    return 0;
}

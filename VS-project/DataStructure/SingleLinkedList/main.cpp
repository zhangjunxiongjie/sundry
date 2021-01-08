// 单链表的实现。

#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main()
{
    SINGLELIST list;

    list.ListCout();
    
    list.ListPushBack(0);
    list.ListPushBack(5);
    list.ListPushBack(7);
    list.ListInsNext(1, 3);
    list.ListInsNext(3, 6);

    list.ListCout();

    list.ListRemNext(list.ListFind(7));
    list.ListPopBack();
    list.ListRemNext(list.ListFind(0));
    list.ListRemNext(list.ListFind(5));
    list.ListPopBack();

    list.ListClear();

    list.ListPopBack();
    list.ListRemNext(list.ListFind(5));


    list.ListCout();

    list.ListPushBack(-1);
    list.ListInsNext(2, 3);

    list.ListCout();

    system("pause");
    return 0;
}

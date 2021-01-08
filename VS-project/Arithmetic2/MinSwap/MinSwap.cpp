// MinSwap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// [23] 最少交换：进行最少的交换使得有 0,1 的数组中所有 0 都位于 1 前面。

#include <iostream>
#include <vector>
using namespace std;

void MinSwap(vector<int>& target) {
    int ileft = 0;
    int iright = target.size() - 1;
    int count = 0;
    while (ileft < iright)
    {
        while (ileft < iright && target.at(ileft) == 0)
        {
            ileft++;
        }
        while (ileft < iright && target.at(iright) == 1)
        {
            iright--;
        }
        if (ileft < iright)
        {
            int middle = target.at(ileft);
            target.at(ileft) = target.at(iright);
            target.at(iright) = middle;
            count++;
        }
    }

    cout << count << ":";
    for (auto iter = target.begin(); iter != target.end(); iter++)
    {
        cout << *iter;
    }
    cout << endl;
}

int main()
{
    vector<int> target{0,1,0,0,1,0,1,0};

    MinSwap(target);

    system("pause");
    return 0;
}

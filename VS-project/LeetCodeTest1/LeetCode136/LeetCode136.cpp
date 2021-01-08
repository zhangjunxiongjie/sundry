// LeetCode136.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【136】只出现一次的数字。

#include <iostream>
#include <vector>
using namespace std;

/* 使用异或实现。
交换律：a ^ b ^ c <=> a ^ c ^ b
任何数于0异或为任何数 0 ^ n => n
相同的数异或为0: n ^ n => 0

var a = [2,3,2,4,4]
2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3
*/
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (auto iter = nums.begin(); iter != nums.end(); iter++)
    {
        result ^= *iter;
    }
    return result;
}

/*
// 时间复杂度太高了，可是又不能使用额外空间根本无法标记。
// 一种想法是直接在原容器直接比较，但是得有一个合理的比较策略。
// 有待优化。
int singleNumber(vector<int>& nums) {
    int result = 0;
    while (!nums.empty())
    {
        auto iter = nums.begin();
        for (; iter != nums.end(); iter++)
        {
            if (*iter == nums.back())
            {
                break;
            }
        }

        if (iter == nums.end() - 1) // 
        {
            result = nums.back();
            break;
        }
        else
        {
            nums.erase(iter);
            nums.pop_back();
        }
    }

    return result;
}
*/

int main()
{
    vector<int> nums{4, 1, 2, 1, 2};
    
    cout << singleNumber(nums) << endl;
    
    system("pause");
    return 0;
}

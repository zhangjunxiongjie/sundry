#include <iostream>
#include <bitset> // 位容器
#include <vector>
#include <cstdlib>

// 只实现两个正整数相乘。
long int two_number_multiply(int num1, int num2)
{
    long int result = 0;
    std::bitset<sizeof(int) * 8> bst(num1);
    for (int i = 0; i < bst.size(); i++)
    {
        if (bst[i])
        {
            result += num2 << i;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        return 1;
    }
    std::cout << two_number_multiply(atoi(argv[1]), atoi(argv[2])) << std::endl;
    
    // system("pause");
    return 0;
}


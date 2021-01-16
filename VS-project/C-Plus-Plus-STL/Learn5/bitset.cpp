// STL bitset 位容器测试。

#include <iostream>

#include <bitset>

#include <string>

using std::bitset;
using std::endl;
using std::cout;

int main()
{
    bitset<7> bst1;
    bitset<7> bst2;
    cout << "1) " << bst1 << endl; //输出 1) 0000000
    bst1.set(0, 1);//将第0位变成1，bst1变为 0000001
    cout << "2) " << bst1 << endl; //输出 2) 0000001
    bst1 <<= 4; //左移4位，变为 0010000
    cout << "3) " << bst1 << endl; //输出 3) 0010000
    bst2.set(2);//第二位设置为1，bst2变成  0000100
    bst2 |= bst1; // bst2变成  0010100
    cout << "4) " << bst2 << endl; //输出 4) 0010100
    cout << "5) " << bst2.to_ulong() << endl; //输出 5) 20
    bst2.flip(); //每一位都取反，bst2变成 1101011
    bst1.set(3); //bst1变成  0011000
    bst2.flip(6); //bst2变成 0101011
    bitset<7> bst3 = bst2 ^ bst1;//bst3 变成 0110011
    cout << "6) " << bst3 << endl; //输出 6) 0110011
    cout << "7) " << bst3[3] << "," << bst3[4] << endl; //输出 7) 0,1

    system("pause");
    return 0;
}
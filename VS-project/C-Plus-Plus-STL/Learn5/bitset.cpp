// STL bitset λ�������ԡ�

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
    cout << "1) " << bst1 << endl; //��� 1) 0000000
    bst1.set(0, 1);//����0λ���1��bst1��Ϊ 0000001
    cout << "2) " << bst1 << endl; //��� 2) 0000001
    bst1 <<= 4; //����4λ����Ϊ 0010000
    cout << "3) " << bst1 << endl; //��� 3) 0010000
    bst2.set(2);//�ڶ�λ����Ϊ1��bst2���  0000100
    bst2 |= bst1; // bst2���  0010100
    cout << "4) " << bst2 << endl; //��� 4) 0010100
    cout << "5) " << bst2.to_ulong() << endl; //��� 5) 20
    bst2.flip(); //ÿһλ��ȡ����bst2��� 1101011
    bst1.set(3); //bst1���  0011000
    bst2.flip(6); //bst2��� 0101011
    bitset<7> bst3 = bst2 ^ bst1;//bst3 ��� 0110011
    cout << "6) " << bst3 << endl; //��� 6) 0110011
    cout << "7) " << bst3[3] << "," << bst3[4] << endl; //��� 7) 0,1

    system("pause");
    return 0;
}
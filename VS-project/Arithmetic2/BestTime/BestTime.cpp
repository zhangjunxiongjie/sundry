// BestTime.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// [25] 最好的时代。根据科学家的出生死亡年份，得出科学家在世最多的年份区间。

#include <iostream>
#include <vector>
using namespace std;

typedef struct 
{
    int birth; // 出生年份
    int die; // 死亡年份。
}Scientist;

void BestTime(vector<int>& birth, vector<int>& die) {
    int count = 0;
    int max = 0, b, d;
    int lastyear = 0;
    for (auto iterb = birth.begin(), iterd = die.begin(); iterb != birth.end() && iterd != die.end();)
    {
        if (*iterb < *iterd)
        {
            count++;
            lastyear = *iterb;
            iterb++;
        }
        else if(*iterb > *iterd)
        {
            count--;
            lastyear = *iterd;
            iterd++;
        }
        else
        {
            iterb++;
            iterd++;
        }
        if (count > max) 
        {
            max = count;
            b = lastyear;
            if (iterb != birth.end() && iterd != die.end())
            {
                d = *iterb < *iterd ? *iterb : *iterd;
            }
            else if(iterb != birth.end()) // 肯定是 birth 数组先到 end，birth到最后意味着 count 只会减不会增，所以剩余的 die 不用处理。
            {
                d = *iterb;
            }
            /*else
            {
                d = *iterd;
            }*/
        }
    }
    cout << max << ":" << b << ":" << d << endl;
}

void struce_To_vector(vector<Scientist>& target, vector<int>& birth, vector<int>& die) {
    for (auto iter = target.begin(); iter != target.end(); iter++)
    {
        birth.push_back(iter->birth);
        die.push_back(iter->die);
    }
    for (auto iter = birth.begin(); iter != birth.end(); iter++)
    {
        for (auto iter1 = iter + 1; iter1 != birth.end(); iter1++)
        {
            if (*iter > *iter1) {
                int middle = *iter;
                *iter = *iter1;
                *iter1 = middle;
            }
        }
    }
    for (auto iter = die.begin(); iter != die.end(); iter++)
    {
        for (auto iter1 = iter + 1; iter1 != die.end(); iter1++)
        {
            if (*iter > * iter1) {
                int middle = *iter;
                *iter = *iter1;
                *iter1 = middle;
            }
        }
    }
    cout << "birth:";
    for (auto iter = birth.begin(); iter != birth.end(); iter++)
    {
        cout << *iter << ":";
    }
    cout << endl;
    cout << "die:";
    for (auto iter = die.begin(); iter != die.end(); iter++)
    {
        cout << *iter << ":";
    }
    cout << endl;
}

int main()
{
    vector<Scientist> target{ {1908, 1929}, {1932, 1945}, {1920, 1934}, {1929, 1935}, {1919, 1938}, {1904, 1922}, 
                              {1924, 1935}, {1929, 1936}, {1929, 1938}, {1910, 1939}, {1926, 1933}, {1913, 1936},
                              {1902, 1929}, {1911, 1924}, {1920, 1935}, {1925, 1943} };
    vector<int> birth, die;

    struce_To_vector(target, birth, die);

    BestTime(birth, die);
    
    system("pause");
    return 0;
}


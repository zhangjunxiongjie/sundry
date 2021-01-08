// StateTransition.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【35】三个水壶（状态转移）：有三个水壶容量分别为 8L,5L,3L。8L 水壶装满水，
// 其余均为空，问如何通过倒满水倒空水得到 4L 水。
// 对初始状态进行状态转换直到出现 4L 水为止，要避免对已进行过状态转换和已遇到过的状态进行再处理
// 出错！！！未实现思路。

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

class Kettle // 状态类。
{
public:
    int large;
    int middle;
    int small;

    friend bool operator==(Kettle& k1, Kettle& k2);

    Kettle(int l, int m, int s);
    ~Kettle();

private:

};

bool operator==(Kettle& k1, Kettle& k2) {
    if (k1.large == k2.large && k1.middle == k2.middle && k1.small == k2.small)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Kettle::Kettle(int l, int m, int s)
{
    large = l;
    middle = m;
    small = s;
}
Kettle::~Kettle()
{
}



void Create(vector<Kettle>& buf, Kettle& ket) { // 生成新状态
    if (ket.large > 0)
    {
        if (ket.large >= 5 - ket.middle)
        {
            buf.push_back(Kettle{ ket.large - (5 - ket.middle), 5, ket.small });
        }
        else
        {
            buf.push_back(Kettle{ 0, ket.middle + ket.large, ket.small });
        }

        if (ket.large >= 3 - ket.small)
        {
            buf.push_back(Kettle{ ket.large - (3 - ket.small), ket.middle, 3 });
        }
        else
        {
            buf.push_back(Kettle{ 0, ket.middle, ket.small + ket.large });
        }
    }
    if (ket.middle > 0)
    {
        if (ket.middle >= 8 - ket.large)
        {
            buf.push_back(Kettle{ 8, ket.middle - (8 - ket.large), ket.small });
        }
        else
        {
            buf.push_back(Kettle{ ket.large + ket.middle, 0, ket.small });
        }
        if (ket.middle >= 3 - ket.small)
        {
            buf.push_back(Kettle{ ket.large, ket.middle - (3 - ket.small), 3 });
        }
        else
        {
            buf.push_back(Kettle{ ket.large, 0, ket.small + ket.middle });
        }
    }
    if(ket.small > 0)
    {
        if (ket.small >= 8 - ket.large)
        {
            buf.push_back(Kettle{ 8, ket.middle, ket.small - (8 - ket.large)});
        }
        else
        {
            buf.push_back(Kettle{ ket.large + ket.small, ket.middle, 0 });
        }
        if (ket.small >= 5 - ket.middle)
        {
            buf.push_back(Kettle{ ket.large, 5, ket.small - (5 - ket.middle) });
        }
        else
        {
            buf.push_back(Kettle{ ket.large, ket.middle + ket.small, 0});
        }
    }
}

void StateChange(Kettle& target) {
    map<Kettle, vector<Kettle>> assistant;
    set<Kettle> vessel;
    queue<Kettle> que;

    vessel.insert(target);
    que.push(target);
    
    while (!que.empty())
    {
        vector<Kettle> buffer;
        Kettle ket = que.front();
        que.pop();

        Create(buffer, ket);

        for (int i = 0; i < buffer.size(); i++)
        {
            auto setiter = vessel.find(buffer.at(i));
            if (setiter != vessel.end())
            {
            }
            else if(buffer.at(i).large == 4 || buffer.at(i).middle == 4)
            {
                return;
            }
            else
            {
                vessel.insert(buffer.at(i));
                que.push(buffer.at(i));
            }
        }
    }
    
}

int main()
{
    Kettle initial{ 8, 0, 0 };

    StateChange(initial);

    system("pause");
    return 0;
}

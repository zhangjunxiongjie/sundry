// LeetCode155.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【155】最小栈。

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    // 有待优化。
    vector<int> data;
    vector<int> list;

    MinStack() {

    }

    void push(int x) {
        data.push_back(x);

        auto iter = list.begin();
        bool flag = true;
        for (; iter != list.end(); iter++)
        {
            if (x > *iter)
            {
                list.insert(iter, x);
                flag = false;
                break;
            }
        }
        if (flag && iter == list.end())
        {
            list.push_back(x);
        }

    }

    void pop() {
        int buffer = data.back();
        data.pop_back();

        auto iter = list.begin();
        bool flag = true;
        for (; iter != list.end(); iter++)
        {
            if (*iter == buffer)
            {
                list.erase(iter);
                flag = false;
                break;
            }
        }
        if (flag && iter == list.end())
        {
            list.pop_back();
        }

    }

    int top() {
        return data.back();
    }

    int getMin() {
        return list.back();
    }
};

int main()
{
    MinStack minStack = MinStack();
    minStack.push(-2);

    minStack.push(0);

    minStack.push(-3);
    
    minStack.getMin();   // -- > 返回 - 3.
    minStack.pop();
    minStack.top();      // -- > 返回 0.
    minStack.getMin();  // -- > 返回 - 2.

    system("pause");
    return 0;
}


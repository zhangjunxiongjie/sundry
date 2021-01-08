// LeetCode150.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// [150] 逆波兰表达式求值

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void stringtochar(string& s, char* c) {
        int i = 0;
        for (; i < s.size(); i++)
        {
            c[i] = s.at(i);
        }
        c[i] = '\0';
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> heap;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens.at(i) != "+" && tokens.at(i) != "-" && tokens.at(i) != "*" && tokens.at(i) != "/")
            {
                // 这里为了将字符串转数字先将 string 转为 char*。然后使用 atoi() 将 char* 转为数字。
                char buffer[5];
                stringtochar(tokens.at(i), buffer);
                cout << buffer << ":";

                heap.push(atoi(buffer));
            }
            else
            {
                int figure2 = heap.top();
                heap.pop();
                int figure1 = heap.top();
                heap.pop();

                int figure = 0;

                if (tokens.at(i) == "+")
                {
                    figure = figure1 + figure2;
                }
                else if (tokens.at(i) == "-")
                {
                    figure = figure1 - figure2;
                }
                else if (tokens.at(i) == "*")
                {
                    figure = figure1 * figure2;
                }
                else if (tokens.at(i) == "/")
                {
                    figure = figure1 / figure2;
                }
                else
                {
                    cout << "error";
                }

                cout << "figure1:" << figure1 << "figure2:" << figure2 << ":";
                heap.push(figure);
            }
        }
        return heap.top();
    }
};

int main()
{
    Solution object;
    
    vector<string> tokens{ "4", "13", "5", "/", "+" };

    cout << object.evalRPN(tokens) << endl;

    system("pause");
    return 0;
}


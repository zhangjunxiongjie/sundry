// LeeCode_test49.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【49】字母异位词分组。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 优化版。
// 判断两个字符串是否为字母异位词。
bool judge(string& str, vector<int> compare)
{
    for (int i = 0; i < str.size(); i++)
    {
        // 因为这里要对compare进行修改但是compare后续还要使用所以这里没有使用引用。
        if (compare.at(str.at(i) - 'a') > 0)
            compare.at(str.at(i) - 'a')--;
        else
            return false;
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>& result = *new vector<vector<string>>;

    vector<vector<int>> compare;
    for (int i = 0; i < strs.size(); i++)
    {
        vector<int> cache;
        cache.resize(26, 0); // 26个零
        string& str = strs.at(i);

        for (int j = 0; j < str.size(); j++)
        {
            cache.at(str.at(j) - 'a')++; // 记录每个字幕的个数
        }
        compare.push_back(cache);
    }

    vector<int> sign; // 标志数组
    for (int i = 0; i < strs.size(); i++)
    {
        sign.push_back(i);
    }
    vector<int> seat;
    while (!sign.empty())
    {
        int flag = sign.at(sign.size() - 1);
        string str = strs.at(flag);

        int i = 0;
        for (; i < result.size(); i++)
        {
            if (result.at(i).at(0).size() == str.size() && judge(str, compare.at(seat.at(i))))
            {
                result.at(i).push_back(str);
                break;
            }
        }
        if (i == result.size())
        {
            vector<string> buffer;
            buffer.push_back(str);

            seat.push_back(flag);
            result.push_back(buffer);
        }
        sign.pop_back();
    }

    return result;
}

/*
// 判断两个字符串是否为字母异位词。
bool judge(string& str1, string& str2, vector<int> compare)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        if (compare.at(str2.at(i) - 'a') > 0)
            compare.at(str2.at(i) - 'a')--;
        else
            return false;
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>& result = *new vector<vector<string>>;

    vector<vector<int>> compare;

    for (int i = 0; i < strs.size(); i++)
    {
        vector<int> cache;
        cache.resize(26, 0); // 26个零
        string& str = strs.at(i);

        for (int j = 0; j < str.size(); j++)
        {
            cache.at(str.at(j) - 'a')++; // 记录每个字幕的个数
        }

        compare.push_back(cache);
    }

    vector<int> sign; // 标志数组
    sign.resize(strs.size(), 1); // 未使用
    int number = 0; // 计数
    while (number != strs.size())
    {
        vector<string> cache;
        int flag;
        for (int i = 0; i < strs.size(); i++)
        {
            if (sign.at(i))
            {
                cache.push_back(strs.at(i));
                sign.at(i) = 0;
                flag = i;
                number++;
                break;
            }
        }

        for (int i = 0; i < strs.size(); i++)
        {
            // cout << i << strs.at(i) << sign.at(i) << cache.at(0) << ":::";

            if (sign.at(i) && judge(cache.at(0), strs.at(i), compare.at(flag)))
            {
                cache.push_back(strs.at(i));
                sign.at(i) = 0;
                number++;
            }
        }
        // cout << endl;

        for (int i = 0; i < cache.size(); i++)
        {
            cout << cache.at(i) << ":";
        }
        cout << endl;


        result.push_back(cache);
    }
    return result;
}
*/

int main()
{
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };

    vector<vector<string>>* result = &groupAnagrams(strs);

    for (int i = 0; i < result->size(); i++)
    {
        for (int j = 0; j < result->at(i).size(); j++)
        {
            cout << result->at(i).at(j) << ":";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}


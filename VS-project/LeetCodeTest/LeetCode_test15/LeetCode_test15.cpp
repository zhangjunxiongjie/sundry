// LeetCode_test15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 力扣：【15】三数之和

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool Judge(vector<int>& x1, vector<int>& x2) // 判重
    {
        return true;
    }

    vector<vector<int>> threeSum(vector<int>& nums) { // 传入一个向量的引用
        vector<vector<int>> target;

        for (int i = 0; i < nums.size(); i++) //先排序
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums.at(i) > nums.at(j))
                {
                    int middle = nums.at(i);
                    nums.at(i) = nums.at(j);
                    nums.at(j) = middle;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) // 计算出所有二元组
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                vector<int> cache;
                cache.push_back(nums.at(i));
                cache.push_back(nums.at(j));
                cache.push_back(-nums.at(i) - nums.at(j)); // 最后加的这个数还没有判断存在性 

                target.push_back(cache);
            }
        }

        for (int i = 0; i < target.size(); i++) // 去除所有不完整三元组
        {
            int j = 0;

            for (; j < nums.size(); j++)
            {
                if (target.at(i).at(2) == nums.at(j))
                    break;
            }
            

            if (target.at(i).at(0) == target.at(i).at(2)) // 如果前面有一个数与最后一个数相同
            {
                for (j = j + 1; j < nums.size(); j++)
                {
                    if (target.at(i).at(2) == nums.at(j))
                        break;
                }
            }

            if (target.at(i).at(1) == target.at(i).at(2))
            {
                for (j = j + 1; j < nums.size(); j++)
                {
                    if (target.at(i).at(2) == nums.at(j))
                        break;
                }
            }
            
            // cout << nums.size() << ":" << j << endl;
            // cout << i << ":" << target.at(i).at(0) << ":" << target.at(i).at(1) << ":" << target.at(i).at(2) << endl;
            
            //cout << "i:" << i << endl;
            if (j == nums.size()) // 删除不完整三元组
            {
                // cout << target.at(i + 1).at(0) << ":" << target.at(i + 1).at(1) << ":" << target.at(i + 1).at(2) << endl;
                target.erase(target.begin() + i, target.begin() + i + 1);
                //cout << target.at(i).at(0) << ":" << target.at(i).at(1) << ":" << target.at(i).at(2) << endl;
                
                i--; // 删除一个少一个,continue.
            }
            
        }


        return target;
    }

};


int main()
{
    vector<int> imput = { -1,0,1,2,-1,-4 };
    Solution object;
    object.threeSum(imput);

    system("pause");
}


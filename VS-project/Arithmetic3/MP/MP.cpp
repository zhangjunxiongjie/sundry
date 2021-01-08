// 模式匹配算法MP，利用跳转表尽可能的避免回溯。

#include <iostream>
#include <string>
using namespace std;

// 构造跳转表
void BuildMP(string r, int* MPtable)
{
	int subscript = 0;  // 下标
	
	for (int i = 0; i < r.length(); i++) // 匹配不成功的模式字符串的位置
	{
		MPtable[i] = 0;
		
		if(i > 1) // i为1，0时对应的值必定为0.否则如果不为0,1则要使用到前面的匹配结果来对后面进行匹配。
		{
			int ir = MPtable[i - 1];  // 当i-1不能匹配到时模式字符串的跳转位置。
			while (true) // 
			{
				if (r.at(ir) == r.at(i - 1)) // 如果能匹配上
				{
					MPtable[i] = ir + 1;
					break;
				}
				else 
				{
					if (ir == 0) // 为零时直接结束
					{
						MPtable[i] = ir;
						break;
					}
					else  // 否则，当ir不能匹配时的跳转位置。递归的一种思想
					{
						ir = MPtable[ir]; // 移动，寻找，试探。
					}
				}

			}

		}
		
		/* 没有利用前面已经匹配的结果，效率较低。
		for (int j = 0, ir = 1; ir < i; j = 0, ir++)
		{

			int middle = ir; // 还原。
			while (ir < i && r.at(j) == r.at(ir)) // 如果相等则继续匹配.
			{
				j++;
				ir++;
			}

			if (ir == i)
			{
				MPtable[i] = j;
				break;
			}

			ir = middle;
		}
		*/
	}

}

void preMP(string r, int* MPtable)
{
	unsigned int i, j;
	i = 0;
	j = MPtable[0] = -1;
	while (i < r.length())
	{
		while (j > -1 && r.at(i) != r.at(j))
		{
			j = MPtable[j];
		}
		MPtable[++i] = ++j;
	}
}


int main()
{
	string target("ctcaatcacaatca");
	string result("");
	
	int MpTable[50]; // 使用new创建一个动态内存的数组。

	BuildMP(result, MpTable);
	// preMP(result, MpTable);

	for (int i = 0; i < result.length(); i++)
	{
		cout << i << ":" << MpTable[i] << endl;
	}

	system("pause");
    return 0;
}


// BM：模式字符串倒序匹配，坏字符偏移规则，好字符偏移规则。
//

#include <iostream>
#include <string>
using namespace std;

// 好后缀偏移规则。
// 可以直接由模式字符串得到每个位置的偏移，有点与MP使用到的跳转表类似。
/*
void GoodChar(int* table, string& t)
{
	
	int step_good;
	int pos1, pos2;

	for (int subscript = t.length() - 1; subscript >= 0; subscript--)
	{
		if (subscript == t.length() - 1) //尾字符为坏字符时，没有好后缀，此时偏移量为零。 
		{
			table[subscript] = 0; 
		}
		if (subscript == 0) // 首字符为坏字符时
		{
			if (t.at(0) == t.at(t.length() - 1)) // 首字符等于最后一个字符时
			{
				table[subscript] = t.length() - 1;
			}
			else
			{
				table[subscript] = t.length();
			}
		}


	}

}
*/
// 好后缀规则实现以及根据模式字符串求得偏移表。
void GoodChar(int* table, string& t)
{
	table[t.length() - 1] = 1; // 坏字符位置为t.length() - 1时，无好字符。 
	for (int subscript = t.length() - 2; subscript >= 0; subscript--) // 不同坏字符位置的偏移量
	{
		// 改变模式字符串开始匹配位置。此处始终是从t.length() - 2开始尝试匹配，然后依次改变尝试匹配的位置。
		for (int move = t.length() - 2; move >= 0; move--) 
		{
			int j = move;
			int i = t.length() - 1;
			while ( i > subscript && j >= 0 && t.at(i) == t.at(j)) // 当匹配前缀时及时不能够全匹配也是有效的匹配。
			{
				i--;
				j--;
			}

			if (i == subscript || j == -1) // 前缀匹配，全匹配。（要么全匹配，要么前缀匹配）
			{
				table[subscript] = (t.length() - 1) - move;
				break;
			}
			
		}
	}
}

// 坏字符偏移规则。坏字符偏移量也可以直接由模式字符串生成一个偏移表直接使用。
int BadChar(string& r, string& t, int r_site, int t_site)
{
	int step_bad;
	int pos1 = t_site, pos2 = -1;

	for (int i = t_site - 1; i >= 0; i--) // 在模式字符串(0~r_site - 1)区间中找到最右端的与坏字符匹配的字符。
	{
		if (r.at(r_site) == t.at(i))
		{
			pos2 = i;
			break;
		}
	}

	step_bad = pos1 - pos2; // 计算偏移量。

	return step_bad;
}

int main()
{
	string result("gcagcagaggcagagtcgcaggcagagcaggcagagaggagagtgcagagagcagagtacagtgcagagacg");
	string target("gcagagag");

	int t_move = target.length() - 1; // 从右向左匹配。
	int r_move = t_move; // 开始匹配的位置。

	// int* BMtable = new int[target.length()];
	int BMtable[50]; // 好后缀偏移表

	GoodChar(BMtable, target); // 直接由模式字符串得到BM表

	
	for (int i = 0; i < target.length(); i++ )
	{
		cout << i << ":" << BMtable[i]<<endl;
	}
	
	
	while(true)
	{
		int r_keep = r_move; // 保留开始匹配的位置信息。

		while (t_move >= 0 && result.at(r_move) == target.at(t_move)) // 进行匹配
		{
			r_move--;
			t_move--;
		}
		
		if (t_move == -1) // 成功匹配。
		{
			cout << r_move + 1 << endl;
			for (int i = r_move + 1; i < target.length() + r_move + 1; i++)
			{
				cout << result.at(i);
			}
			cout << endl;
			for (int i = 0; i < target.length(); i++)
			{
				cout << target.at(i);
			}
			cout << endl;
			break;
		}
		else
		{
			int good_offset = BMtable[t_move]; // 好后缀偏移量

			int bad_offset = BadChar(result, target, r_move, t_move); // 坏字符偏移量

			if (good_offset > bad_offset) // 取较大的偏移量以确保最优。
			{
				r_move = r_keep + good_offset;
			}
			else
			{
				r_move = r_keep + bad_offset;
			}

			t_move = target.length() - 1; // 重置模式字符串匹配位置
		}

	}
	
	system("pause");
	return 0;
}

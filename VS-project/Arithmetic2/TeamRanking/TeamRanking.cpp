// TeamRanking.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// [22] 球队排名：n 只球队进行循环锦标赛，每支球队之间都比赛过一次，现在你拥有所有的比赛结果。（不存在和局）
// 试对球队进行排名，使得每个球队都排在其所赢球队前面。
// 这里仅仅是排在其某一个输给当前球队的球队前面，而不是排在所有输给其的球队前面（特例下才可实现）。

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// 单场比赛比赛结果。
typedef struct {
	string winteam; // 获胜队
	string loseteam; // 输队
}Match;

// 计分法 赢一局得一分，输一局不得分。
// 此法是按照球队的总体实力进行排列，所以并不一定全部满足前一个球队赢后一个球队的要求（特例情况下可能全部满足）
void Scoring(vector<Match>& match, vector<string>& team) {
	map<string, int> teamscor;
	for (auto iter = team.begin(); iter != team.end(); iter++)
	{
		teamscor.insert(pair<string, int>(*iter, 0));
	}
	for (auto iter = match.begin(); iter != match.end(); iter++)
	{
		auto mapiter = teamscor.find(iter->winteam);
		if (mapiter != teamscor.end())
		{
			mapiter->second++;
		}
	}
	for (auto iter = teamscor.begin(); iter != teamscor.end(); iter++)
	{
		cout << iter->first << ":" << iter->second << endl;
	}
	cout << endl;
}

// 直接按照某一规则插入排列。
// 插入的规则就是找到第一个输给插入球队的球队并插入在其前面。所以所有球队都满足其后球队输给当前球队的要求。
void Arrange(map<string, vector<string>>& match) {
	vector<string> result;
	for (auto iter = match.begin(); iter != match.end(); iter++)
	{
		auto veciter = result.begin();
		
		auto resultend = result.end(); // result.end() 可能已发生改变，所以这里要记录下来。

		for (; veciter != result.end(); veciter++)
		{
			auto veciter1 = iter->second.begin();
			for(; veciter1 != iter->second.end(); veciter1++)
			{
				if (*veciter == *veciter1)
				{
					result.insert(veciter, iter->first);
					break;
				}
			}
			if (veciter1 != iter->second.end())
			{
				break;
			}
		}

		if (veciter == resultend) // result.end() 可能已发生改变，所以这里要记录下来。
		{
			result.push_back(iter->first);
		}
	}

	for (auto veciter = result.begin(); veciter != result.end(); veciter++)
	{
		cout << *veciter << ":";
	}
	cout << endl;
}

// 将比赛结果用另一种形式进行表示。结构体 转 字典形式。
void match_To_show(vector<Match>& match, map<string, vector<string>>& match1, vector<string>& team) {
	for (auto iter = team.begin(); iter != team.end(); iter++)
	{
		vector<string> buffer;
		match1.insert(pair<string, vector<string>>(*iter, buffer));
	}
	for (auto iter = match.begin(); iter != match.end(); iter++)
	{
		auto mapiter = match1.find(iter->winteam);
		if (mapiter == match1.end())
		{
			match1.insert(pair<string, vector<string>>(iter->winteam, { iter->loseteam }));
		}
		else
		{
			mapiter->second.push_back(iter->loseteam);
		}
	}
}

int main()
{
	// 球队：a b c d e 比赛结果。
	vector<Match> matchresult{ {"a","b"},
							   {"b","c"},
							   {"c","d"},{"c","a"},
							   {"d","e"},{"d","a"},{"d","b"},
							   {"e","b"},{"e","c"},{"e","a"} };

	vector<string> team{ "a", "b", "c", "d", "e" };

	Scoring(matchresult, team);


	map<string, vector<string>> matchresult1;
	/*
	matchresult1.insert(pair<string, vector<string>>("a", { "b","c","d","e" }));
	matchresult1.insert(pair<string, vector<string>>("b", { "c","d","e" }));
	matchresult1.insert(pair<string, vector<string>>("c", { "d","e" }));
	matchresult1.insert(pair<string, vector<string>>("d", { "e" }));
	*/
	match_To_show(matchresult, matchresult1, team);
	for (auto iter = matchresult1.begin(); iter != matchresult1.end(); iter++)
	{
		cout << iter->first << ":";
		for (auto veciter = iter->second.begin(); veciter != iter->second.end(); veciter++)
		{
			cout << *veciter << ",";
		}
		cout << endl;
	}
	cout << endl;

	Arrange(matchresult1);
	
	system("pause");
	return 0;
}

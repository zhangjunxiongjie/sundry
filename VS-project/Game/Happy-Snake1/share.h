#ifndef SHARE_H
#define SHARE_H

// 公用共享函数及数据类
// ??? array容器从1开始索引还是从零开始？？？
#include <array>

class Share
{
public:

	Share(int f, int h, int l); //构造函数

	typedef enum Key
	{
		restart, // 重新开始
		keep, // 保持，继续
		quit, // 退出。
		nullity // 无效
	}KEY;

	KEY GetKey(); // 获取按键
	void SetKey(KEY k); // 重置按键

	void InIt(); // 重新开始初始化

	void GoToXY(const int x, const int y); // 设置光标位置

	void SetTextColor(int colorID); // 设置文本前景颜色

	void SetBackColor(int colorID); // 设置文本背景颜色
	void SetBackColor(); // 重载

	int PATTERN; // 游戏模式

	int Game_Duration; //游戏持续时间

	int FoodValidTime; //食物总的有效时间
	int CreateFoodsum; //创造食物总数

	int RoundNumber; //当前回合数

	int SCORE; // 得分

	int SnakeSurvive; // 蛇的存活时间

	std::array<int, 4> SLEEP{ 135, 100, 60, 30 }; // 四种模式下蛇的延迟时间

private:

	KEY KeyChoice = keep;
	bool KeyChoiceValid = false; // 暂时无效

	int WINDOW_LONG; // 游戏窗口的长和高
	int WINDOW_HIGH;

	void SetWindowSize(int cols, int lines)  // 窗口大小设置，构造函数内执行
	{
		system("title 贪吃蛇");  //设置窗口标题

		char cmd[30] = {};

		sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);  //一个图形■占两个字符，故宽度乘以2

		system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
	}
};

#endif

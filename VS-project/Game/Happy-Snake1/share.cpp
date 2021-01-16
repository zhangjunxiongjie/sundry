#include "share.h"
#include <Windows.h>

Share::Share(int f, int h, int l) :FoodValidTime(f), WINDOW_HIGH(h), WINDOW_LONG(l), SnakeSurvive(60), Game_Duration(0), CreateFoodsum(0), RoundNumber(0), SCORE(0) //构造函数
{
	Share::SetWindowSize(WINDOW_LONG, WINDOW_HIGH); // 设置窗口大小

	// int PATTERN; // 游戏模式
	// int Game_Duration; //游戏持续时间
	// int FoodValidTime; //食物总的有效时间
	// int CreateFoodsum; //创造食物总数
	// int WINDOW_LONG; // 游戏窗口的长和高
	// int WINDOW_HIGH;
}

Share::KEY Share::GetKey() // 获取按键
{
	if (KeyChoiceValid)
	{
		KeyChoiceValid = false;
		return KeyChoice;
	}
	else // 不能取按键值
	{
		return Share::nullity;
	}
}

void Share::SetKey(KEY k) // 重置按键
{
	KeyChoiceValid = true; // 这里不做判断无论是否为有效位都可以重置按键
	KeyChoice = k;
}

void Share::InIt() // 重新开始初始化
{
	int Game_Duration = 0; //游戏持续时间

	int CreateFoodsum = 0; //创造食物总数

	//int RoundNumber = 1; //当前回合数

	int SCORE = 0; // 得分
}

void Share::GoToXY(const int x, const int y) // 设置光标位置
{
	COORD position;
	position.X = x * 2;    // ??? 为什么要乘以2呢？
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows接口
}

void Share::SetTextColor(int colorID) // 设置文本前景颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void Share::SetBackColor(int colorID) // 设置文本背景颜色
{
}

void Share::SetBackColor() // 设置文本背景颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}
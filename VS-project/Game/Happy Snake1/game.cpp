#include "game.h"
#include "share.h"
#include <Windows.h>

bool Game::Start()
{
	share.RoundNumber++; // 回合数

	share.InIt(); // 游戏重新开始初始化

	if (share.RoundNumber != 1) // 如果不是第一回合要进行清屏,以及一些数据处理
	{
		system("cls");
		snake.InIt();
	}
	assis.PatternChoice(); // 游戏模式选择
	map.Draw(); // 绘制地图包括游戏信息

	share.SetTextColor(6);
	snake.Draw(); // 绘制蛇身

	food.CreateFood(snake); // 产生新食物
	food.Draw(snake); //绘制食物

	while (true)
	{
		snake.KeyMonitor(); // 按键检测转向或退出

		snake.RuleMove(); // 常规移动

		snake.OverEdge(); // 边界检测

		snake.EatSame(); // 是否吃到自己

		snake.JudgeSurvive(); // 判断是否超过存活时间,并绘制存活进度条

		switch (share.GetKey())
		{
		case Share::keep:
			break; // 继续，不作任何操作
		case Share::restart:
			return true;// 重新开始
		case Share::quit:
			return false; // 退出
		}

		snake.JudgeEatFood(food); // 判断是否吃到食物，如果吃到则产生新食物

		food.Draw(snake); // 绘制食物

		share.Game_Duration++; // 游戏持续时间

		Sleep(share.SLEEP.at(share.PATTERN)); // 根据游戏模式不同进行延时
	}

	return false;
}

Game::Game(Share& s, Assistant& a) :share(s), map(s), assis(a), food(share), snake(share, map, assis)
{
	assis.StartCartoon(); //游戏开启动画
}
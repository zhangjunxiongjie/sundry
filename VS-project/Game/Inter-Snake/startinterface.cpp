#include "startinterface.h"
#include <windows.h>

// 向蛇头方向绘制的过程
void StartInterface::PrintFirst()//蛇从左边出现到完全出现的过程
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed); // 延时，动画效果
	}
}

// 产生新的蛇头并清除蛇尾的过程
void StartInterface::PrintSecond()//蛇从左向右移动的过程
{
	for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
	{
		/*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8); // 蛇头计算公式

		startsnake.emplace_back(Point(i, j)); // 添加新的蛇头
		startsnake.back().Print(); //

		startsnake.front().Clear(); // 清除蛇尾
		startsnake.pop_front();

		Sleep(speed); // 延时
	}
}

// 清除蛇尾的过程。
void StartInterface::PrintThird()//蛇从接触右边到消失的过程
{
	while (!startsnake.empty() || textsnake.back().GetX() < 33) //当蛇还没消失或文字没移动到指定位置
	{
		// 当蛇未消失时清除蛇尾，如果蛇未消失但是文字已经到达指定位置那蛇会继续移动并且文字也会继续移动。
		// 这里在文字移动的部分应该也增加一个判断当到达指定位置时就不再移动。
		if (!startsnake.empty()) //如果蛇还没消失，继续移动
		{
			startsnake.front().Clear();
			startsnake.pop_front();
		}

		// 在蛇移动的过程中，文字随着蛇向右移动
		ClearText();//清除已有文字
		PrintText();//绘制更新位置后的文字

		Sleep(speed);
	}
}

void StartInterface::PrintText() // 文本输出
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

void StartInterface::ClearText()
{
	for (auto& point : textsnake) //清除的同时将文字整体向右移动一格
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

void StartInterface::Action() // 游戏开启动画
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
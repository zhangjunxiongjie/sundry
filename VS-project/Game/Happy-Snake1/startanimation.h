#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "basexy.h"

class StartInterface // 游戏开启动画类
{
public:

	StartInterface() : speed(35) {
		startsnake.emplace_back(BaseXY(0, 14)); //蛇
		startsnake.emplace_back(BaseXY(1, 14));
		startsnake.emplace_back(BaseXY(2, 15));
		startsnake.emplace_back(BaseXY(3, 16));
		startsnake.emplace_back(BaseXY(4, 17));
		startsnake.emplace_back(BaseXY(5, 18));
		startsnake.emplace_back(BaseXY(6, 17));
		startsnake.emplace_back(BaseXY(7, 16));
		startsnake.emplace_back(BaseXY(8, 15));
		startsnake.emplace_back(BaseXY(9, 14));

		textsnake.emplace_back(BaseXY(-26, 14));//S
		textsnake.emplace_back(BaseXY(-25, 14));
		textsnake.emplace_back(BaseXY(-27, 15));
		textsnake.emplace_back(BaseXY(-26, 16));
		textsnake.emplace_back(BaseXY(-25, 17));
		textsnake.emplace_back(BaseXY(-27, 18));
		textsnake.emplace_back(BaseXY(-26, 18));

		textsnake.emplace_back(BaseXY(-23, 14));//N
		textsnake.emplace_back(BaseXY(-23, 15));
		textsnake.emplace_back(BaseXY(-23, 16));
		textsnake.emplace_back(BaseXY(-23, 17));
		textsnake.emplace_back(BaseXY(-23, 18));
		textsnake.emplace_back(BaseXY(-22, 15));
		textsnake.emplace_back(BaseXY(-21, 16));
		textsnake.emplace_back(BaseXY(-20, 17));
		textsnake.emplace_back(BaseXY(-19, 14));
		textsnake.emplace_back(BaseXY(-19, 15));
		textsnake.emplace_back(BaseXY(-19, 16));
		textsnake.emplace_back(BaseXY(-19, 17));
		textsnake.emplace_back(BaseXY(-19, 18));

		textsnake.emplace_back(BaseXY(-17, 18));//A
		textsnake.emplace_back(BaseXY(-16, 17));
		textsnake.emplace_back(BaseXY(-15, 16));
		textsnake.emplace_back(BaseXY(-14, 15));
		textsnake.emplace_back(BaseXY(-14, 16));
		textsnake.emplace_back(BaseXY(-13, 14));
		textsnake.emplace_back(BaseXY(-13, 16));
		textsnake.emplace_back(BaseXY(-12, 15));
		textsnake.emplace_back(BaseXY(-12, 16));
		textsnake.emplace_back(BaseXY(-11, 16));
		textsnake.emplace_back(BaseXY(-10, 17));
		textsnake.emplace_back(BaseXY(-9, 18));

		textsnake.emplace_back(BaseXY(-7, 14));//K
		textsnake.emplace_back(BaseXY(-7, 15));
		textsnake.emplace_back(BaseXY(-7, 16));
		textsnake.emplace_back(BaseXY(-7, 17));
		textsnake.emplace_back(BaseXY(-7, 18));
		textsnake.emplace_back(BaseXY(-6, 16));
		textsnake.emplace_back(BaseXY(-5, 15));
		textsnake.emplace_back(BaseXY(-5, 17));
		textsnake.emplace_back(BaseXY(-4, 14));
		textsnake.emplace_back(BaseXY(-4, 18));

		textsnake.emplace_back(BaseXY(-2, 14));//E
		textsnake.emplace_back(BaseXY(-2, 15));
		textsnake.emplace_back(BaseXY(-2, 16));
		textsnake.emplace_back(BaseXY(-2, 17));
		textsnake.emplace_back(BaseXY(-2, 18));
		textsnake.emplace_back(BaseXY(-1, 14));
		textsnake.emplace_back(BaseXY(-1, 16));
		textsnake.emplace_back(BaseXY(-1, 18));
		textsnake.emplace_back(BaseXY(0, 14));
		textsnake.emplace_back(BaseXY(0, 16));
		textsnake.emplace_back(BaseXY(0, 18));
	}

	// 动画蛇移动的三种状态
	void PrintFirst();

	void PrintSecond();

	void PrintThird(); // 在绘制蛇的最后一个状态时开始绘制蛇。

	// 文字的绘制和清除,每一次清楚都将文字的所有组成坐标向右移动一格，下一次绘制时整体就向右移动了一格。
	void PrintText();

	void ClearText();

	void Action(); // 游戏开启动画

private:

	std::deque<BaseXY> startsnake;//开始动画中的蛇

	std::vector<BaseXY> textsnake;//开始动画中的文字

	int speed;//动画的速度
};
#endif // STRATINTERFACE_H

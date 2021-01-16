#ifndef SNAKE_H
#define SNAKE_H

// #include <queue> // STL向量（可变长数组）
#include <deque> // 不能使用queue,因为需要访问每一个元素才能绘制
#include "basexy.h"
#include "share.h"
#include "map.h"
#include "assistant.h"
#include "food.h"
// #include "foods.h"

// 一条蛇多个食物

class Food;
class Snake // 单条蛇基本类
{
public:

	Snake(Share& s, Map& m, Assistant& a); //
	void InIt(); // 后续的初始化工作

	void Draw(); // 身体绘制

	void PlusMove(); // 移动（增长移动,头部增长方式）
	void RuleMove(); // 常规移动

	void DrawSurvive(); // 进度条绘制

	void KeyMonitor(); // 监测按键判断转向或退出  ！！！按键检测

	void OverEdge(); // 是否超出边界
	void EatSame(); // 是否吃到自己或同类

	bool JudgeEatFood(Food& food); // 判断是否吃到食物，每一次移动都判断一下

	void JudgeSurvive(); //判断并刷新存活时间
	// bool operator== (const Food& food) { return (this->snakebody.back() == food.food); } // 重置‘==’运算符

private:
	friend class Food; // 运算符重载需要访问snake的成员
	// friend class Foods; // 产生食物会判断一下是否与蛇神

	int length; // 长度

	int survive; // 存活时间（已存活时间）

	// int score; // 得分（蛇当前吃到的食物个数）

	// 这里实际上并不是队列容器，因为在产生食物时会随机访问蛇身所以此处不能使用队列容器。
	std::deque<BaseXY> snakebody; // 蛇的身体队列，先进先出，先进尾后进头

	Share& share;

	Map& map;

	Assistant& assis;

	// Food& food;

	// Foods& foods;

	enum
	{
		up,
		down,
		left,
		right
	} direction; // 方向(枚举量)
};

#endif

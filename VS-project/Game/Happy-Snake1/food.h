#ifndef FOOD_H
#define FOOD_H

#include "basexy.h"
#include "snake.h"
#include "share.h"
// #include "foods.h"
// 单个食物基本类

class Snake;
class Food
{
public:

	// Food(int a, int b, Share& s);

	Food(Share& s);

	void Draw(Snake& snake); // 食物绘制

	void CreateFood(Snake& snake); // 创造食物。

	// bool operator== (const Snake& s) { return (this->food == s.snakebody.back()); } // 重置‘==’运算符

private:
	friend class Snake; // 用于运算符重载
	// friend class Foods;

	BaseXY food; // 食物

	//食物已有效时间
	int surplustime; //食物剩余时间为零时食物自动删除，并重新产生食物，

	bool flickerflag; //闪烁标记

	Share& share;
	// Snake& snake;
};

#endif

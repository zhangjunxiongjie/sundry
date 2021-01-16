#ifndef FOODS_H
#define FOODS_H

#include <list>
#include "food.h"
#include "snake.h" 
#include "share.h"

class Foods // 食物组类
{
public:
	Foods(Share& s);

	void Draws(Snake& snake); // 绘制所有食物

	void CreateFood(Snake& snake); //创造新的食物。


private:
	friend class Snake; // 友元 Snake需要访问foodlist才能判断是否吃到食物

	std::list<Food> foodlist; // 食物列表，可以删除或添加任意位置（容器中的位置）的食物

	int foodsum; // 当前食物总数

	// 创造食物时会使用到
	// Snake& snake; // 这里蛇对象要使用到食物对象，而食物对象同时也要使用到蛇对象。 
	
	Share& share;

};


#endif 

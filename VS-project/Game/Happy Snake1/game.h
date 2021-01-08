#ifndef GAME_H
#define GAME_H
// 总的游戏类
#include "assistant.h"
#include "share.h"
#include "map.h"
#include "snake.h"
// #include "foods.h"
#include "food.h"

class Game
{
public:
	Game(Share& s, Assistant& a);

	bool Start(); //游戏开始

private:

	Share& share;

	Assistant& assis;

	Map map;

	Snake snake;

	// Foods foods;
	Food food;
};

#endif

#ifndef GAME_H
#define GAME_H
// �ܵ���Ϸ��
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

	bool Start(); //��Ϸ��ʼ

private:

	Share& share;

	Assistant& assis;

	Map map;

	Snake snake;

	// Foods foods;
	Food food;
};

#endif

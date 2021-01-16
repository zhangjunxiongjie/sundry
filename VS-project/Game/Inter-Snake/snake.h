#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake // 蛇类
{
public:

	enum Direction { UP, DOWN, LEFT, RIGHT }; // 方向枚举量

	// 构造函数
	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8); // 根据参数构造Point对象
		snake.emplace_back(16, 8); // 初始化蛇对象，body（身体的位置）,初始状态有三节
		direction = Direction::DOWN; //移动方向为向下
	}

	void InitSnake(); // 初始绘制蛇身

	void Move(); // 蛇增长时的移动，头节点增长方式

	void NormalMove(); // 蛇身正常移动

	bool OverEdge(); // 判断新增头节点是否超出边界

	bool HitItself(); //

	bool ChangeDirection();

	bool GetFood(const Food&);

	bool GetBigFood(Food&);

private:

	std::deque<Point> snake; // deque一个STL提供的队列容器（先入先出）

	Direction direction;  // 方向

	friend class Food;//将Food类置为友元，以便访问其私有元素
};
#endif // SNAKE_H

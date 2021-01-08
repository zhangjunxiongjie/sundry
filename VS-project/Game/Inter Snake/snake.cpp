#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>

void Snake::InitSnake()//初始化绘制蛇
{
	for (auto& point : snake) // 
	{
		point.PrintCircular(); // 打印蛇的每一节身体
	}
}

void Snake::Move()//蛇增长时的移动，头节点增长方式
{
	switch (direction) // 根据方向移动蛇
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1)); // 在队列最后面添加新的头节点
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}

	SetColor(14); // 设置文本颜色

	snake.back().PrintCircular(); // 绘制新的头节点
}

void Snake::NormalMove()//蛇正常移动，头增长，尾缩短
{
	Move(); // 在后面增加头部移动到的节点

	snake.front().Clear(); // 队列的前面是蛇尾后面是蛇头

	snake.pop_front(); // （STL）删除头部（队列头部，蛇尾部）元素
}

bool Snake::OverEdge() //判断新增头节点是否超出边界
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::HitItself()//撞到自身
{
	std::deque<Point>::size_type cnt = 1;

	Point* head = new Point(snake.back().GetX(), snake.back().GetY());//获得头部坐标

	// auto& point : snake 定义了一个临时对象point对队列snake进行遍历
	for (auto& point : snake) //如果整条蛇中与蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snake.size())
		return true; // 没有撞到自身
	else
		return false; // 撞到了自己的身体
}

bool Snake::ChangeDirection() //改变方向
{
	char ch;
	if (_kbhit())//_kbhit()监测是否有按键输入
	{
		ch = _getch(); // 获取按键值？？？这里-32是什么意思？为什么有两次获取
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC
			return false;

		default:
			return true;
		}
	}
	return true;
}

bool Snake::GetFood(const Food& cfood) // 判断是否吃到食物
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}

bool Snake::GetBigFood(Food& cfood) // 特殊食物消失
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0); // 设置光标位置？？？
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}
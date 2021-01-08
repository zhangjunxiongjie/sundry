#include "snake.h"
#include <conio.h>
#include <iostream>

Snake::Snake(Share& s, Map& m, Assistant& a) :share(s), map(m), assis(a), length(3), survive(0)
{
	snakebody.emplace_back(BaseXY(14, 8)); // 下面两者具有相同的效果，通过函数重载实现
	snakebody.emplace_back(15, 8); // 根据参数构造Point对象
	snakebody.emplace_back(16, 8); // 初始化蛇对象，body（身体的位置）,初始状态有三节
	direction = Snake::down; //移动方向为向下
}

void Snake::InIt() // 后续的初始化工作
{
	snakebody.clear(); //

	length = 3;
	survive = 0; // 蛇的已存活时间

	snakebody.emplace_back(BaseXY(14, 8)); // 下面两者具有相同的效果，通过函数重载实现
	snakebody.emplace_back(15, 8); // 根据参数构造Point对象
	snakebody.emplace_back(16, 8); // 初始化蛇对象，body（身体的位置）,初始状态有三节
	direction = Snake::down; //移动方向为向下
}

void Snake::Draw() // 身体绘制
{
	for (auto& point : snakebody) //
	{
		point.Draw(0); // 打印蛇的每一节身体
	}

	// share.GoToXY(0, 31); // 消除蛇后面的尾巴
}

void Snake::DrawSurvive() // 进度条绘制
{
}

void Snake::PlusMove() // 移动（增长移动,头部增长方式）
{
	switch (direction) // 根据方向移动蛇
	{
	case Snake::up:
		snakebody.emplace_back(BaseXY(snakebody.back().GetX(), snakebody.back().GetY() - 1)); // 在队列最后面添加新的头节点
		break;
	case Snake::down:
		snakebody.emplace_back(BaseXY(snakebody.back().GetX(), snakebody.back().GetY() + 1));
		break;
	case Snake::left:
		snakebody.emplace_back(BaseXY(snakebody.back().GetX() - 1, snakebody.back().GetY()));
		break;
	case Snake::right:
		snakebody.emplace_back(BaseXY(snakebody.back().GetX() + 1, snakebody.back().GetY()));
		break;
	default:
		break;
	}

	share.SetTextColor(14); // 设置文本颜色

	snakebody.back().Draw(0); // 绘制新的头节点

	// share.GoToXY(0, 31); // 消除蛇后面的尾巴
}

void Snake::RuleMove() // 常规移动
{
	PlusMove();

	snakebody.front().Clean(); // 队列的前面是蛇尾后面是蛇头

	snakebody.pop_front(); // （STL）删除头部（队列头部，蛇尾部）元素

	// share.GoToXY(0, 31); // 消除蛇后面的尾巴
}

void Snake::KeyMonitor() // 监测按键判断转向或退出  ！！！按键检测
{
	char ch;
	if (_kbhit())//_kbhit()监测是否有按键输入
	{
		ch = _getch(); // 获取按键值？？？这里-32是什么意思？为什么有两次获取
		switch (ch)
		{
		case 72:
			if (direction != Snake::down)//如果方向与当前运动方向相反，无效
				direction = Snake::up;
			break;
		case 80:
			if (direction != Snake::up)
				direction = Snake::down;
			break;
		case 75:
			if (direction != Snake::right)
				direction = Snake::left;
			break;
		case 77:
			if (direction != Snake::left)
				direction = Snake::right;
			break;
		case 27://ESC
			map.ESCChoice();  // 上一层要先检查选项是否有效
			break;
		default:
			break;
		}
	}
}

void Snake::OverEdge() // 是否超出边界
{
	if (snakebody.back().GetX() < 30 &&
		snakebody.back().GetY() < 30 &&
		snakebody.back().GetX() > 1 &&
		snakebody.back().GetY() > 1);
	else
	{
		assis.LoserChoice(); // 上一层要先检查选项是否有效
	}
}

void Snake::EatSame() // 是否吃到自己(或同类)
{
	std::deque<BaseXY>::size_type cnt = 1;

	BaseXY* head = new BaseXY(snakebody.back().GetX(), snakebody.back().GetY());//获得头部坐标

	// auto& point : snake 定义了一个临时对象point对队列snake进行遍历
	for (BaseXY point : snakebody) //如果整条蛇中与蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snakebody.size()); // 没有撞到自身
	else
		assis.LoserChoice();  // 撞到了自己的身体,
}

void Snake::JudgeSurvive() // 判断并刷新存活时间
{
	if (survive <= share.SnakeSurvive)
	{
		share.GoToXY(0, 0);

		for (int i = 0; i < share.SnakeSurvive; i++)
		{
			if (i < share.SnakeSurvive - survive)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
		}

		survive++;
	}
	else
	{
		assis.LoserChoice();
	}
}

bool Snake::JudgeEatFood(Food& food) // 判断是否吃到食物
{
	// 如果食物坐标和蛇头坐标相同则表示吃到食物
	if ((snakebody.back().GetX() == food.food.GetX()) && (snakebody.back().GetY() == food.food.GetY())) // 这里this是一个指针而在函数重载中第一个参数应该是一个对象所以这里要使用取值运算符
	{
		// 食物个数不唯一的或就可能产生食物坐标相同的情况，但也无需担心，因为remove方法会移除所有和参数相同的成员

		PlusMove(); // 头部增长式的移动，无需考虑食物的清除因为蛇头必然会将其覆盖。

		length++; // 蛇身长度

		map.Refresh(); // 刷新得分

		survive = 0; // 刷新存活时间。

		food.CreateFood(*this);  // 产生一个食物并且重绘所有食物

		return true;
	}
	return false;
}

/*
void Snake::JudgeEatFood() // 判断是否吃到食物，每一次移动都判断一下
{
	for (auto food : foods.foodlist)
	{
		// 如果食物坐标和蛇头坐标相同则表示吃到食物
		if (*this == food) // 这里this是一个指针而在函数重载中第一个参数应该是一个对象所以这里要使用取值运算符
		{
			// 食物个数不唯一的或就可能产生食物坐标相同的情况，但也无需担心，因为remove方法会移除所有和参数相同的成员
			foods.foodlist.remove(food); // list容器的remove方法移除和参数food相同的元素成员。
			PlusMove(); // 头部增长式的移动，无需考虑食物的清除因为蛇头必然会将其覆盖。

			length++; // 蛇身长度

			foods.CreateFood(*this);  // 产生一个食物并且重绘所有食物
		}
	}
}
*/
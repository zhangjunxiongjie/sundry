#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>

void Snake::InitSnake()//��ʼ��������
{
	for (auto& point : snake) // 
	{
		point.PrintCircular(); // ��ӡ�ߵ�ÿһ������
	}
}

void Snake::Move()//������ʱ���ƶ���ͷ�ڵ�������ʽ
{
	switch (direction) // ���ݷ����ƶ���
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1)); // �ڶ������������µ�ͷ�ڵ�
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

	SetColor(14); // �����ı���ɫ

	snake.back().PrintCircular(); // �����µ�ͷ�ڵ�
}

void Snake::NormalMove()//�������ƶ���ͷ������β����
{
	Move(); // �ں�������ͷ���ƶ����Ľڵ�

	snake.front().Clear(); // ���е�ǰ������β��������ͷ

	snake.pop_front(); // ��STL��ɾ��ͷ��������ͷ������β����Ԫ��
}

bool Snake::OverEdge() //�ж�����ͷ�ڵ��Ƿ񳬳��߽�
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::HitItself()//ײ������
{
	std::deque<Point>::size_type cnt = 1;

	Point* head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������

	// auto& point : snake ������һ����ʱ����point�Զ���snake���б���
	for (auto& point : snake) //���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snake.size())
		return true; // û��ײ������
	else
		return false; // ײ�����Լ�������
}

bool Snake::ChangeDirection() //�ı䷽��
{
	char ch;
	if (_kbhit())//_kbhit()����Ƿ��а�������
	{
		ch = _getch(); // ��ȡ����ֵ����������-32��ʲô��˼��Ϊʲô�����λ�ȡ
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
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

bool Snake::GetFood(const Food& cfood) // �ж��Ƿ�Ե�ʳ��
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}

bool Snake::GetBigFood(Food& cfood) // ����ʳ����ʧ
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0); // ���ù��λ�ã�����
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}
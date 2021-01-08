#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake // ����
{
public:

	enum Direction { UP, DOWN, LEFT, RIGHT }; // ����ö����

	// ���캯��
	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8); // ���ݲ�������Point����
		snake.emplace_back(16, 8); // ��ʼ���߶���body�������λ�ã�,��ʼ״̬������
		direction = Direction::DOWN; //�ƶ�����Ϊ����
	}

	void InitSnake(); // ��ʼ��������

	void Move(); // ������ʱ���ƶ���ͷ�ڵ�������ʽ

	void NormalMove(); // ���������ƶ�

	bool OverEdge(); // �ж�����ͷ�ڵ��Ƿ񳬳��߽�

	bool HitItself(); //

	bool ChangeDirection();

	bool GetFood(const Food&);

	bool GetBigFood(Food&);

private:

	std::deque<Point> snake; // dequeһ��STL�ṩ�Ķ��������������ȳ���

	Direction direction;  // ����

	friend class Food;//��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
};
#endif // SNAKE_H

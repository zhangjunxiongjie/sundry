#ifndef FOOD_H
#define FOOD_H

#include "basexy.h"
#include "snake.h"
#include "share.h"
// #include "foods.h"
// ����ʳ�������

class Snake;
class Food
{
public:

	// Food(int a, int b, Share& s);

	Food(Share& s);

	void Draw(Snake& snake); // ʳ�����

	void CreateFood(Snake& snake); // ����ʳ�

	// bool operator== (const Snake& s) { return (this->food == s.snakebody.back()); } // ���á�==�������

private:
	friend class Snake; // �������������
	// friend class Foods;

	BaseXY food; // ʳ��

	//ʳ������Чʱ��
	int surplustime; //ʳ��ʣ��ʱ��Ϊ��ʱʳ���Զ�ɾ���������²���ʳ�

	bool flickerflag; //��˸���

	Share& share;
	// Snake& snake;
};

#endif

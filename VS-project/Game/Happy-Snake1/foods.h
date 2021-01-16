#ifndef FOODS_H
#define FOODS_H

#include <list>
#include "food.h"
#include "snake.h" 
#include "share.h"

class Foods // ʳ������
{
public:
	Foods(Share& s);

	void Draws(Snake& snake); // ��������ʳ��

	void CreateFood(Snake& snake); //�����µ�ʳ�


private:
	friend class Snake; // ��Ԫ Snake��Ҫ����foodlist�����ж��Ƿ�Ե�ʳ��

	std::list<Food> foodlist; // ʳ���б�����ɾ�����������λ�ã������е�λ�ã���ʳ��

	int foodsum; // ��ǰʳ������

	// ����ʳ��ʱ��ʹ�õ�
	// Snake& snake; // �����߶���Ҫʹ�õ�ʳ����󣬶�ʳ�����ͬʱҲҪʹ�õ��߶��� 
	
	Share& share;

};


#endif 

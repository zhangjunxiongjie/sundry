#ifndef SNAKE_H
#define SNAKE_H

// #include <queue> // STL�������ɱ䳤���飩
#include <deque> // ����ʹ��queue,��Ϊ��Ҫ����ÿһ��Ԫ�ز��ܻ���
#include "basexy.h"
#include "share.h"
#include "map.h"
#include "assistant.h"
#include "food.h"
// #include "foods.h"

// һ���߶��ʳ��

class Food;
class Snake // �����߻�����
{
public:

	Snake(Share& s, Map& m, Assistant& a); //
	void InIt(); // �����ĳ�ʼ������

	void Draw(); // �������

	void PlusMove(); // �ƶ��������ƶ�,ͷ��������ʽ��
	void RuleMove(); // �����ƶ�

	void DrawSurvive(); // ����������

	void KeyMonitor(); // ��ⰴ���ж�ת����˳�  �������������

	void OverEdge(); // �Ƿ񳬳��߽�
	void EatSame(); // �Ƿ�Ե��Լ���ͬ��

	bool JudgeEatFood(Food& food); // �ж��Ƿ�Ե�ʳ�ÿһ���ƶ����ж�һ��

	void JudgeSurvive(); //�жϲ�ˢ�´��ʱ��
	// bool operator== (const Food& food) { return (this->snakebody.back() == food.food); } // ���á�==�������

private:
	friend class Food; // �����������Ҫ����snake�ĳ�Ա
	// friend class Foods; // ����ʳ����ж�һ���Ƿ�������

	int length; // ����

	int survive; // ���ʱ�䣨�Ѵ��ʱ�䣩

	// int score; // �÷֣��ߵ�ǰ�Ե���ʳ�������

	// ����ʵ���ϲ����Ƕ�����������Ϊ�ڲ���ʳ��ʱ����������������Դ˴�����ʹ�ö���������
	std::deque<BaseXY> snakebody; // �ߵ�������У��Ƚ��ȳ����Ƚ�β���ͷ

	Share& share;

	Map& map;

	Assistant& assis;

	// Food& food;

	// Foods& foods;

	enum
	{
		up,
		down,
		left,
		right
	} direction; // ����(ö����)
};

#endif

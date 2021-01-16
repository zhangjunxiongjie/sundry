#include "snake.h"
#include <conio.h>
#include <iostream>

Snake::Snake(Share& s, Map& m, Assistant& a) :share(s), map(m), assis(a), length(3), survive(0)
{
	snakebody.emplace_back(BaseXY(14, 8)); // �������߾�����ͬ��Ч����ͨ����������ʵ��
	snakebody.emplace_back(15, 8); // ���ݲ�������Point����
	snakebody.emplace_back(16, 8); // ��ʼ���߶���body�������λ�ã�,��ʼ״̬������
	direction = Snake::down; //�ƶ�����Ϊ����
}

void Snake::InIt() // �����ĳ�ʼ������
{
	snakebody.clear(); //

	length = 3;
	survive = 0; // �ߵ��Ѵ��ʱ��

	snakebody.emplace_back(BaseXY(14, 8)); // �������߾�����ͬ��Ч����ͨ����������ʵ��
	snakebody.emplace_back(15, 8); // ���ݲ�������Point����
	snakebody.emplace_back(16, 8); // ��ʼ���߶���body�������λ�ã�,��ʼ״̬������
	direction = Snake::down; //�ƶ�����Ϊ����
}

void Snake::Draw() // �������
{
	for (auto& point : snakebody) //
	{
		point.Draw(0); // ��ӡ�ߵ�ÿһ������
	}

	// share.GoToXY(0, 31); // �����ߺ����β��
}

void Snake::DrawSurvive() // ����������
{
}

void Snake::PlusMove() // �ƶ��������ƶ�,ͷ��������ʽ��
{
	switch (direction) // ���ݷ����ƶ���
	{
	case Snake::up:
		snakebody.emplace_back(BaseXY(snakebody.back().GetX(), snakebody.back().GetY() - 1)); // �ڶ������������µ�ͷ�ڵ�
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

	share.SetTextColor(14); // �����ı���ɫ

	snakebody.back().Draw(0); // �����µ�ͷ�ڵ�

	// share.GoToXY(0, 31); // �����ߺ����β��
}

void Snake::RuleMove() // �����ƶ�
{
	PlusMove();

	snakebody.front().Clean(); // ���е�ǰ������β��������ͷ

	snakebody.pop_front(); // ��STL��ɾ��ͷ��������ͷ������β����Ԫ��

	// share.GoToXY(0, 31); // �����ߺ����β��
}

void Snake::KeyMonitor() // ��ⰴ���ж�ת����˳�  �������������
{
	char ch;
	if (_kbhit())//_kbhit()����Ƿ��а�������
	{
		ch = _getch(); // ��ȡ����ֵ����������-32��ʲô��˼��Ϊʲô�����λ�ȡ
		switch (ch)
		{
		case 72:
			if (direction != Snake::down)//��������뵱ǰ�˶������෴����Ч
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
			map.ESCChoice();  // ��һ��Ҫ�ȼ��ѡ���Ƿ���Ч
			break;
		default:
			break;
		}
	}
}

void Snake::OverEdge() // �Ƿ񳬳��߽�
{
	if (snakebody.back().GetX() < 30 &&
		snakebody.back().GetY() < 30 &&
		snakebody.back().GetX() > 1 &&
		snakebody.back().GetY() > 1);
	else
	{
		assis.LoserChoice(); // ��һ��Ҫ�ȼ��ѡ���Ƿ���Ч
	}
}

void Snake::EatSame() // �Ƿ�Ե��Լ�(��ͬ��)
{
	std::deque<BaseXY>::size_type cnt = 1;

	BaseXY* head = new BaseXY(snakebody.back().GetX(), snakebody.back().GetY());//���ͷ������

	// auto& point : snake ������һ����ʱ����point�Զ���snake���б���
	for (BaseXY point : snakebody) //���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snakebody.size()); // û��ײ������
	else
		assis.LoserChoice();  // ײ�����Լ�������,
}

void Snake::JudgeSurvive() // �жϲ�ˢ�´��ʱ��
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

bool Snake::JudgeEatFood(Food& food) // �ж��Ƿ�Ե�ʳ��
{
	// ���ʳ���������ͷ������ͬ���ʾ�Ե�ʳ��
	if ((snakebody.back().GetX() == food.food.GetX()) && (snakebody.back().GetY() == food.food.GetY())) // ����this��һ��ָ����ں��������е�һ������Ӧ����һ��������������Ҫʹ��ȡֵ�����
	{
		// ʳ�������Ψһ�Ļ�Ϳ��ܲ���ʳ��������ͬ���������Ҳ���赣�ģ���Ϊremove�������Ƴ����кͲ�����ͬ�ĳ�Ա

		PlusMove(); // ͷ������ʽ���ƶ������迼��ʳ��������Ϊ��ͷ��Ȼ�Ὣ�串�ǡ�

		length++; // ������

		map.Refresh(); // ˢ�µ÷�

		survive = 0; // ˢ�´��ʱ�䡣

		food.CreateFood(*this);  // ����һ��ʳ�ﲢ���ػ�����ʳ��

		return true;
	}
	return false;
}

/*
void Snake::JudgeEatFood() // �ж��Ƿ�Ե�ʳ�ÿһ���ƶ����ж�һ��
{
	for (auto food : foods.foodlist)
	{
		// ���ʳ���������ͷ������ͬ���ʾ�Ե�ʳ��
		if (*this == food) // ����this��һ��ָ����ں��������е�һ������Ӧ����һ��������������Ҫʹ��ȡֵ�����
		{
			// ʳ�������Ψһ�Ļ�Ϳ��ܲ���ʳ��������ͬ���������Ҳ���赣�ģ���Ϊremove�������Ƴ����кͲ�����ͬ�ĳ�Ա
			foods.foodlist.remove(food); // list������remove�����Ƴ��Ͳ���food��ͬ��Ԫ�س�Ա��
			PlusMove(); // ͷ������ʽ���ƶ������迼��ʳ��������Ϊ��ͷ��Ȼ�Ὣ�串�ǡ�

			length++; // ������

			foods.CreateFood(*this);  // ����һ��ʳ�ﲢ���ػ�����ʳ��
		}
	}
}
*/
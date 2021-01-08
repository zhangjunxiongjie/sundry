#include "food.h"

/*
Food::Food(int a, int b, Share& s) :food(a, b), share(s), flickerflag(true), surplustime(0)
{
}
*/
Food::Food(Share& s) :share(s), surplustime(0), flickerflag(true), food(0, 0)
{
}

void Food::Draw(Snake& snake) // ʳ�����
{
	if (share.FoodValidTime - 15 <= surplustime) // ʵ����˸
	{
		if (flickerflag)
		{
			food.Draw(2);
			flickerflag = !flickerflag;
		}
		else
		{
			food.Clean();
			flickerflag = !flickerflag;
		}
	}
	else
	{
		food.Draw(2);  // ����
	}

	surplustime++; // ʳ����Чʱ�䡣

	if (surplustime == share.FoodValidTime) // ����ʱ����������Чʱ��ʱ���²���ʳ��
	{
		food.Clean();
		CreateFood(snake);
	}
}

void Food::CreateFood(Snake& snake) // ����ʳ�
{
	/*����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��*/

	int tmp_x; //
	int tmp_y;

	while (true)
	{
		tmp_x = rand() % 30; // rand()��ȡ�����
		tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;

		bool flag = false;

		for (auto& node : snake.snakebody) // ��������ڵ㣬ȷ��ʳ���������ص���food��snake����Ԫ�����໥���Է���˽�г�Ա
		{
			if (node == BaseXY(tmp_x, tmp_y)) { // �ж�����ڵ��Ƿ����������������
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // ���������ʳ�������������ص������²���

		break;
	}

	food.Reset(tmp_x, tmp_y); // ˢ��ʳ������
	surplustime = 0; // ˢ��ʳ�����ʱ��

	share.SCORE += share.PATTERN;

	Draw(snake); // ����ʳ��

	share.CreateFoodsum++; // �������ܵ�ʳ�����
}
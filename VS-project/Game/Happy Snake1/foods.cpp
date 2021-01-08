#include "foods.h"

Foods::Foods(Share& s) :share(s),foodsum(0)
{

}

void Foods::Draws(Snake& snake) // ��������ʳ��
{
	share.SetTextColor(13); // ������ɫ
	for (auto& food : foodlist)
	{
		food.Draw();
		if (share.FoodValidTime == food.surplustime)
		{
			foodlist.remove(food); // ���ʱ�䵽����ɾ���Ǹ�ʳ��������µ�ʳ��
			CreateFood(snake);
		}
	}
}

void Foods::CreateFood(Snake& snake) //�����µ�ʳ�
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
			if ( node == BaseXY(tmp_x,tmp_y) ) { // �ж�����ڵ��Ƿ����������������
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // ���������ʳ�������������ص������²���

		break;
	}

	foodlist.push_back(Food(tmp_x, tmp_y, share)); // ĩβ���һ��ʳ��

	Draws(snake); // ��������ʳ��

	share.CreateFoodsum++;
}



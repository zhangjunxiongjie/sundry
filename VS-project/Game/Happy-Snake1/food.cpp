#include "food.h"

/*
Food::Food(int a, int b, Share& s) :food(a, b), share(s), flickerflag(true), surplustime(0)
{
}
*/
Food::Food(Share& s) :share(s), surplustime(0), flickerflag(true), food(0, 0)
{
}

void Food::Draw(Snake& snake) // 食物绘制
{
	if (share.FoodValidTime - 15 <= surplustime) // 实现闪烁
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
		food.Draw(2);  // 绘制
	}

	surplustime++; // 食物有效时间。

	if (surplustime == share.FoodValidTime) // 持续时间等于最大有效时间时重新产生食物
	{
		food.Clean();
		CreateFood(snake);
	}
}

void Food::CreateFood(Snake& snake) // 创造食物。
{
	/*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。*/

	int tmp_x; //
	int tmp_y;

	while (true)
	{
		tmp_x = rand() % 30; // rand()获取随机数
		tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;

		bool flag = false;

		for (auto& node : snake.snakebody) // 遍历蛇身节点，确保食物与蛇身不重叠，food和snake是友元所有相互可以访问私有成员
		{
			if (node == BaseXY(tmp_x, tmp_y)) { // 判断身体节点是否与产生的随机点相等
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // 如果产生的食物坐标与蛇身重叠则重新产生

		break;
	}

	food.Reset(tmp_x, tmp_y); // 刷新食物坐标
	surplustime = 0; // 刷新食物持续时间

	share.SCORE += share.PATTERN;

	Draw(snake); // 绘制食物

	share.CreateFoodsum++; // 产生的总的食物个数
}
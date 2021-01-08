#include "foods.h"

Foods::Foods(Share& s) :share(s),foodsum(0)
{

}

void Foods::Draws(Snake& snake) // 绘制所有食物
{
	share.SetTextColor(13); // 设置颜色
	for (auto& food : foodlist)
	{
		food.Draw();
		if (share.FoodValidTime == food.surplustime)
		{
			foodlist.remove(food); // 如果时间到了则删除那个食物，不产生新的食物
			CreateFood(snake);
		}
	}
}

void Foods::CreateFood(Snake& snake) //创造新的食物。
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
			if ( node == BaseXY(tmp_x,tmp_y) ) { // 判断身体节点是否与产生的随机点相等
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // 如果产生的食物坐标与蛇身重叠则重新产生

		break;
	}

	foodlist.push_back(Food(tmp_x, tmp_y, share)); // 末尾添加一个食物

	Draws(snake); // 绘制所有食物

	share.CreateFoodsum++;
}



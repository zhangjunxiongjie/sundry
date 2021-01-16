#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

void Food::DrawFood(Snake& csnake)//绘制食物
{
	/*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。
	  同时每5颗食物就出现一颗限时食物*/
	while (true)
	{
		int tmp_x = rand() % 30; // rand()获取随机数
		int tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;

		bool flag = false;

		for (auto& point : csnake.snake) // 遍历蛇身节点，确保食物与蛇身不重叠，food和snake是友元所有相互可以访问私有成员
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // 如果产生的食物坐标与蛇身重叠则重新产生
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y); // 设置光标位置
		SetColor(13); // 设置颜色
		std::cout << "★"; // 输出食物
		++cnt;
		cnt %= 5; // 每产生五个食物就产生一个闪烁限时食物
		if (cnt == 0)
		{
			DrawBigFood(csnake); // 绘制闪烁限时食物
		}
		break;
	}
}

void Food::DrawBigFood(Snake& csnake)//绘制限时食物
{
	// 绘制进度条
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------";//进度条
	progress_bar = 42;

	while (true) // 产生闪烁限时食物坐标并绘制
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetColor(18);
		std::cout << "■";
		big_flag = true;
		flash_flag = true;
		break;
	}
}

int Food::GetCnt() // 获得当前已产生食物总数
{
	return cnt;
}

void Food::FlashBigFood()//闪烁限时食物
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	if (flash_flag) // 实现食物闪烁
	{
		std::cout << "  ";
		flash_flag = false;
	}
	else
	{
		std::cout << "■";
		flash_flag = true;
	}

	SetCursorPosition(26, 0);
	SetColor(11);
	for (int i = 42; i >= progress_bar; --i) //进度条缩短
		std::cout << "\b \b"; // \b = 退格键（backspace）\r = 回车键（carrige return）
		// 光标移动到进度条最后前移一格然后输出空格（填充）然后移动到当前进度条的最后。
		// 这里还有待改进因为这里实际上每次都是先将光标移动到最后然后往前填充空格，实际上每次将光标移动到进度条的末尾然后向前一次填充即可。
	--progress_bar;

	if (progress_bar == 0) { // 进度条为零时限时食物消失
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}
}

bool Food::GetBigFlag() // 是否有限时食物
{
	return big_flag;
}

int Food::GetProgressBar() // 得到限时食物计时
{
	return progress_bar;
}
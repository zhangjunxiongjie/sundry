#include "map.h"
#include <Windows.h> // 延时
#include <iostream> //
#include <conio.h> // 按键检测

Map::Map(Share& s) :share(s)
{
	initmap.emplace_back(BaseXY(1, 1));
	initmap.emplace_back(BaseXY(2, 1));
	initmap.emplace_back(BaseXY(3, 1));
	initmap.emplace_back(BaseXY(4, 1));
	initmap.emplace_back(BaseXY(5, 1));
	initmap.emplace_back(BaseXY(6, 1));
	initmap.emplace_back(BaseXY(7, 1));
	initmap.emplace_back(BaseXY(8, 1));
	initmap.emplace_back(BaseXY(9, 1));
	initmap.emplace_back(BaseXY(10, 1));
	initmap.emplace_back(BaseXY(11, 1));
	initmap.emplace_back(BaseXY(12, 1));
	initmap.emplace_back(BaseXY(13, 1));
	initmap.emplace_back(BaseXY(14, 1));
	initmap.emplace_back(BaseXY(15, 1));
	initmap.emplace_back(BaseXY(16, 1));
	initmap.emplace_back(BaseXY(17, 1));
	initmap.emplace_back(BaseXY(18, 1));
	initmap.emplace_back(BaseXY(19, 1));
	initmap.emplace_back(BaseXY(20, 1));
	initmap.emplace_back(BaseXY(21, 1));
	initmap.emplace_back(BaseXY(22, 1));
	initmap.emplace_back(BaseXY(23, 1));
	initmap.emplace_back(BaseXY(24, 1));
	initmap.emplace_back(BaseXY(25, 1));
	initmap.emplace_back(BaseXY(26, 1));
	initmap.emplace_back(BaseXY(27, 1));
	initmap.emplace_back(BaseXY(28, 1));
	initmap.emplace_back(BaseXY(29, 1));
	initmap.emplace_back(BaseXY(30, 1));
	initmap.emplace_back(BaseXY(1, 2));
	initmap.emplace_back(BaseXY(30, 2));
	initmap.emplace_back(BaseXY(1, 3));
	initmap.emplace_back(BaseXY(30, 3));
	initmap.emplace_back(BaseXY(1, 4));
	initmap.emplace_back(BaseXY(30, 4));
	initmap.emplace_back(BaseXY(1, 5));
	initmap.emplace_back(BaseXY(30, 5));
	initmap.emplace_back(BaseXY(1, 6));
	initmap.emplace_back(BaseXY(30, 6));
	initmap.emplace_back(BaseXY(1, 7));
	initmap.emplace_back(BaseXY(30, 7));
	initmap.emplace_back(BaseXY(1, 8));
	initmap.emplace_back(BaseXY(30, 8));
	initmap.emplace_back(BaseXY(1, 9));
	initmap.emplace_back(BaseXY(30, 9));
	initmap.emplace_back(BaseXY(1, 10));
	initmap.emplace_back(BaseXY(30, 10));
	initmap.emplace_back(BaseXY(1, 11));
	initmap.emplace_back(BaseXY(30, 11));
	initmap.emplace_back(BaseXY(1, 12));
	initmap.emplace_back(BaseXY(30, 12));
	initmap.emplace_back(BaseXY(1, 13));
	initmap.emplace_back(BaseXY(30, 13));
	initmap.emplace_back(BaseXY(1, 14));
	initmap.emplace_back(BaseXY(30, 14));
	initmap.emplace_back(BaseXY(1, 15));
	initmap.emplace_back(BaseXY(30, 15));
	initmap.emplace_back(BaseXY(1, 16));
	initmap.emplace_back(BaseXY(30, 16));
	initmap.emplace_back(BaseXY(1, 17));
	initmap.emplace_back(BaseXY(30, 17));
	initmap.emplace_back(BaseXY(1, 18));
	initmap.emplace_back(BaseXY(30, 18));
	initmap.emplace_back(BaseXY(1, 19));
	initmap.emplace_back(BaseXY(30, 19));
	initmap.emplace_back(BaseXY(1, 20));
	initmap.emplace_back(BaseXY(30, 20));
	initmap.emplace_back(BaseXY(1, 21));
	initmap.emplace_back(BaseXY(30, 21));
	initmap.emplace_back(BaseXY(1, 22));
	initmap.emplace_back(BaseXY(30, 22));
	initmap.emplace_back(BaseXY(1, 23));
	initmap.emplace_back(BaseXY(30, 23));
	initmap.emplace_back(BaseXY(1, 24));
	initmap.emplace_back(BaseXY(30, 24));
	initmap.emplace_back(BaseXY(1, 25));
	initmap.emplace_back(BaseXY(30, 25));
	initmap.emplace_back(BaseXY(1, 26));
	initmap.emplace_back(BaseXY(30, 26));
	initmap.emplace_back(BaseXY(1, 27));
	initmap.emplace_back(BaseXY(30, 27));
	initmap.emplace_back(BaseXY(1, 28));
	initmap.emplace_back(BaseXY(30, 28));
	initmap.emplace_back(BaseXY(1, 29));
	initmap.emplace_back(BaseXY(30, 29));
	initmap.emplace_back(BaseXY(1, 30));
	initmap.emplace_back(BaseXY(2, 30));
	initmap.emplace_back(BaseXY(3, 30));
	initmap.emplace_back(BaseXY(4, 30));
	initmap.emplace_back(BaseXY(5, 30));
	initmap.emplace_back(BaseXY(6, 30));
	initmap.emplace_back(BaseXY(7, 30));
	initmap.emplace_back(BaseXY(8, 30));
	initmap.emplace_back(BaseXY(9, 30));
	initmap.emplace_back(BaseXY(10, 30));
	initmap.emplace_back(BaseXY(11, 30));
	initmap.emplace_back(BaseXY(12, 30));
	initmap.emplace_back(BaseXY(13, 30));
	initmap.emplace_back(BaseXY(14, 30));
	initmap.emplace_back(BaseXY(15, 30));
	initmap.emplace_back(BaseXY(16, 30));
	initmap.emplace_back(BaseXY(17, 30));
	initmap.emplace_back(BaseXY(18, 30));
	initmap.emplace_back(BaseXY(19, 30));
	initmap.emplace_back(BaseXY(20, 30));
	initmap.emplace_back(BaseXY(21, 30));
	initmap.emplace_back(BaseXY(22, 30));
	initmap.emplace_back(BaseXY(23, 30));
	initmap.emplace_back(BaseXY(24, 30));
	initmap.emplace_back(BaseXY(25, 30));
	initmap.emplace_back(BaseXY(26, 30));
	initmap.emplace_back(BaseXY(27, 30));
	initmap.emplace_back(BaseXY(28, 30));
	initmap.emplace_back(BaseXY(29, 30));
	initmap.emplace_back(BaseXY(30, 30));
}

void Map::MapDraw() // 地图绘制
{
	system("cls"); // 清屏

	for (auto& point : initmap)
	{
		point.Draw(1);
		Sleep(10);//调用Sleep（延时）函数可营造动画效果
	}
}

void Map::InfoDraw() // 信息绘制
{
	/*绘制侧边栏*/
	share.SetTextColor(3);
	share.GoToXY(33, 1);
	std::cout << "Greedy Snake";
	share.GoToXY(34, 2);
	std::cout << "贪吃蛇";
	share.GoToXY(31, 4);
	std::cout << "难度：";
	share.GoToXY(36, 5);
	switch (share.PATTERN + 1) // 这里因为游戏模式是从零开始的
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	share.GoToXY(31, 7);
	std::cout << "得分：";
	share.GoToXY(37, 8);
	std::cout << "     0";
	share.GoToXY(33, 13);
	std::cout << " 方向键移动";
	share.GoToXY(33, 15);
	std::cout << " ESC键暂停";
}

void Map::Draw()
{
	MapDraw(); // 绘制地图
	InfoDraw(); // 绘制信息
}

void Map::Refresh() // 每吃到一个食物进行得分刷新。
{
	share.SCORE = share.SCORE + (share.PATTERN + 1) * 10; //share.PATTERN游戏模式作为权重从零开始所以此处加1

	/*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/
	share.GoToXY(37, 8);
	share.SetTextColor(11);
	int bit = 0;  //当前分数的位数
	int tmp = share.SCORE;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)  // 分数右对齐
	{
		std::cout << " ";
	}
	std::cout << share.SCORE;
}

void Map::ESCChoice() // 按键退出选择菜单。！！！按键检测
{
	/*绘制菜单*/
	share.SetTextColor(11);
	share.GoToXY(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	share.GoToXY(34, 21);
	share.SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	share.GoToXY(34, 23);
	share.SetTextColor(11);
	std::cout << "重新开始";
	Sleep(100);
	share.GoToXY(34, 25);
	std::cout << "退出游戏";
	share.GoToXY(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					share.GoToXY(34, 21);
					share.SetBackColor();
					std::cout << "继续游戏";
					share.GoToXY(34, 23);
					share.SetTextColor(11);
					std::cout << "重新开始";

					--tmp_key;
					break;
				case 3:
					share.GoToXY(34, 23);
					share.SetBackColor();
					std::cout << "重新开始";
					share.GoToXY(34, 25);
					share.SetTextColor(11);
					std::cout << "退出游戏";

					--tmp_key;
					break;
				}
			}
			else if (tmp_key == 1)
			{
				share.GoToXY(34, 21);
				share.SetTextColor(11);
				std::cout << "继续游戏";

				share.GoToXY(34, 25);
				share.SetBackColor();
				std::cout << "退出游戏";

				tmp_key = 3;
			}
			break;

		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					share.GoToXY(34, 23);
					share.SetBackColor();
					std::cout << "重新开始";
					share.GoToXY(34, 21);
					share.SetTextColor(11);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					share.GoToXY(34, 25);
					share.SetBackColor();
					std::cout << "退出游戏";
					share.GoToXY(34, 23);
					share.SetTextColor(11);
					std::cout << "重新开始";

					++tmp_key;
					break;
				}
			}
			else if (tmp_key == 3)
			{
				share.GoToXY(34, 25);
				share.SetTextColor(11);
				std::cout << "退出游戏";

				share.GoToXY(34, 21);
				share.SetBackColor();
				std::cout << "继续游戏";

				tmp_key = 1;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		share.GoToXY(0, 31);
	}

	if (tmp_key == 1) //选择继续游戏，则将菜单擦除
	{
		share.SetTextColor(14);
		share.GoToXY(32, 19);
		std::cout << "      ";
		share.GoToXY(34, 21);
		std::cout << "        ";
		share.GoToXY(34, 23);
		std::cout << "        ";
		share.GoToXY(34, 25);
		std::cout << "        ";

		share.SetKey(Share::keep);
	}
	else if (tmp_key == 2)
	{
		share.SetKey(Share::restart);
	}
	else
	{
		share.SetKey(Share::quit);
	}
}
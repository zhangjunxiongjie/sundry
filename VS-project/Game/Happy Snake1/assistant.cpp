#include "assistant.h"
#include "startanimation.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

Assistant::Assistant(Share& s) :share(s)  // 构造函数
{
}

void Assistant::StartCartoon() //游戏启动动画
{
	StartInterface* si = new StartInterface();

	share.SetTextColor(2);  // 设置文本颜色

	si->Action();

	delete si;

	/*设置光标位置，并输出提示语，等待任意键输入结束*/
	share.GoToXY(13, 26);
	std::cout << "Press any key to start... ";
	share.GoToXY(13, 27);
	system("pause"); // 暂停,按任意键可继续
}

void Assistant::PatternChoice() // 模式选择 ！！！按键检测
{
	/*初始化界面选项*/
	share.SetTextColor(3);
	share.GoToXY(13, 26);
	std::cout << "                          ";
	share.GoToXY(13, 27);
	std::cout << "                          ";
	share.GoToXY(6, 21);
	std::cout << "请选择游戏难度：";
	share.GoToXY(6, 22);
	std::cout << "(上下键选择,回车确认)";

	share.GoToXY(27, 22);
	share.SetBackColor();//第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";

	share.GoToXY(27, 24);
	share.SetTextColor(3);
	std::cout << "普通模式";
	share.GoToXY(27, 26);
	std::cout << "困难模式";
	share.GoToXY(27, 28);
	std::cout << "炼狱模式";

	share.GoToXY(0, 31);

	/*上下方向键选择模块*/
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					share.GoToXY(27, 22);//给待选中项设置背景色
					share.SetBackColor();
					std::cout << "简单模式";

					share.GoToXY(27, 24);//将已选中项取消我背景色
					share.SetTextColor(3);
					std::cout << "普通模式";

					--key;
					break;
				case 3:
					share.GoToXY(27, 24);
					share.SetBackColor();
					std::cout << "普通模式";

					share.GoToXY(27, 26);
					share.SetTextColor(3);
					std::cout << "困难模式";

					--key;
					break;
				case 4:
					share.GoToXY(27, 26);
					share.SetBackColor();
					std::cout << "困难模式";

					share.GoToXY(27, 28);
					share.SetTextColor(3);
					std::cout << "炼狱模式";

					--key;
					break;
				}
			}
			else if (key == 1)
			{
				share.GoToXY(27, 22);//给待选中项设置背景色
				share.SetTextColor(3);
				std::cout << "简单模式";

				share.GoToXY(27, 28);
				share.SetBackColor();
				std::cout << "炼狱模式";

				key = 4;
			}
			break;

		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					share.GoToXY(27, 24);
					share.SetBackColor();
					std::cout << "普通模式";
					share.GoToXY(27, 22);
					share.SetTextColor(3);
					std::cout << "简单模式";

					++key;
					break;
				case 2:
					share.GoToXY(27, 26);
					share.SetBackColor();
					std::cout << "困难模式";
					share.GoToXY(27, 24);
					share.SetTextColor(3);
					std::cout << "普通模式";

					++key;
					break;
				case 3:
					share.GoToXY(27, 28);
					share.SetBackColor();
					std::cout << "炼狱模式";
					share.GoToXY(27, 26);
					share.SetTextColor(3);
					std::cout << "困难模式";

					++key;
					break;
				}
			}
			else if (key == 4)
			{
				share.GoToXY(27, 28);
				share.SetTextColor(3);
				std::cout << "炼狱模式";

				share.GoToXY(27, 22);//给待选中项设置背景色
				share.SetBackColor();
				std::cout << "简单模式";

				key = 1;
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环

		share.GoToXY(0, 31);//将光标置于左下角，避免关标闪烁影响游戏体验
	}

	share.PATTERN = key - 1; // 游戏模式

	// share.SnakeSurvive = share.SLEEP.at(share.PATTERN) / 2; // 蛇的存活时间和游戏模式挂钩，每次更新游戏模式都要更新存活时间
}

void Assistant::LoserChoice() // 游戏失败时的选择 ！！！按键检测
{
	/*绘制游戏结束界面*/
	Sleep(500); // 延时函数<windows.h>
	share.SetTextColor(11);
	share.GoToXY(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	share.GoToXY(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	share.GoToXY(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	share.GoToXY(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	share.GoToXY(24, 13);
	std::cout << share.SCORE;
	Sleep(30);
	share.GoToXY(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	share.GoToXY(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	share.GoToXY(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	share.GoToXY(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	share.GoToXY(12, 18);
	share.SetBackColor();
	std::cout << "嗯，好的";
	share.GoToXY(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key > 1)
			{
				share.GoToXY(12, 18);
				share.SetBackColor();
				std::cout << "嗯，好的";
				share.GoToXY(20, 18);
				share.SetTextColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			else if (tmp_key == 1)
			{
				share.GoToXY(12, 18);
				share.SetTextColor(11);
				std::cout << "嗯，好的";
				share.GoToXY(20, 18);
				share.SetBackColor();
				std::cout << "不了，还是学习有意思";
				tmp_key = 2;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				share.GoToXY(20, 18);
				share.SetBackColor();
				std::cout << "不了，还是学习有意思";
				share.GoToXY(12, 18);
				share.SetTextColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			else if (tmp_key == 2)
			{
				share.GoToXY(12, 18);
				share.SetBackColor();
				std::cout << "嗯，好的";
				share.GoToXY(20, 18);
				share.SetTextColor(11);
				std::cout << "不了，还是学习有意思";
				tmp_key = 1;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		share.GoToXY(0, 31);
		if (flag) {
			break;
		}
	}

	share.SetTextColor(11);

	switch (tmp_key)
	{
	case 1:
		share.SetKey(share.restart); //重新开始
		break;
	case 2:
		share.SetKey(share.quit);//退出游戏
		break;
	default:
		share.SetKey(share.restart); // 重新开始
		break;
	}
}
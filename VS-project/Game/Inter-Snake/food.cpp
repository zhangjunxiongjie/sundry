#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

void Food::DrawFood(Snake& csnake)//����ʳ��
{
	/*����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��
	  ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��*/
	while (true)
	{
		int tmp_x = rand() % 30; // rand()��ȡ�����
		int tmp_y = rand() % 30;

		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;

		bool flag = false;

		for (auto& point : csnake.snake) // ��������ڵ㣬ȷ��ʳ���������ص���food��snake����Ԫ�����໥���Է���˽�г�Ա
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;  // ���������ʳ�������������ص������²���
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y); // ���ù��λ��
		SetColor(13); // ������ɫ
		std::cout << "��"; // ���ʳ��
		++cnt;
		cnt %= 5; // ÿ�������ʳ��Ͳ���һ����˸��ʱʳ��
		if (cnt == 0)
		{
			DrawBigFood(csnake); // ������˸��ʱʳ��
		}
		break;
	}
}

void Food::DrawBigFood(Snake& csnake)//������ʱʳ��
{
	// ���ƽ�����
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------";//������
	progress_bar = 42;

	while (true) // ������˸��ʱʳ�����겢����
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
		std::cout << "��";
		big_flag = true;
		flash_flag = true;
		break;
	}
}

int Food::GetCnt() // ��õ�ǰ�Ѳ���ʳ������
{
	return cnt;
}

void Food::FlashBigFood()//��˸��ʱʳ��
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	if (flash_flag) // ʵ��ʳ����˸
	{
		std::cout << "  ";
		flash_flag = false;
	}
	else
	{
		std::cout << "��";
		flash_flag = true;
	}

	SetCursorPosition(26, 0);
	SetColor(11);
	for (int i = 42; i >= progress_bar; --i) //����������
		std::cout << "\b \b"; // \b = �˸����backspace��\r = �س�����carrige return��
		// ����ƶ������������ǰ��һ��Ȼ������ո���䣩Ȼ���ƶ�����ǰ�����������
		// ���ﻹ�д��Ľ���Ϊ����ʵ����ÿ�ζ����Ƚ�����ƶ������Ȼ����ǰ���ո�ʵ����ÿ�ν�����ƶ�����������ĩβȻ����ǰһ����伴�ɡ�
	--progress_bar;

	if (progress_bar == 0) { // ������Ϊ��ʱ��ʱʳ����ʧ
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}
}

bool Food::GetBigFlag() // �Ƿ�����ʱʳ��
{
	return big_flag;
}

int Food::GetProgressBar() // �õ���ʱʳ���ʱ
{
	return progress_bar;
}
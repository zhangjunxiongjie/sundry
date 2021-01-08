#include "game.h"
#include "share.h"
#include <Windows.h>

bool Game::Start()
{
	share.RoundNumber++; // �غ���

	share.InIt(); // ��Ϸ���¿�ʼ��ʼ��

	if (share.RoundNumber != 1) // ������ǵ�һ�غ�Ҫ��������,�Լ�һЩ���ݴ���
	{
		system("cls");
		snake.InIt();
	}
	assis.PatternChoice(); // ��Ϸģʽѡ��
	map.Draw(); // ���Ƶ�ͼ������Ϸ��Ϣ

	share.SetTextColor(6);
	snake.Draw(); // ��������

	food.CreateFood(snake); // ������ʳ��
	food.Draw(snake); //����ʳ��

	while (true)
	{
		snake.KeyMonitor(); // �������ת����˳�

		snake.RuleMove(); // �����ƶ�

		snake.OverEdge(); // �߽���

		snake.EatSame(); // �Ƿ�Ե��Լ�

		snake.JudgeSurvive(); // �ж��Ƿ񳬹����ʱ��,�����ƴ�������

		switch (share.GetKey())
		{
		case Share::keep:
			break; // �����������κβ���
		case Share::restart:
			return true;// ���¿�ʼ
		case Share::quit:
			return false; // �˳�
		}

		snake.JudgeEatFood(food); // �ж��Ƿ�Ե�ʳ�����Ե��������ʳ��

		food.Draw(snake); // ����ʳ��

		share.Game_Duration++; // ��Ϸ����ʱ��

		Sleep(share.SLEEP.at(share.PATTERN)); // ������Ϸģʽ��ͬ������ʱ
	}

	return false;
}

Game::Game(Share& s, Assistant& a) :share(s), map(s), assis(a), food(share), snake(share, map, assis)
{
	assis.StartCartoon(); //��Ϸ��������
}
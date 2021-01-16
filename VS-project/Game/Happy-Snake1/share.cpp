#include "share.h"
#include <Windows.h>

Share::Share(int f, int h, int l) :FoodValidTime(f), WINDOW_HIGH(h), WINDOW_LONG(l), SnakeSurvive(60), Game_Duration(0), CreateFoodsum(0), RoundNumber(0), SCORE(0) //���캯��
{
	Share::SetWindowSize(WINDOW_LONG, WINDOW_HIGH); // ���ô��ڴ�С

	// int PATTERN; // ��Ϸģʽ
	// int Game_Duration; //��Ϸ����ʱ��
	// int FoodValidTime; //ʳ���ܵ���Чʱ��
	// int CreateFoodsum; //����ʳ������
	// int WINDOW_LONG; // ��Ϸ���ڵĳ��͸�
	// int WINDOW_HIGH;
}

Share::KEY Share::GetKey() // ��ȡ����
{
	if (KeyChoiceValid)
	{
		KeyChoiceValid = false;
		return KeyChoice;
	}
	else // ����ȡ����ֵ
	{
		return Share::nullity;
	}
}

void Share::SetKey(KEY k) // ���ð���
{
	KeyChoiceValid = true; // ���ﲻ���ж������Ƿ�Ϊ��Чλ���������ð���
	KeyChoice = k;
}

void Share::InIt() // ���¿�ʼ��ʼ��
{
	int Game_Duration = 0; //��Ϸ����ʱ��

	int CreateFoodsum = 0; //����ʳ������

	//int RoundNumber = 1; //��ǰ�غ���

	int SCORE = 0; // �÷�
}

void Share::GoToXY(const int x, const int y) // ���ù��λ��
{
	COORD position;
	position.X = x * 2;    // ??? ΪʲôҪ����2�أ�
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows�ӿ�
}

void Share::SetTextColor(int colorID) // �����ı�ǰ����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void Share::SetBackColor(int colorID) // �����ı�������ɫ
{
}

void Share::SetBackColor() // �����ı�������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}
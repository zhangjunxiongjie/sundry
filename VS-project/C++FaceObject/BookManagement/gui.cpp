#include "public.h"
#include <Windows.h>

void PublicFunction::LightSet(bool set) // ��������,����boolֵ����ѡ���Ƿ����,Ϊ��͸�����
{
	if (set)
	{
		SetBackColor(); // ����ѡ��
	}
	else
	{
		SetFrontColor(); // ��������
	}
}

void PublicFunction::SetFrontColor() //����ǰ��ɫ,ʵ������Ϊ�������ɫ��ͳһ��ɫɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

void PublicFunction::SetBackColor() //����ǰ��ɫΪ��ɫ����ɫΪ��ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE  |  // ǰ��ɫ
	  ( BACKGROUND_BLUE  |  // ����ɫ
		BACKGROUND_GREEN |
		BACKGROUND_RED ) );
}


void PublicFunction::GoToXY(const int x, const int y) // �ƶ���굽ָ��λ��
{
	COORD position;
	position.X = x; 
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows�ӿ�
}

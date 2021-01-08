#include "public.h"
#include <Windows.h>


Share::Juri PublicFunction::ToJuri(int j) // 
{
	switch (j)
	{
	case 0:
		return Share::Root;
	case 1:
		return Share::Dry;
	case 2:
		return Share::Leaf;
	default:
		return Share::JuriError;
	}
}
Share::State PublicFunction::ToState(int s) // 
{
	switch (s)
	{
	case 0:
		return Share::Want;
	case 1:
		return Share::Reading;
	case 2:
		return Share::Read;
	case 3:
		return Share::Null;
	default:
		return Share::StateError;
	}
}
int PublicFunction::JuriTo(Share::Juri j) // 
{
	switch (j)
	{
	case Share::Root:
		return 0;
		break;
	case Share::Dry:
		return 1;
		break;
	case Share::Leaf:
		return 2;
		break;
	default:
		return 3;
		break;
	}
}
int PublicFunction::StateTo(Share::State s) // 
{
	switch (s)
	{
	case Share::Want:
		return 0;
		break;
	case Share::Reading:
		return 1;
		break;
	case Share::Read:
		return 2;
		break;
	case Share::Null:
		return 3;
		break;
	default:
		return 4;
		break;
	}
}


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
void PublicFunction::GoToXY(const int x, const int y) // �ƶ���굽ָ��λ��
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows�ӿ�
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

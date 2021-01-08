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


void PublicFunction::LightSet(bool set) // 高亮设置,根据bool值设置选项是否高亮,为真就高亮。
{
	if (set)
	{
		SetBackColor(); // 高亮选项
	}
	else
	{
		SetFrontColor(); // 消除高亮
	}
}
void PublicFunction::GoToXY(const int x, const int y) // 移动光标到指定位置
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows接口
}


void PublicFunction::SetFrontColor() //设置前景色,实际作用为清除背景色。统一蓝色色调。
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}
void PublicFunction::SetBackColor() //设置前景色为蓝色背景色为白色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE  |  // 前景色
	  ( BACKGROUND_BLUE  |  // 背景色
		BACKGROUND_GREEN |
		BACKGROUND_RED ) );
}

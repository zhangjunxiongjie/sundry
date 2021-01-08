#include "public.h"
#include <Windows.h>

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


void PublicFunction::GoToXY(const int x, const int y) // 移动光标到指定位置
{
	COORD position;
	position.X = x; 
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows接口
}

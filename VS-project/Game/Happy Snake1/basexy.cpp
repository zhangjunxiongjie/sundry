#include "basexy.h"
#include <iostream>
#include <Windows.h>

BaseXY::BaseXY(int a, int b) : x(a), y(b)
{
}

void BaseXY::GoToXY(const int x, const int y) // 设置光标位置
{
	COORD position;
	position.X = x * 2;    // ??? 为什么要乘以2呢？
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows接口
}

void BaseXY::Draw(int n) //绘制
{
	if (n == 0)
	{
		GoToXY(x, y);
		std::cout << "○"; // 蛇身
	}
	else if (n == 1)
	{
		GoToXY(x, y);
		std::cout << "■"; // 地图
	}
	else if (n == 2)
	{
		GoToXY(x, y);
		std::cout << "★"; // 食物
	}
}

void BaseXY::Clean() // 清除
{
	GoToXY(x, y);
	std::cout << "  ";
}

void BaseXY::Reset(int a, int b) //坐标重置
{
	x = a;
	y = b;
}

int BaseXY::GetX() //
{
	return x;
}

int BaseXY::GetY() //
{
	return y;
}
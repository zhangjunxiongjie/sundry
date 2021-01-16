#ifndef BASEXY_H
#define BASEXY_H

// 位置基本单位类
#include "share.h"

class BaseXY
{
public:

	BaseXY(int a, int b);

	void GoToXY(const int x, const int y); // 设置光标位置

	void Draw(int n); //绘制

	void Clean(); // 清除

	void Reset(int a, int b); //坐标重置

	int GetX(); //
	int GetY(); //

	bool operator== (const BaseXY& point) { return (point.x == this->x) && (point.y == this->y); } // 重置‘==’运算符

private:

	int x;
	int y;
};

#endif 
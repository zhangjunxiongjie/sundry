#ifndef POINT_H
#define POINT_H

class Point // 节点基本单位类，或食物节点或蛇身节点或地图单位节点
{
public:

	Point(const int x, const int y) : x(x), y(y) {} // 构造函数

	void Print(); // 在位置x,y上输出方块

	void PrintCircular(); //在位置x，y上输出圆形

	void Clear(); //清除x,y上的输出

	void ChangePosition(const int x, const int y); //设置新的x，y坐标

	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); } // 重置‘==’运算符

	int GetX() { return this->x; } // 得到x，y坐标

	int GetY() { return this->y; }

private:
	int x, y;
};
#endif // POINT_H

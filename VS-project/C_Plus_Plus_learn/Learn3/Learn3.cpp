// Learn3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 静态多态性（函数重载与覆盖）

#include <iostream>
using namespace std;

class Point
{
public:
	Point(float x = 0, float y = 0); // 构造函数
	
	void setPoint(float, float);  // 参数设置函数
	
	float getX() const { return x; }  // 获得私有成员值
	float getY() const { return y; }

	friend ostream& operator<<(ostream&, const Point&);  // 运算符重载，此处只能使用友元函数而不能使用成员函数

protected:  // 受保护成员
	float x, y;
};

Point::Point(float a, float b)
{
	x = a;
	y = b;
}

void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}

ostream& operator<<(ostream& output, const Point& p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}



class Circle:public Point   // 公用派生类
{
public:
	Circle(float x = 0, float y = 0, float r = 0);
	
	void setRadius(float);
	float getRadius() const;

	float area() const;  // 返回圆面积

	friend ostream& operator<<(ostream&, const Circle&);

protected: // 这里的成员为了能使派生类能够直接访问到要使用受保护的的属性而不能使用私有属性

	float radius;
};

Circle::Circle(float a, float b, float r):Point(a, b),radius(r){}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius; 
}

float Circle::area() const
{
	return 3.14159 * radius * radius;
}

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Center=[" << c.x << "," << c.y << "],r=" << c.radius << ",area=" << c.area() << endl;
	return output;
}



class Cylinder : public Circle
{

public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0):Circle(x, y, r), height(h){}

	void setHeight(float);
	float getHeight() const;

	float area() const;
	float volume() const;
	
	friend ostream& operator<<(ostream&, const Cylinder&);

protected:
	float height;

};

void Cylinder::setHeight(float h) { height = h; }

float Cylinder::getHeight() const { return height; }

float Cylinder::area() const
{
	return 2 * Circle::area() + 2 * 3.14159 * radius * height; 
}

float Cylinder::volume() const
{
	return Circle::area() * height;
}

ostream& operator<<(ostream& output, const Cylinder& cy)
{
	output << "Center=[" << cy.x << "," << cy.y << "],r=" << cy.radius << ",h=" << cy.height << "\narea=" << cy.area() << ",volume=" << cy.volume() << endl;
	return output;
}



int main()
{
	/*
	Point p(3.5, 6.4);
	
	cout << p.getX() << " " << p.getY() << endl;	
	
	p.setPoint(8.5, 6.8);
	cout << p;
	*/

	/*
	Circle c(3.5, 6.4, 5.2);
	
	cout << "x:" << c.getX() << "y:" << c.getY() << "r:" << c.getRadius() << "area:" << c.area() << endl;
	
	c.setRadius(7.5);
	c.setPoint(5, 5);
	cout << c;

	Point& pRef = c;
	cout << pRef;
	*/

	Cylinder cy1(3.5, 6.4, 5.2, 10);
	
	cy1.setHeight(15);
	cy1.setRadius(7.5);
	cy1.setPoint(5, 5);
	cout << cy1;

	Point &pRef = cy1; //运算符重载的测试，不同参数调用不同的运算符重载函数。
	cout << pRef;

	Circle &cRef = cy1;
	cout << cRef;

	system("Pause");
	return 0;
}






// Learn4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 动态多态性（虚函数），纯虚函数，抽象基类

#include <iostream>
using namespace std;

// 声明抽象基类 Shape
class Shape
{
public:
	virtual float area() const { return 0.0; } // 虚函数
	virtual float volume() const { return 0.0; } // 
	virtual void shapeName() const = 0; // 纯虚函数

};


// 公用派生类
class Point: public Shape
{
public:
	
	Point(float = 0, float = 0); // 构造函数
	
	void setPoint(float, float);  // 参数设置
	float getX() const { return x; } // 参数获得
	float getY() const { return y; }
	
	virtual void shapeName() const { cout << "Point:"; } // 输出名称

	friend ostream &operator << (ostream &, const Point &);  // 运算符重载

protected:
	float x, y;
};

Point:: Point( float a, float b )
{
	x = a;
	y = b;
}

void Point::setPoint( float a, float b )
{
	x = a;
	y = b;
}

ostream &operator<<( ostream &output, const Point &p)
{
	output << "[" << p.x << "," << p.y << "]";
	return output;
}


class Circle:public Point
{
public:
	Circle( float x = 0, float y = 0, float r = 0);
	
	void setRadius(float);
	float getRadius() const;

	virtual float area() const;     // 求表面积
	virtual void shapeName() const { cout << "Circle:"; }  // 求体积

	friend ostream &operator<<(ostream &, const Circle &);

protected:
	float radius;
};

Circle::Circle(float a, float b, float r) :Point(a, b), radius(r) {}

void Circle::setRadius(float r) 
{
	radius = r;
}

float Circle::getRadius() const { return radius; }

float Circle::area() const { return 3.14159 * radius * radius; }

ostream &operator<<(ostream &output, const Circle &c)
{
	output << "[" << c.x << "," << c.y << "],r=" << c.radius;
	return output;
}



class Cylinder :public Circle
{
public:

	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	
	void setHeight(float);
	
	virtual float area() const;
	virtual float volume() const;
	
	virtual void shapeName() const { cout << "Cylinder:"; }
	
	friend ostream &operator<<(ostream &, const Cylinder &);

protected:
	float height;

};

Cylinder::Cylinder(float a, float b, float r, float h) :Circle(a, b, r), height(h) {}

void Cylinder::setHeight(float h) { height = h; }

float Cylinder::area() const { return 2 * Circle::area() + 2 * 3.14159 * radius * height; }

float Cylinder::volume() const { return Circle::area() * height; }

ostream &operator<<(ostream &output, const Cylinder &cy)
{
	output << "[" << cy.x << "," << cy.y << "],r=" << cy.radius << ",h=" << cy.height;
	return output;
}

int main()
{
	Point point(3.2, 4.5);
	Circle circle(2.4, 1.2, 5.6);
	Cylinder cylinder(3.5, 6.4, 5.2, 10.5);

	// 静态关联
	// 使用不同类的对象实例，直接调用类函数
	point.shapeName();
	cout << point << endl;

	circle.shapeName();
	cout << circle << endl;

	cylinder.shapeName();
	cout << cylinder << endl;

	Shape* pt;

	// 动态关联
	// 使用基类指针调用虚函数，使用动态关联；如果调用的是一般函数则调用的是指针所属类的函数；
	// 如果调用虚函数则调用指向对象所属类的虚函数。
	pt = &point;       
	pt->shapeName(); 

	pt = &circle;
	pt->shapeName();

	pt = &cylinder;
	pt->shapeName();
	
	// system("Pause");
	return 0;
}



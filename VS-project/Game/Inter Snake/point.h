#ifndef POINT_H
#define POINT_H

class Point // �ڵ������λ�࣬��ʳ��ڵ������ڵ���ͼ��λ�ڵ�
{
public:

	Point(const int x, const int y) : x(x), y(y) {} // ���캯��

	void Print(); // ��λ��x,y���������

	void PrintCircular(); //��λ��x��y�����Բ��

	void Clear(); //���x,y�ϵ����

	void ChangePosition(const int x, const int y); //�����µ�x��y����

	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); } // ���á�==�������

	int GetX() { return this->x; } // �õ�x��y����

	int GetY() { return this->y; }

private:
	int x, y;
};
#endif // POINT_H

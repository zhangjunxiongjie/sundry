#ifndef BASEXY_H
#define BASEXY_H

// λ�û�����λ��
#include "share.h"

class BaseXY
{
public:

	BaseXY(int a, int b);

	void GoToXY(const int x, const int y); // ���ù��λ��

	void Draw(int n); //����

	void Clean(); // ���

	void Reset(int a, int b); //��������

	int GetX(); //
	int GetY(); //

	bool operator== (const BaseXY& point) { return (point.x == this->x) && (point.y == this->y); } // ���á�==�������

private:

	int x;
	int y;
};

#endif 
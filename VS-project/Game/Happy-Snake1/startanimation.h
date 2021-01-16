#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "basexy.h"

class StartInterface // ��Ϸ����������
{
public:

	StartInterface() : speed(35) {
		startsnake.emplace_back(BaseXY(0, 14)); //��
		startsnake.emplace_back(BaseXY(1, 14));
		startsnake.emplace_back(BaseXY(2, 15));
		startsnake.emplace_back(BaseXY(3, 16));
		startsnake.emplace_back(BaseXY(4, 17));
		startsnake.emplace_back(BaseXY(5, 18));
		startsnake.emplace_back(BaseXY(6, 17));
		startsnake.emplace_back(BaseXY(7, 16));
		startsnake.emplace_back(BaseXY(8, 15));
		startsnake.emplace_back(BaseXY(9, 14));

		textsnake.emplace_back(BaseXY(-26, 14));//S
		textsnake.emplace_back(BaseXY(-25, 14));
		textsnake.emplace_back(BaseXY(-27, 15));
		textsnake.emplace_back(BaseXY(-26, 16));
		textsnake.emplace_back(BaseXY(-25, 17));
		textsnake.emplace_back(BaseXY(-27, 18));
		textsnake.emplace_back(BaseXY(-26, 18));

		textsnake.emplace_back(BaseXY(-23, 14));//N
		textsnake.emplace_back(BaseXY(-23, 15));
		textsnake.emplace_back(BaseXY(-23, 16));
		textsnake.emplace_back(BaseXY(-23, 17));
		textsnake.emplace_back(BaseXY(-23, 18));
		textsnake.emplace_back(BaseXY(-22, 15));
		textsnake.emplace_back(BaseXY(-21, 16));
		textsnake.emplace_back(BaseXY(-20, 17));
		textsnake.emplace_back(BaseXY(-19, 14));
		textsnake.emplace_back(BaseXY(-19, 15));
		textsnake.emplace_back(BaseXY(-19, 16));
		textsnake.emplace_back(BaseXY(-19, 17));
		textsnake.emplace_back(BaseXY(-19, 18));

		textsnake.emplace_back(BaseXY(-17, 18));//A
		textsnake.emplace_back(BaseXY(-16, 17));
		textsnake.emplace_back(BaseXY(-15, 16));
		textsnake.emplace_back(BaseXY(-14, 15));
		textsnake.emplace_back(BaseXY(-14, 16));
		textsnake.emplace_back(BaseXY(-13, 14));
		textsnake.emplace_back(BaseXY(-13, 16));
		textsnake.emplace_back(BaseXY(-12, 15));
		textsnake.emplace_back(BaseXY(-12, 16));
		textsnake.emplace_back(BaseXY(-11, 16));
		textsnake.emplace_back(BaseXY(-10, 17));
		textsnake.emplace_back(BaseXY(-9, 18));

		textsnake.emplace_back(BaseXY(-7, 14));//K
		textsnake.emplace_back(BaseXY(-7, 15));
		textsnake.emplace_back(BaseXY(-7, 16));
		textsnake.emplace_back(BaseXY(-7, 17));
		textsnake.emplace_back(BaseXY(-7, 18));
		textsnake.emplace_back(BaseXY(-6, 16));
		textsnake.emplace_back(BaseXY(-5, 15));
		textsnake.emplace_back(BaseXY(-5, 17));
		textsnake.emplace_back(BaseXY(-4, 14));
		textsnake.emplace_back(BaseXY(-4, 18));

		textsnake.emplace_back(BaseXY(-2, 14));//E
		textsnake.emplace_back(BaseXY(-2, 15));
		textsnake.emplace_back(BaseXY(-2, 16));
		textsnake.emplace_back(BaseXY(-2, 17));
		textsnake.emplace_back(BaseXY(-2, 18));
		textsnake.emplace_back(BaseXY(-1, 14));
		textsnake.emplace_back(BaseXY(-1, 16));
		textsnake.emplace_back(BaseXY(-1, 18));
		textsnake.emplace_back(BaseXY(0, 14));
		textsnake.emplace_back(BaseXY(0, 16));
		textsnake.emplace_back(BaseXY(0, 18));
	}

	// �������ƶ�������״̬
	void PrintFirst();

	void PrintSecond();

	void PrintThird(); // �ڻ����ߵ����һ��״̬ʱ��ʼ�����ߡ�

	// ���ֵĻ��ƺ����,ÿһ������������ֵ�����������������ƶ�һ����һ�λ���ʱ����������ƶ���һ��
	void PrintText();

	void ClearText();

	void Action(); // ��Ϸ��������

private:

	std::deque<BaseXY> startsnake;//��ʼ�����е���

	std::vector<BaseXY> textsnake;//��ʼ�����е�����

	int speed;//�������ٶ�
};
#endif // STRATINTERFACE_H

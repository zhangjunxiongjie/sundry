#ifndef ASSISTANT_H
#define ASSISTANT_H
// ��Ϸ����������ģʽѡ����Ϸʧ��ѡ��

#include "share.h"

class Assistant
{
public:

	Assistant(Share& s);   // ���캯��

	void StartCartoon(); //��Ϸ��������

	void PatternChoice(); // ģʽѡ�� �������������

	void LoserChoice(); // ��Ϸʧ��ʱ��ѡ�� �������������

private:
	Share& share;
};

#endif

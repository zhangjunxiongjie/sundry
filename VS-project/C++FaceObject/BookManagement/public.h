#ifndef PUBLIC_H
#define PUBLIC_H

#include "share.h"

class PublicFunction // gui�������ڼ̳У�����һЩ���ú������߳��ú�����
{
public:

	// Gui
	void GoToXY(const int x, const int y);  //���ù��λ��
	void LightSet(bool set); // ��������,����boolֵ����ѡ���Ƿ����
	void SetFrontColor(); // ���ù̶�ǰ��ɫ��ȡ������ɫ
	void SetBackColor(); // ���ù̶�����ɫ��ǰ��ɫ�����Ｔ�����˱���ɫҲ������ǰ��ɫ��
	
	// ����תֵ
	int JuriTo(Share::Juri j); // 
	int StateTo(Share::State s); // 
	// ֵת����
	Share::State ToState(int s);
	Share::Juri ToJuri(int j);

};



#endif // !PUBLIC_H
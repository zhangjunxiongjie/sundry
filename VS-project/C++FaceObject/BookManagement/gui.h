#ifndef PublicFunction_H
#define PublicFunction_H

// 

class PublicFunction // gui�������ڼ̳У�����һЩ���ú������߳��ú�����
{
public:

	void GoToXY(const int x, const int y);  //���ù��λ��
	
	void SetFrontColor(); // ���ù̶�ǰ��ɫ��ȡ������ɫ

	void SetBackColor(); // ���ù̶�����ɫ��ǰ��ɫ�����Ｔ�����˱���ɫҲ������ǰ��ɫ��

	void LightSet(bool set); // ��������,����boolֵ����ѡ���Ƿ����

private:

};



#endif // !PublicFunction_H
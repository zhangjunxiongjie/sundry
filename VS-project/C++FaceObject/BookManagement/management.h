#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "public.h"
#include "user.h"
#include "library.h"

class Management:public PublicFunction  // ͼ�����ϵͳ�࣬
{
public:
	Management();
	~Management();

	void GuiInit(); // ����ϵͳGUI��ʼ��

	void Run();		// �ܵ�ִ���߼��������

	void DisposeChoice(int choice); // ����ѡ�
	void RootGui(int choice); // ���û�PublicFunction
	void Root(); // ��ͬȨ���û���ִ���߼�

	void Dry();

	void Leaf();

private:

	User* user; // ��¼�û�

	Usergroup* users; // �û������
	
	Library* library; // ��⣬ ��Ϊ�����û�����ʹ�õ������������ϲ����ʵ����
	
	BookGroup* bookgroup; // ����������ʹ�ø�������ļ����г�ʼ����
};


#endif
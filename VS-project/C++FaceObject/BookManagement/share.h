#ifndef SHARE_H
#define SHARE_H

//�ļ�
#define USER_FILE "usergroup.txt" // �û������ļ�
#define LIBRARY_FILE "library.txt" // ����ļ�

//����
#define WINDOWS_TALL 30    // ���ڸ�
#define WINDOWS_WIDTH 100   // ���ڿ�

// �û�
#define USER_MAX_NUMBER 100    // ����û�����0~99
#define BOOK_MAX_NUMBER 10000  // ����鼮����

// ��������
class Share // �������ͣ�ȫ�ֱ�����
{
public:

	typedef enum Jurisdiction // ÿ���û���Ȩ��ö����
	{
		Root, // ��
		Dry,  // ��
		Leaf,  // Ҷ
		JuriError // Ȩ�޴��� 
	}Juri;

	typedef enum BookState // ÿ�����ڸ����û��е�״̬ö����
	{
		Want, // ���
		Reading,  // ���ڶ�
		Read,  // �Ѷ�
		Null,  // δ��ӵ�˽�����,��ʾ�鼮״̬ʱʹ�á�
		StateError // ״̬����
	}State;

};

#endif
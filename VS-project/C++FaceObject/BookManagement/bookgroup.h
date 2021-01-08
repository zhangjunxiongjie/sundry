#ifndef BOOKGROUP_H
#define BOOKGROUP_H

#include "public.h"
#include "book.h"
#include "library.h"
#include <string>
#include <list>


class BookGroup:public PublicFunction // �����������Ը��������в��� 
{
public:

	BookGroup(std::string a, Library* b);
	~BookGroup();

	void InIt(); // ��ʼ��������⡣
	void Save(); // ���������⡣

	void UserUser(); // �û�������
	void UserUserGui(int choice); //�û�ʹ��Gui;

	void DisposeChoice(int choice); //����ѡ�� 

	void LookBooks(); // �鿴�����鼮
	
	void StateInput(int& state); // ״̬����
	void AddBook(); // ����鼮��

	void IdInPut(int& id); // id�����ɾ��ID��һ�������Լ�����롣
	void DeleteBook(); // ɾ���鼮��

private:

	
	std::list<Book> books; // ��⣬��������λ�ý����鼮����

	int booknumber; // �鼮����

	Library* library; // �û�ʵ������������ܡ�

	std::string UserBookFile;  // �û�����ļ�

};

#endif // !BOOKGROUP_H
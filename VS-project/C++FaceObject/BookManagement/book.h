#ifndef BOOK_H
#define BOOK_H

#include "share.h"
#include "public.h"
#include <string>


class Book:public PublicFunction  // ����
{
public:
	
	Book();
	~Book();

	void InIt(std::ifstream& input); // ��ȡ����ʼ�����鼮���ݣ�������ݳ�ʼ����
	void UserInIt(std::ifstream& input); // �û�������ݳ�ʼ��

	void Save(std::ofstream& output);  //�鼮���ݱ���
	void UserSave(std::ofstream& output);

	int GetId();    // ���ֵ�������鼮��Ϣչʾ��չʾ�Ľṹ���ϲ㴦��
	std::string GetBookname(); 
	std::string GetWritername();
	std::string GetPressname();
	std::string GetCategory();
	Share::BookState GetState(); // 
	void ResetState(Share::BookState s); // ����״̬

	void LookBook(int site); // ��ָ���а�һ����ʽ����鼮��Ϣ��

private:
	
	friend class Library; // ���������鼮ʱ��ʹ�õ���

	int id;   // ÿ�����ڲ�ͬ������ж���һ����ͬ��Ψһ��ID�ţ��Ա���������ƥ�䡣
	
	std::string bookname;
	std::string writername;
	std::string pressname;
	std::string category;  // ���
	
	Share::BookState state; // �鼮��״̬,���ڸ������ʱ���á����������鼮ʱ����Ҫ��ʼ����
};

#endif
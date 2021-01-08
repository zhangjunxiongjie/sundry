#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "public.h"
#include <list>

class Library:public PublicFunction // ͼ����࣬�ܵ�������
{
public:
	Library();
	~Library();

	void Init(); // ��ʼ������б�
	void Save(); // ������ݱ���

	void LibraryGroup(); // ���������߼���
	void LibraryGroupGui(int choice); // GUI
	void DisposeChoice(int choice); // ѡ���֧����

	void Find(); // ����Ա��������������û�������ʹ�õĲ�����Ϊ�˼��߼������û�������ʾ״̬��
	void FindUser(std::list<Book>& userbooks); // �û��������,���⴦��
	void FindGui(int choice); // GUI
	void FindDisposeChoice(int choice); // ѡ���֧����

	void IdInput(int& id); // ID���롣
	void IdFind(); // ID�������߼�
	Book* IdFindUser(int id); // ���û�����鼮ʹ�õ�ID��ѯ�߼�������


	void BookNameFind(); // �������ң�
	void WriterNameFind(); // ���߲��ң�
	void PressNameFind(); // ��������ҡ�
	void CategoryFind(); // �����ҡ�

	int ProduceId(); // ר�����ڲ���id
	void AddBook(); // ����鼮���鼮ID��ϵͳ���ɣ�������鼮ʱҪ���鼮��һЩ������һЩ���ƣ���֤20���ַ������£�

	void DeleteBook(); // ɾ���鼮(ֻ�ܸ����鼮IDɾ��)

	void ImportData(); // �������ݡ�

private:

	std::list<Book> books; // ��⣬��������λ�ý����鼮����

	int booknumber; // �鼮����
};

#endif

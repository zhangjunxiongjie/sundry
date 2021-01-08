#pragma once
// �������ʵ�֡�

class SINGLELIST
{
private:
	typedef struct NODE
	{
		int value;
		struct NODE* next;
	} NODE;
	typedef NODE* NODEPOINT; // ����

	NODEPOINT Head, Tail;
	int Size;

	void ReqMemory(NODEPOINT& point); // �����ڴ档
	void RemMemory(NODEPOINT& point); // �ͷ��ڴ档

	void ListDestroy(); // �ƻ�

public:
	SINGLELIST();

	void ListClear(); // ���
	int ListSize(); // ����Ԫ�ظ�����

	bool ListInsNext(const int& inssite, const int& data); // ����
	bool ListPushBack(const int& data); // ��� ������ ListInsNext ʵ�֡�

	int ListRemNext(const int& remsite); // �Ƴ� 
	int ListPopBack(); // �Ƴ��� ������ ListRemNext ʵ�֡�

	int ListFind(const int& data); // ����λ�á�

	int ListData(const int& site);  // ���λ��Ϊ site ������ֵ��

	void ListCout(); // �����

	~SINGLELIST();

};
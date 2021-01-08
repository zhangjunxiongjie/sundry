#ifndef USERGROUP_H
#define USERGROUP_H

#include <list>
#include <string>

#include "user.h"
#include "public.h"
#include "share.h"

class User;
class Usergroup:public PublicFunction  // �û��������ڣ���¼��֤��Ȩ���б��û�����root���ܽ��У�
{
public:
	Usergroup();
	~Usergroup();

	// ��ʼ���ͱ��档
	void Init();  // ��ʼ�������أ��û��б�
	void Save();  // �û����ݱ���

	// �û���¼��
	User* LogOn();  // �û���¼�߼��� ֱ���û���¼�ɹ��������û�����
	void LogOnGUI(); //��½����
	void LogOnInPut(std::string& cache, bool sign); // ��¼�û������������룬ʵ������*����ʾ��

	// �û�����
	void UserGroup(); // �û�����  
	void UserGroupGui(int choice);   // �û�������档
	void DisposeChoice(int choice); // ����ѡ��

	// �û�������
	void LookUsers(); // ��������û�
 
	void IdInPut(int& id); // id�����ɾ��ID��һ�������Լ�����롣
	void DeleteUser(); // ɾ���û�; // ֻ��ɾ���û����ݲ�����ɾ���鼮����

	Share::Juri JuriInput(); //  �û�������롣
	int ProduceId(); // ϵͳ�����û�id
	int JudgeSame(std::string username);  // ����,����ظ���ɾ����ԭ�����û����Դﵽ�޸ĵ�Ч����
	void AddUser(); // ����û�

private:

	std::list<User> users; // �û���
	
	int usernumber; // �û���

};

#endif // !USERGROUP_H

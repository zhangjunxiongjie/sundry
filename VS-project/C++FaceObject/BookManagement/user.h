#ifndef USER_H
#define USER_H

#include "share.h"
#include "bookgroup.h"
#include "usergroup.h"
#include "public.h"
#include <fstream>
#include <string>

class User:public PublicFunction // �û���
{
public:
	User();
	~User ();

	void InIt(std::ifstream& file); // ���ļ����ݳ�ʼ���˶���
	void Save(std::ofstream& file); // ���浽�ļ���

	void LookUser(int site); // �û���ʽ�������site�С�

	// ���ֵ
	std::string GetName(); // 
	std::string GetPassword(); // 
	int GetID(); // 
	Share::Juri GetJuri(); // 

private:

	friend class Usergroup; // Usergroup ������û�ʱ��Ҫֱ�ӷ���User�����Բ���ֵ�����������ֱ�Ӹ�һ����Ԫ�ɡ�

	int id; // ÿ���û�����һ��Ψһ�Ҳ����ID���ڴ����û�ʱҪ�������е��û��ҵ���С��δʹ�õ�ID�ţ�root�û�����ɾ��,idΪ0��
	std::string name;  // �û���
	std::string password; // �û�����
	Share::Juri juri;  // Ȩ�ޣ��û�����ʱȷ�������ɸı�

};

#endif 




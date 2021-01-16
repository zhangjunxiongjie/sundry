#ifndef SHARE_H
#define SHARE_H

// ���ù�������������
// ??? array������1��ʼ�������Ǵ��㿪ʼ������
#include <array>

class Share
{
public:

	Share(int f, int h, int l); //���캯��

	typedef enum Key
	{
		restart, // ���¿�ʼ
		keep, // ���֣�����
		quit, // �˳���
		nullity // ��Ч
	}KEY;

	KEY GetKey(); // ��ȡ����
	void SetKey(KEY k); // ���ð���

	void InIt(); // ���¿�ʼ��ʼ��

	void GoToXY(const int x, const int y); // ���ù��λ��

	void SetTextColor(int colorID); // �����ı�ǰ����ɫ

	void SetBackColor(int colorID); // �����ı�������ɫ
	void SetBackColor(); // ����

	int PATTERN; // ��Ϸģʽ

	int Game_Duration; //��Ϸ����ʱ��

	int FoodValidTime; //ʳ���ܵ���Чʱ��
	int CreateFoodsum; //����ʳ������

	int RoundNumber; //��ǰ�غ���

	int SCORE; // �÷�

	int SnakeSurvive; // �ߵĴ��ʱ��

	std::array<int, 4> SLEEP{ 135, 100, 60, 30 }; // ����ģʽ���ߵ��ӳ�ʱ��

private:

	KEY KeyChoice = keep;
	bool KeyChoiceValid = false; // ��ʱ��Ч

	int WINDOW_LONG; // ��Ϸ���ڵĳ��͸�
	int WINDOW_HIGH;

	void SetWindowSize(int cols, int lines)  // ���ڴ�С���ã����캯����ִ��
	{
		system("title ̰����");  //���ô��ڱ���

		char cmd[30] = {};

		sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);  //һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2

		system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
	}
};

#endif

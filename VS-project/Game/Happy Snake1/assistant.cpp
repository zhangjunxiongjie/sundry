#include "assistant.h"
#include "startanimation.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

Assistant::Assistant(Share& s) :share(s)  // ���캯��
{
}

void Assistant::StartCartoon() //��Ϸ��������
{
	StartInterface* si = new StartInterface();

	share.SetTextColor(2);  // �����ı���ɫ

	si->Action();

	delete si;

	/*���ù��λ�ã��������ʾ��ȴ�������������*/
	share.GoToXY(13, 26);
	std::cout << "Press any key to start... ";
	share.GoToXY(13, 27);
	system("pause"); // ��ͣ,��������ɼ���
}

void Assistant::PatternChoice() // ģʽѡ�� �������������
{
	/*��ʼ������ѡ��*/
	share.SetTextColor(3);
	share.GoToXY(13, 26);
	std::cout << "                          ";
	share.GoToXY(13, 27);
	std::cout << "                          ";
	share.GoToXY(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	share.GoToXY(6, 22);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";

	share.GoToXY(27, 22);
	share.SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";

	share.GoToXY(27, 24);
	share.SetTextColor(3);
	std::cout << "��ͨģʽ";
	share.GoToXY(27, 26);
	std::cout << "����ģʽ";
	share.GoToXY(27, 28);
	std::cout << "����ģʽ";

	share.GoToXY(0, 31);

	/*���·����ѡ��ģ��*/
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					share.GoToXY(27, 22);//����ѡ�������ñ���ɫ
					share.SetBackColor();
					std::cout << "��ģʽ";

					share.GoToXY(27, 24);//����ѡ����ȡ���ұ���ɫ
					share.SetTextColor(3);
					std::cout << "��ͨģʽ";

					--key;
					break;
				case 3:
					share.GoToXY(27, 24);
					share.SetBackColor();
					std::cout << "��ͨģʽ";

					share.GoToXY(27, 26);
					share.SetTextColor(3);
					std::cout << "����ģʽ";

					--key;
					break;
				case 4:
					share.GoToXY(27, 26);
					share.SetBackColor();
					std::cout << "����ģʽ";

					share.GoToXY(27, 28);
					share.SetTextColor(3);
					std::cout << "����ģʽ";

					--key;
					break;
				}
			}
			else if (key == 1)
			{
				share.GoToXY(27, 22);//����ѡ�������ñ���ɫ
				share.SetTextColor(3);
				std::cout << "��ģʽ";

				share.GoToXY(27, 28);
				share.SetBackColor();
				std::cout << "����ģʽ";

				key = 4;
			}
			break;

		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					share.GoToXY(27, 24);
					share.SetBackColor();
					std::cout << "��ͨģʽ";
					share.GoToXY(27, 22);
					share.SetTextColor(3);
					std::cout << "��ģʽ";

					++key;
					break;
				case 2:
					share.GoToXY(27, 26);
					share.SetBackColor();
					std::cout << "����ģʽ";
					share.GoToXY(27, 24);
					share.SetTextColor(3);
					std::cout << "��ͨģʽ";

					++key;
					break;
				case 3:
					share.GoToXY(27, 28);
					share.SetBackColor();
					std::cout << "����ģʽ";
					share.GoToXY(27, 26);
					share.SetTextColor(3);
					std::cout << "����ģʽ";

					++key;
					break;
				}
			}
			else if (key == 4)
			{
				share.GoToXY(27, 28);
				share.SetTextColor(3);
				std::cout << "����ģʽ";

				share.GoToXY(27, 22);//����ѡ�������ñ���ɫ
				share.SetBackColor();
				std::cout << "��ģʽ";

				key = 1;
			}
			break;

		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

		share.GoToXY(0, 31);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}

	share.PATTERN = key - 1; // ��Ϸģʽ

	// share.SnakeSurvive = share.SLEEP.at(share.PATTERN) / 2; // �ߵĴ��ʱ�����Ϸģʽ�ҹ���ÿ�θ�����Ϸģʽ��Ҫ���´��ʱ��
}

void Assistant::LoserChoice() // ��Ϸʧ��ʱ��ѡ�� �������������
{
	/*������Ϸ��������*/
	Sleep(500); // ��ʱ����<windows.h>
	share.SetTextColor(11);
	share.GoToXY(10, 8);
	std::cout << "��������������������������������������������������������������������������������������";
	Sleep(30);
	share.GoToXY(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	share.GoToXY(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	share.GoToXY(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	share.GoToXY(24, 13);
	std::cout << share.SCORE;
	Sleep(30);
	share.GoToXY(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	share.GoToXY(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	share.GoToXY(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	share.GoToXY(10, 21);
	std::cout << "��������������������������������������������������������������������������������������";

	Sleep(100);
	share.GoToXY(12, 18);
	share.SetBackColor();
	std::cout << "�ţ��õ�";
	share.GoToXY(0, 31);

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key > 1)
			{
				share.GoToXY(12, 18);
				share.SetBackColor();
				std::cout << "�ţ��õ�";
				share.GoToXY(20, 18);
				share.SetTextColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			else if (tmp_key == 1)
			{
				share.GoToXY(12, 18);
				share.SetTextColor(11);
				std::cout << "�ţ��õ�";
				share.GoToXY(20, 18);
				share.SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				tmp_key = 2;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				share.GoToXY(20, 18);
				share.SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				share.GoToXY(12, 18);
				share.SetTextColor(11);
				std::cout << "�ţ��õ�";
				++tmp_key;
			}
			else if (tmp_key == 2)
			{
				share.GoToXY(12, 18);
				share.SetBackColor();
				std::cout << "�ţ��õ�";
				share.GoToXY(20, 18);
				share.SetTextColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				tmp_key = 1;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		share.GoToXY(0, 31);
		if (flag) {
			break;
		}
	}

	share.SetTextColor(11);

	switch (tmp_key)
	{
	case 1:
		share.SetKey(share.restart); //���¿�ʼ
		break;
	case 2:
		share.SetKey(share.quit);//�˳���Ϸ
		break;
	default:
		share.SetKey(share.restart); // ���¿�ʼ
		break;
	}
}
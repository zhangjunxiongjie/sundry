#include "startanimation.h"
#include <windows.h>

// ����ͷ������ƵĹ���
void StartInterface::PrintFirst()//�ߴ���߳��ֵ���ȫ���ֵĹ���
{
	for (auto& point : startsnake)
	{
		point.Draw(0);
		Sleep(speed); // ��ʱ������Ч��
	}
}

// �����µ���ͷ�������β�Ĺ���
void StartInterface::PrintSecond()//�ߴ��������ƶ��Ĺ���
{
	for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
	{
		/*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8); // ��ͷ���㹫ʽ

		startsnake.emplace_back(BaseXY(i, j)); // ����µ���ͷ
		startsnake.back().Draw(0); //

		startsnake.front().Clean(); // �����β
		startsnake.pop_front();

		Sleep(speed); // ��ʱ
	}
}

// �����β�Ĺ��̡�
void StartInterface::PrintThird()//�ߴӽӴ��ұߵ���ʧ�Ĺ���
{
	while (!startsnake.empty() || textsnake.back().GetX() < 33) //���߻�û��ʧ������û�ƶ���ָ��λ��
	{
		// ����δ��ʧʱ�����β�������δ��ʧ���������Ѿ�����ָ��λ�����߻�����ƶ���������Ҳ������ƶ���
		// �����������ƶ��Ĳ���Ӧ��Ҳ����һ���жϵ�����ָ��λ��ʱ�Ͳ����ƶ���
		if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�
		{
			startsnake.front().Clean();
			startsnake.pop_front();
		}

		// �����ƶ��Ĺ����У����������������ƶ�
		ClearText();//�����������
		PrintText();//���Ƹ���λ�ú������

		Sleep(speed);
	}
}

void StartInterface::PrintText() // �ı����
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Draw(1);
	}
}

void StartInterface::ClearText()
{
	for (auto& point : textsnake) //�����ͬʱ���������������ƶ�һ��
	{
		if (point.GetX() >= 0)
			point.Clean();
		point.Reset(point.GetX() + 1, point.GetY());
	}
}

void StartInterface::Action() // ��Ϸ��������
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
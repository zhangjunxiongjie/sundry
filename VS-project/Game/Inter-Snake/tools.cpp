#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines) //���ô��ڴ�С
{
	system("title ̰����");  //���ô��ڱ���

	char cmd[30] = {};

	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);  //һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2

	system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(const int x, const int y) //���ù��λ��
{
	COORD position;
	position.X = x * 2; // ??? ΪʲôҪ����2�أ�
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); // Windows�ӿ�
}

void SetColor(int colorID) //�����ı���ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}
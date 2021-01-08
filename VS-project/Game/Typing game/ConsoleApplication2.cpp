// 此项目实现打字游戏 

#include "pch.h"
#include <conio.h>
#include "graphics.h"
#include <time.h>

#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")

HWND hWnd;

void Welcome();
 
void PlayGame();

int main()
{

	Welcome();

	_getch();  //按任意键继续

	PlayGame();

	return 0;
}


void Welcome()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	loadimage(NULL,L"object.jpg");

	mciSendString(L"open 一次就好.mp3 alias zgz",NULL,0,NULL); //打开音乐
	mciSendString(L"play zgz", NULL,0,NULL);   //播放音乐

	settextstyle(30, 0, L"宋体");  //设置字的大小和字体

	settextcolor(RGB(170,130,130));  //设置字的颜色

	setbkmode(TRANSPARENT);   //设置字体为背景透明

	outtextxy(200,50,L"打字练习系统");  //在屏幕指定位置输出文字

	while (!_kbhit())
	{
		Sleep(200);   //延时，休眠
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //设置字的颜色
		outtextxy(250, 430, L"按任意键继续。。。");
		Sleep(200);   //延时，休眠
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //设置字的颜色
		outtextxy(250, 430, L"按任意键继续。。。");
		Sleep(200);   //延时，休眠
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //设置字的颜色
		outtextxy(250, 430, L"按任意键继续。。。"); 
		Sleep(200);   //延时，休眠
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //设置字的颜色
		outtextxy(250, 430, L"按任意键继续。。。");
	}

}

void PlayGame()
{
	hWnd = GetHWnd();
	cleardevice();  //刷新屏幕
	int record = 0, count = 10;
	while (1)
	{
		char obj;
		char key;
		int objx, objy;
		settextcolor(RGB(255,255,255));
		settextstyle(30, 0, L"微软雅黑");
		obj = rand() % 26 + 65;
		objx = rand() % 611 + 5;  
		for (objy=0;objy<480;objy++)
		{
			cleardevice();
			outtextxy(objx, objy, obj);
			Sleep(count);
			if (_kbhit())
			{
				key = _getch();
				if (key == obj)
					break;
				else
				{
					MessageBox(hWnd, L"曹尼玛", L"提示", MB_OK);
					exit(0);
				}
			}
		}
		if (objy >= 480)
		{
			MessageBox(hWnd, L"草拟吗", L"提示", MB_OK);
			exit(0);
		}
		record++;
		switch (record)
		{
		case 10: count--; break;
		case 18: count--; break;
		case 23: count--; break;
		case 27: count--; break;
		case 30: count--; break;
		case 32: count--; break;
		case 33: count--; break;
		case 34: count--; break;
		case 35: count--; break;
		}
	}
}
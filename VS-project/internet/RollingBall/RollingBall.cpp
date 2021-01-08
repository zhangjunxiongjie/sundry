/*
	项目名称：（一个跳板小游戏）
		RollingBall
	作者：
		tzdhu.z@qq.com (1926594835)
	编译环境：
		Visual Studio 2017，EasyX_20190219(beta)
	发布日期：
		2019-2-2
	最后修改：
		2019-2-23
	项目介绍：
		本程序由单例设计模式 RollingBall 公有继承 BallAndPlank
		protected 便于派生类访问基类数据成员
		模板颜色随机，位置随机
		界面由初始化界面大小控制，初学者可自行更改
	版权声明：
		本程序完全由作者所创，不涉及任何侵权行为，仅用于学习
*/

// 头文件
#include <graphics.h>
#include <conio.h>
#include <ctime>



// 全局变量
const COLORREF BKCOLOR = BLACK;															// 绘图窗口背景颜色
const int max_x = 640;																	// 绘图窗口像素宽度
const int max_y = 480;																	// 绘图窗口像素高度
const int max_smx = GetSystemMetrics(SM_CXSCREEN);										// 电脑屏幕像素宽度
const int max_smy = GetSystemMetrics(SM_CYSCREEN);										// 电脑屏幕像素高度
const int inverse_operate_score = 600;													// 反向操作启动分数
static IMAGE img_start(80, 40), id_start(80, 40), img_exit(80, 40), id_exit(80, 40);	// 用于按钮效果的 IMAGE



////////////////////////////////////////////////////
// 小球和木板类
class BallAndPlank
{
	//小球结构体
	typedef struct BALL
	{
		int ball_x;						// 小球球心位置 x
		int ball_y;						// 小球球心位置 y
	}Ball;

	//木板结构体
	typedef struct PLANK
	{
		int plank_x;					// 木板左端位置 x
		int plank_y;					// 木板位置 y
		int plank_len;					// 木板长度
		COLORREF plank_color;			// 木板颜色
		int thorn_x;					// 尖刺左端位置 x
		bool is_thorn;					// 木板是否有尖刺
	}Plank;

public:
	// 构造函数初始化参数
	BallAndPlank()
	{
		// 小球
		ball_r = 4;
		ball_ddx = 1;
		ball_dx_min = 0;
		ball_dx_max = 8;
		left_right = STOP;
		ball_dx = ball_dx_min;
		ball_dy = ball_dx_min;
		ball_color = RGB(255, 0, 0);

		// 木板
		plank_dy = 1;
		plank_len_min = 50;
		plank_len_max = 150;
		thorn_len = 32;
		thorn_h = 4;
		plank_gap = (max_y - 1) / plank_num;
	}

	~BallAndPlank()
	{
		// 未定义
	}

	// 小球颜色绘制小球
	void DrawBall(int x, int y)
	{
		setfillcolor(ball_color);
		solidcircle(x, y, ball_r);
	}

	// 背景颜色清除小球
	void CleanBall(int x, int y)
	{
		setfillcolor(BKCOLOR);
		solidcircle(x, y, ball_r);
	}

	bool IsThorn()
	{
		return (rand() % 1000 > 600) ? true : false;
	}

	// 木板颜色绘制木板
	void DrawPlank()
	{
		for (int i = 0; i < plank_num; i++)
		{
			setlinecolor(plank[i].plank_color);
			line(plank[i].plank_x, plank[i].plank_y, plank[i].plank_x + plank[i].plank_len, plank[i].plank_y);
			if (plank[i].is_thorn == true)
			{
				for (int j = plank[i].thorn_x; j < plank[i].thorn_x + thorn_len; j += 2 * thorn_h)
				{
					line(j, plank[i].plank_y, j + thorn_h, plank[i].plank_y - thorn_h - 1);
					line(j + thorn_h, plank[i].plank_y - thorn_h - 1, j + 2 * thorn_h, plank[i].plank_y);
				}
			}
		}
	}

	// 背景颜色清除木板
	void CleanPlank()
	{
		setlinecolor(BKCOLOR);
		for (int i = 0; i < plank_num; i++)
		{
			line(plank[i].plank_x, plank[i].plank_y, plank[i].plank_x + plank[i].plank_len, plank[i].plank_y);
			if (plank[i].is_thorn == true)
			{
				for (int j = plank[i].thorn_x; j < plank[i].thorn_x + thorn_len; j += 2 * thorn_h)
				{
					line(j, plank[i].plank_y, j + thorn_h, plank[i].plank_y - thorn_h - 1);
					line(j + thorn_h, plank[i].plank_y - thorn_h - 1, j + 2 * thorn_h, plank[i].plank_y);
				}
			}
		}
	}

protected:												// 保护用于派生类访问数据成员
	// 小球属性
	enum Left_Right { STOP, LEFT, RIGHT };				// 枚举小球左右方向
	int ball_r;											// 小球半径
	int ball_ddx;										// 可视为小球加速度
	int ball_dx_min;									// 小球 x 方向最小步长
	int ball_dx_max;									// 小球 x 方向最大步长
	int left_right;										// 小球左右方向
	int ball_dx;										// 可视为小球 x 方向速度
	int ball_dy;										// 可视为小球 y 方向速度
	COLORREF ball_color;								// 小球颜色
	Ball ball;											// 小球结构对象

	// 木板属性
	enum Plank_Num { plank_num = 7 };					// 枚举初始化木板数量
	int plank_dy;										// 可视为木板速度
	int plank_len_min;									// 木板最小长度
	int plank_len_max;									// 木板最大长度
	int plank_gap;										// 木板间隔
	int thorn_len;										// 尖刺长度
	int thorn_h;										// 尖刺高度
	Plank plank[plank_num];								// 木板结构对象数组
};



////////////////////////////////////////////////////
// 单例设计模式 RollingBall派生类
class RollingBall : public BallAndPlank
{
public:
	~RollingBall()
	{
		// 未定义
	}

	// 获取单例指针
	static RollingBall* GetInstance()
	{
		static RollingBall RB;
		return &RB;
	}

	// 开始前介绍界面
	void Introduce()
	{
		setbkcolor(BKCOLOR);
		cleardevice();
		settextcolor(LIGHTMAGENTA);
		settextstyle(50, 0, _T("黑体"));
		outtextxy((max_x - textwidth(_T("RollingBall"))) / 2, max_y / 5, _T("RollingBall"));
		settextcolor(GREEN);
		settextstyle(25, 0, _T("黑体"));
		outtextxy((max_x - textwidth(_T("ESC退出,空格暂停"))) / 2, max_y / 5 * 2 + 20, _T("ESC退出,空格暂停"));
		outtextxy((max_x - textwidth(_T("控制方向:左右方向键,AD,鼠标左右键"))) / 2, max_y / 5 * 2 + 60, _T("控制方向:左右方向键,AD,鼠标左右键"));

		SetWorkingImage(&img_start);
		setbkcolor(LIGHTGRAY);
		cleardevice();
		settextcolor(BROWN);
		settextstyle(25, 0, _T("黑体"));
		outtextxy((80 - textwidth(_T("开始"))) / 2, (40 - textheight(_T("开始"))) / 2, _T("开始"));

		SetWorkingImage(&id_start);
		setbkcolor(DARKGRAY);
		cleardevice();
		settextcolor(BROWN);
		settextstyle(25, 0, _T("黑体"));
		outtextxy((80 - textwidth(_T("开始"))) / 2, (40 - textheight(_T("开始"))) / 2, _T("开始"));

		SetWorkingImage(&img_exit);
		setbkcolor(LIGHTGRAY);
		cleardevice();
		settextcolor(BROWN);
		settextstyle(25, 0, _T("黑体"));
		outtextxy((80 - textwidth(_T("退出"))) / 2, (40 - textheight(_T("退出"))) / 2, _T("退出"));

		SetWorkingImage(&id_exit);
		setbkcolor(DARKGRAY);
		cleardevice();
		settextcolor(BROWN);
		settextstyle(25, 0, _T("黑体"));
		outtextxy((80 - textwidth(_T("退出"))) / 2, (40 - textheight(_T("退出"))) / 2, _T("退出"));

		SetWorkingImage();
		int yy = max_y / 4 * 3;
		int exit_x = max_x / 2 - 200;
		int start_x = max_x / 2 + 120;
		putimage(start_x, yy, &img_start);
		putimage(exit_x, yy, &img_exit);

		// 检测是否点击相关按钮及按键
		MOUSEMSG msg;
		bool selected = false;
		while (!selected)
		{
			while (MouseHit())
			{
				msg = GetMouseMsg();

				if ((msg.x >= start_x && msg.x <= start_x + 80 && msg.y >= yy && msg.y <= yy + 40 && msg.uMsg == WM_LBUTTONDOWN) || GetAsyncKeyState(VK_RETURN) & 0x8000)
				{
					putimage(start_x, yy, &id_start);
					Sleep(200);
					putimage(start_x, yy, &img_start);
					Sleep(100);
					selected = true;
					break;
				}
				else if ((msg.x >= exit_x && msg.x <= exit_x + 80 && msg.y >= yy && msg.y <= yy + 40 && msg.uMsg == WM_LBUTTONDOWN) || GetAsyncKeyState(VK_ESCAPE) & 0x8000)
				{
					putimage(exit_x, yy, &id_exit);
					Sleep(200);
					putimage(exit_x, yy, &img_exit);
					Sleep(100);
					exit(0);
				}
			}

			Sleep(16);
		}
	}

	// 初始化游戏界面
	void Initialize()
	{
		setbkcolor(BKCOLOR);
		cleardevice();
		setlinecolor(DARKGRAY);
		line(0, 0, 0, max_y - 1);
		line(max_y, 0, max_y, max_y - 1);
		line(0, 0, max_y - 1, 0);
		line(0, max_y - 1, max_y - 1, max_y - 1);

		for (int i = 0; i < max_y; i += 2 * die_top)
		{
			line(i, 0, i + die_top, die_top);
			line(i + die_top, die_top, i + 2 * die_top, 0);
		}

		for (int i = 0; i < plank_num; i++)
		{
			plank[i].plank_y = (i + 1) * plank_gap;
			plank[i].plank_len = rand() % (plank_len_max - plank_len_min) + plank_len_min + 1;
			plank[i].plank_x = rand() % (max_y - plank[i].plank_len);
			plank[i].plank_color = HSVtoRGB(float(rand() % 360), float(1.0), float(1.0));
			plank[i].is_thorn = IsThorn();
			if (plank[i].is_thorn == true)
				plank[i].thorn_x = plank[i].plank_x + rand() % (plank[i].plank_len - thorn_len);
		}

		plank[3].is_thorn = false;
		ball.ball_x = plank[3].plank_x + plank[3].plank_len / 2;
		ball.ball_y = plank[3].plank_y - 1 - ball_r;
		DrawBall(ball.ball_x, ball.ball_y);
		DrawPlank();
		Sleep(sleep_time);
	}

	// 检测是否死亡
	bool IsDead()
	{
		if (ball.ball_y <= die_top + ball_r || ball.ball_y >= max_y - 1 - ball_r || is_dead)
		{
			is_dead = true;
			return true;
		}
		else
			return false;
	}

	// 打印分数,速度及是否开启反向操作
	void PrintScore()
	{
		settextcolor(RED);
		settextstyle(16, 0, _T("黑体"));
		score = time_num / 5;
		TCHAR str[20];
		_stprintf_s(str, _T("当前得分: %d"), score);
		outtextxy(max_y + 5, max_y / 6 * 5 + 10, str);

		if (score < 50)	plank_dy = 1;
		else if (score < 200)	plank_dy = 2;
		else if (score < 500)	plank_dy = 3;
		else if (score < 1000)	plank_dy = 4;
		else if (score < 1500)	plank_dy = 5;
		else					plank_dy = 6;

		_stprintf_s(str, _T("当前速度: %d/6"), plank_dy);
		outtextxy(max_y + 5, max_y / 2 - 10, str);
		if (score > inverse_operate_score)
			outtextxy(max_y + 5, max_y / 11, _T("反向操作 已开启"));
		else
			outtextxy(max_y + 5, max_y / 11, _T("反向操作 未开启"));
	}

	// 非ESC结束时显示最终分数
	void Finish()
	{
		if (is_dead)
		{
			TCHAR str[50];
			_stprintf_s(str, _T("\t     您的最终得分为: %d\t\t"), score);
			MessageBox(GetHWnd(), str, _T("游戏结束"), MB_OK);
		}
	}

	// 游戏运行处理
	void GameRunning()
	{
		// 清除小球和木板
		CleanBall(ball.ball_x, ball.ball_y);
		CleanPlank();

		// 计��木板位置
		for (int i = 0; i < plank_num; i++)
			plank[i].plank_y -= plank_dy;

		// 顶木板是否消失，是 则生成尾木板
		if (plank[0].plank_y < die_top + ball_r + 1)
		{
			for (int i = 0; i < plank_num - 1; i++)
				plank[i] = plank[i + 1];
			plank[plank_num - 1].plank_y = (plank_num)* plank_gap;
			plank[plank_num - 1].plank_len = rand() % (plank_len_max - plank_len_min) + plank_len_min + 1;
			plank[plank_num - 1].plank_x = rand() % (max_y - plank[plank_num - 1].plank_len);
			plank[plank_num - 1].plank_color = HSVtoRGB(float(rand() % 360), float(1.0), float(1.0));
			plank[plank_num - 1].is_thorn = IsThorn();
			if (plank[plank_num - 1].is_thorn == true)
				plank[plank_num - 1].thorn_x = plank[plank_num - 1].plank_x + rand() % (plank[plank_num - 1].plank_len - thorn_len);
		}

		// 计算小球球心 x 位置(加减速效果)
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState('A') & 0x8000) || (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
		{
			if (score < inverse_operate_score)
			{
				if (left_right == LEFT)
					ball_dx = (ball_dx += ball_ddx) > ball_dx_max ? ball_dx_max : ball_dx;
				else
				{
					ball_dx = ball_dx_min;
					left_right = LEFT;
				}
				ball.ball_x = (ball.ball_x -= ball_dx) < ball_r ? ball_r : ball.ball_x;
			}
			else
			{
				if (left_right == RIGHT)
					ball_dx = (ball_dx += ball_ddx) > ball_dx_max ? ball_dx_max : ball_dx;
				else
				{
					ball_dx = ball_dx_min;
					left_right = RIGHT;
				}
				ball.ball_x = (ball.ball_x += ball_dx) > (max_y - 1 - ball_r) ? max_y - 1 - ball_r : ball.ball_x;
			}
		}
		else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState('D') & 0x8000) || (GetAsyncKeyState(VK_RBUTTON) & 0x8000))
		{
			if (score > inverse_operate_score)
			{
				if (left_right == LEFT)
					ball_dx = (ball_dx += ball_ddx) > ball_dx_max ? ball_dx_max : ball_dx;
				else
				{
					ball_dx = ball_dx_min;
					left_right = LEFT;
				}
				ball.ball_x = (ball.ball_x -= ball_dx) < ball_r ? ball_r : ball.ball_x;
			}
			else
			{
				if (left_right == RIGHT)
					ball_dx = (ball_dx += ball_ddx) > ball_dx_max ? ball_dx_max : ball_dx;
				else
				{
					ball_dx = ball_dx_min;
					left_right = RIGHT;
				}
				ball.ball_x = (ball.ball_x += ball_dx) > (max_y - 1 - ball_r) ? max_y - 1 - ball_r : ball.ball_x;
			}
		}
		else
		{
			ball_dx -= ball_ddx;
			if (ball_dx > ball_dx_min)
			{
				if (left_right == LEFT)
					ball.ball_x = (ball.ball_x -= ball_dx) < ball_r ? ball_r : ball.ball_x;
				else if (left_right == RIGHT)
					ball.ball_x = (ball.ball_x += ball_dx) > (max_y - 1 - ball_r) ? max_y - 1 - ball_r : ball.ball_x;
			}
			else
			{
				ball_dx = ball_dx_min;
				left_right = STOP;
			}
		}

		// 计算小球球心 y 位置(加速效果)
		int ii = 0;	// 用于确定小球位于哪块木板上方
		while (ball.ball_y - plank_dy > plank[ii].plank_y - 1 - ball_r)
			ii++;

		if (ii < plank_num&&
			ball.ball_x >= plank[ii].plank_x && ball.ball_x <= plank[ii].plank_x + plank[ii].plank_len
			&& (ball.ball_y - plank_dy == plank[ii].plank_y - 1 - ball_r || ball.ball_y >= plank[ii].plank_y - 1 - ball_r))
		{
			ball.ball_y = plank[ii].plank_y - 1 - ball_r;
			ball_dy = ball_dx_min;
		}
		else
		{
			ball_dy = (ball_dy += ball_ddx) > ball_dx_max ? ball_dx_max : ball_dy;
			ball.ball_y += ball_dy;
			if (ii < plank_num &&
				ball.ball_x >= plank[ii].plank_x && ball.ball_x <= plank[ii].plank_x + plank[ii].plank_len && ball.ball_y >= plank[ii].plank_y - 1 - ball_r)
			{
				ball.ball_y = plank[ii].plank_y - 1 - ball_r;
				ball_dy = ball_dx_min;
			}
			else if (ball.ball_y > max_y - 1 - ball_r)
				ball.ball_y = max_y - 1 - ball_r;
		}

		// 判断小球是否触碰尖刺
		if (ball.ball_x >= plank[ii].thorn_x - ball_r / 2 && ball.ball_x <= plank[ii].thorn_x + thorn_len + ball_r / 2
			&& ball.ball_y == plank[ii].plank_y - 1 - ball_r && plank[ii].is_thorn)
			is_dead = true;

		// 绘制木板和小球
		DrawPlank();
		DrawBall(ball.ball_x, ball.ball_y);
		FlushBatchDraw();
		time_num++;

		// 打印分数,速度及是否开启反向操作
		PrintScore();
		Sleep(sleep_time);
	}

private:
	// 构造函数初始化参数
	RollingBall()
	{
		score = 0;
		die_top = 5;
		time_num = 0;
		sleep_time = 20;
		is_dead = false;
	}

	RollingBall(const RollingBall& rb) {}							// 禁止拷贝构造
	RollingBall& operator = (const RollingBall& rb) {}				// 禁止赋值重载
	int sleep_time;													// 游戏刷新时间间隔
	int time_num;													// 记录游戏刷新次数
	int die_top;													// 顶部尖刺位置
	int score;														// 记录分数
	bool is_dead;													// 是否死亡
};



////////////////////////////////////////////////////
// main 主函数
int main()
{
	initgraph(max_x, max_y, NOMINIMIZE);
	srand((unsigned)time(NULL));

	// 获取单例指针
	RollingBall* rb = RollingBall::GetInstance();

	rb->Introduce();
	rb->Initialize();
	BeginBatchDraw();

	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000))
	{
		rb->GameRunning();
		if (rb->IsDead())
			break;
		if (_kbhit() && _getwch() == ' ')
			_getwch();
	}

	EndBatchDraw();
	rb->Finish();

	closegraph();
	return 0;
}
#ifndef ASSISTANT_H
#define ASSISTANT_H
// 游戏启动动画，模式选择，游戏失败选项

#include "share.h"

class Assistant
{
public:

	Assistant(Share& s);   // 构造函数

	void StartCartoon(); //游戏启动动画

	void PatternChoice(); // 模式选择 ！！！按键检测

	void LoserChoice(); // 游戏失败时的选择 ！！！按键检测

private:
	Share& share;
};

#endif

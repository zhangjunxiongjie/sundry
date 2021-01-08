#ifndef PUBLIC_H
#define PUBLIC_H

#include "share.h"

class PublicFunction // gui基类用于继承，放置一些公用函数或者常用函数。
{
public:

	// Gui
	void GoToXY(const int x, const int y);  //设置光标位置
	void LightSet(bool set); // 高亮设置,根据bool值设置选项是否高亮
	void SetFrontColor(); // 设置固定前景色，取消背景色
	void SetBackColor(); // 设置固定背景色和前景色（这里即设置了背景色也设置了前景色）
	
	// 类型转值
	int JuriTo(Share::Juri j); // 
	int StateTo(Share::State s); // 
	// 值转类型
	Share::State ToState(int s);
	Share::Juri ToJuri(int j);

};



#endif // !PUBLIC_H
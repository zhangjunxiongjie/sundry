#ifndef PublicFunction_H
#define PublicFunction_H

// 

class PublicFunction // gui基类用于继承，放置一些公用函数或者常用函数。
{
public:

	void GoToXY(const int x, const int y);  //设置光标位置
	
	void SetFrontColor(); // 设置固定前景色，取消背景色

	void SetBackColor(); // 设置固定背景色和前景色（这里即设置了背景色也设置了前景色）

	void LightSet(bool set); // 高亮设置,根据bool值设置选项是否高亮

private:

};



#endif // !PublicFunction_H
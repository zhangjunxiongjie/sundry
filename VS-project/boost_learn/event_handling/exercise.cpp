// 练习

// 读题后一脸懵逼，这里实现竟没有使用事件处理。

#include "public.h"

/*
编写一个程序，定义一个名为 button 的类，表示GUI中的一个可点击按钮。为该类加入两个方法 add_handler() 和 remove_handler()，
它们均要求一个函数名作为参数。如果 click() 方法被调用，已登记的函数将被按顺序执行。
如下测试你的代码，创建一个 button 类的实例，从事件处理器内部向标准输出流写出一个信息。 
调用 click() 函数模拟用鼠标点击该按钮。
*/

Button::Button(boost::function<void()> func1, boost::function<void()> func2) : _addHandler(func1), _removeHandler(func2)
{

}
void Button::click()
{
	_add_handler(_addHandler);
	_remove_handler(_removeHandler);
}

void Button::_add_handler(boost::function<void()>& func)
{
	func();
}

void Button::_remove_handler(boost::function<void()>& func)
{
	func();
}
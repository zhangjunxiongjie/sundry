// public header

#include <iostream>
#include <boost\signals2.hpp>
#include <boost\optional\optional_io.hpp>  //

void signal_func();

void boost_signal();

#include <boost\function.hpp> 
void function_signal();

void signal_func1();
void signal_func2();

void boost_signal_more_connect();

void boost_signal_more_connect_customize();

void boost_signal_more_connect_disconnect();

void boost_signal_connect_slots();


int signal_func3();
int signal_func4();

void boost_signal_return();

#include <algorithm> 
void boost_signal_return_customize_use();

#include <vector>
void boost_signal_return_customize_save();

void boost_signal_connection();

#include <boost/bind.hpp> 
#include <memory> 
void boost_connection_bind();

// exercise
class Button
{
public:
	Button(boost::function<void()> func1, boost::function<void()> fun2);

	void click();
private:
	boost::function<void()> _addHandler; // 变量小写驼峰式命名
	boost::function<void()> _removeHandler;

	// 私有函数命名。
	void _add_handler(boost::function<void()>& func);
	void _remove_handler(boost::function<void()>& func);
};

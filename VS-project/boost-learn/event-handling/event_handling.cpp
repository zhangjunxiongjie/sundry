// 事件处理，信号槽机制
// 

#include "public.h"

void signal_func()
{
	std::cout << "Hello, world!" << std::endl;
}

/*
Boost.Signals 所实现的模式被命名为 '信号至插槽' (signal to slot)，它基于以下概念：当对应的信号被发出时，
相关联的插槽即被执行。原则上，你可以把单词 '信号' 和 '插槽' 分别替换为 '事件' 和 '事件处理器'。 不过，
由于信号可以在任意给定的时间发出，所以这一概念放弃了 '事件' 的名字。
*/
// 信号槽简单示例
void boost_signal()
{
	// boost::signal 实际上被实现为一个模板函数，具有被用作为事件处理器的函数的签名，该签名也是它的模板参数。 
	// 在这个例子中，只有签名为 void () 的函数可以被成功关联至信号 s。
	/*
	函数 func() 被通过 connect() 方法关联至信号 s。由于 func() 符合所要求的 void() 签名，所以该关联成功建立。
	因此当信号 s 被触发时，func() 将被调用。信号是通过调用 s 来触发的，就象普通的函数调用那样。 这个函数的签名
	对应于作为模板参数传入的签名：因为 void() 不要求任何参数，所以括号内是空的。调用 s 会引发一个触发器，
	进而执行相应的 func() 函数 - 之前用 connect() 关联了的。
	*/
	
	boost::signals2::signal<void()> s; // 创建一个能与特定函数关联的信号槽。
	s.connect(signal_func); // 信号槽关联函数
	s(); // 触发信号。
}

// 使用function模块实现信号槽
/*
和前一个例子相类似，func() 被关联至 f。当 f 被调用时，就会相应地执行 func()。Boost.Function 仅限于这种情形下适用，
而 Boost.Signals 则提供了多得多的方式，如关联多个函数至单个特定信号，
*/
void function_signal()
{
	boost::function<void()> f;
	f = signal_func; // 关联
	f(); // 触发。
}



void signal_func1()
{
	std::cout << "Hello" << std::flush; // std::flush 刷新输出流
}
void signal_func2()
{
	std::cout << ", world!" << std::endl; // std::endl 刷新输出流并换行。
}

// 关联多个函数至单个特定信号，
void boost_signal_more_connect()
{
	boost::signals2::signal<void()> s;
	s.connect(signal_func1);
	s.connect(signal_func2);
	s();
}

/*
boost::signal 可以通过反复调用 connect() 方法来把多个函数赋值给单个特定信号。当该信号被触发时，这些函数被按照之前用 
connect() 进行关联时的顺序来执行。另外，执行的顺序也可通过 connect() 方法的另一个重载版本来明确指定，
该重载版本要求以一个 int 类型的值作为额外的参数。
*/
// 可自定义执行顺序的多函数关联
void boost_signal_more_connect_customize()
{
	boost::signals2::signal<void()> s;
	s.connect(1, signal_func2);  // 第一个参数作为优先级，数值越小优先级越高。
	s.connect(0, signal_func1);
	s();
}

// 关联函数的释放
void boost_signal_more_connect_disconnect()
{
	boost::signals2::signal<void()> s;
	s.connect(signal_func1);
	s.connect(signal_func2);
	
	s.disconnect(signal_func2); // 释放关联函数。
	
	s();
}

// 一些信号槽的基本方法
void boost_signal_connect_slots()
{
	boost::signals2::signal<void()> s;
	s.connect(signal_func1);
	s.connect(signal_func2);
	
	std::cout << s.num_slots() << std::endl; // num_slots() 返回已关联函数的数量。如果没有函数被关联，则 num_slots() 返回0。 
	
	if (!s.empty()) // 如果关联函数不为空则触发信号。
		s();
	s.disconnect_all_slots(); // 释放所有函数。
}



int signal_func3()
{
	return 1;
}
int signal_func4()
{
	return 2;
}

// 以下例子实际上会把 2 写出至标准输出流。两个返回值都被 s 正确接收，但除了最后一个值，其它值都会被忽略。 
// 缺省情况下，所有被关联函数中，实际上只有最后一个返回值被返回。
// 函数的返回值
void boost_signal_return()
{
	boost::signals2::signal<int()> s;
	s.connect(signal_func3);
	s.connect(signal_func4);

	std::cout << s() << std::endl;
}

// 可以定制一个信号，令每个返回值都被相应地处理。为此，要把一个称为合成器(combiner)的东西作为第二个参数传递给 boost::signal。
// 自定义的函数返回值。
template <typename T>
struct min_element_use
{
	typedef T result_type;

	template <typename InputIterator>
	T operator()(InputIterator first, InputIterator last) const
	{
		return *std::min_element(first, last);
	}
};
void boost_signal_return_customize_use()
{
	// 合成器是一个重载了 operator()() 操作符的类。这个操作符会被自动调用，传入两个迭代器，
	// 指向某个特定信号的所有返回值。以上例子使用了标准 C++ 算法 std::min_element() 
	// 来确定并返回最小的值。

	boost::signals2::signal<int(), min_element_use<int> > s;
	s.connect(signal_func3);
	s.connect(signal_func4);
	
	std::cout << s() << std::endl;
}

// 函数返回值的保存。
template <typename T>   // 合成器？？
struct min_element_save
{
	typedef T result_type;

	template <typename InputIterator>
	T operator()(InputIterator first, InputIterator last) const
	{
		return T(first, last);
	}
};
void boost_signal_return_customize_save()
{
	boost::signals2::signal<int(), min_element_save<std::vector<int> > > s;
	s.connect(signal_func3);
	s.connect(signal_func4);
	std::vector<int> v = s();

	std::cout << *std::min_element(v.begin(), v.end()) << std::endl;
}


// 使用 connection 管理信号槽
void boost_signal_connection()
{
	boost::signals2::signal<void()> s;
	boost::signals2::connection c = s.connect(signal_func);
	
	s();
	
	c.disconnect(); // 如何确定释放那个函数呢。
}


// ???
class world : public boost::signals2::trackable
{
public:
	void hello() const
	{
		std::cout << "Hello, world!" << std::endl;
	}
};
void boost_connection_bind()
{
	boost::signals2::signal<void()> s;
	{
		std::auto_ptr<world> w(new world());
		s.connect(boost::bind(&world::hello, w.get()));
	}

	std::cout << s.num_slots() << std::endl;
	s();
}
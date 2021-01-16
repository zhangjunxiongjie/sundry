// FunctionObject.cpp : 函数指针对象
//

#include "public.h"

void stl_print(int i)
{
	std::cout << i << ":";
}
void stl_for_each() // 演示 for_each 用法
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::for_each(v.begin(), v.end(), stl_print); // 第三个参数只能接受一个参数的函数指针
	std::cout << std::endl << std::endl;
}

// stl 实现函数改元
class stl_add : public std::binary_function<int, int, void> // 派生
{
public:
	void operator()(int i, int j) const
	{
		std::cout << i + j << ":";
	}
};
void stl_bind1st()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	// 这里要使用 binary_function 派生一个类才能在第三个参数位置使用带一个参数以上的函数。
	std::for_each(v.begin(), v.end(), std::bind1st(stl_add(), 100));
	std::cout << std::endl << std::endl;
}


// boost 实现函数改元便于以函数指针形式传入其它函数
void boost_add(int i, int j)
{
	std::cout << i + j << ":";
}
void boost_bind()
{
	/*
	使用 boost::bind() 可以使像 add() 这样的函数不再需要为了要用于 std::for_each() 而转换为函数对象。 
	使用 boost::bind()，这个函数可以忽略其第一个参数而使用。因为 add() 函数要求两个参数，两个参数都必须传递给 
	boost::bind()。第一个参数是常数值10，而第二个参数则是一个怪异的 _1。_1 被称为占位符(placeholder)，
	定义于 Boost.Bind。除了 _1，Boost.Bind 还定义了 _2 和 _3。 通过使用这些占位符，boost::bind() 可以变为一元、
	二元或三元的函数。 对于 _1, boost::bind() 变成了一个一元函数 - 即只要求一个参数的函数。 这是必需的，
	因为 std::for_each() 正是要求一个一元函数作为其第三个参数。当这个程序执行时，std::for_each() 对容器 v 中的
	第一个元素调用该一元函数。 元素的值通过占位符 _1 传入到一元函数中。 这个占位符和常数值被进一步传递到 add() 函数。 
	通过使用这种机制，std::for_each() 只看到了由 boost::bind() 所定义的一元函数。 而 boost::bind() 本身则只是调用了
	另一个函数，并将常数值或占位符作为参数传入给它。
	*/
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	// 使用 boost::bind 函数可以不用派生类，增加一个函数对象，可以直接将一个多元函数转换为一个一元、二元或三元的函数；
	// 这样就可以方便的将函数指针作为一个参数传入一个函数内，不管这个函数要求传入的函数指针对应的函数参数是多少个。
	std::for_each(v.begin(), v.end(), boost::bind(boost_add, 10, _1));
	
	std::cout << std::endl << std::endl;
}

 // 函数改元实例
bool boost_compare(int i, int j) // 定义排序规则，用于排序算法。
{
	return i > j;
}
void boost_sort()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	// 这里原函数也是二元函数故使用 boost 作用不大。
	std::sort(v.begin(), v.end(), boost::bind(boost_compare, _1, _2)); // 二元
	// 打印
	std::for_each(v.begin(), v.end(), stl_print); // 第三个参数只能接受一个参数的函数指针
	std::cout << std::endl << std::endl;

	// 但是当原函数不宜改变时也可以使用 boost 交换参数。
	std::sort(v.begin(), v.end(), boost::bind(boost_compare, _2, _1)); // 二元
	// 打印
	std::for_each(v.begin(), v.end(), stl_print); // 第三个参数只能接受一个参数的函数指针
	
	std::cout << std::endl << std::endl;
}

// 存在引用参数的函数改元。
void boost_ref_add(int i, int j, std::ostream& os)
{
	os << i + j << ":";
}
void boost_ref_for_each()
{
	/*
	 Boost.Ref 通常与 Boost.Bind 一起使用。它提供了两个函数 - boost::ref() 和 boost::cref() - 定义于 boost/ref.hpp.
	当要用于 boost::bind() 的函数带有至少一个引用参数时，Boost.Ref 就很重要了。 由于 boost::bind() 会复制它的参数，
	所以引用必须特别处理。
	*/
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	// 使用 boost::bind 将三元函数改成一元函数。需要注意的是第三个参数是一个引用。
	/*
	因为传给 boost::bind() 的参数是以值方式传递的，所以 std::cout 不能直接使用，否则该函数会试图创建它的一份拷贝。
	通过使用模板函数 boost::ref()，象 std::cout 这样的流就可以被以引用方式传递，也就可以成功编译上面这个例子了。
	要以引用方式传递常量对象，可以使用模板函数 boost::cref()。
	*/
	std::for_each(v.begin(), v.end(), boost::bind(boost_ref_add, 10, _1, boost::ref(std::cout)));
	
	std::cout << std::endl << std::endl;
}


// 函数指针对象管理函数指针
void boost_function_ptr()
{
	// 封装函数指针
	/*
	boost::function 可以定义一个指针，指向具有特定签名的函数。以上例子定义了一个指针 f，它可以指向某个接受
	一个类型为 const char* 的参数且返回一个类型为 int 的值的函数。定义完成后，匹配此签名的函数均可赋值给这个指针。 
	这个例程就是先将 std::atoi() 赋值给 f，然后再将它重赋值为 std::strlen()。注意，给定的数据类型并不需要
	精确匹配：虽然 std::strlen() 是以 std::size_t 作为返回类型的，但是它也可以被赋值给 f。因为 f 是一个函数指针(对象)，
	所以被赋值的函数可以通过重载的 operator()() 操作符来调用。 取决于当前被赋值的是哪一个函数，在这个例子中
	将调用 std::atoi() 或 std::strlen()。如果 f 未赋予一个函数而被调用，则会抛出一个 boost::bad_function_call 异常。
	*/
	boost::function<int(const char*)> f = std::atoi;  // 将字符串转换为数值
	std::cout << f("1609") << ":";
	
	f = std::strlen; // 重新赋值 必须与函数指针对象拥有相同的函数参数列表。
	std::cout << f("1609") << ":";

	std::cout << std::endl << std::endl;
}

// 函数指针对象未初始化抛出异常
void boost_bad_function_call()
{
	try
	{
		boost::function<int(const char*)> f;
		f("");
	}
	catch (boost::bad_function_call& ex)
	{
		std::cout << ex.what();
	}

	std::cout << std::endl << std::endl;
}

// 函数指针对象管理成员函数指针
class World
{
public:
	void hello(std::ostream& os)
	{
		os << "Hello, world!";
	}
};
void boost_member_function_ptr()
{
	/*
	将值 0 赋给一个 boost::function 类型的函数指针，将会释放当前所赋的函数。 释放之后再调用它也会导致 
	boost::bad_function_call 异常被抛出。要检查一个函数指针是否被赋值某个函数，可以使用 empty() 函数或 
	operator bool() 操作符。通过使用 Boost.Function，类成员函数也可以被赋值给类型为 boost::function 的对象。
	
	在调用这样的一个函数时，传入的第一个参数表示了该函数被调用的那个特定对象。因此，在模板定义中的
	左括号后的第一个参数必须是该特定类（对象）的指针。 接下来的参数才是表示相应的成员函数的签名。
	这个程序还使用了来自 Boost.Ref 库的 boost::ref()，它提供了一个方便的机制向 Boost.Function 传递引用。
	*/
	boost::function<void(World*, std::ostream&)> f = &World::hello;
	
	World w;  // 实例化类
	
	// 将对象（成员函数所属类实例化的对象）传入，对于传入的不同实体成员函数运行结果也不同。
	f(&w, boost::ref(std::cout));  // 引用参数特殊处理

	std::cout << std::endl << std::endl;
}


/*
匿名函数 - 又称为 lambda 函数 - 已经在多种编程语言中存在，但 C++ 除外。不过在 Boost.Lambda 库的帮助下，
现在在 C++ 应用中也可以使用它们了。lambda 函数的目标是令源代码更为紧凑，从而也更容易理解。
*/
// 匿名函数实现 stl_print()
void boost_lambda_print()
{
	// Boost.Lambda 提供了几个结构来定义匿名函数。 
	// 代码就被置于执行的地方，从而省去将它包装为一个函数再进行相应的函数调用的这些开销。

	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	std::for_each(v.begin(), v.end(), std::cout << boost::lambda::_1 << ":");
	std::cout << std::endl << std::endl;
}

/*
Boost.Lambda 提供了几个结构来定义匿名函数。代码就被置于执行的地方，从而省去将它包装为一个函数再进行相应的函数调用的这些开销。 
与原来的例子一样，这个程序将容器 v 的所有元素写出至标准输出流。与 Boost.Bind 相类似，Boost.Lambda 也定义了三个占位符，
名为 _1, _2 和 _3。 但与 Boost.Bind 不同的是，这些占位符是定义在单独的名字空间的。 因此，该例中的第一个占位符是通过 
boost::lambda::_1 来引用的。 为了满足编译器的要求，必须包含相应的头文件 boost/lambda/lambda.hpp。
虽然代码的位置位于 std::for_each() 的第三个参数处，看起来很怪异，但 Boost.Lambda 可以写出正常的 C++ 代码。 
通过使用占位符，容器 v 的元素可以通过 << 传给 std::cout 以将它们写出到标准输出流。
虽然 Boost.Lambda 非常强大，但也有一些缺点。要在以上例子中插入换行的话，必须用 "\n" 来替代 std::endl 才能成功编译。 
因为一元 std::endl 模板函数所要求的类型不同于 lambda 函数 std::cout << boost::lambda::_1 的函数，所以在此不能使用它。
*/
// 匿名函数的条件语句。
void boost_lambda_if()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	std::for_each(v.begin(), v.end(),
		boost::lambda::if_then(boost::lambda::_1 > 1,
			std::cout << boost::lambda::_1 << ":"));

	std::cout << std::endl << std::endl;
}



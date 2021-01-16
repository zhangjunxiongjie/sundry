// STL 容器 容器即用来存储并管理某类对象的集合。
/*
STL 中已经提供的容器主要如下：
vector <T>：一种向量。
list <T>：一个双向链表容器，完成了标准 C++ 数据结构中链表的所有功能。
queue <T>：一种队列容器，完成了标准 C++ 数据结构中队列的所有功能。
stack <T>：一种栈容器，完成了标准 C++ 数据结构中栈的所有功能。
deque <T>：双端队列容器，完成了标准 C++ 数据结构中栈的所有功能。
priority_queue <T>：一种按值排序的队列容器。
set <T>：一种集合容器。
multiset <T>：一种允许出现重复元素的集合容器。
map <key, val>：一种关联数组容器。
multimap <key, val>：一种允许出现重复 key 值的关联数组容器。

容器可以分为序列式容器和关联式容器两大类
*/

#include <iostream>

using namespace std;



#include <memory>
/*
C++ 库中的 auto_ptr 对象是一种智能指针。智能指针是一种类，即其对象的特征结类似于指针。智能指针存储 new 分配的内存地址，也可以被解除引用。
智能指针是一个类对象，可以修改和扩充简单指针的行为。智能指针可以建立引用计数，这使得多个对象可共享由智能指针跟踪的同一个值。
当使用该值的对象数为 0 时，智能指针将删除该值。智能指针可以提高内存的使用效率，帮助防止内存泄露(自动进行内存回收)。
*/
void autor()
{
	auto_ptr <double> pd;
	
	double* p_reg = new double;
	
	// pd = p_reg; //① 不允许，不能将指针直接赋给此对象。
	
	pd = auto_ptr <double>(p_reg); //允许,此处使用p_reg作为参数建立匿名对象，这个匿名对象可以直接赋值给pd。
	
	// auto_ptr <double> panto = p_reg; //不允许，与 ① 处类似，auto_ptr <double>(p_reg)只是使用p_reg建立了一个匿名对象对其自身并无修改。
	
	auto_ptr <double> pauto(p_reg); //允许

}

#include <vector>
void intr()
{
	vector <int> tr; // 定义一个“数组”对象

	for (int i = 0; i < 100; i++)
		tr.push_back(i);  // 向其中推入值

}

#include <string>
// 在计算机领域，字符集合是在字符与整数值之间的一种映射关系。
// C++ 语言允许程序员使用任何字符集作为字符串的字符，也允许程序员使用扩充字符集或可移植的数值编码。
// 从原则上讲，字符串能以任何（带有正确的复制操作）类型作为其字符类型。
// 标准字符串类 string 要求其中的字符不能包含用户自定义复制操作，有助于字符串 I/O 的简化与高效率。

void stringr()
{
	/*
	string strs //生成空字符串
	string s(str) //生成字符串str的复制品
	string s(str, stridx) //将字符串str中始于stridx的部分作为构造函数的初值
	string s(str, strbegin, strlen) //将字符串str中始于strbegin、长度为strlen的部分作为字符串初值
	string s(cstr) //以C_string类型cstr作为字符串s的初值
	string s(cstr, char_len)    //以C_string类型cstr的前char_len个字符串作为字符串s的初值
	string s(num, c) //生成一个字符串，包含num个c字符
	string s(strs, beg, end)    //以strs的[beg, end]区间内的字符作为字符串s的初值

	string s('x');    //错误
	string s(1, 'x');    //正确
	string s("x");    //正确
	*/
	string stuff;  // 定义一个字符串对象
	cin >> stuff;
	getline(cin, stuff);

	// 构造函数
	string str("12345678");
	char ch[] = "abcdefgh";
	string a; //定义一个空字符串
	string str_1(str); //构造函数，全部复制
	string str_2(str, 2, 5); //构造函数，从字符串str的第2个元素开始，复制5个元素，赋值给str_2
	string str_3(ch, 5); //将字符串ch的前5个元素赋值给str_3
	string str_4(5, 'X'); //将 5 个 'X' 组成的字符串 "XXXXX" 赋值给 str_4
	string str_5(str.begin(), str.end()); //复制字符串 str 的所有元素，并赋值给 str_5
	cout << str << endl;
	cout << a << endl;
	cout << str_1 << endl;
	cout << str_2 << endl;
	cout << str_3 << endl;
	cout << str_4 << endl;
	cout << str_5 << endl;

	// 字符串长度
	int size = 0;
	int length = 0;
	unsigned long maxsize = 0; // 无符号长整型
	int capacity = 0;
	string str("12345678"); 
	string str_custom;
	str_custom = str;  // 字符串赋值
	// str_custom.resize(5);
	str_custom.reserve(5); // 重新分配内存。重新分配的大小由其参数决定。reserve() 的默认参数为 0。
	size = str_custom.size(); 
	length = str_custom.length(); // size() 和 length() 会返回 string 类型对象中的字符个数，且它们的执行效果相同。
	maxsize = str_custom.max_size(); // 返回 string 类型对象最多可包含的字符数。一旦程序使用长度超过 max_size() 的 string 操作，编译器会拋出 length_error 异常。
	capacity = str_custom.capacity(); // 返回在重新分配内存之前，string 类型对象所能包含的最大字符数。
	cout << "size = " << size << endl;
	cout << "length = " << length << endl;
	cout << "maxsize = " << maxsize << endl;
	cout << "capacity = " << capacity << endl;
	
	// 字符串访问
	/* 
	字符串中元素的访问是允许的，一般可使用两种方法访问字符串中的单一字符：下标操作符[] 和 成员函数at()。这两种访问方法是有区别的：
	下标操作符[] 在使用时不检查索引的有效性，如果下标超出字符的长度范围，会导致未定义行为。
	对于常量字符串，使用下标操作符时，字符串的最后字符（即 '\0'）是有效的。对应 string 类型对象（常量型）最后一个字符的下标是有效的，调用返回字符 '\0'。
	函数 at() 在使用时会检查下标是否有效。如果给定的下标超出字符的长度范围，系统会抛出 out_of_range 异常。
	*/
	// 为修改 string 字符串的内容，下标操作符 [] 和函数 at() 均返回字符的“引用”。但当字符串的内存被重新分配以后，可能会发生执行错误。
	const std::string cS("c.biancheng.net");
	std::string s("abode");
	char temp = 0;
	char temp_1 = 0;
	char temp_2 = 0;
	char temp_3 = 0;
	char temp_4 = 0;
	char temp_5 = 0;
	temp = s[2]; // 获取字符 'c'
	temp_1 = s.at(2); // 获取字符 'c'
	temp_2 = s[s.length()]; // 未定义行为，返回字符'\0'，但Visual C++ 2012执行时未报错
	temp_3 = cS[cS.length()]; // 指向字符 '\0'。常量字符串大小是固定的，最后一个字符就是'\0'。
	temp_4 = s.at(s.length()); // 程序异常
	temp_5 = cS.at(cS.length()); // 程序异常
	std::cout << temp << temp_1 << temp_2 << temp_3 << temp_4 << temp_5 << std::endl;

	std::string s("abode");
	std::cout << s << std::endl;
	char& r = s[2]; //建立引用关系
	char* p = &s[3]; //建立引用关系
	r = 'X';//修改内容
	*p = 'Y';//修改内容
	std::cout << s << std::endl; //输出
	s = "12345678"; //重新赋值
	r = 'X'; //修改内容
	*p = 'Y'; //修改内容
	std::cout << s << std::endl; //输出

	// 字符串比较
	// 字符串可以和类型相同的字符串相比较，也可以和具有同样字符类型的数组比较。
}

#include <stack>
void stackr()
{
	stack <int> st; //定义堆栈对象
	for (int i = 0; i < 10; i++)
		st.push(i); //将数据压入堆钱
	while (!st.empty())
	{
		cout << st.top() << " "; //弹出堆中的第一个元素，并输出
		st.pop(); //弹出堆栈元素
	}
	cout << endl;
	cin.get();    //任意键退出
}

int main()
{
		
	system("Pause");
	return 0;
}





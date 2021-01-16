// string_dispose.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "public.h"

/*
在进入正题之前，有必要先审视下区域设置的问题，本章中提到的很多函数都需要一个附加的区域设置参数。区域设置在标准 C++ 
中封装了文化习俗相关的内容，包括货币符号，日期时间格式，分隔整数部分与分数部分的符号（基数符）以及多于三个数字时的
分隔符（千位符）。在字符串处理方面，区域设置和特定文化中对字符次序以及特殊字符的描述有关。例如，字母表中是否含有
变异元音字母以及其在字母表中的位置都由语言文化决定。如果一个函数用于将字符串转换为大写形式，那么其实施步骤取决于
具体的区域设置。在德语中，字母 'ä' 显然要转换为 'Ä'，然而在其他语言中并不一定。使用类 std::string 时区域设置可以忽略， 
因为它的函数均不依赖于特定语言。然而在本章中为了使用 Boost C++ 库，区域设置的知识是必不可少的。C++ 标准中在 locale 
文件中定义了类 std::locale。每个 C++ 程序自动拥有一个此类的实例，即不能直接访问的全局区域设置。如果要访问它，
需要使用默认构造函数构造类 std::locale 的对象，并使用与全局区域设置相同的属性初始化。
*/
// 区域设置。
void stl_locale()
{
	std::locale loc;
	std::cout << loc.name() << ":";

	// strcoll 这个函数用于按照字典顺序比较第一个字符串是否小于第二个。
	std::cout << std::strcoll("，", "0") << std::endl;

	/*
	以上程序在标准输出流输出 C，这是基本区域设置的名称，它包括了 C 语言编写的程序中默认使用的描述。
	这也是每个 C++ 应用的默认全局区域设置，它包括了美式文化中使用的描述。例如，货币符号使用美元符号，基字符为英文句号，
	日期中的月份用英语书写。全局区域设置可以使用类 std::locale 中的静态函数 global() 改变。
	*/
	
	// 改变区域设置。
	std::locale::global(std::locale("chinese"));
	std::locale locChange;
	
	std::cout << locChange.name() << ":";
	std::cout << std::strcoll("，", "0") << std::endl;

	/*
	执行程序，得到结果为 1 和 -1 。 虽然函数的参数是一样的，却得到了不同的结果。原因很简单，在第一次调用函数 
	std::strcoll() 时，使用了全局 C 区域设置；而在第二次调用时，全局区域设置更改为中国文化。从输出中可以看出，
	在这两种区域设置中，字符 '，' 和 '0' 的次序是不同的。很多 C 函数以及 C++ 流都与区域设置有关。 尽管类 std::string 
	中的函数是与区域设置独立工作的，但是以下各节中提到的函数并不是这样。所以，在本章中还会多次提到区域设置的相关内容。
	*/
}


/*
Boost C++ 字符串算法库 Boost.StringAlgorithms 提供了很多字符串操作函数。字符串的类型可以是 std::string， 
std::wstring 或任何其他模板类 std::basic_string 的实例。
Boost.StringAlgorithms 库中许多函数都可以接受一个类型为 std::locale 的对象作为附加参数。而此参数是可选的，
如果不设置将使用默认全局区域设置。
*/
// 
void boost_algorithm()
{
	// std::setlocale(LC_ALL, "chinese"); // 自定义全局区域
	std::string s = "shang hai ni hao";
	
	// 如果作为参数传入的字符串自身需要被转换为大（小）写形式，可以使用函数 boost::algorithm::to_upper() 
	// 或 boost::algorithm::to_lower ()。
	std::cout << "original: " << s << std::endl;
	std::cout << "to upper: " << boost::algorithm::to_upper_copy(s) << std::endl; // 用于得到一个字符串的大写形式，
	boost::algorithm::to_upper(s);  // 在原字符串上将其转换为大写
	std::cout << "to lower: " << boost::algorithm::to_lower_copy(s) << std::endl; // 用于得到一个字符串的小写形式，
	boost::algorithm::to_lower(s);
															  
	// boost::algorithm::to_upper_copy(s, std::locale("chinese")) 设置区域。

	// boost::algorithm::erase_all_copy() 从整个字符串中删除特定的某个字符。如果只在此字符首次出现时删除，
	// 可以使用函数 boost::algorithm::erase_first_copy()。如果要在字符串头部或尾部删除若干字符，可以使用函数 
	// boost::algorithm::erase_head_copy() 和 boost::algorithm::erase_tail_copy() 。
	std::cout << "del first 'h': " << boost::algorithm::erase_first_copy(s, "h") << std::endl;
	std::cout << "del nth 'h'-1: " << boost::algorithm::erase_nth_copy(s, "h", 1) << std::endl; // 删除出现的第2个h。 
	std::cout << "del tail 'h' : " << boost::algorithm::erase_last_copy(s, "h") << std::endl;
	std::cout << "del all 'h'  : " << boost::algorithm::erase_all_copy(s, "h") << std::endl;
	std::cout << "del head 5   : " << boost::algorithm::erase_head_copy(s, 5) << std::endl;
	std::cout << "del tail 3   : " <<boost::algorithm::erase_tail_copy(s, 3) << std::endl;

	/*
	以下各个不同函数 boost::algorithm::find_first()、boost::algorithm::find_last()、boost::algorithm::find_nth()、 
	boost::algorithm::find_head() 以及 boost::algorithm::find_tail() 可以用于在字符串中查找子串。
	所有这些函数的共同点是均返回类型为 boost::iterator_range 类的一对迭代器。此类起源于 Boost C++ 的 Boost.Range 库， 
	它在迭代器的概念上定义了“范围”。因为操作符 << 由 boost::iterator_range 类重载而来，单个搜索算法的结果可以直接
	写入标准输出流。
	*/
	std::cout << "find \"hai ni\":" << boost::algorithm::find_first(s, "hai ni") << std::endl;
	std::cout << "find \"xyz\"   :" << boost::algorithm::find_first(s, "xyz") << std::endl;

	// 函数 boost::algorithm::join() 接受一个字符串的容器作为第一个参数，根据第二个参数将这些字符串连接起来。
	std::string s1 = "a!";
	std::vector<std::string>  v;
	v.push_back(s);
	v.push_back(s1);
	std::cout << "join vessel 'v' unit:" << boost::algorithm::join(v, " ") << std::endl;

	/*
	Boost.StringAlgorithms 库不但提供了查找子串或删除字母的函数，而且提供了使用字符串替代子串的函数，包括 
	boost::algorithm::replace_first_copy()，boost::algorithm::replace_nth_copy()，boost::algorithm::replace_last_copy()，
	boost::algorithm::replace_all_copy()，boost::algorithm::replace_head_copy() 以及 boost::algorithm::replace_tail_copy() 等等。
	*/
	std::cout << "replace first h as 0: " << boost::algorithm::replace_first_copy(s, "h", "0") << std::endl;
	std::cout << "replace two   h as 0: " << boost::algorithm::replace_nth_copy(s, "h", 1, "0") << std::endl;
	std::cout << "replace last  h as 0: " << boost::algorithm::replace_last_copy(s, "h", "0") << std::endl;
	std::cout << "replace all   h as 0: " << boost::algorithm::replace_all_copy(s, "h", "0") << std::endl;
	std::cout << "replace head 5 as '': " << boost::algorithm::replace_head_copy(s, 5, "zhang") << std::endl;
	std::cout << "replace tail 3 as '': " << boost::algorithm::replace_tail_copy(s, 3, "jun") << std::endl;

	/*
	在给定分界符后，使用函数 boost::algorithm::split() 可以将一个字符串拆分为一个字符串容器。它需要给定一个谓词作为
	第三个参数以判断应该在字符串的哪个位置分割。这个例子使用了辅助函数 boost::algorithm::is_space() 创建一个谓词，
	在每个空格字符处分割字符串。
	
	函数 boost::algorithm::is_digit() 返回的谓词在字符为数字时返回布尔值 true。检查字符是否为大写或小写的辅助函数分别是 
	boost::algorithm::is_upper() 和 boost::algorithm::is_lower()。所有这些函数都默认使用全局区域设置，除非在参数中
	指定其他区域设置。
	*/
	v.clear();
	boost::algorithm::split(v, s, boost::algorithm::is_space());
	std::cout << "split number: " << v.size() << std::endl;
	
	// 字符串比较
	std::cout << "$s$ with \"shang\" compare starts: " << boost::algorithm::starts_with(s, "shang") << std::endl;
	std::cout << "$s$ with \"hao\" compare ends    : " << boost::algorithm::ends_with(s, "hao") << std::endl;
	std::cout << "$s$ with \"hai\" compare contains: "  << boost::algorithm::contains(s, "hai") << std::endl;
	std::cout << "-------------------------------: " << boost::algorithm::lexicographical_compare(s, "") << std::endl;

}


/*
Boost.Regex 库中两个最重要的类是 boost::regex 和 boost::smatch，它们都在 boost/regex.hpp 文件中定义。 
前者用于定义一个正则表达式，而后者可以保存搜索结果。
*/ 
void boost_regex()
{
	/*
	函数 boost::regex_match() 用于字符串与正则表达式的比较。在整个字符串匹配正则表达式时其返回值为 true 。
	函数 boost::regex_search() 可用于在字符串中搜索正则表达式。
	*/
	std::string s = "shang hai ni hao a!";
	boost::regex expr("(\\w+)\\s(\\w+)");  // 定义正则表达式。
	std::cout << boost::regex_match(s, expr) << std::endl; // 当字符串完全与正则表达式匹配时返回 true。
	
	/*
	函数 boost::regex_search() 可以接受一个类型为 boost::smatch 的引用的参数用于储存结果。函数 boost::regex_search() 
	只用于分类的搜索，本例实际上返回了两个结果，它们是基于正则表达式的分组。
	存储结果的类 boost::smatch 事实上是持有类型为 boost::sub_match 的元素的容器，可以通过与类 std::vector 相似的界面访问。 
	例如， 元素可以通过操作符 operator[]() 访问。
	另一方面，类 boost::sub_match 将迭代器保存在对应于正则表达式分组的位置。因为它继承自类 std::pair，
	迭代器引用的子串可以使用 first 和 second 访问。如果像上面的例子那样，只把子串写入标准输出流，那么通过重载操作符 << 
	就可以直接做到这一点，那么并不需要访问迭代器。
	请注意结果保存在迭代器中而 boost::sub_match 类并不复制它们，这说明它们只是在被迭代器引用的相关字符串存在时才可以访问。
	另外，还需要注意容器 boost::smatch 的第一个元素存储的引用是指向匹配正则表达式的整个字符串的，匹配第一组的第一个子串
	由索引 1 访问。
	*/
	boost::smatch what;
	if (boost::regex_search(s, what, expr))
	{
		std::cout << what[0] << "+++" << what[1] << "---" << what[2] << std::endl; // ？？？匹配的其他字串呢？
	}

	/*
	除了待搜索的字符串和正则表达式之外，boost::regex_replace() 函数还需要一个格式参数，它决定了子串、
	匹配正则表达式的分组如何被替换。如果正则表达式不包含任何分组，相关子串将被用给定的格式一个个地被替换。
	*/
	expr = boost::regex("\\s");
	std::string fmt("_");
	std::cout << boost::regex_replace(s, expr, fmt) << std::endl; // 匹配位置替换


	// 此程序将 boost::regex_constants::format_literal 标志作为第四参数传递给函数 boost::regex_replace()，
	// 从而抑制了格式参数中对特殊字符的处理
	expr = "(\\w+)\\s(\\w+)";
	fmt = "\\2 \\1";
	std::cout << boost::regex_replace(s, expr, fmt) << std::endl;
	std::cout << boost::regex_replace(s, expr, fmt, boost::regex_constants::format_literal) << std::endl;

}


/*
Boost.Tokenizer 库可以在指定某个字符为分隔符后，遍历字符串的部分表达式。

Boost.Tokenizer 库在 boost/tokenizer.hpp 文件中定义了模板类 boost::tokenizer ，其模板参数为支持相关表达式的类。 
上面的例子中就使用了 boost::char_separator 类作为模板参数，它将空格和标点符号视为分隔符。

词汇分割器必须由类型为 std::string 的字符串初始化。通过使用 begin() 和 end() 方法，词汇分割器可以像容器一样访问。
通过使用迭代器，可以得到前述字符串的部分表达式。模板参数的类型决定了如何达到部分表达式。

因为 boost::char_separator 类默认将空格和标点符号视为分隔符，所以本例显示的结果为 Boost 、 C 、 + 、 + 和 libraries 。 
为了识别这些分隔符， boost::char_separator 函数调用了 std::isspace() 函数和 std::ispunct 函数。 ()Boost.Tokenizer 
库会区分要隐藏的分隔符和要显示的分隔符。 在默认的情况下，空格会隐藏而标点符号会显示出来，所以这个例子里显示了两个加号。
*/
void boost_tokenizer()
{
	
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	std::string s = "Boost C++ libraries";
	tokenizer tok(s);
	for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;

	// 如果不需要将标点符号作为分隔符，可以在传递给词汇分割器之前相应地初始化 boost::char_separator 对象。
	// 类 boost::char_separator 的构造函数可以接受三个参数，只有第一个是必须的，它描述了需要隐藏的分隔符。 
	// 在本例中，空格仍然被视为分隔符。
	boost::char_separator<char> sep(" "); // 第一个参数作为隐藏的分隔符集合
	tok = tokenizer(s, sep);
	for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;

	// 第二个参数指定了需要显示的分隔符。在不提供此参数的情况下，将不显示任何分隔符。
	sep = boost::char_separator<char>("+", " "); // 第二个参数是需要显示的分隔符集合。 
	tok = tokenizer(s, sep);
	for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;

	// 第三个参数决定了是否显示空的部分表达式。如果连续找到两个分隔符，他们之间的部分表达式将为空。在默认情况下，
	// 这些空表达式是不会显示的。第三个参数可以改变默认的行为。
	sep = boost::char_separator<char>(" ", "+", boost::keep_empty_tokens); // 
	tok = tokenizer(s, sep);
	for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;
	// 执行以上程序，会显示另外两个的空表达式。其中第一个是在两个加号中间的而第二个是加号和之后的空格之间的。

	// 词汇分割器也可用于不同的字符串类型。
	// 这个例子遍历了一个类型为 std::wstring 的字符串。为了使用这个类型的字符串，必须使用另外的模板参数初始化词汇分割器，
	// 对 boost::char_separator 类也是如此，他们都需要参数 wchar_t 初始化。
	typedef boost::tokenizer<boost::char_separator<wchar_t>, std::wstring::const_iterator, std::wstring> tokenizerW;
	std::wstring sW = L"Boost C++ libraries";
	boost::char_separator<wchar_t> sepW(L" ");
	tokenizerW tokW(sW, sepW);
	for (tokenizerW::iterator it = tokW.begin(); it != tokW.end(); ++it)
		std::wcout << *it << ":";
	std::cout << std::endl;

	// 除了 boost::char_separator 类之外， Boost.Tokenizer 还提供了另外两个类以识别部分表达式。
	// boost::escaped_list_separator 类用于读取由逗号分隔的多个值，这个格式的文件通常称为 CSV（comma separated values，逗号分隔文件），
	// 它甚至还可以处理双引号以及转义序列。所以本例的输出为 Boost 和 C++ libraries 。
	typedef boost::tokenizer<boost::escaped_list_separator<char> > tokenizerELS;  // ELS
	s = std::string("Boost,\"C++ libraries\"");
	tokenizerELS tokELS(s);
	for (tokenizerELS::iterator it = tokELS.begin(); it != tokELS.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;

	// 另一个是 boost::offset_separator 类，必须用实例说明。这个类的对象必须作为第二个参数传递给 boost::tokenizer 
	// 类的构造函数。
	// boost::offset_separator 指定了部分表达式应当在字符串中的哪个位置结束。以下程序制定第一个部分表达式在 5 
	// 个字符后结束，第二个字符串在另 5 个字符后结束，第三个也就是最后一个字符串应当在之后的 9 个字符后结束。 
	// 输出的结果为 Boost 、  C++  和 libraries 。
	typedef boost::tokenizer<boost::offset_separator> tokenizerOS;
	s = std::string("Boost C++ libraries");
	int offsets[] = { 5, 5, 9 }; // 分割后的字符串的大小。
	boost::offset_separator sepOS(offsets, offsets + 3);
	tokenizerOS tokOS(s, sepOS);
	for (tokenizerOS::iterator it = tokOS.begin(); it != tokOS.end(); ++it)
		std::cout << *it << ":";
	std::cout << std::endl;
}


/*
Boost.Format 库可以作为定义在文件 cstdio 中的函数 std::printf() 的替代。std::printf() 函数最初出现在 C 标准中，
提供格式化数据输出功能，但是它既不是类型安全的又不能扩展。因此在 C++ 应用中，Boost.Format 库通常是数据格式化
输出的上佳之选。
Boost.Format 库在文件 boost/format.hpp 中定义了类 boost::format。与函数 std::printf 相似的是，传递给() boost::format 
的构造函数的参数也是一个字符串，它由控制格式的特殊字符组成。实际数据通过操作符 % 相连，在输出中替代特殊字符。
*/
void boost_format()
{
	std::cout << boost::format("%1%.%2%.%3%") % 16 % 9 % 2008 << std::endl;
	// Boost.Format 类使用置于两个百分号之间的数字作为占位符，占位符稍后通过 % 操作符与实际数据连接。 
	// 以上程序使用数字16、9 和 2009 组成一个日期字符串，以 16.9.2008的格式输出。如果要月份出现在日期之前，
	// 即美式表示，只需交换占位符即可。
	std::cout << boost::format("%2%/%1%/%3%") % 16 % 9 % 2008 << std::endl;

	// 如果要使用C++ 操作器格式化数据，Boost.Format 库提供了函数 boost::io::group() 。
	std::cout << boost::format("%1% %2% %1%") % boost::io::group(std::showpos, 99) % 100 << std::endl;
	
	// 本例的结果显示为 +99 100 +99。因为操作器 std::showpos() 通过 boost::io::group() 与数字 99 连接，所以只要显示 99， 
	// 在它前面就会自动加上加号。如果需要加号仅在 99 第一次输出时显示，则需要改造格式化占位符。
	std::cout << boost::format("%|1$+| %2% %1%") % 99 % 100 << std::endl;
	// 为了将输出格式改为 +99 100 99，不但需要将数据的引用符号由 1$ 变为 1%，
	// 还需要在其两侧各添加一个附加的管道符号，即将占位符 %1% 替换为 %|1$+|。

	// 请注意，虽然一般对数据的引用不是必须的，但是所有占位符一定要同时设置为指定或非指定。 
	// 以下例子在执行时会出现错误，因为它给第二个和第三个占位符设置了引用但是却忽略了第一个。
	try
	{
		std::cout << boost::format("%|+| %2% %1%") % 99 % 100 << std::endl;
	}
	catch (boost::io::format_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	// 此程序抛出了类型为 boost::io::format_error 的异常。严格地说，Boost.Format 库抛出的异常为 
	// boost::io::bad_format_string。但是由于所有的异常类都继承自 boost::io::format_error 类，捕捉此类型的异常会轻松一些。
	
	// 以下例子演示了不引用数据的方法。
	std::cout << boost::format("%|+| %|| %||") % 99 % 100 % 99 << std::endl;

	// 第二、第三个占位符的管道符号可以被安全地省略，因为在这种情况下，他们并不指定格式。这样的语法看起来很像 
	// std::printf ()的那种。
	std::cout << boost::format("%+d %d %d") % 99 % 100 % 99 << std::endl;
	// 虽然这看起来就像 std::printf() ，但是 Boost.Format 库有类型安全的优点。 格式化字符串中字母 'd' 的使用
	// 并不表示输出数字，而是表示 boost::format 类所使用的内部流对象上的 std::dec() 操作器，它可以使用某些对 
	// std::printf() 函数无意义的格式字符串，如果使用 std::printf() 会导致程序在运行时崩溃。
	std::cout << boost::format("%+s %s %s") % 99 % 100 % 99 << std::endl;
	// 尽管在 std::printf() 函数中，字母 's' 只用于表示类型为 const char* 的字符串，然而以上程序却能正常运行。 
	// 因为在 Boost.Format 库中，这并不代表强制为字符串，它会结合适当的操作器，调整内部流的操作模式。
	// 所以即使在这种情况下， 在内部流中加入数字也是没问题的。

}
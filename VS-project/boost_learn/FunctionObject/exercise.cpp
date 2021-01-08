#include "public.h"

#include <algorithm> 
#include <functional> 
#include <vector> 
#include <iostream> 

// 简化以下程序，将函数对象 divide_by 转换为一个函数，并将 for 循环替换为用一个标准的 C++ 算法来输出数据：
class divide_by : public std::binary_function<int, int, int>
{
public:
    int operator()(int n, int div) const
    {
        return n / div;
    }
};
void exercise()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), std::bind2nd(divide_by(), 2));

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << ":";
    
    std::cout << std::endl;
}

int optimize_divide_by(int n, int div)
{
    return n / div;
}
void optimizeExercise()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 如何直接使用带返回值的匿名函数。
    boost::function<int(int)> fun = (boost::lambda::_1 / 2);
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), fun);

    // 改元
    // std::transform(numbers.begin(), numbers.end(), numbers.begin(), boost::bind(optimize_divide_by, _1, 2));

    // 匿名函数实现
    std::for_each(numbers.begin(), numbers.end(), std::cout << boost::lambda::_1 << ":");
    // for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    //    std::cout << *it << ":";

    std::cout << std::endl << std::endl;
}

// 简化以下程序，将两个 for 循环都替换为标准的 C++ 算法：
void exercise1()
{
    std::vector<std::string> strings;
    strings.push_back("Boost");
    strings.push_back("C++");
    strings.push_back("Libraries");

    std::vector<int> sizes;

    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
        sizes.push_back(it->size());

    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); ++it)
        std::cout << *it << ":";

    std::cout << std::endl;
}

void optimize_string_size(std::string& c, std::vector<int>& v)
{
    v.push_back(c.size());
}
void optimizeExercise1()
{
    std::vector<std::string> strings;
    strings.push_back("Boost");
    strings.push_back("C++");
    strings.push_back("Libraries");

    std::vector<int> sizes;

    // 这里甚是麻烦
    // 这里 for_each 传入函数的只能是一个拷贝对象或者是引用并不能对 _1 做什么操作。
    // 如果使用匿名函数就不能直接使用参数对象的方法，暂无解决办法。
    std::for_each(strings.begin(), strings.end(), boost::bind(optimize_string_size, _1, boost::ref(sizes)));
    std::for_each(sizes.begin(), sizes.end(), std::cout << boost::lambda::_1 << ":");

    std::cout << std::endl << std::endl;
}

// 简化以下程序，修改变量 processors 的类型，并将 for 循环替换为标准的 C++ 算法：
void exercise2()
{
    std::vector<int(*)(const char*)> processors;
    processors.push_back(std::atoi);
    processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen));

    const char data[] = "1.23";

    for (std::vector<int(*)(const char*)>::iterator it = processors.begin(); it != processors.end(); ++it)
        std::cout << (*it)(data) << ":";
    
    std::cout << std::endl;
}

void optimize_function_operator(int f(const char*), const char data[])
{
    std::cout << f(data) << ":";
}
void optimizeExercise2()
{
    // 修改变量 processors 的类型 ??
    // 这里还要咋样修改类型呢靠，难不成改成函数指针对象容器 ？？
    std::vector<int(*)(const char*)> processors;
    processors.push_back(std::atoi);
    processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen));

    const char data[] = "1.23";

    std::for_each(processors.begin(), processors.end(), boost::bind(optimize_function_operator, _1, data));

    std::cout << std::endl << std::endl;
}
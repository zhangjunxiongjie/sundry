#include "public.h"

#include <algorithm> 
#include <functional> 
#include <vector> 
#include <iostream> 

// �����³��򣬽��������� divide_by ת��Ϊһ������������ for ѭ���滻Ϊ��һ����׼�� C++ �㷨��������ݣ�
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

    // ���ֱ��ʹ�ô�����ֵ������������
    boost::function<int(int)> fun = (boost::lambda::_1 / 2);
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), fun);

    // ��Ԫ
    // std::transform(numbers.begin(), numbers.end(), numbers.begin(), boost::bind(optimize_divide_by, _1, 2));

    // ��������ʵ��
    std::for_each(numbers.begin(), numbers.end(), std::cout << boost::lambda::_1 << ":");
    // for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    //    std::cout << *it << ":";

    std::cout << std::endl << std::endl;
}

// �����³��򣬽����� for ѭ�����滻Ϊ��׼�� C++ �㷨��
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

    // ���������鷳
    // ���� for_each ���뺯����ֻ����һ������������������ò����ܶ� _1 ��ʲô������
    // ���ʹ�����������Ͳ���ֱ��ʹ�ò�������ķ��������޽���취��
    std::for_each(strings.begin(), strings.end(), boost::bind(optimize_string_size, _1, boost::ref(sizes)));
    std::for_each(sizes.begin(), sizes.end(), std::cout << boost::lambda::_1 << ":");

    std::cout << std::endl << std::endl;
}

// �����³����޸ı��� processors �����ͣ����� for ѭ���滻Ϊ��׼�� C++ �㷨��
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
    // �޸ı��� processors ������ ??
    // ���ﻹҪզ���޸������ؿ����Ѳ��ɸĳɺ���ָ��������� ����
    std::vector<int(*)(const char*)> processors;
    processors.push_back(std::atoi);
    processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen));

    const char data[] = "1.23";

    std::for_each(processors.begin(), processors.end(), boost::bind(optimize_function_operator, _1, data));

    std::cout << std::endl << std::endl;
}
// exercise 

#include "public.h"

// 使用适当的智能指针优化下面的程序：
char* get(const char* s)
{
    int s_len = std::strlen(s) + 1; // '\n' 
    int text_len = s_len;
    char* text = new char[text_len];
    // strncpy(text, s, s_len); // warning unsafe 不安全。
    cout << "leng>" << text_len << ":" << s_len << endl;
    strncpy_s(text, text_len, s, s_len);  // 
    return text;
}
void print(char* text)
{
    std::cout << text << std::endl;
}
int exercise(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << argv[0] << " <data>" << std::endl;
        return 1;
    }

    char* text = get(argv[1]);
    print(text);
    delete[] text;

    cout << endl;
    return 0;
}
int optimizeExercise(int argc, char* argv[]) // 优化
{
    if (argc < 2)
    {
        std::cerr << argv[0] << " <data>" << std::endl;
        return 1;
    }
    
    int text_len = std::strlen(argv[1]) + 1;
    cout << "leng>" << text_len << endl;

    boost::scoped_array<char> text(new char[text_len]);
    strncpy_s(text.get(), text_len, argv[1], text_len);
    cout << text.get() << endl;
    
    cout << endl;
    return 0;
}

// 优化下面的程序：
template <typename T>
T* create()
{
    return new T;
}
int exercise1()
{
    std::vector<int*> v;
    v.push_back(create<int>());

    return 0;
}
int optimizeExercise1()
{
    boost::ptr_vector<int> v;
    v.push_back(create<int>());
    
    return 0;
}
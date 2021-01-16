/*
when: 2020-06-03
where: 四川省巴中市平昌县
solution explain: 学习使用 boost 库
*/
// project explain: 事件处理（信号槽机制）。
// file explain:

#include "public.h"

int main()
{
    // boost_signal(); // 信号槽简单示例
    
    // function_signal(); // 使用function模块实现信号槽

    // boost_signal_more_connect(); // 关联多个函数至单个特定信号

    // boost_signal_more_connect_customize();  // 可自定义执行顺序的多函数关联

    // boost_signal_more_connect_disconnect(); // 关联函数的释放

    // boost_signal_connect_slots(); // 一些信号槽的基本方法

    // boost_signal_return();  // 函数的返回值

    // boost_signal_return_customize_use();  // 自定义的函数返回值。

    // boost_signal_return_customize_save(); // 函数返回值的保存。

    // boost_signal_connection(); // 使用 connection 管理信号槽

    // boost_connection_bind(); // ???

    // exercise 未实现
    Button b(signal_func1, signal_func2);
    b.click();

    system("pause");
    return 0;
}
/*
when: 2020-06-02
where: 四川省巴中市平昌县
solution explain: 学习使用 boost 库
*/
// project explain: 函数对象。
// file explain:

#include "public.h"

int main()
{

	// stl_print(); // 使用 STL 算法实现数组元素打印

	// stl_bind1st(); // 使用 STL 算法实现数组元素增加一个值再打印

	// boost_bind(); // 使用 boost 实现数组元素增加一个值再打印。

	// boost_sort(); // 自定义排序规则进行排序。

	// boost_ref_for_each(); // 带引用参数的函数改元。

	// boost_function_ptr(); // 函数指针的封装

	// boost_bad_function_call(); // 异常捕获

	// 无法实现。
	// void boost_member_function_ptr(); // 函数指针对象管理成员函数。

	// boost_lambda_print(); // 用 boost 的匿名函数实现数组元素打印。

	// boost_lambda_if(); // 匿名函数实现条件语句

	// 练习
	// exercise();
	// optimizeExercise();

	// exercise1();
	// optimizeExercise1();

	exercise2();
	optimizeExercise2();

	system("pause");
	return 0;
}

// public header

#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm> 

#include <boost/bind.hpp>

void stl_print(int i);
void stl_for_each();


#include <functional> 
// class stl_add;
void stl_bind1st();


void boost_add(int i, int j);
void boost_bind();


bool boost_compare(int i, int j);   // 定义排序规则，用于排序算法。
void boost_sort();


void boost_ref_add(int i, int j, std::ostream& os);
void boost_ref_for_each();


#include <boost/function.hpp>
#include <cstdlib> 
#include <cstring> 
void boost_function_ptr();


void boost_bad_function_call();


// class World;
void boost_member_function_ptr();

#include <boost/lambda/lambda.hpp> 
void boost_lambda_print();
 
#include <boost/lambda/if.hpp>
void boost_lambda_if();

// 练习
void exercise();
void optimizeExercise();

void exercise1();
void optimizeExercise1();

void exercise2();
void optimizeExercise2();

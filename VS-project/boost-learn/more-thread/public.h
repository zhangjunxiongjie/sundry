#include <iostream>
#include <boost/thread.hpp>

void wait(int seconds);

void thread();
void boost_thread();

void thread_interrupt();
void boost_thread_interrupt();

void thread_synchronization();
void thread_lock_guard();
void boost_thread_synchronization();

void thread_unique_lock();
void boost_thraed_unique_lock();

#include <vector>
#include <cstdlib>
#include <ctime>
void thread_shared_lock_fill();
void thread_shared_lock_print();
void thread_shared_lock_count();
void boost_thread_shared_lock();

void thread_condition_variable_fill();
void thread_condition_variable_print();
void boost_thread_condition_variable();

void thread_private_data_init_number_generator();
void thread_private_data_random_number_generator();
void boost_thread_private_data();

void thread_TLS_init_number_generator();
void thread_TLS_random_number_generator();
void boost_thread_TLS();

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/cstdint.hpp>
void exercise();

void exercise1();

void exercise2_calculate();
void exercise2_print();
void exercise2_thread();
void exercise2();

// test
void test_thread();
void test_boost_thread();

# include <limits>
# include <cmath>
# include <cassert>
bool test_boost_thread_a11c(void);

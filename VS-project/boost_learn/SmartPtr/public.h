// 练习题，程序优化。

#include <vector> 
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> 
char* get(const char* s);
void print(char* text);
int exercise(int argc, char* argv[]);

#include <boost/scoped_array.hpp>
int optimizeExercise(int argc, char* argv[]);

int exercise1();

#include <boost/ptr_container/ptr_vector.hpp>	
int optimizeExercise1();

#include <boost/scoped_ptr.hpp>
void scoped_ptr();

#include <boost/scoped_array.hpp>
void scoped_array();

#include <boost/shared_ptr.hpp>	
void shared_ptr();

#include <boost/shared_array.hpp>	
void shared_array();

#include <boost/weak_ptr.hpp>	
#include <windows.h>	
DWORD WINAPI reset(LPVOID p);
DWORD WINAPI print(LPVOID p);
void weak_ptr();


#include <boost/intrusive_ptr.hpp>	
#include <atlbase.h>	
void intrusive_ptr_add_ref(IDispatch* p);
void intrusive_ptr_release(IDispatch* p);
void check_windows_folder();
void intrusive_ptr();


#include <boost/ptr_container/ptr_vector.hpp>	
void smart_ptr_vessel();
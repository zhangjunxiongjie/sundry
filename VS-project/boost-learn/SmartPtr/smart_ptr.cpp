// example

#include "public.h"

void scoped_ptr() 
{
	
	// *ptr == *(i.get())
	// ptr.get() 返回指针；
	// boost::scoped_ptr<type> 对象只能存放基本类型指针；
	// 作用域指针的析构函数使用	delete 操作符来释放所包含的对象；

	boost::scoped_ptr<int>	ptr(new	int); // 作用域指针
	cout << "pointer>" << ptr.get() << endl;

	*ptr = 1;
	cout << "value>" << *ptr << endl;
	*ptr.get() = 2;
	cout << "value>" << *ptr.get() << endl;

	ptr.reset(new	int); // 重置指针对象 
	cout << "pointer>" << ptr.get() << endl;

	cout << endl;

}



void scoped_array() 
{

	// 作用域数组的析构函数使用	delete[] 操作符来释放所包含的对象。	
	// 因为该操作符只能用于数组对象，所以作用域数组必须通过动态分配的数组来初始化。 
	
	boost::scoped_array<int> array(new int[3]);
	cout << "pointer>" << array.get() << endl;

	*array.get() = 0;
	array.get()[1] = 1;
	array[2] = 2; // 超出范围不检查。出错。
	cout << "value>" << *array.get() << ":" << array.get()[1] << ":" << array[2] << endl;

	array.reset(new	int[3]);
	cout << "pointer>" << array.get() << endl;

	cout << endl;

}



void	shared_ptr() 
{
	// 共享指针，可以使用容器存储容器存储一个引用。
	// boost::shared_ptr 不一定要独占一个对象，它可以和其他	boost::shared_ptr 类型的智能指针共享所有权。	
	// 在这种情况下，当引用对象的最后一个智能指针销毁后，对象才会被释放。 
	// 因为所有权可以在	boost::shared_ptr 之间共享，任何一个共享指针都可以被复制，这跟 boost::scoped_ptr 是不同的。	
	// 这样就可以在标准容器里存储智能指针了,你不能在标准容器中存储 std::auto_ptr，因为它们在拷贝的时候传递了所有权。
	// 默认情况下,boost::shared_ptr 使用 delete 操作符来销毁所含的对象。	
	// 然而，具体通过什么方法 来销毁，是可以指定的

	std::vector<boost::shared_ptr<int>>	heap;

	boost::shared_ptr<int> ptr(new	int(1));
	boost::shared_ptr<int>	ptr1(ptr);		// 拷贝构造，创建一个引用		
	heap.push_back(boost::shared_ptr<int>(ptr));
	heap.push_back(boost::shared_ptr<int>(ptr1));
	cout << "pointer>" << ptr.get() << ":" << ptr1.get() << endl;
	cout << "pointer>" << heap.at(0).get() << ":" << heap.at(1).get() << endl;

	cout << "value>" << *ptr.get() << ":" << *ptr1.get() << ":" << *heap.at(0) << ":" << *heap.at(1) << endl;

	*ptr.get() = 2;
	cout << "value>" << *ptr.get() << ":" << *ptr1.get() << ":" << *heap.at(0) << ":" << *heap.at(1) << endl;

	ptr.reset(new int(2));
	cout << "pointer>" << ptr.get() << ":" << ptr1.get() << endl;
	
	cout << endl;
}



void shared_array() 
{
	// 共享数组的行为类似于共享指针。	
	// 关键不同在于共享数组在析构时,默认使用 delete[] 操作符来释放所含的对象。	
	// 因为这个操作符只能用于数组对象,共享数组必须通过动态分配的数组的地址来初始化。 
	
	boost::shared_array<int> array(new int[2]);	
	boost::shared_array<int> array1(array);
	cout << "pointer>" << array.get() << ":" << array1.get() << endl;
			
	array[0] = 1, array[1] = 2;
	std::cout << "value>" << array[0] << ":" << array[1] << std::endl;
	std::cout << "value>" << array1[0] << ":" << array1[1] << std::endl;

	array[0] = 3, array[1] = 4;
	std::cout << "value>" << array[0] << ":" << array[1] << std::endl;
	std::cout << "value>" << array1[0] << ":" << array1[1] << std::endl;
	
	array1.reset(new int[2]);
	std::cout << "pointer>" << array.get() << ":" << array1.get() << endl;

	cout << endl;
}



DWORD WINAPI reset(LPVOID p) 
{
	boost::shared_ptr<int>* sh = static_cast<boost::shared_ptr<int>*>(p);
	
	// Sleep(1000); // 睡眠
	// *sh->get() = 100;	
	
	sh->reset();

	return 0;
}
DWORD WINAPI print(LPVOID p) 
{ 
	// Sleep(1000); // 睡眠
	boost::weak_ptr<int>* w = static_cast<boost::weak_ptr<int>*>(p);			
	
	// Sleep(1000); // 睡眠
	// 如果共享指针在reset线程中被释放那么lock函数就返回nullptr，否则就可以获得共享指针对象那么共享指针对象就有多个引用。
	boost::shared_ptr<int>	sh = w->lock();	 		
	
	
	if (sh) // 当先执行到 sh = w->lock() 时，输出99。当先执行*sh->get() = 100在执行sh = w->lock()时输出100。
		cout << *sh << std::endl;	
	else // 当reset执行完后在执行sh = w->lock()时输出nullptr。
	{
		cout << "nullptr" << endl;
	}

	return	0; 
}
void weak_ptr()
{ 
	// 基于共享指针的弱指针。？？？不太能理解它的作用。
	// 弱指针保证了多线程通过指针公用共享指针时，共享指针使用的安全性。
	// 弱指针本身对于对象的生存期没有任何影响。lock()返回一个共享指针，print()函数就可以安全的访问对象了。	
	// 这就保证了——即使另一个线程要释放对象——由于我们有返回的共享指针，对象依然存在。

	boost::shared_ptr<int>	sh(new int(99));			
	boost::weak_ptr<int> w(sh);			
	
	HANDLE	threads[2];			
	
	threads[0] = CreateThread(0, 0, reset, &sh, 0, 0);			
	threads[1] = CreateThread(0, 0, print, &w, 0, 0);	

	WaitForMultipleObjects(2, threads, TRUE, INFINITE); 

	cout << endl;
}



void intrusive_ptr_add_ref(IDispatch* p) 
{ 
	p->AddRef(); // 引用次数增加 
}
void intrusive_ptr_release(IDispatch* p) 
{ 
	p->Release(); // 引用次数减少
}
void check_windows_folder() 
{ 
	CLSID clsid;			
	CLSIDFromProgID(CComBSTR("Scripting.FileSystemObject"), &clsid);			
	void* p;			
	CoCreateInstance(clsid, 0, CLSCTX_INPROC_SERVER, __uuidof(IDispatch), &p);			
	
	boost::intrusive_ptr<IDispatch>	disp(static_cast<IDispatch*>(p));			
	
	CComDispatchDriver	dd(disp.get());			
	
	CComVariant	arg("C:\\Windows");			
	CComVariant	ret(false);			
	
	dd.Invoke1(CComBSTR("FolderExists"), &arg, &ret);			
	
	cout << (ret.boolVal != 0) << std::endl; 
}
void intrusive_ptr() 
{ 
	// 介入式指针的工作方式和共享指针完全一样。	
	// boost::shared_ptr 在内部记录着引用到某个对象的共享指针的数量，可是对介入式指针来说，程序员就得自己来做记录。	
	// 对于框架对象来说这就特别有用，因为它们记录着自身被引用的次数。
	// 使用了 windows api 一脸懵逼。？？？

	CoInitialize(0);

	check_windows_folder();			
	
	CoUninitialize(); 

	cout << endl;
}



void smart_ptr_vessel()  
{ 
	// 智能指针容器可以自己释放数组元素指针的空间
	// Boost C++库提供了指针容器,专门用来管理一堆动态分配的对象。
	// 专门用于管理动态分配对象的容器还包括：boost::ptr_deque，boost::ptr_list，boost::ptr_set，boost::ptr_map，
	// boost::ptr_unordered_set 和 boost::ptr_unordered_map。 它们类似于 STL 中的容器。
	boost::ptr_vector<int> v;			
	v.push_back(new	int(1));			
	v.push_back(new	int(2));
	cout << "pointer>" << &v[0] << ":" << &v[1] << endl;

	cout << endl;
}


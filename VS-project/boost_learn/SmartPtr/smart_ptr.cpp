// example

#include "public.h"

void scoped_ptr() 
{
	
	// *ptr == *(i.get())
	// ptr.get() ����ָ�룻
	// boost::scoped_ptr<type> ����ֻ�ܴ�Ż�������ָ�룻
	// ������ָ�����������ʹ��	delete ���������ͷ��������Ķ���

	boost::scoped_ptr<int>	ptr(new	int); // ������ָ��
	cout << "pointer>" << ptr.get() << endl;

	*ptr = 1;
	cout << "value>" << *ptr << endl;
	*ptr.get() = 2;
	cout << "value>" << *ptr.get() << endl;

	ptr.reset(new	int); // ����ָ����� 
	cout << "pointer>" << ptr.get() << endl;

	cout << endl;

}



void scoped_array() 
{

	// �������������������ʹ��	delete[] ���������ͷ��������Ķ���	
	// ��Ϊ�ò�����ֻ������������������������������ͨ����̬�������������ʼ���� 
	
	boost::scoped_array<int> array(new int[3]);
	cout << "pointer>" << array.get() << endl;

	*array.get() = 0;
	array.get()[1] = 1;
	array[2] = 2; // ������Χ����顣����
	cout << "value>" << *array.get() << ":" << array.get()[1] << ":" << array[2] << endl;

	array.reset(new	int[3]);
	cout << "pointer>" << array.get() << endl;

	cout << endl;

}



void	shared_ptr() 
{
	// ����ָ�룬����ʹ�������洢�����洢һ�����á�
	// boost::shared_ptr ��һ��Ҫ��ռһ�����������Ժ�����	boost::shared_ptr ���͵�����ָ�빲������Ȩ��	
	// ����������£������ö�������һ������ָ�����ٺ󣬶���Żᱻ�ͷš� 
	// ��Ϊ����Ȩ������	boost::shared_ptr ֮�乲���κ�һ������ָ�붼���Ա����ƣ���� boost::scoped_ptr �ǲ�ͬ�ġ�	
	// �����Ϳ����ڱ�׼������洢����ָ����,�㲻���ڱ�׼�����д洢 std::auto_ptr����Ϊ�����ڿ�����ʱ�򴫵�������Ȩ��
	// Ĭ�������,boost::shared_ptr ʹ�� delete �����������������Ķ���	
	// Ȼ��������ͨ��ʲô���� �����٣��ǿ���ָ����

	std::vector<boost::shared_ptr<int>>	heap;

	boost::shared_ptr<int> ptr(new	int(1));
	boost::shared_ptr<int>	ptr1(ptr);		// �������죬����һ������		
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
	// �����������Ϊ�����ڹ���ָ�롣	
	// �ؼ���ͬ���ڹ�������������ʱ,Ĭ��ʹ�� delete[] ���������ͷ������Ķ���	
	// ��Ϊ���������ֻ�������������,�����������ͨ����̬���������ĵ�ַ����ʼ���� 
	
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
	
	// Sleep(1000); // ˯��
	// *sh->get() = 100;	
	
	sh->reset();

	return 0;
}
DWORD WINAPI print(LPVOID p) 
{ 
	// Sleep(1000); // ˯��
	boost::weak_ptr<int>* w = static_cast<boost::weak_ptr<int>*>(p);			
	
	// Sleep(1000); // ˯��
	// �������ָ����reset�߳��б��ͷ���ôlock�����ͷ���nullptr������Ϳ��Ի�ù���ָ�������ô����ָ�������ж�����á�
	boost::shared_ptr<int>	sh = w->lock();	 		
	
	
	if (sh) // ����ִ�е� sh = w->lock() ʱ�����99������ִ��*sh->get() = 100��ִ��sh = w->lock()ʱ���100��
		cout << *sh << std::endl;	
	else // ��resetִ�������ִ��sh = w->lock()ʱ���nullptr��
	{
		cout << "nullptr" << endl;
	}

	return	0; 
}
void weak_ptr()
{ 
	// ���ڹ���ָ�����ָ�롣��������̫������������á�
	// ��ָ�뱣֤�˶��߳�ͨ��ָ�빫�ù���ָ��ʱ������ָ��ʹ�õİ�ȫ�ԡ�
	// ��ָ�뱾����ڶ����������û���κ�Ӱ�졣lock()����һ������ָ�룬print()�����Ϳ��԰�ȫ�ķ��ʶ����ˡ�	
	// ��ͱ�֤�ˡ�����ʹ��һ���߳�Ҫ�ͷŶ��󡪡����������з��صĹ���ָ�룬������Ȼ���ڡ�

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
	p->AddRef(); // ���ô������� 
}
void intrusive_ptr_release(IDispatch* p) 
{ 
	p->Release(); // ���ô�������
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
	// ����ʽָ��Ĺ�����ʽ�͹���ָ����ȫһ����	
	// boost::shared_ptr ���ڲ���¼�����õ�ĳ������Ĺ���ָ������������ǶԽ���ʽָ����˵������Ա�͵��Լ�������¼��	
	// ���ڿ�ܶ�����˵����ر����ã���Ϊ���Ǽ�¼���������õĴ�����
	// ʹ���� windows api һ���±ơ�������

	CoInitialize(0);

	check_windows_folder();			
	
	CoUninitialize(); 

	cout << endl;
}



void smart_ptr_vessel()  
{ 
	// ����ָ�����������Լ��ͷ�����Ԫ��ָ��Ŀռ�
	// Boost C++���ṩ��ָ������,ר����������һ�Ѷ�̬����Ķ���
	// ר�����ڹ���̬��������������������boost::ptr_deque��boost::ptr_list��boost::ptr_set��boost::ptr_map��
	// boost::ptr_unordered_set �� boost::ptr_unordered_map�� ���������� STL �е�������
	boost::ptr_vector<int> v;			
	v.push_back(new	int(1));			
	v.push_back(new	int(2));
	cout << "pointer>" << &v[0] << ":" << &v[1] << endl;

	cout << endl;
}


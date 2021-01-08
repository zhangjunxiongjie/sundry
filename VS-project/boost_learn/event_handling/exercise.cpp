// ��ϰ

// �����һ���±ƣ�����ʵ�־�û��ʹ���¼�����

#include "public.h"

/*
��дһ�����򣬶���һ����Ϊ button ���࣬��ʾGUI�е�һ���ɵ����ť��Ϊ��������������� add_handler() �� remove_handler()��
���Ǿ�Ҫ��һ����������Ϊ��������� click() ���������ã��ѵǼǵĺ���������˳��ִ�С�
���²�����Ĵ��룬����һ�� button ���ʵ�������¼��������ڲ����׼�����д��һ����Ϣ�� 
���� click() ����ģ����������ð�ť��
*/

Button::Button(boost::function<void()> func1, boost::function<void()> func2) : _addHandler(func1), _removeHandler(func2)
{

}
void Button::click()
{
	_add_handler(_addHandler);
	_remove_handler(_removeHandler);
}

void Button::_add_handler(boost::function<void()>& func)
{
	func();
}

void Button::_remove_handler(boost::function<void()>& func)
{
	func();
}
/*
when: 2020-06-03
where: �Ĵ�ʡ������ƽ����
solution explain: ѧϰʹ�� boost ��
*/
// project explain: �¼������źŲۻ��ƣ���
// file explain:

#include "public.h"

int main()
{
    // boost_signal(); // �źŲۼ�ʾ��
    
    // function_signal(); // ʹ��functionģ��ʵ���źŲ�

    // boost_signal_more_connect(); // ������������������ض��ź�

    // boost_signal_more_connect_customize();  // ���Զ���ִ��˳��Ķຯ������

    // boost_signal_more_connect_disconnect(); // �����������ͷ�

    // boost_signal_connect_slots(); // һЩ�źŲ۵Ļ�������

    // boost_signal_return();  // �����ķ���ֵ

    // boost_signal_return_customize_use();  // �Զ���ĺ�������ֵ��

    // boost_signal_return_customize_save(); // ��������ֵ�ı��档

    // boost_signal_connection(); // ʹ�� connection �����źŲ�

    // boost_connection_bind(); // ???

    // exercise δʵ��
    Button b(signal_func1, signal_func2);
    b.click();

    system("pause");
    return 0;
}
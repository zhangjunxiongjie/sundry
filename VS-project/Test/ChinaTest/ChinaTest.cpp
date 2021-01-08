// ChinaTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// C++中文字符串处理测试。

#include <iostream>
#include <string>
using namespace std;

// 把传入的str普通字符字符串转化为宽字符字符串保存在传入的宽字符串指针中
wchar_t* MBCS2Unicode(wchar_t* buff, const char* str) // 普通字符串转宽字符串
{
	wchar_t* wp = buff;  // 接收传入指针
	char* p = (char*)str; // 
	while (*p)  // 将普通字符转为宽字符 
	{
		if (*p & 0x80) 
		{
			*wp = *(wchar_t*)p;  // 这里直接对传入指针进行操作
			p++;
		}
		else {
			*wp = (wchar_t)* p;
		}
		wp++;
		p++;
	}
	*wp = 0x0000;  // 宽字符串的字符结尾标志
	return buff;  // 返回一个宽字符的字符串指针
}
char* Unicode2MBCS(char* buff, const wchar_t* str) // 宽字符串转普通字符串
{
	wchar_t* wp = (wchar_t*)str;
	char* p = buff, * tmp;
	while (*wp) {
		tmp = (char*)wp;
		if (*wp & 0xFF00) {
			*p = *tmp;
			p++; tmp++;
			*p = *tmp;
			p++;
		}
		else {
			*p = *tmp;
			p++;
		}
		wp++;
	}
	*p = 0x00;
	return buff;
}

// 容器对象的转换是基于普通字符串与宽字符串的转换基础上的
wstring str2wstr(string str) // 普通字符串容器转宽字符串容器
{
	size_t len = str.size();
	wchar_t* b = ( wchar_t* )malloc( (len + 1) * sizeof(wchar_t) ); // 申请与普通字符数目相同的宽字符空间
	if (b != NULL)
	{
		MBCS2Unicode(b, str.c_str()); // string实例的c_str()方法把string对象转换成c语言中的字符串（字符数组）样式（返回一个字符串指针）
		
		// 经过MBCS2Unicode函数后b中保存的是str字符串转化为宽字符串的结果。
		wstring r(b); // wstring:C++中处理宽字符字符串的容器，将宽字符串作为初始值生成一个c++的容器对象
		
		free(b);
		return r;  // 返回这个宽字符容器对象
	}
	else
	{
		cout << "内存分配失败！";
		system("exit");
	}
}
string wstr2str(wstring wstr) // 宽字符串容器转普通字符串容器
{
	size_t len = wstr.size();
	char* b = (char*)malloc((2 * len + 1) * sizeof(char));
	
	if (b != NULL)
	{
		Unicode2MBCS(b, wstr.c_str());
		string r(b);
		free(b);
		return r;
	}
	else
	{
		cout << "内存分配失败！";
		system("exit");
	}
}


// 
int wputs(const wchar_t* wstr) 
{
	int len = wcslen(wstr);
	char* buff = (char*)malloc((len * 2 + 1) * sizeof(char));
	Unicode2MBCS(buff, wstr);
	printf("%s", buff);
	free(buff);
	return 0;
}
int wputs(wstring wstr)
{
	wputs(wstr.c_str()); // wstr.c_str() 将宽字符串容器转化为普通宽字符串
	return 0;
}




int main()
{
	//输入层：接收char*输入，并将其转换为wchar*
	string input = "今天你在武汉！！";
	string temp = "在";

	//逻辑层在whcar*或wstring的基础上进行字符串操作，此时操作最小单位为中文字符，不会再有乱码。
	wstring buff = str2wstr(input);  // 返回一个宽字符串容器，这里要根据右边的返回值重新构造一个新的宽字符容器
	wstring temp_buff = str2wstr(temp);
	
	// wcslen(buff.c_str()) 返回将buff容器转化为普通宽字符串的长度。
	cout << "input的中文个数:" << wcslen(buff.c_str()) << "   temp的中文个数:" << wcslen(temp_buff.c_str()) << endl;
	cout << "判断input第三个是否是'在':" << (buff[3] == temp_buff[0]) << endl;;

	//输出层将wchar*的结果再次转换为char*，返回给外部
	wputs(buff);

	system("pause");
	return 0;
}
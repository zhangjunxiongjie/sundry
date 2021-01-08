// Learn6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 文件读写操作。
// 继续文件操作时一方面要注意文件的指针位置，
// 另一方面要注意文件的读写都要先放在缓冲区中然后经过缓冲区刷新才能够到达目的地

#include <fstream>
#include <iostream>
using namespace std;

class FileObject
{
public:
	FileObject(char* a, int b); // char_traits<char> c
	~FileObject();

	void FileCout();
	void FileCin();

private:
	int run;
	fstream iofile;
};

// 这里要注意对象中的对象的初始化不能放在构造函数内进行。
FileObject::FileObject(char *a, int b) :iofile(a, ios::out | ios::in), run(b)
{	
	if (!iofile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
}

FileObject::~FileObject()
{
	iofile.close();
}


// 打开一个二进制文件，并读入数据
void FileObject::FileCout()
{

	int buffer;
	
	iofile.seekp(ios::beg);  // 移动文件指针到文件起始位置。

	cout << "enter 10 integer numbers:" << endl;

	for (int i = 0; i < run; i++)
	{
		cin >> buffer;
		iofile << buffer << " ";
	}
	iofile << endl; // 刷新缓冲区
}

// 打开一个二进制文件，并读出数据。
void FileObject::FileCin()
{
	int buffer;
	
	iofile.seekp(ios::beg);  // 移动文件指针到文件起始位置。

	for (int i = 0; i < run; i++)
	{
		iofile >> buffer;
		cout << buffer << " ";
	}
	cout << endl;

}


int main()
{
	char a[] = "test.dat";
	int number = 10;

	FileObject iorun(a, number);

	iorun.FileCout();
	iorun.FileCin();

	system("Pause");
	return 0;
}





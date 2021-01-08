// Win32线程创建测试程序
// 需要在cmd窗口中运行exe文件，C语言的线程实现。

#include <Windows.h>
#include <stdio.h>
// #include <iostream>

DWORD Sum;

DWORD WINAPI summation(LPVOID Param)   // 线程执行函数
{
	DWORD Upper = *(DWORD*)Param;
	for (DWORD i = 0; i <= Upper; i++)
	{
		Sum += i;
	}
	return (Sum);
}

int main(int argc, char* argv[])   // 主线程
{
	DWORD ThreadId;
	HANDLE ThreadHandle;
	int Param;

	if (argc != 2)
	{
		fprintf(stderr, "An integer parameter is required\n");
		return -1;
	}
	Param = atoi(argv[1]);
	if (Param < 0)
	{
		fprintf(stderr, "An integer >= is required\n");
		return -1;
	}    // 两个判断都是确保输入有效

	ThreadHandle = CreateThread(NULL, 0, summation, &Param, 0, &ThreadId);  // 线程创建

	if (ThreadHandle != NULL)   // 判断线程是否创建成功。
	{
		WaitForSingleObject(ThreadHandle, INFINITE);    // 等待线程执行结束（使创建者线程阻塞，直至累加和线程退出）

		CloseHandle(ThreadHandle);   // 关闭线程，释放线程资源。

		printf("sum=%d\n", Sum);
	}

	// system("Pause");
}
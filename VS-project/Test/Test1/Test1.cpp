// Win32�̴߳������Գ���
// ��Ҫ��cmd����������exe�ļ���C���Ե��߳�ʵ�֡�

#include <Windows.h>
#include <stdio.h>
// #include <iostream>

DWORD Sum;

DWORD WINAPI summation(LPVOID Param)   // �߳�ִ�к���
{
	DWORD Upper = *(DWORD*)Param;
	for (DWORD i = 0; i <= Upper; i++)
	{
		Sum += i;
	}
	return (Sum);
}

int main(int argc, char* argv[])   // ���߳�
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
	}    // �����ж϶���ȷ��������Ч

	ThreadHandle = CreateThread(NULL, 0, summation, &Param, 0, &ThreadId);  // �̴߳���

	if (ThreadHandle != NULL)   // �ж��߳��Ƿ񴴽��ɹ���
	{
		WaitForSingleObject(ThreadHandle, INFINITE);    // �ȴ��߳�ִ�н�����ʹ�������߳�������ֱ���ۼӺ��߳��˳���

		CloseHandle(ThreadHandle);   // �ر��̣߳��ͷ��߳���Դ��

		printf("sum=%d\n", Sum);
	}

	// system("Pause");
}
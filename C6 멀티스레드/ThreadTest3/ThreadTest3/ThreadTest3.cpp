#include <Windows.h>
#include <iostream>

int sum = 0;

DWORD WINAPI MyThread(LPVOID arg)
{
	int num = (int)(long long)arg;

	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}

	return 0;
}


int main(int argc, char* argv[])
{
	int num = 100;

	HANDLE hThread = CreateThread(NULL, 0, MyThread, (LPVOID)(long long)num, CREATE_SUSPENDED, NULL);;

	std::cout << "스레드 실행 전. 계산 결과 = " << sum << std::endl;

	ResumeThread(hThread);
	WaitForSingleObject(hThread, INFINITE);

	std::cout << "스레드 실행 후. 계산 결과 = " << sum << std::endl;

	CloseHandle(hThread);

	return 0;
}
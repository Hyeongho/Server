#include <Windows.h>
#include <iostream>
#include <thread>

int sum = 0;

void MyThread(LPVOID arg)
{
	int num = (int)(long long)arg;

	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}

	return;
}


int main(int argc, char* argv[])
{
	int num = 100;

	std::thread t(MyThread, (LPVOID)(long long)num);

	std::cout << "스레드 실행 전. 계산 결과 = " << sum << std::endl;

	t.join();

	std::cout << "스레드 실행 후. 계산 결과 = " << sum << std::endl;

	return 0;
}
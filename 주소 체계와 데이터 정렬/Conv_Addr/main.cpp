#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(std::string Message);

int main(int argc, char** argv)
{
	WSADATA wsaData;

	std::string strAddr = "203.211.218.102:9190";
	//char strAddr[50] = "203.211.218.102:9190";
	char strAddrBuf[50];

	SOCKADDR_IN servAddr;
	int size = sizeof(servAddr);

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error");
	}

	if (WSAStringToAddressA(const_cast<char*>(strAddr.c_str()), AF_INET, NULL, reinterpret_cast<SOCKADDR*>(&servAddr), &size) == SOCKET_ERROR)
	{
		ErrorHandling("WSAStringToAddress() error");
	}

	size = sizeof(strAddrBuf);

	if (WSAAddressToStringA((SOCKADDR*)&servAddr, sizeof(servAddr), NULL, strAddrBuf, (LPDWORD)&size) == SOCKET_ERROR)
	{
		ErrorHandling("WSAAddressToString() error");
	}

	std::cout << "최종 변환 결과: " << strAddrBuf << std::endl;

	WSACleanup();

	return 0;
}

void ErrorHandling(std::string Message)
{
	std::cout << Message << std::endl;
	exit(1);
}

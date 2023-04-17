#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(std::string Message);

int main(int argc, char** argv)
{
	WSADATA wsaData;

	std::string addr1 = "1.2.3.4";
	std::string addr2 = "1.2.3.256";

	unsigned long convAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error");
	}

	convAddr = inet_addr(addr1.c_str());

	if (convAddr == INADDR_NONE)
	{
		std::cout << "Error Occur: " << std::hex << convAddr << std::endl;
	}

	else
	{
		std::cout << "Unsignrd long addr1(network ordered): " << std::hex << convAddr << std::endl;
	}

	convAddr = inet_addr(addr2.c_str());

	if (convAddr == INADDR_NONE)
	{
		std::cout << "Error Occur: " << std::hex << convAddr << std::endl;
	}

	else
	{
		std::cout << "Unsignrd long addr2(network ordered): " << std::hex << convAddr << std::endl;
	}

	WSACleanup();

	return 0;
}

void ErrorHandling(std::string Message)
{
	std::cout << Message << std::endl;
	exit(1);
}
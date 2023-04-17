#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(std::string Message);

int main(int argc, int** argv)
{
	WSADATA wsaData;

	SOCKET hSerSock;

	std::string servIP = "127.0.0.1";
	std::string servPort = "9190";

	SOCKADDR_IN servAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error");
	}

	hSerSock = socket(PF_INET, SOCK_STREAM, 0);

	if (hSerSock == INVALID_SOCKET)
	{
		ErrorHandling("socket() error");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(servIP.c_str());
	servAddr.sin_port = htons(atoi(servPort.c_str()));

	if (bind(hSerSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		ErrorHandling("bind() error");
	}

	std::cout << "���� ��ũ���� " << hSerSock << " �� ���Ͽ� �ּ� �Ҵ���� �Ϸ�" << std::endl << std::endl;

	WSACleanup();

	return 0;
}

void ErrorHandling(std::string Message)
{
	std::cout << Message << std::endl;
	exit(1);
}
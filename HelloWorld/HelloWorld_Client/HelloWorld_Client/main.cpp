#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <string>

void ErrorHandling(std::string Message);

int main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET hSocket;
	char message [30];
	int strLen;
	SOCKADDR_IN servAddr;

	if (argc != 3)
	{
		std::cout << "USAGE: " << argv[0] << "<IP> <port>" << std::endl;
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error!");
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0); // 辑滚 立加阑 困茄 家南 积己

	if (hSocket == INVALID_SOCKET)
	{
		ErrorHandling("hSocket() error");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		ErrorHandling("connect() error!");
	}


	strLen = recv(hSocket, message, sizeof(message) - 1, 0);

	if (strLen == -1)
	{
		ErrorHandling("read() error!");
	}

	message[strLen] = 0;

	std::cout << "Message from server: " << message << std::endl;

	closesocket(hSocket);
	WSACleanup();

	return 0;

}

void ErrorHandling(std::string Message)
{
	std::cout << Message << std::endl;

	exit(1);
}
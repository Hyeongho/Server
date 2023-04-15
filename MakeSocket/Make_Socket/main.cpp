#include <iostream>
#include <WinSock2.h>
#include <string>

void ErrorHandling(const char *Message);

int main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET hTCPSock;
	SOCKET hUDPSock;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error!");
	}

	hTCPSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // �������� TCP ���� ����

	if (hTCPSock == INVALID_SOCKET)
	{
		ErrorHandling("socket() error");
	}

	hUDPSock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (hUDPSock == INVALID_SOCKET)
	{
		ErrorHandling("socket() error");
	}

	std::cout << "������ TCP ������ �ڵ�: " << hTCPSock << std::endl;
	std::cout << "������ UDP ������ �ڵ�: " << hUDPSock << std::endl;

	closesocket(hTCPSock);
	closesocket(hUDPSock);

	WSACleanup();

	return 0;
}

void ErrorHandling(const char* Message)
{
	std::cout << Message << std::endl;
}
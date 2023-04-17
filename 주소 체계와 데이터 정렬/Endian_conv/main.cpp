#include <winsock2.h>
#include <iostream>
#include <string>

void ErrorHandling(std::string Message);

int main(int argc, char **argv)
{
	WSADATA wsaData;

	short hostOrdPort = 0x1234;
	short netOrdPort;

	long hostOrdAdd = 0x12345678;
	long netOrdAdd;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error!");
	}

	netOrdPort = htons(hostOrdPort);
	netOrdAdd = htonl(hostOrdAdd);

	std::cout << "Host ordered port: " << std::hex << hostOrdPort << std::endl;
	std::cout << "Network ordered port: " << std::hex << netOrdPort << std::endl << std::endl;

	std::cout << "Host ordered Address: " << std::hex << hostOrdAdd << std::endl;
	std::cout << "Network ordered Address: " << std::hex << netOrdAdd << std::endl << std::endl;

	return 0;
}

void ErrorHandling(std::string Message)
{
	std::cout << Message << std::endl;
	exit(1);
}

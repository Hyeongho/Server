#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h> // Ãß°¡

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(std::string Message);

int main(int argc, char** argv)
{
    WSADATA wsaData;

    std::string addr1 = "1.2.3.4";
    std::string addr2 = "1.2.3.256";

    struct in_addr convAddr;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error");
    }

    if (inet_pton(AF_INET, addr1.c_str(), &convAddr) == 1)
    {
        std::cout << "Unsigned long addr(network ordered): " << std::hex << convAddr.s_addr << std::endl;
    }

    else
    {
        std::cout << "Error Occur" << std::endl;
    }

    if (inet_pton(AF_INET, addr2.c_str(), &convAddr) == 1)
    {
        std::cout << "Unsigned long addr(network ordered): " << std::hex << convAddr.s_addr << std::endl;
    }

    else
    {
        std::cout << "Error Occur" << std::endl;
    }

    WSACleanup();

    return 0;
}

void ErrorHandling(std::string Message)
{
    std::cout << Message << std::endl;
    exit(1);
}

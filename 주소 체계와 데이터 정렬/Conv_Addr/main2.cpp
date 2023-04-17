#include <iostream>
#include <string>
#include <winsock2.h>
#include <Ws2tcpip.h> // InetNtopA() 함수 사용을 위한 헤더 파일

#pragma comment(lib, "ws2_32.lib")

void ErrorHandling(std::string Message);

int main(int argc, char** argv)
{
    WSADATA wsaData;

    std::string strAddr = "203.211.218.102:9190";
    char strAddrBuf[50];

    SOCKADDR_IN servAddr;
    int size = sizeof(servAddr);

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error");
    }

    if (InetPtonA(AF_INET, strAddr.c_str(), &servAddr.sin_addr) != 1)
    {
        ErrorHandling("InetPtonA() error");
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9190);

    // WSAAddressToStringA() 대신 InetNtopA() 함수 사용
    if (InetNtopA(AF_INET, &servAddr.sin_addr, strAddrBuf, sizeof(strAddrBuf)) == NULL)
    {
        ErrorHandling("InetNtopA() error");
    }

    std::cout << "최종 변환 결과: " << strAddrBuf << ":" << ntohs(servAddr.sin_port) << std::endl;

    WSACleanup();

    return 0;
}

void ErrorHandling(std::string Message)
{
    std::cout << Message << std::endl;
    exit(1);
}

#include "Common.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[]) {
    // 윈속 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        return 1;
    }

    /*----------------*/
    /* IPv4 변환 연습 */
    /*----------------*/

    // 원래의 IPv4 주소 출력
    const char* ipv4test = "147.46.114.70";
    std::cout << "IPv4 주소(변환전) = " << ipv4test << std::endl;

    // WSAStringToAddress() 함수 연습
    sockaddr_in ipv4num;

    int ipv4numLen = sizeof(ipv4num);
    wchar_t wideIpv4Test[INET_ADDRSTRLEN];
    MultiByteToWideChar(CP_ACP, 0, ipv4test, -1, wideIpv4Test, INET_ADDRSTRLEN);

    if (WSAStringToAddress(wideIpv4Test, AF_INET, nullptr, reinterpret_cast<sockaddr*>(&ipv4num), &ipv4numLen) != 0)
    {
        std::cout << "IPv4 주소 변환에 실패했습니다." << std::endl;
    }

    else
    {
        std::cout << "IPv4 주소(변환 후) = 0x" << std::hex << std::showbase << ipv4num.sin_addr.s_addr << std::endl;
    }

    // inet_ntop() 함수 연습
    wchar_t ipv4str[INET_ADDRSTRLEN];
    DWORD ipv4strLen = INET_ADDRSTRLEN;

    if (WSAAddressToString(reinterpret_cast<sockaddr*>(&ipv4num), sizeof(ipv4num), nullptr, reinterpret_cast<LPWSTR>(ipv4str), &ipv4strLen) != 0)
    {
        std::cout << "IPv4 주소 변환에 실패했습니다." << std::endl;
    }

    else {
        std::wcout << "IPv4 주소(다시 변환 후) = " << ipv4str << std::endl;
    }

    std::cout << std::endl;

    /*----------------*/
    /* IPv6 변환 연습 */
    /*----------------*/

    // 원래의 IPv6 주소 출력
    const char* ipv6test = "2001:0230:abcd:ffab:023:eb00:ffff:1111";
    std::cout << "IPv6 주소(변환 전) = " << ipv6test << std::endl;

    // WSAStringToAddress() 함수 연습
    sockaddr_in6 ipv6num;
    int ipv6numLen = sizeof(ipv6num);
    wchar_t wideIpv6Test[INET6_ADDRSTRLEN];
    MultiByteToWideChar(CP_ACP, 0, ipv6test, -1, wideIpv6Test, INET6_ADDRSTRLEN);

    if (WSAStringToAddress(wideIpv6Test, AF_INET6, nullptr, reinterpret_cast<sockaddr*>(&ipv6num), &ipv6numLen) != 0)
    {
        std::cout << "IPv6 주소 변환에 실패했습니다." << std::endl;
    }

    else
    {
        std::cout << "IPv6 주소(변환 후) = 0x";

        for (int i = 0; i < 16; i++)
        {
            printf("%02x", ipv6num.sin6_addr.u.Byte[i]);
        }

        std::cout << std::endl;
    }

    // inet_ntop() 함수 연습
    wchar_t ipv6str[INET6_ADDRSTRLEN];
    DWORD ipv6strLen = INET6_ADDRSTRLEN;
    if (WSAAddressToString(reinterpret_cast<sockaddr*>(&ipv6num), sizeof(ipv6num), nullptr, reinterpret_cast<LPWSTR>(ipv6str), &ipv6strLen) != 0) 
    {
        std::cout << "IPv6 주소 변환에 실패했습니다." << std::endl;
    }

    else 
    {
        std::wcout << "IPv6 주소(다시 변환 후) = " << ipv6str << std::endl;
    }

    // 윈속 종료
    WSACleanup();

    return 0;
}

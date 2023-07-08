#include "Common.h"

int main(int argc, char* argv[])
{
	// 윈속 초기화
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	/*----------------*/
	/* IPv4 변환 연습 */
	/*----------------*/

	// 원래의 IPv4 주소 출력
	const char* ipv4test = "147.46.114.70";
	cout << "IPv4 주소(변환전) = " << ipv4test << endl;

	// inet_addr() 함수 사용
	unsigned long ipv4num = inet_addr(ipv4test);
	if (ipv4num == INADDR_NONE) 
	{
		std::cout << "IPv4 주소 변환에 실패했습니다." << std::endl;
	}

	else 
	{
		std::cout << "IPv4 주소(변환 후) = " << std::hex << std::showbase << ipv4num << std::endl;
	}

	// inet_ntop() 함수 연습
	char ipv4str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));

	cout << "IPv4 주소(다시 변환 후) = " << ipv4str << endl;

	cout << endl;

	/*----------------*/
	/* IPv6 변환 연습 */
	/*----------------*/

	// 원래의 IPv6 주소 출력
	const char* ipv6test = "2001:0230:abcd:ffab:023:eb00:ffff:1111";

	cout << "IPv6 주소(변환 전) = " << ipv6test << endl;

	// inet_pton() 함수 연습
	struct in6_addr ipv6num;
	inet_pton(AF_INET6, ipv6test, &ipv6num);

	cout << "IPv6 주소(변환 후) = 0x";
	for (int i = 0; i < 16; i++)
	{
		printf("%02x", ipv6num.s6_addr[i]);
		//std::cout << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(ipv6num.s6_addr[i]);
	}

	cout << endl;

	// inet_ntop() 함수 연습
	char ipv6str[INET6_ADDRSTRLEN];
	inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str));

	cout << "IPv6 주소(다시 변환 후) = " << ipv6str << endl;

	// 윈속 종료
	WSACleanup();

	return 0;
}
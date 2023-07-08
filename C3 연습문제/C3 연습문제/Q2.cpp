#include "Common.h"

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	/*----------------*/
	/* IPv4 ��ȯ ���� */
	/*----------------*/

	// ������ IPv4 �ּ� ���
	const char* ipv4test = "147.46.114.70";
	cout << "IPv4 �ּ�(��ȯ��) = " << ipv4test << endl;

	// inet_addr() �Լ� ���
	unsigned long ipv4num = inet_addr(ipv4test);
	if (ipv4num == INADDR_NONE) 
	{
		std::cout << "IPv4 �ּ� ��ȯ�� �����߽��ϴ�." << std::endl;
	}

	else 
	{
		std::cout << "IPv4 �ּ�(��ȯ ��) = " << std::hex << std::showbase << ipv4num << std::endl;
	}

	// inet_ntop() �Լ� ����
	char ipv4str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));

	cout << "IPv4 �ּ�(�ٽ� ��ȯ ��) = " << ipv4str << endl;

	cout << endl;

	/*----------------*/
	/* IPv6 ��ȯ ���� */
	/*----------------*/

	// ������ IPv6 �ּ� ���
	const char* ipv6test = "2001:0230:abcd:ffab:023:eb00:ffff:1111";

	cout << "IPv6 �ּ�(��ȯ ��) = " << ipv6test << endl;

	// inet_pton() �Լ� ����
	struct in6_addr ipv6num;
	inet_pton(AF_INET6, ipv6test, &ipv6num);

	cout << "IPv6 �ּ�(��ȯ ��) = 0x";
	for (int i = 0; i < 16; i++)
	{
		printf("%02x", ipv6num.s6_addr[i]);
		//std::cout << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(ipv6num.s6_addr[i]);
	}

	cout << endl;

	// inet_ntop() �Լ� ����
	char ipv6str[INET6_ADDRSTRLEN];
	inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str));

	cout << "IPv6 �ּ�(�ٽ� ��ȯ ��) = " << ipv6str << endl;

	// ���� ����
	WSACleanup();

	return 0;
}
#include "Common.h"

#define TESTNAME "www.geogle.com"

// 도메인 이름 -> IPv4 주소
bool GetIPAddr(const char* name, struct in_addr* addr)
{
	struct hostent* ptr = gethostbyname(name);

	if (ptr == NULL)
	{
		err_display("gethostbyname()");

		return false;
	}

	if (ptr->h_addrtype != AF_INET)
	{
		return false;
	}

	memcpy(addr, ptr->h_addr, ptr->h_length);

	return true;
}

// IPv4 주소 -> 도메인 이름
bool GetDomainName(struct in_addr addr, char* name, int namelen)
{
	struct hostent* ptr = gethostbyaddr((const char*)&addr, sizeof(addr), AF_INET);

	if (ptr == NULL)
	{
		err_display("gethostbyaddr()");

		return false;
	}

	if (ptr->h_addrtype != AF_INET)
	{
		return false;
	}

	strncpy(name, ptr->h_name, namelen);

	return true;
}

int main(int argc, char* argv[])
{
	// 윈속 초기화
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	cout << "도메인 이름(변환 전) = " << TESTNAME << endl;

	// 도메인 이름 -> IP 주소
	struct in_addr addr;

	if (GetIPAddr(TESTNAME, &addr))
	{
		// 성공하면 결과 출력
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &addr, str, sizeof(str));
		cout << "IP 주소(변환 후) = " << str << endl;
	}

	// IP 주소 -> 도메인 이름
	char name[256];

	if (GetDomainName(addr, name, sizeof(name)))
	{
		// 성공하면 결과 출력
		cout << "도메인 이름(다시 변환 후) = " << name << endl;
	}

	// 윈속 종료
	WSACleanup();

	return 0;
}
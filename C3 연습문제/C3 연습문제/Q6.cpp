#include "Common.h"

#define TESTNAME "www.naver.com"

int main(int argc, char* argv[])
{
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		return 1;
	}

	struct hostent* ptr = gethostbyname(TESTNAME);

	// ȣ��Ʈ ����
	cout << "[ȣ��Ʈ ����]" << endl;

	for (int i = 0; ptr->h_aliases[i] != NULL; i++)
	{
		printf("%s\n", ptr->h_aliases[i]);
	}

	cout << endl;

	// IPv4 ���
	cout << "[IPv4 ���]" << endl;

	for (int i = 0; ptr->h_addr_list[i] != NULL; i++)
	{
		printf("%s\n", inet_ntoa(*(IN_ADDR*)ptr->h_addr_list[i]));
	}

	return 0;
}
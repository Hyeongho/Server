#include "Common.h"

int main(int argc, char* argv[])
{
	// 윈속 초기화
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	u_short x1 = 0x1234;
	u_long y1 = 0x12345678;
	u_short x2;
	u_long y2;

	// 호스트 바이트 -> 네트워크 바이트
	cout << "[호스트 바이트 -> 네트워크 바이트]" << endl;

	x2 = htons(x1);
	cout << hex << showbase << x1 << " -> " << hex << showbase << x2 << endl;

	y2 = htonl(y1);
	cout << hex << showbase << y1 << " -> " << hex << showbase << y2 << endl;

	cout << endl;

	// 네트워크 바이트 -> 호스트 바이트
	cout << "[네트워크 바이트 -> 호스트 바이트]" << endl;

	cout << hex << showbase << x2 << " -> " << hex << showbase << ntohs(x2) << endl;
	cout << hex << showbase << y2 << " -> " << hex << showbase << ntohl(y2) << endl;

	cout << endl;

	// 잘못된 사용 예
	cout << "[잘못된 사용 예]" << endl;
	cout << hex << showbase << x1 << " -> " << hex << showbase << htonl(x1) << endl;

	// 윈속 종료
	WSACleanup();

	return 0;
}
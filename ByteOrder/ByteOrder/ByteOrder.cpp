#include "Common.h"

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	u_short x1 = 0x1234;
	u_long y1 = 0x12345678;
	u_short x2;
	u_long y2;

	// ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ
	cout << "[ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ]" << endl;

	x2 = htons(x1);
	cout << hex << showbase << x1 << " -> " << hex << showbase << x2 << endl;

	y2 = htonl(y1);
	cout << hex << showbase << y1 << " -> " << hex << showbase << y2 << endl;

	cout << endl;

	// ��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ
	cout << "[��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ]" << endl;

	cout << hex << showbase << x2 << " -> " << hex << showbase << ntohs(x2) << endl;
	cout << hex << showbase << y2 << " -> " << hex << showbase << ntohl(y2) << endl;

	cout << endl;

	// �߸��� ��� ��
	cout << "[�߸��� ��� ��]" << endl;
	cout << hex << showbase << x1 << " -> " << hex << showbase << htonl(x1) << endl;

	// ���� ����
	WSACleanup();

	return 0;
}
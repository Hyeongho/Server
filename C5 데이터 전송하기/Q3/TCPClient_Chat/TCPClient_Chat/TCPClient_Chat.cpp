#include "../../../Common.h"

string SERVERIP = "127.0.0.1";

#define SERVERPORT 9000
#define BUFSIZE 1024

int main(int argc, char* argv[])
{
	int retval;

	// ����� �μ��� ������ IP �ּҷ� ���
	if (argc > 1)
	{
		SERVERIP = argv[1];
	}

	// ���� �ʱ�ȭ
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	// ���� ����
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET)
	{
		err_quit("socket()");
	}

	// connect()
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET, SERVERIP.c_str(), &serveraddr.sin_addr);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	if (retval == SOCKET_ERROR)
	{
		err_quit("connect()");
	}

	// ������ ��ſ� ����� ����
	char buf[BUFSIZE];

	const char* testdata[] =
	{
		"�ȳ��ϼ���",
		"�ݰ�����",
		"���õ��� �� �̾߱Ⱑ ���� �� ���׿�",
		"���� �׷��׿�",
	};

	int len;

	// ������ ������ ���
	while (1)
	{
		string str;

		cin >> str;

		if (str == "q" || str == "Q")
		{
			break;
		}

		int len = str.size();

		strncpy(buf, str.c_str(), len);

		buf[len++] = '\n';

		// ������ ������(���� ����)
		retval = send(sock, (char*)&len, sizeof(int), 0);

		if (retval == SOCKET_ERROR)
		{
			err_display("send()");
		}

		// ������ ������(���� ����)
		retval = send(sock, buf, len, 0);

		if (retval == SOCKET_ERROR)
		{
			err_display("send()");
		}

		printf("\n[TCP Ŭ���̾�Ʈ] %d + %d ����Ʈ�� ���½��ϴ�.\n", (int)sizeof(int), retval);
		cout << str << endl << endl;
	}

	// ���� �ݱ�
	closesocket(sock);

	//���� ����
	WSACleanup();

	return 0;
}
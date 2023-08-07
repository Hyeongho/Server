#include "../../../Common.h"

string SERVERIP = "127.0.0.1";

#define SERVERPORT 9000
#define BUFSIZE 1024

int main(int argc, char* argv[])
{
	int retval;

	// 명령행 인수가 있으면 IP 주소로 사용
	if (argc > 1)
	{
		SERVERIP = argv[1];
	}

	// 윈속 초기화
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	// 소켓 생성
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

	// 데이터 통신에 사용할 변수
	char buf[BUFSIZE];

	const char* testdata[] =
	{
		"안녕하세요",
		"반가워요",
		"오늘따라 할 이야기가 많을 것 같네요",
		"저도 그렇네요",
	};

	int len;

	// 서버와 데이터 통신
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

		// 데이터 보내기(고정 길이)
		retval = send(sock, (char*)&len, sizeof(int), 0);

		if (retval == SOCKET_ERROR)
		{
			err_display("send()");
		}

		// 데이터 보내기(가변 길이)
		retval = send(sock, buf, len, 0);

		if (retval == SOCKET_ERROR)
		{
			err_display("send()");
		}

		printf("\n[TCP 클라이언트] %d + %d 바이트를 보냈습니다.\n", (int)sizeof(int), retval);
		cout << str << endl << endl;
	}

	// 소켓 닫기
	closesocket(sock);

	//윈속 종료
	WSACleanup();

	return 0;
}
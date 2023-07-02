#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����

#include <winsock2.h> // ���� 2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���

#include <Windows.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ

using namespace std;

// ���� �Լ� ���� ��� �� ����
void err_quit(const char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	MessageBoxA(NULL, (const char*)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

// ���� �Լ� ���� ���
void err_display(const char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	printf("[%s] %s\n", msg, (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

// ���� �Լ� ���� ���
void err_display(int errcode)
{
	LPVOID lpMsgBuf;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errcode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&lpMsgBuf, 0, NULL);
	printf("[����] %s\n", (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

// �� �ڵ�� ���� ���� �ڵ���� Commom.h �� ��� ���

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(1, 1), &wsa) != 0)
	{
		return 1;
	}

	cout << "wsa.wVersion: " << wsa.wVersion << endl;
	cout << "wsa.wHighVersion: " << wsa.wHighVersion << endl;
	cout << "wsa.szDescription: " << wsa.szDescription << endl;
	cout << "wsa.szSystemStatus: " << wsa.szSystemStatus << endl;

	cout << endl;

	cout << "[�˸�] ���� �ʱ�ȭ ����" << endl;

	// ���� ����
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET)
	{
		err_quit("socket()");
	}

	cout << "[�˸�] ���� ���� ����" << endl;

	// ���� �ݱ�
	closesocket(sock);

	// ���� ����
	WSACleanup();

	return 0;
}
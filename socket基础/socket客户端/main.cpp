#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	// ��ʼ���ͻ���
	WSAData wsdata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsdata);
	if (ret < 0)
	{
		printf("erro!");
	}
	
	// �����׽���
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// ���������������
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = PF_INET;  // ����ipv4
	sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	connect(sock, (SOCKADDR*)& sockAddr, sizeof(SOCKADDR));


	// ���շ���������
	char szBuffer[MAXBYTE] = { 0 };
	recv(sock, szBuffer, MAXBYTE, NULL);

	// ������յ�������
	//printf("Message from server:%S\n", szBuffer);

	cout << szBuffer << endl;

	// �ر��׽���

	closesocket(sock);
	

	// �رն�̬��

	WSACleanup();
	system("pause");
	return 0;


	
}

#define _WINSOCK_DEPRECATED_NO_WARNINGS 

#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")


int main()
{
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret < 0)
	{
		printf("pls restart!");
	}

	// �����׽��ֲ����ؾ��
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (servSock == NULL)
	{
		printf("erro");
	}

	// ���׽���
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockaddr_in));
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	bind(servSock, (SOCKADDR*)& sockAddr, sizeof(SOCKADDR));

	//�������״̬
	listen(servSock, 20);

	//���տͻ�������
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)& clntAddr, &nSize);
	if (clntSock == NULL)
	{
		printf("erro");
	}
	// ��ͻ��˷�������
	const char* str = "hello,world";
	send(clntSock, str, strlen(str) + sizeof(char), NULL);

	//�ر��׽���
	closesocket(clntSock);
	closesocket(servSock);

	//��ֹ DLL ��ʹ��
	WSACleanup();
	return 0;
}
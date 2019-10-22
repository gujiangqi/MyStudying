#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	// 初始化客户端
	WSAData wsdata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsdata);
	if (ret < 0)
	{
		printf("erro!");
	}
	
	// 创建套接字
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 向服务器发送请求
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = PF_INET;  // 采用ipv4
	sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	connect(sock, (SOCKADDR*)& sockAddr, sizeof(SOCKADDR));


	// 接收服务器数据
	char szBuffer[MAXBYTE] = { 0 };
	recv(sock, szBuffer, MAXBYTE, NULL);

	// 输出接收到的数据
	//printf("Message from server:%S\n", szBuffer);

	cout << szBuffer << endl;

	// 关闭套接字

	closesocket(sock);
	

	// 关闭动态库

	WSACleanup();
	system("pause");
	return 0;


	
}

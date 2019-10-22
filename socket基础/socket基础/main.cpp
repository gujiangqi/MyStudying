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

	// 创建套接字并返回句柄
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (servSock == NULL)
	{
		printf("erro");
	}

	// 绑定套接字
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockaddr_in));
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	bind(servSock, (SOCKADDR*)& sockAddr, sizeof(SOCKADDR));

	//进入监听状态
	listen(servSock, 20);

	//接收客户端请求
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)& clntAddr, &nSize);
	if (clntSock == NULL)
	{
		printf("erro");
	}
	// 向客户端发送数据
	const char* str = "hello,world";
	send(clntSock, str, strlen(str) + sizeof(char), NULL);

	//关闭套接字
	closesocket(clntSock);
	closesocket(servSock);

	//终止 DLL 的使用
	WSACleanup();
	return 0;
}
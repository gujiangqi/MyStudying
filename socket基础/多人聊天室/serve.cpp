#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <cstring>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//===============全局常量================
const int BUF_SIZE = 2048;

//===============全局变量================
SOCKET sockSer, sockCli;	 // 创建套接字
SOCKADDR_IN addrSer, addrCli; // 创建地址
int naddr = sizeof(sockaddr_in);
char sendbuf[BUF_SIZE];
char inputbuf[BUF_SIZE];
char recbuf[BUF_SIZE];


int main()
{
	// 加载socket库 WSA:windows下的异步套接字
	// 同步方式指的是发送方不等接收方响应，便接着发下个数据包的通信方式；
	// 异步指发送方发出数据后，等收到接收方发回的响应，才发下一个数据包的通信方式。
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0)
	{
		// 输出出错信息
		cout << "载入socket库失败" << endl;
		return 0;
	}

	// 创建一个socket
	// AF:address family   
	// INET：ipv4
	// 不指定协议的话，就初始化为0；
	sockSer = socket(AF_INET, SOCK_STREAM, 0);

	// 初始化地址：sockAddr_in是一个结构体，里面包含好几个参数
	// inet_addr 是将网络地址转化成网络字节序二进制
	addrSer.sin_addr.S_un.S_addr = inet_addr("192.168.0.106");
	addrSer.sin_family = AF_INET;

	// 1024以上的可以随便写
	addrSer.sin_port = htons(12348);

	// 绑定
	// sockaddr_in 类型的指针，方便来赋值
	// sockaddr 方便来传输
	bind(sockSer, (sockaddr*)& addrSer, sizeof(sockaddr));

	// 监听 listen:监听是不是有一个连接的请求
	while (1)
	{
		listen(sockSer, 5);

		// accept函数新建一个套接口，来接受客户端的数据
		sockCli = accept(sockSer, (sockaddr*)& addrCli,&naddr);
		if (sockCli != INVALID_SOCKET)  // 连接成功
		{
			cout << "连接成功！" << endl;
			strcpy(sendbuf, "hello!");
			// send()第一个参数，是listen新建的socket
			send(sockCli, sendbuf, sizeof(sendbuf), 0);
		}
	}
	return 0;
}
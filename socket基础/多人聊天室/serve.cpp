#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <cstring>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//===============ȫ�ֳ���================
const int BUF_SIZE = 2048;

//===============ȫ�ֱ���================
SOCKET sockSer, sockCli;	 // �����׽���
SOCKADDR_IN addrSer, addrCli; // ������ַ
int naddr = sizeof(sockaddr_in);
char sendbuf[BUF_SIZE];
char inputbuf[BUF_SIZE];
char recbuf[BUF_SIZE];


int main()
{
	// ����socket�� WSA:windows�µ��첽�׽���
	// ͬ����ʽָ���Ƿ��ͷ����Ƚ��շ���Ӧ������ŷ��¸����ݰ���ͨ�ŷ�ʽ��
	// �첽ָ���ͷ��������ݺ󣬵��յ����շ����ص���Ӧ���ŷ���һ�����ݰ���ͨ�ŷ�ʽ��
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0)
	{
		// ���������Ϣ
		cout << "����socket��ʧ��" << endl;
		return 0;
	}

	// ����һ��socket
	// AF:address family   
	// INET��ipv4
	// ��ָ��Э��Ļ����ͳ�ʼ��Ϊ0��
	sockSer = socket(AF_INET, SOCK_STREAM, 0);

	// ��ʼ����ַ��sockAddr_in��һ���ṹ�壬��������ü�������
	// inet_addr �ǽ������ַת���������ֽ��������
	addrSer.sin_addr.S_un.S_addr = inet_addr("192.168.0.106");
	addrSer.sin_family = AF_INET;

	// 1024���ϵĿ������д
	addrSer.sin_port = htons(12348);

	// ��
	// sockaddr_in ���͵�ָ�룬��������ֵ
	// sockaddr ����������
	bind(sockSer, (sockaddr*)& addrSer, sizeof(sockaddr));

	// ���� listen:�����ǲ�����һ�����ӵ�����
	while (1)
	{
		listen(sockSer, 5);

		// accept�����½�һ���׽ӿڣ������ܿͻ��˵�����
		sockCli = accept(sockSer, (sockaddr*)& addrCli,&naddr);
		if (sockCli != INVALID_SOCKET)  // ���ӳɹ�
		{
			cout << "���ӳɹ���" << endl;
			strcpy(sendbuf, "hello!");
			// send()��һ����������listen�½���socket
			send(sockCli, sendbuf, sizeof(sendbuf), 0);
		}
	}
	return 0;
}
#define  _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
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
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0)
	{
		cout << "erro:!" << endl;
		return 0;
	}

	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);
	if (sockCli == NULL)
	{
		return 0;
	}

	// ��ʼ���ͻ��˵ĵ�ַ��
	addrCli.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrCli.sin_port = htons(12348);
	addrCli.sin_family = AF_INET;

	// ��ʼ���������˵ĵ�ַ��
	addrSer.sin_addr.S_un.S_addr = inet_addr("172.20.10.4");
	addrSer.sin_port = htons(12348);
	addrSer.sin_family = AF_INET;
	while (1)
	{
		int ret= connect(sockCli, (sockaddr*)& addrSer, sizeof(addrSer));
		if (ret ==0)
		{
			recv(sockCli, recbuf, sizeof(recbuf), 0);
		}
	}

	return 0;
}

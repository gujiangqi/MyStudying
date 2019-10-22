#include <iostream>
#include <cstdlib>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") // 加载ws2_32.dll

using namespace std;

int main()
{
    // 初始化Dll
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    system("pause");
    return 0;
}
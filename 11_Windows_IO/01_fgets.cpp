/* 
 * descripition：从txt文档中读取数据，按照格式读取到‘=’后的值
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;

#define MAX_INT 1024
int main(int argc, char *argv[])
{
    char buffer[MAX_INT] = {0};
    int buffer2[100] = {1};
    FILE *stream;
    stream = fopen("C:\\Users\\gujiangqi\\Desktop\\test.txt", "r");
    if (stream == NULL)
    {
        printf("open error");
        exit(1);
    }
    while (!feof(stream))
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer) - 1, stream);
        string str = buffer;
        if ((str[0] != '#') && (str.find("=", 0) != string::npos))
        {
            size_t index = str.find(' ', 0);
            while (index != string::npos)
            {
                str.erase(index, 1);
                index = str.find(' ', 0);
            }
            cout << str.substr((str.find('=', 0) + 1));
        }
    }

    fclose(stream);
    system("pause");
    return 0;
}
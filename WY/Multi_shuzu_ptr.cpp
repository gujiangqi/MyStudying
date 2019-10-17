#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    //定义了一个10行5列的指针数组
    //释放内存的时候，采用降维处理
    int **p;           //定义了一个二维指针数组
    p = new int *[10]; //表示定义了一个10个元素的指针数组  可以这么看（int* [10]）;
    for (int i = 0; i < 10; i++)
    {
        p[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            p[i][j] = i + j;
            cout << p[i][j] << "  ";
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        delete[] p[i];
    }
    delete p;

    // 已知行数
    int *p1[3]; //定义了一个指向3行的指针数组，其中列数未指定
    for (int i = 0; i < 3; i++)
    {
        p1[i] = new int[2];
        for (int j = 0; j < 2; j++)
        {
            p1[i][j] = i + j;
        }
    }

    //已知列数
    int(*p2)[4]; //指向数组的指针
    p2 = new int[5][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            p2[i][j] = i + j;
        }
    }
   // delete p2;

    system("pause");
    return 0;
}
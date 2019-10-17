#include <iostream>
#include <cstdlib>
using namespace std;
// 任务的实现者
// 相当于虚函数表
int add(int a, int b)
{
    printf("func add.....\n");
    return a + b;
}

int add2(int a, int b)
{
    printf("func add2.....\n");
    return a + 2 * b;
}
int add3(int a, int b)
{
    printf("func add3.....\n");
    return a + 3 * b;
}

// 任务的调用者
// 函数指针做函数参数
typedef int (*myPointerFunc)(int a, int b);
int MainOp(myPointerFunc myfuncAdd)
{
    return myfuncAdd(3, 4);
}

int MainOp2(int (*myPointerFunc)(int a, int b))
{
    return myPointerFunc(3, 4);
}

//间接调用
void main02()
{
    MainOp(add); // 非直接调用
    MainOp(add2);
    MainOp(add3);
}
int main()
{
    add(1, 2); //直接调用
    // 定义一个函数类型
    {
        typedef int(MyfuncType)(int a, int b); //定义了一个函数类型
        MyfuncType *myPointerFunc = NULL;      //定义了一个指针，这个指针指向了某一种类的函数
        myPointerFunc = &add;                  // 细节，这边取地址与不取地址都能通过。
        myPointerFunc(3, 4);                   //简接调用
    }
    {
        int (*myPointerFunc)(int a, int b);
        myPointerFunc = add;
        myPointerFunc(3, 4);
    }

    // 函数指针做函数参数的思想剖析
    main02();
    system("pause");
    return 0;
}
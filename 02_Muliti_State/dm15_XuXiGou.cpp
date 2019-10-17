#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

//虚析构函数
class A
{
public:
    A()
    {
        p = new char[20];
        strcpy(p, "obja");
        printf("A()\n");
    }
    virtual ~A()
    {
        delete[] p;
        printf("~A()\n");
    }

private:
    char *p;
};
class B : public A
{
public:
    B()
    {
        p = new char[20];
        strcpy(p, "objb");
        printf("B()\n");
    }
    ~B()
    {
        delete[] p;
        printf("~B()\n");
    }

private:
    char *p;
};

class C : public B
{
public:
    C()
    {
        p = new char[20];
        strcpy(p, "objc");
        printf("C()\n");
    }
    ~C()
    {
        delete[] p;
        printf("~C()\n");
    }

private:
    char *p;
};
//只执行了父类的析构函数，会出现内存的泄露
//想通过父类指针，析构父类的所有成员
void howtodelete(A *base)
{
    delete base; // 这句话不会表现多态 这种属性
}
int main()
{
    C *myc = new C;

   // howtodelete(myc);
    delete myc;//直接删除
    
    system("pause");
    return 0;
}

/*
    1.函数重载
        必须在同一个类中进行
        子类无法重载父类的函数，父类同名函数将被名称覆盖
        重载是在编译期间根据参数类型和个数决定函数调用
    2.函数重写
        必须发生在父类与子类之间
        并且父类与子类中的函数必须有完全相同的类型
        使用virutal声明之后能够产生多态(如果不使用virtual，那叫重定义)
        多态是在运行期间根据具体对象的类型决定函数调用 
*/

/*
    重写分为两类
    1.虚函数重写将发生多态
    2.非虚函数重写将发生重定义
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

class Parent
{
public:
     void abc()
    {
        cout << "abc" << endl;
    }
    //重载
    virtual void func()
    {
        cout << "func() do..." << endl;
    }
    virtual void func(int i)
    {
        cout << "func() do..." << i << endl;
    }
    virtual void func(int i, int j)
    {
        cout << "func() do..." << i << " " << j << endl;
    }
};

class child : public Parent
{
public:
    void abc()
    {
        cout << "abc" << endl;
    }
    virtual void func(int i, int j)
    {
        cout << "func(int i,int j) do ..." << i << " " << j << endl;
    }
};


int main()
{
    child c1;
    c1.Parent::abc();
    system("pause");
    return 0;
}
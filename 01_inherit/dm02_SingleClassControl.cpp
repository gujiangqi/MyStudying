//单个类的访问控制
#include <stdio.h>
#include <iostream>
using namespace std;
//public 修饰的成员变量 方法 在类的内部 类的外部都能使用
//protected: 修饰的成员变量 方法 在类的内部使用 可以在继承类使用，不能在类的外部使用
//private:修饰的成员变量 方法 只能在类的内部使用
class Parent
{
public:
    int a;

protected:
    int b;

private:
    int c;

public:
    void printT()
    {
        cout << "printT" << endl;
    }
};

//公共继承不能继承私有属性
class child : public Parent
{
public:
    void useVar()
    {
        a = 0; //ok
        b = 0; //ok
        //c = 0; //
    }

protected:
private:
};

//私有继承会全部继承为私有属性
class child2 : private Parent
{
public:
    void useVar()
    {
        a = 0; //ok
        b = 0; //ok
        //c = 0; //
    }

protected:
private:
};

//私有继承会全部继承为私有属性
class child3 : protected Parent
{
public:
    void useVar()
    {
        a = 0; //ok
        b = 0; //ok
       //c = 0; //保护继承无法访问私有属性
    }

protected:
private:
};
int main01()
{
    Parent t1, t2;
    t1.a = 10;
    //t2.b = 20; //类的外部protected不可以访问
    //t3.c = 30;

   
    return 0;
}

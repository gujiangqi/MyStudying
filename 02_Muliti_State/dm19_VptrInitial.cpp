#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;
//构造函数中调用虚函数能发生多态吗

class parent
{
public:
    parent(int a = 0)
    {
        this->a = a;
        print();
    }
    //虚函数表，存储函数的地址
    virtual void print() //1.动手脚的地方，协商vitual关键字，c++会特殊处理
    {
        cout << "我是爹" << endl;
    }

private:
    int a;
};

class child : public parent
{
public:
    child(int a = 0, int b = 0) : parent(a)
    {
        this->b = b;
    }
    virtual void print()
    {
        cout << "我是儿子" << endl;
    }

private:
    int b;
};

void HowToPlay(parent *base)
{
    base->print();
  
}
int main()
{
   
    child c1;//定义子类对象时，在这个过程中，在父类构造函数中能调用虚构造函数吗
  
    system("pause");
    return 0;
}
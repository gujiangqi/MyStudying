#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

class figure
{
    //约定一个统一的接口，让子类去实现
public:
    virtual void getAera() = 0; //纯虚函数，还有纯虚函数的类是抽象类
};

class circle : public figure
{
public:
    circle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    virtual void getAera()
    {
        cout << "Circle's Area = " << 3.14 * a * a << endl;
  
    }

private:
    int a;
    int b;
};

class Tri : public figure
{
public:
    Tri(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    virtual void getAera()
    {
        cout << "Tri's Area = " << 0.5 * b * a << endl;
    
    }

private:
    int a;
    int b;
};

class Square : public figure
{
public:
    Square(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    virtual void getAera()
    {
        cout << "Square's Area = " << b * a << endl;

    }

private:
    int a;
    int b;
};

void playObj(figure *base)
{
    base->getAera();
}
int main()
{
    //figure A; //抽象类不可以实例化
    figure *base;
    circle c1(10, 20);
    Tri t1(10, 20);
    Square s1(10, 20);

    
    //面向抽象类编程（面向接口编程）
    //解耦合
    playObj(&t1);
    playObj(&s1);
    playObj(&c1);
    system("pause");
    return 0;
}
//继承中的构造和析构
#include <iostream>
using namespace std;

//类型兼容原则

class Parent
{
private:
    /* data */
public:
    Parent(){

    };
    ~Parent(){

    };
    void print()
    {
        printf("我是爹");
    };
};
class child : public Parent
{
public:
    void printC()
    {
        printf("这是儿子");
    };
};
void howToPrint(Parent *base)
{
    base->print(); //父亲的 成员函数
}

void howToPrint2(Parent &base)
{
    base.print(); //父亲的 成员函数
}
int main()
{
    //
    Parent p1;
    p1.print();

    child c1;
    c1.printC();
    c1.print();

    //1 基类指针（引用）指向 子类对象，调用父类的函数

    //1-1
    Parent *p = NULL;
    p = &c1;
    p->print();

    //1-2 指针做函数参数
    howToPrint(&c1);

    //1-3 引用做函数参数
    howToPrint2(c1);
    howToPrint2(*p);

    //第二层含义

    //可以让子类对象初始化子父类对象
    Parent p3 = c1;
    return 0;
}
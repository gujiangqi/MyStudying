#include <iostream>
using namespace std;

class A
{
public:
    static int a;
    int b;

public:
    void get_child()
    {
        cout << "b " << b << endl;
    }
};
int A::a = 100; //不是简单的变量赋值，更重要的是要告诉C++编译器 分配内存 在继承内中 用到了a不然会报错
//1.static关键字 遵守 派生类的访问控制规则
class B : public A
{
public:
    int b, c;

public:
    void get_child()
    {
        cout<<a<<endl;
        cout << "b " << b << endl;
    }
};
int main()
{
    A a1;
    B b1;
    b1.b = 1; //默认修改子类的成员变量
    b1.get_child();

    b1.A::b = 100;
    b1.get_child();
    system("pause");
    return 0;
}
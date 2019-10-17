#include <iostream>
using namespace std;

class A
{
    public:
    int a,b;
    public:
    void get_child()
    {
        cout << "b "<<b << endl;
    }
};
class B:public A
{
    public:
    int b,c;
    public:
    void get_child()
    {
        cout << "b "<<b << endl;
    }
};
int main()
{
    A a1;
    B b1;
    b1.b =1;//默认修改子类的成员变量
    b1.get_child();

    b1.A::b = 100;
    b1.get_child();
    system("pause");
    return 0;
}
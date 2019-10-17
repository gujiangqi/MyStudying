//兼容性原则遇上函数重载
#include <iostream>
using namespace std;

class parent
{
public:
    parent(int a)
    {
        this->a = a;
        cout << "a" << a << endl;
    }
    virtual void print()
    {
        cout << "Parent::a " << a << endl;
    }

private:
    int a;
};
class child : public parent
{
public:
    child(int b) : parent(b)
    {
        this->b = b;
        cout << "b" << b << endl;
    }
    void print()
    {
        cout << "Child::b " << b << endl;
    }

private:
    int b;
};

int main()
{
    parent *base = NULL;
    parent p1(20);
    child c1(30);
    base = &p1;
    base->print();

    base = &c1;
    base->print();
    system("pause");
    return 0;
}

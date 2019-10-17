#include <iostream>
using namespace std;

class B
{
public:
    int b;
};
class B1 : virtual public B
{
public:
    int b1;
};

class B2 : virtual public B
{
public:
    int b2;
};

class C : public B1, public B2
{
public:
    int c;
};
int main()
{
    C c1;
    c1.b1 = 100;
    c1.b2 = 200;
    c1.c = 102;
    c1.b = 105; //继承的二义性和虚继承
    system("pause");
    return 0;
}
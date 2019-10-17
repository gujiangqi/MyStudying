#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

class interface1
{
public:
    virtual int add(int a, int b) = 0;
    virtual void printf() = 0;
};

class interface2
{
public:
    virtual int multi(int a, int b) = 0;
    virtual void printf() = 0;
};
class parent
{
public:
    int getA(int a)
    {
        a = 0;
        return 0;
    }

private:
    int a;
};
class child : public parent, public interface1, public interface2
{
    virtual int add(int a, int b)
    {
        cout << "add have been done..." << endl;
        return a + b;
    }
    virtual void printf()
    {
    }
    virtual int multi(int a, int b)
    {
        cout << "multi have been done..." << endl;
        return a * b;
    }
};

int main()
{
    child c1;
    child c2;
    interface1 *it1 = &c1;
    it1->add(1, 2);
    interface2 *it2 = &c2;
    it2->multi(3, 6);

    system("pause");
    return 0; 
}
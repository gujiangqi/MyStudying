#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

class A
{
public:
    int b;
};
class B1 : virtual public A
{
public:
    int b;
};

class B2 : virtual public A
{
public:
    int b;
};

class C : public B1, public  B2
{
public:
    int C;
};
int main()
{
    C myc;
    myc.C = 10;
    myc.b = 20; //二义性，指向不明
    system("pause");
    return 0;
}
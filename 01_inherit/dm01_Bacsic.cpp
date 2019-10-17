#include <iostream>
using namespace std;
//子类有父类的所有成员变量和成员函数(除了构造函数和析构函数)
//子类是一种特殊的父类
//子类可以当做父类对象使用

//派生类访问控制的结论：一般都是按照public继承，项目开发中，均是按照public继承
//需要被外界访问的成员设置成public
//protected 修饰的成员变量是为了在家族中进行使用的
class Parent
{
public:
    void print()
    {
        cout << "a" << endl;
        cout << "b" << endl;
    }
    int a, b;

private:
};

class child:public Parent
{
private:
    int c;
};

int main()
{
    child c1;
    //c1.c =1;
    c1.a = 2;
    c1.b =3;
    
    cout << "hao" << endl;
}
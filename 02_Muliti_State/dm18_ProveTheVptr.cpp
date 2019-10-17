#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

/*
    澶氭€佹垚绔嬬殑涓変釜鏉′欢锛�
        瑕佹湁缁ф壙锛岃鏈夎櫄鍑芥暟閲嶅啓锛岀埗绫绘寚閽堟寚鍚戝瓙绫诲璞�
*/

class parent1
{
public:
    parent1(int a = 0)
    {
        this->a = a;
    }
    //虚函数表，存储函数的地址
    void print() //1.动手脚的地方，协商vitual关键字，c++会特殊处理
    {
        cout << "我是爹" << endl;
    }

private:
    int a;
};

class parent2
{
public:
    parent2(int a = 0)
    {
        this->a = a;
    }
    //虚函数表，存储函数的地址
    virtual void print() //1.动手脚的地方，协商vitual关键字，c++会特殊处理
    {
        cout << "我是爹" << endl;
    }

private:
    int a;
};

class child : public parent1
{
public:
    child(int a = 0, int b = 0) : parent1(a)
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

void HowToPlay(parent1 *base)
{
    base->print(); //会有多态发生//根据传来的对象执行不同的函数，父类执行父类的程序，子类执行子类的程序
    //C++编译器根本不需要区分
    //父类对象和子类对象分别有一个vptr指针，==>虚函数表==>函数的入口地址，完成了迟绑定的效果
    //迟绑定（运行的时候，c++才去判断）
}
int main()
{

 
    printf("sizeof(parent1): %d sizeof(parent2): %d ",sizeof(parent1),sizeof(parent2));
    system("pause");
    return 0;
}
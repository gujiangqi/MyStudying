//缁ф壙鍜岀粍鍚堢殑娣锋惌
#include <iostream>
using namespace std;

class Object
{
public:
    Object(int a, int b)
    {
        this->a = a;
        this->b = b;
        cout << "object 构造函数 执行"
             << "a" << a << "b" << b << endl;
    }
    ~Object()
    {
        cout << "老祖宗的析构函数" << endl;
    }

protected:
    int a, b;
};
class Parent : public Object
{
private:
    int a, b;

public:
    Parent(const char *p) : Object(1, 2)
    {
        cout << "父类的构造函数..." << p << endl;
    };
    ~Parent()
    {
        printf("父类的析构函数 \n");
    };
    void print(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("锟斤拷锟角碉拷 \n");
    };

protected:
    const char *p;
};

class child : public Parent
{
public:
    child(const char *p) : Parent(p), obj1(2, 4), obj2(3, 6)
    {
        this->myp = p;
        cout << "子类的构造函数" << myp << endl;
    }
    ~child()
    {
        cout << "子类的析构函数" << endl;
    }
    void printC()
    {
        printf("杩欐槸鍎垮瓙");
    };

private:
    int c;

protected:
    const char *myp;
    Object obj1, obj2;
};
void playobj()
{
child c1("ab");
}
int main()
{
    playobj();
    system("pause");
    return 0;
}
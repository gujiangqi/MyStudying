//继承和组合的混搭
#include <iostream>
using namespace std;

class Object
{
public:
    Object(int a, int b)
    {
        this->a = a;
        this->b = b;
        cout << "object ���캯�� ִ��"
             << "a" << a << "b" << b << endl;
    }
    ~Object()
    {
        cout << "�����ڵ���������" << endl;
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
        cout << "����Ĺ��캯��..." << p << endl;
    };
    ~Parent()
    {
        printf("������������� \n");
    };
    void print(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("���ǵ� \n");
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
        cout << "����Ĺ��캯��" << myp << endl;
    }
    ~child()
    {
        cout << "�������������" << endl;
    }
    void printC()
    {
        printf("这是儿子");
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
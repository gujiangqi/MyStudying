//子类父类中的析构与构�?

//继承中的构造和析构
#include <iostream>
using namespace std;
//�ȵ��ø��๹�캯�����ٵ�������Ĺ��캯��
//����˳���෴
//类型兼容原则

class Parent
{
private:
    int a, b;

public:
    Parent(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("���๹�캯�� \n");
    };
    ~Parent()
    {
        printf("���������������� \n");
    };
    void print(int a, int b)
    {
        this->a = a;
        this->b = b;
        printf("���ǵ� \n");
    };
};

class child : public Parent
{
public:
    child(int a, int b, int c) : Parent(a, b)
    {
        this->c = c;
        cout << "���๹�캯��" << endl;
    }
    ~child()
    {
        cout << "������������" << endl;
    }
    void printC()
    {
        printf("这是儿子");
    };

private:
    int c;
};
void playobj()
{
    child c1(1, 2, 3);
}
int main()
{
    //  Parent p(1, 2);
    playobj();
    system("pause");
    return 0;
}
